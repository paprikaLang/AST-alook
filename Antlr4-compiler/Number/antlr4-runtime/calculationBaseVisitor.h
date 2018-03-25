
// Generated from /Users/paprika/Desktop/练习库/AST/Antlr4-compiler/Number/calculation.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "calculationVisitor.h"


/**
 * This class provides an empty implementation of calculationVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  calculationBaseVisitor : public calculationVisitor {
public:

  virtual antlrcpp::Any visitProgram(calculationParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrint(calculationParser::PrintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(calculationParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlank(calculationParser::BlankContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResult(calculationParser::ResultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParen(calculationParser::ParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIden(calculationParser::IdenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSub(calculationParser::AddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDiv(calculationParser::MulDivContext *ctx) override {
    return visitChildren(ctx);
  }


};

