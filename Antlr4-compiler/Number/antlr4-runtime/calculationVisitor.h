
// Generated from /Users/paprika/Desktop/练习库/AST/Antlr4-compiler/Number/calculation.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "calculationParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by calculationParser.
 */
class  calculationVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by calculationParser.
   */
    virtual antlrcpp::Any visitProgram(calculationParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitPrint(calculationParser::PrintContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(calculationParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitBlank(calculationParser::BlankContext *context) = 0;

    virtual antlrcpp::Any visitResult(calculationParser::ResultContext *context) = 0;

    virtual antlrcpp::Any visitParen(calculationParser::ParenContext *context) = 0;

    virtual antlrcpp::Any visitIden(calculationParser::IdenContext *context) = 0;

    virtual antlrcpp::Any visitAddSub(calculationParser::AddSubContext *context) = 0;

    virtual antlrcpp::Any visitMulDiv(calculationParser::MulDivContext *context) = 0;


};

