#!/bin/zsh -i

antlr4 calculation.g4 -o antlr4-runtime-java
cd antlr4-runtime-java
javac calculation*.java
grun calculation $1 -gui ../calculation.expr