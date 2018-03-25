// source.swift
enum HogwartsHouse {
    case gryffindor
    case hufflepuff
    case ravenclaw
    case slytherin
}

protocol EnumSet {}
extension HogwartsHouse: EnumSet {}
