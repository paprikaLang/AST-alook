#include <fstream>
#include <iostream>

#include "antlr4/antlr4-runtime.h"
#include "antlr4-runtime/calculationLexer.h"
#include "antlr4-runtime/calculationParser.h"
#include "antlr4-runtime/calculationBaseVisitor.h"

#include "MyVisitor.h"
 
using antlr4::ANTLRInputStream;
using antlr4::CommonTokenStream;
using antlr4::tree::ParseTree;
using antlr4::tree::ParseTreeWalker;
using std::cout;
using std::endl;
using std::ifstream;

int main(int argc, char *argv[])
{
  ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  calculationLexer lexer(&input);
  //create a token stream
  CommonTokenStream tokens(&lexer);
  //create a parser for recognizing the tokens
  calculationParser parser(&tokens);
  //try to parse one of the rules
  calculationParser::ProgramContext *tree = parser.program();
  MyVisitor visitor;
  visitor.visitProgram(tree);
  // cout<<tree->toStringTree(&parser)<<endl;
}