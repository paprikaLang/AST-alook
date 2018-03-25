#ifndef MY_VISITOR_H
#define MY_VISITOR_H

#include <map>
#include <string>
#include <iostream>

#include "antlr4-runtime.h"
#include "antlr4-runtime/calculationLexer.h"
#include "antlr4-runtime/calculationParser.h"
#include "antlr4-runtime/calculationBaseVisitor.h"

using antlrcpp::Any;
using std::cout;
using std::endl;
using std::map;
using std::string;

class MyVisitor : public calculationBaseVisitor
{
  map<string, int> symbols;

public:
  MyVisitor() : symbols(map<string, int>()) {}

public:
  virtual antlrcpp::Any visitProgram(calculationParser::ProgramContext *ctx) override
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrint(calculationParser::PrintContext *ctx) override
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(calculationParser::AssignmentContext *ctx) override
  {
    std::string varName = ctx->IDENTIFIER()->toString();
    antlrcpp::Any value = visit(ctx->expression());
    symbols[varName] = value.as<int>();
    #ifdef DEBUG
    cout<<"CALLED: visitAssignment"<<endl;
    cout<<"["<<varName<<"]="<<value.as<int>()<<endl;
    #endif
    
    // return value;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlank(calculationParser::BlankContext *ctx) override
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResult(calculationParser::ResultContext *ctx) override
  {
    int value = std::stoi(ctx->getText());
    #ifdef DEBUG
    cout<<"CALLED: visitResult"<<endl;
    cout<<"Number: "<<value<<endl;
    #endif
    return value;
    // return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParen(calculationParser::ParenContext *ctx) override
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIden(calculationParser::IdenContext *ctx) override
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSub(calculationParser::AddSubContext *ctx) override
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDiv(calculationParser::MulDivContext *ctx) override
  {
    return visitChildren(ctx);
  }
};
#endif