// Generated from calculation.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link calculationParser}.
 */
public interface calculationListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link calculationParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(calculationParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link calculationParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(calculationParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link calculationParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(calculationParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link calculationParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(calculationParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link calculationParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(calculationParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link calculationParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(calculationParser.ExpressionContext ctx);
}