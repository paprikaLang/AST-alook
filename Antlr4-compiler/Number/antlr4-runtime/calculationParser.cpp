
// Generated from /Users/paprika/Desktop/练习库/AST/Antlr4-compiler/Number/calculation.g4 by ANTLR 4.7.1


#include "calculationListener.h"
#include "calculationVisitor.h"

#include "calculationParser.h"


using namespace antlrcpp;
using namespace antlr4;

calculationParser::calculationParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

calculationParser::~calculationParser() {
  delete _interpreter;
}

std::string calculationParser::getGrammarFileName() const {
  return "calculation.g4";
}

const std::vector<std::string>& calculationParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& calculationParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

calculationParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<calculationParser::StatementContext *> calculationParser::ProgramContext::statement() {
  return getRuleContexts<calculationParser::StatementContext>();
}

calculationParser::StatementContext* calculationParser::ProgramContext::statement(size_t i) {
  return getRuleContext<calculationParser::StatementContext>(i);
}


size_t calculationParser::ProgramContext::getRuleIndex() const {
  return calculationParser::RuleProgram;
}

void calculationParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void calculationParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any calculationParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calculationVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

calculationParser::ProgramContext* calculationParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, calculationParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(7); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(6);
      statement();
      setState(9); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << calculationParser::T__1)
      | (1ULL << calculationParser::ADD)
      | (1ULL << calculationParser::SUB)
      | (1ULL << calculationParser::IDENTIFIER)
      | (1ULL << calculationParser::NEWLINE)
      | (1ULL << calculationParser::Number))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

calculationParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t calculationParser::StatementContext::getRuleIndex() const {
  return calculationParser::RuleStatement;
}

void calculationParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PrintContext ------------------------------------------------------------------

calculationParser::ExpressionContext* calculationParser::PrintContext::expression() {
  return getRuleContext<calculationParser::ExpressionContext>(0);
}

calculationParser::PrintContext::PrintContext(StatementContext *ctx) { copyFrom(ctx); }

void calculationParser::PrintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrint(this);
}
void calculationParser::PrintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrint(this);
}

antlrcpp::Any calculationParser::PrintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calculationVisitor*>(visitor))
    return parserVisitor->visitPrint(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlankContext ------------------------------------------------------------------

tree::TerminalNode* calculationParser::BlankContext::NEWLINE() {
  return getToken(calculationParser::NEWLINE, 0);
}

calculationParser::BlankContext::BlankContext(StatementContext *ctx) { copyFrom(ctx); }

void calculationParser::BlankContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlank(this);
}
void calculationParser::BlankContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlank(this);
}

antlrcpp::Any calculationParser::BlankContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calculationVisitor*>(visitor))
    return parserVisitor->visitBlank(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentContext ------------------------------------------------------------------

tree::TerminalNode* calculationParser::AssignmentContext::IDENTIFIER() {
  return getToken(calculationParser::IDENTIFIER, 0);
}

calculationParser::ExpressionContext* calculationParser::AssignmentContext::expression() {
  return getRuleContext<calculationParser::ExpressionContext>(0);
}

calculationParser::AssignmentContext::AssignmentContext(StatementContext *ctx) { copyFrom(ctx); }

void calculationParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}
void calculationParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}

antlrcpp::Any calculationParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calculationVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}
calculationParser::StatementContext* calculationParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, calculationParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(16);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<calculationParser::PrintContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(11);
      expression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<calculationParser::AssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(12);
      match(calculationParser::IDENTIFIER);
      setState(13);
      match(calculationParser::T__0);
      setState(14);
      expression(0);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<calculationParser::BlankContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(15);
      match(calculationParser::NEWLINE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

calculationParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t calculationParser::ExpressionContext::getRuleIndex() const {
  return calculationParser::RuleExpression;
}

void calculationParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ResultContext ------------------------------------------------------------------

tree::TerminalNode* calculationParser::ResultContext::Number() {
  return getToken(calculationParser::Number, 0);
}

calculationParser::ResultContext::ResultContext(ExpressionContext *ctx) { copyFrom(ctx); }

void calculationParser::ResultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResult(this);
}
void calculationParser::ResultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResult(this);
}

