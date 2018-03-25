protocol DictionaryConvertible {}

struct Cat: DictionaryConvertible {
    let name: String
    let age: Int
}

struct Wizard: DictionaryConvertible {
    let name: String
    let cat: Cat
}

struct Gryffindor: DictionaryConvertible {
    let wizards: [Wizard]
}
