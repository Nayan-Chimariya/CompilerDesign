%{
#include "calc.tab.h"
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUM; }
[ \t\n]     { /* ignore whitespace */ }
"+"         { return ADD; }
"-"         { return SUB; }
"*"         { return MUL; }
"/"         { return DIV; }
"("         { return LPAREN; }
")"         { return RPAREN; }
.           { return yytext[0]; }

%%

int yywrap() {
    return 1;
}
