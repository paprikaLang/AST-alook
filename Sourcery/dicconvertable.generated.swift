// Generated using Sourcery 0.10.0 — https://github.com/krzysztofzablocki/Sourcery
// DO NOT EDIT


extension Cat {
    var value: [String: Any] {
        return [
            "name": name
            , 
            "age": age
        ]
    }
}
extension Gryffindor {
    var value: [String: Any] {
        return [
            "wizards": wizards.map { $0.value }
        ]
    }
}
extension Wizard {
    var value: [String: Any] {
        return [
            "name": name
            , 
            "cat": cat.value
        ]
    }
}
