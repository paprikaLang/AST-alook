// Generated from calculation.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class calculationLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, IDENTIFIER=8, 
		NEWLINE=9, SPACES=10, Number=11, Real=12, Exponent=13, Decimal=14, Integer=15, 
		Digit=16;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "IDENTIFIER", 
		"NEWLINE", "SPACES", "Number", "Real", "Exponent", "Decimal", "Integer", 
		"Digit"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'='", "'*'", "'/'", "'+'", "'-'", "'('", "')'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, null, "IDENTIFIER", "NEWLINE", 
		"SPACES", "Number", "Real", "Exponent", "Decimal", "Integer", "Digit"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public calculationLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "calculation.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\22n\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\3\2\3\2\3"+
		"\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\6\t\63\n\t\r\t\16\t"+
		"\64\3\n\5\n8\n\n\3\n\3\n\3\n\3\n\3\13\6\13?\n\13\r\13\16\13@\3\13\3\13"+
		"\3\f\3\f\5\fG\n\f\3\r\3\r\3\r\3\r\3\r\5\rN\n\r\5\rP\n\r\3\16\3\16\5\16"+
		"T\n\16\3\16\3\16\3\17\7\17Y\n\17\f\17\16\17\\\13\17\3\17\3\17\3\17\7\17"+
		"a\n\17\f\17\16\17d\13\17\3\20\3\20\7\20h\n\20\f\20\16\20k\13\20\3\21\3"+
		"\21\2\2\22\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33"+
		"\17\35\20\37\21!\22\3\2\6\4\2C\\c|\4\2\13\13\"\"\4\2GGgg\4\2--//\2w\2"+
		"\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2"+
		"\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2"+
		"\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\3#\3\2\2"+
		"\2\5%\3\2\2\2\7\'\3\2\2\2\t)\3\2\2\2\13+\3\2\2\2\r-\3\2\2\2\17/\3\2\2"+
		"\2\21\62\3\2\2\2\23\67\3\2\2\2\25>\3\2\2\2\27F\3\2\2\2\31O\3\2\2\2\33"+
		"Q\3\2\2\2\35Z\3\2\2\2\37e\3\2\2\2!l\3\2\2\2#$\7?\2\2$\4\3\2\2\2%&\7,\2"+
		"\2&\6\3\2\2\2\'(\7\61\2\2(\b\3\2\2\2)*\7-\2\2*\n\3\2\2\2+,\7/\2\2,\f\3"+
		"\2\2\2-.\7*\2\2.\16\3\2\2\2/\60\7+\2\2\60\20\3\2\2\2\61\63\t\2\2\2\62"+
		"\61\3\2\2\2\63\64\3\2\2\2\64\62\3\2\2\2\64\65\3\2\2\2\65\22\3\2\2\2\66"+
		"8\7\17\2\2\67\66\3\2\2\2\678\3\2\2\289\3\2\2\29:\7\f\2\2:;\3\2\2\2;<\b"+
		"\n\2\2<\24\3\2\2\2=?\t\3\2\2>=\3\2\2\2?@\3\2\2\2@>\3\2\2\2@A\3\2\2\2A"+
		"B\3\2\2\2BC\b\13\2\2C\26\3\2\2\2DG\5\37\20\2EG\5\31\r\2FD\3\2\2\2FE\3"+
		"\2\2\2G\30\3\2\2\2HI\5\37\20\2IJ\5\33\16\2JP\3\2\2\2KM\5\35\17\2LN\5\33"+
		"\16\2ML\3\2\2\2MN\3\2\2\2NP\3\2\2\2OH\3\2\2\2OK\3\2\2\2P\32\3\2\2\2QS"+
		"\t\4\2\2RT\t\5\2\2SR\3\2\2\2ST\3\2\2\2TU\3\2\2\2UV\5\37\20\2V\34\3\2\2"+
		"\2WY\5!\21\2XW\3\2\2\2Y\\\3\2\2\2ZX\3\2\2\2Z[\3\2\2\2[]\3\2\2\2\\Z\3\2"+
		"\2\2]^\7\60\2\2^b\5!\21\2_a\5!\21\2`_\3\2\2\2ad\3\2\2\2b`\3\2\2\2bc\3"+
		"\2\2\2c\36\3\2\2\2db\3\2\2\2ei\5!\21\2fh\5!\21\2gf\3\2\2\2hk\3\2\2\2i"+
		"g\3\2\2\2ij\3\2\2\2j \3\2\2\2ki\3\2\2\2lm\4\62;\2m\"\3\2\2\2\r\2\64\67"+
		"@FMOSZbi\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}