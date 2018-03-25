
// Generated from /Users/paprika/Desktop/Antlr4-compiler/Hello.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "HelloListener.h"


/**
 * This class provides an empty implementation of HelloListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  HelloBaseListener : public HelloListener {
public:

  virtual void enterWelcome(HelloParser::WelcomeContext * /*ctx*/) override { }
  virtual void exitWelcome(HelloParser::WelcomeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

