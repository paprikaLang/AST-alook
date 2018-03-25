
// Generated from /Users/paprika/Desktop/练习库/AST/Antlr4-compiler/Number/calculation.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "calculationParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by calculationParser.
 */
class  calculationListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(calculationParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(calculationParser::ProgramContext *ctx) = 0;

  virtual void enterPrint(calculationParser::PrintContext *ctx) = 0;
  virtual void exitPrint(calculationParser::PrintContext *ctx) = 0;

  virtual void enterAssignment(calculationParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(calculationParser::AssignmentContext *ctx) = 0;

  virtual void enterBlank(calculationParser::BlankContext *ctx) = 0;
  virtual void exitBlank(calculationParser::BlankContext *ctx) = 0;

  virtual void enterResult(calculationParser::ResultContext *ctx) = 0;
  virtual void exitResult(calculationParser::ResultContext *ctx) = 0;

  virtual void enterParen(calculationParser::ParenContext *ctx) = 0;
  virtual void exitParen(calculationParser::ParenContext *ctx) = 0;

  virtual void enterIden(calculationParser::IdenContext *ctx) = 0;
  virtual void exitIden(calculationParser::IdenContext *ctx) = 0;

  virtual void enterAddSub(calculationParser::AddSubContext *ctx) = 0;
  virtual void exitAddSub(calculationParser::AddSubContext *ctx) = 0;

  virtual void enterMulDiv(calculationParser::MulDivContext *ctx) = 0;
  virtual void exitMulDiv(calculationParser::MulDivContext *ctx) = 0;


};

