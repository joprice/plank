//
//  FileGenerator.swift
//  Plank
//
//  Created by Rahul Malik on 7/23/15.
//  Copyright © 2015 Rahul Malik. All rights reserved.
//

import Foundation

public typealias GenerationParameters = [GenerationParameterType: String]

let formatter = DateFormatter()
let date = Date()

public enum GenerationParameterType {
    case classPrefix
    case recursive
    case includeRuntime
    case indent
}

public enum Languages: String {
    case objectiveC = "objc"
    case flowtype = "flow"
}

public protocol FileGeneratorManager {
    static func filesToGenerate(descriptor: SchemaObjectRoot, generatorParameters: GenerationParameters) -> [FileGenerator]
    static func runtimeFiles() -> [FileGenerator]
}

public protocol FileGenerator {
    func renderFile() -> String
    var fileName: String { mutating get }
    var indent: Int { get }
}

// Currently not usable until upgrading the Swift Toolchain on CI
//extension Dictionary where Key == GenerationParameterType, Value == String {
//    func indent(file: FileGenerator) -> Int {
//        // Check if the GenerationParameters have an indentation set on it else just use the file indent
//        let indent: Int? = self[.indent].flatMap { Int($0) }
//        return indent ?? file.indent
//    }
//}

// Workaround until we can use the version from above
extension Dictionary where Value: ExpressibleByStringLiteral {
    // Check if the GenerationParameters have an indentation set on it else just use the file indent
    func indent(file: FileGenerator) -> Int {
        let key: Key? = GenerationParameterType.indent as? Key
        let indentFlag: String? = key.flatMap { self[$0] as? String }
        let indent: Int? = indentFlag.flatMap { Int($0) }
        return indent ?? file.indent
    }
}

extension FileGenerator {

    func renderCommentHeader() -> String {
        formatter.dateStyle = DateFormatter.Style.long
        formatter.timeStyle = .medium
        formatter.timeZone = TimeZone(identifier: "UTC")
        formatter.dateFormat = "MM-dd-yyyy 'at' HH:mm:ss"

        var copy = self

        let header = [
            "//",
            "//  \(copy.fileName)",
            "//  Autogenerated by plank",
            "//",
            "//  DO NOT EDIT - EDITS WILL BE OVERWRITTEN",
            "//  @generated",
            "//"
        ]

        return header.joined(separator: "\n")
    }
}

extension FileGeneratorManager {
    func generateFile(_ schema: SchemaObjectRoot, outputDirectory: URL, generationParameters: GenerationParameters) {
        Self.filesToGenerate(descriptor: schema, generatorParameters: generationParameters).forEach {
            writeFile(file: $0, outputDirectory: outputDirectory, generationParameters: generationParameters)
        }
    }

    public func generateFileRuntime(outputDirectory: URL, generationParameters: GenerationParameters) {
        Self.runtimeFiles().forEach {
            writeFile(file: $0, outputDirectory: outputDirectory, generationParameters: generationParameters)
        }
    }
}

func generator(forLanguage language: Languages) -> FileGeneratorManager {
    switch language {
    case .objectiveC:
        return ObjectiveCFileGenerator()
    case .flowtype:
        return JSFileGenerator()
    }
}

public func generateRuntimeFiles(outputDirectory: URL, generationParameters: GenerationParameters, forLanguages languages: [Languages]) {
    let fileGenerators: [FileGeneratorManager] = languages.map(generator)
    fileGenerators.forEach {
        $0.generateFileRuntime(outputDirectory: outputDirectory, generationParameters: generationParameters)
    }
}

public func writeFile(file: FileGenerator, outputDirectory: URL, generationParameters: GenerationParameters) {
    var file = file
    let indent = generationParameters.indent(file: file)
    let indentSpaces = String(repeating: " ", count: indent)
    let fileContents = file.renderFile()
                           .replacingOccurrences(of: "\t", with: indentSpaces)
                           .appending("\n") // Ensure there is exactly one new line a the end of the file
    do {
        try fileContents.write(
            to: URL(string: file.fileName, relativeTo: outputDirectory)!,
            atomically: true,
            encoding: String.Encoding.utf8)
    } catch {
        assert(false)
    }
}

public func loadSchemasForUrls(urls: Set<URL>) -> [(URL, Schema)] {
    return urls.map { ($0, FileSchemaLoader.sharedInstance.loadSchema($0)) }
}

public func generateDeps(urls: Set<URL>) {
    let urlSchemas = loadSchemasForUrls(urls: urls)
    let deps = Set(urlSchemas.map { (url, schema) -> String in
        ([url] + schema.deps()).map { $0.path }.joined(separator: ":")
    })
    deps.forEach { dep in
        print(dep)
    }
}

public func generateFiles(urls: Set<URL>, outputDirectory: URL, generationParameters: GenerationParameters, forLanguages languages: [Languages]) {
    let fileGenerators: [FileGeneratorManager] = languages.map(generator)
    _ = loadSchemasForUrls(urls: urls)
    var processedSchemas = Set<URL>([])
    repeat {
        _ = FileSchemaLoader.sharedInstance.refs.map({ (url: URL, schema: Schema) -> Void in
            if processedSchemas.contains(url) {
                return
            }
            processedSchemas.insert(url)
            switch schema {
            case .object(let rootObject):
                fileGenerators.forEach { generator in
                    generator.generateFile(rootObject,
                                           outputDirectory: outputDirectory,
                                           generationParameters: generationParameters)
                }
            default:
                assert(false, "Incorrect Schema for root.") // TODO Better error message.
            }
        })
    } while (
        generationParameters[.recursive] != nil &&
        processedSchemas.count != FileSchemaLoader.sharedInstance.refs.keys.count)
    if generationParameters[.includeRuntime] != nil {
        fileGenerators.forEach {
            $0.generateFileRuntime(outputDirectory: outputDirectory, generationParameters: generationParameters)
        }
    }
}
