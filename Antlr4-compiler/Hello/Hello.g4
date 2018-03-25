grammar Hello;

welcome: 'hello' ID;

ID: [a-zA-Z]+;

SPACE: [ \t\r\n]+ -> skip;
