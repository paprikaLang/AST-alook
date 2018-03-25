
// Generated from /Users/paprika/Desktop/练习库/AST/Antlr4-compiler/Number/calculation.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "calculationListener.h"


/**
 * This class provides an empty implementation of calculationListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  calculationBaseListener : public calculationListener {
public:

  virtual void enterProgram(calculationParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(calculationParser::ProgramContext * /*ctx*/) override { }

  virtual void enterPrint(calculationParser::PrintContext * /*ctx*/) override { }
  virtual void exitPrint(calculationParser::PrintContext * /*ctx*/) override { }

  virtual void enterAssignment(calculationParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(calculationParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterBlank(calculationParser::BlankContext * /*ctx*/) override { }
  virtual void exitBlank(calculationParser::BlankContext * /*ctx*/) override { }

  virtual void enterResult(calculationParser::ResultContext * /*ctx*/) override { }
  virtual void exitResult(calculationParser::ResultContext * /*ctx*/) override { }

  virtual void enterParen(calculationParser::ParenContext * /*ctx*/) override { }
  virtual void exitParen(calculationParser::ParenContext * /*ctx*/) override { }

  virtual void enterIden(calculationParser::IdenContext * /*ctx*/) override { }
  virtual void exitIden(calculationParser::IdenContext * /*ctx*/) override { }

  virtual void enterAddSub(calculationParser::AddSubContext * /*ctx*/) override { }
  virtual void exitAddSub(calculationParser::AddSubContext * /*ctx*/) override { }

  virtual void enterMulDiv(calculationParser::MulDivContext * /*ctx*/) override { }
  virtual void exitMulDiv(calculationParser::MulDivContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