antlrcpp::Any calculationParser::ResultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calculationVisitor*>(visitor))
    return parserVisitor->visitResult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenContext ------------------------------------------------------------------

calculationParser::ExpressionContext* calculationParser::ParenContext::expression() {
  return getRuleContext<calculationParser::ExpressionContext>(0);
}

calculationParser::ParenContext::ParenContext(ExpressionContext *ctx) { copyFrom(ctx); }

void calculationParser::ParenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParen(this);
}
void calculationParser::ParenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParen(this);
}

antlrcpp::Any calculationParser::ParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calculationVisitor*>(visitor))
    return parserVisitor->visitParen(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdenContext ------------------------------------------------------------------

tree::TerminalNode* calculationParser::IdenContext::IDENTIFIER() {
  return getToken(calculationParser::IDENTIFIER, 0);
}

calculationParser::IdenContext::IdenContext(ExpressionContext *ctx) { copyFrom(ctx); }

void calculationParser::IdenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIden(this);
}
void calculationParser::IdenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIden(this);
}

antlrcpp::Any calculationParser::IdenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calculationVisitor*>(visitor))
    return parserVisitor->visitIden(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubContext ------------------------------------------------------------------

std::vector<calculationParser::ExpressionContext *> calculationParser::AddSubContext::expression() {
  return getRuleContexts<calculationParser::ExpressionContext>();
}

calculationParser::ExpressionContext* calculationParser::AddSubContext::expression(size_t i) {
  return getRuleContext<calculationParser::ExpressionContext>(i);
}

calculationParser::AddSubContext::AddSubContext(ExpressionContext *ctx) { copyFrom(ctx); }

void calculationParser::AddSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSub(this);
}
void calculationParser::AddSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSub(this);
}

antlrcpp::Any calculationParser::AddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calculationVisitor*>(visitor))
    return parserVisitor->visitAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivContext ------------------------------------------------------------------

std::vector<calculationParser::ExpressionContext *> calculationParser::MulDivContext::expression() {
  return getRuleContexts<calculationParser::ExpressionContext>();
}

calculationParser::ExpressionContext* calculationParser::MulDivContext::expression(size_t i) {
  return getRuleContext<calculationParser::ExpressionContext>(i);
}

calculationParser::MulDivContext::MulDivContext(ExpressionContext *ctx) { copyFrom(ctx); }

void calculationParser::MulDivContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDiv(this);
}
void calculationParser::MulDivContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calculationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDiv(this);
}

antlrcpp::Any calculationParser::MulDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calculationVisitor*>(visitor))
    return parserVisitor->visitMulDiv(this);
  else
    return visitor->visitChildren(this);
}

calculationParser::ExpressionContext* calculationParser::expression() {
   return expression(0);
}

