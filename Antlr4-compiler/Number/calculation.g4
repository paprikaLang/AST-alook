grammar calculation;
import numbers;

program: statement+;

statement: expression # print
    | IDENTIFIER '=' expression # assignment
    | NEWLINE # blank
    ; //支持变量赋值

expression: expression ('*' | '/') expression  #mulDiv
    | expression ('+' | '-') expression # addSub
    | ('+' | '-')? Number # result
    | IDENTIFIER # iden
    | '(' expression ')' # paren
    ;
MUL: '*';
DIV: '/';
ADD: '+';
SUB: '-';

IDENTIFIER: [a-zA-Z]+;
NEWLINE: '\r'?'\n' -> skip;
SPACES: [ \t]+ -> skip; 