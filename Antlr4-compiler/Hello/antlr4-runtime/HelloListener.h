
// Generated from /Users/paprika/Desktop/Antlr4-compiler/Hello.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "HelloParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by HelloParser.
 */
class  HelloListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterWelcome(HelloParser::WelcomeContext *ctx) = 0;
  virtual void exitWelcome(HelloParser::WelcomeContext *ctx) = 0;


};