calculationParser::ExpressionContext* calculationParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  calculationParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  calculationParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, calculationParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(28);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case calculationParser::ADD:
      case calculationParser::SUB:
      case calculationParser::Number: {
        _localctx = _tracker.createInstance<ResultContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(20);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == calculationParser::ADD

        || _la == calculationParser::SUB) {
          setState(19);
          _la = _input->LA(1);
          if (!(_la == calculationParser::ADD

          || _la == calculationParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        setState(22);
        match(calculationParser::Number);
        break;
      }

      case calculationParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<IdenContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(23);
        match(calculationParser::IDENTIFIER);
        break;
      }

      case calculationParser::T__1: {
        _localctx = _tracker.createInstance<ParenContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(24);
        match(calculationParser::T__1);
        setState(25);
        expression(0);
        setState(26);
        match(calculationParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(38);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(36);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(30);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(31);
          _la = _input->LA(1);
          if (!(_la == calculationParser::MUL

          || _la == calculationParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(32);
          expression(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(33);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(34);
          _la = _input->LA(1);
          if (!(_la == calculationParser::ADD

          || _la == calculationParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(35);
          expression(5);
          break;
        }

        } 
      }
      setState(40);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool calculationParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool calculationParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> calculationParser::_decisionToDFA;
atn::PredictionContextCache calculationParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN calculationParser::_atn;
std::vector<uint16_t> calculationParser::_serializedATN;

std::vector<std::string> calculationParser::_ruleNames = {
  "program", "statement", "expression"
};

std::vector<std::string> calculationParser::_literalNames = {
  "", "'='", "'('", "')'", "'*'", "'/'", "'+'", "'-'"
};

std::vector<std::string> calculationParser::_symbolicNames = {
  "", "", "", "", "MUL", "DIV", "ADD", "SUB", "IDENTIFIER", "NEWLINE", "SPACES", 
  "Number", "Real", "Exponent", "Decimal", "Integer", "Digit"
};

dfa::Vocabulary calculationParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> calculationParser::_tokenNames;

calculationParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x12, 0x2c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x3, 0x2, 0x6, 0x2, 0xa, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0xb, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x13, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x17, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x1f, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x27, 0xa, 
    0x4, 0xc, 0x4, 0xe, 0x4, 0x2a, 0xb, 0x4, 0x3, 0x4, 0x2, 0x3, 0x6, 0x5, 
    0x2, 0x4, 0x6, 0x2, 0x4, 0x3, 0x2, 0x8, 0x9, 0x3, 0x2, 0x6, 0x7, 0x2, 
    0x30, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4, 0x12, 0x3, 0x2, 0x2, 0x2, 0x6, 
    0x1e, 0x3, 0x2, 0x2, 0x2, 0x8, 0xa, 0x5, 0x4, 0x3, 0x2, 0x9, 0x8, 0x3, 
    0x2, 0x2, 0x2, 0xa, 0xb, 0x3, 0x2, 0x2, 0x2, 0xb, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0xb, 0xc, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3, 0x3, 0x2, 0x2, 0x2, 0xd, 
    0x13, 0x5, 0x6, 0x4, 0x2, 0xe, 0xf, 0x7, 0xa, 0x2, 0x2, 0xf, 0x10, 0x7, 
    0x3, 0x2, 0x2, 0x10, 0x13, 0x5, 0x6, 0x4, 0x2, 0x11, 0x13, 0x7, 0xb, 
    0x2, 0x2, 0x12, 0xd, 0x3, 0x2, 0x2, 0x2, 0x12, 0xe, 0x3, 0x2, 0x2, 0x2, 
    0x12, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x5, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x16, 0x8, 0x4, 0x1, 0x2, 0x15, 0x17, 0x9, 0x2, 0x2, 0x2, 0x16, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x1f, 0x7, 0xd, 0x2, 0x2, 0x19, 0x1f, 0x7, 0xa, 
    0x2, 0x2, 0x1a, 0x1b, 0x7, 0x4, 0x2, 0x2, 0x1b, 0x1c, 0x5, 0x6, 0x4, 
    0x2, 0x1c, 0x1d, 0x7, 0x5, 0x2, 0x2, 0x1d, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x14, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1e, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x28, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 
    0xc, 0x7, 0x2, 0x2, 0x21, 0x22, 0x9, 0x3, 0x2, 0x2, 0x22, 0x27, 0x5, 
    0x6, 0x4, 0x8, 0x23, 0x24, 0xc, 0x6, 0x2, 0x2, 0x24, 0x25, 0x9, 0x2, 
    0x2, 0x2, 0x25, 0x27, 0x5, 0x6, 0x4, 0x7, 0x26, 0x20, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x23, 0x3, 0x2, 0x2, 0x2, 0x27, 0x2a, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x8, 0xb, 0x12, 
    0x16, 0x1e, 0x26, 0x28, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

calculationParser::Initializer calculationParser::_init;
