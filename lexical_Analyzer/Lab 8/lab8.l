
%{
#include<stdio.h>
int character=0,word=0,line=0;
%}

%%

int|char|float|double|void { printf("KEYWORD: %s\n", yytext); }
if|else|for|while|do|switch|case|break|continue|return { printf("CONTROL: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("IDENTIFIER: %s\n", yytext); }
[0-9]+ { printf("NUMBER: %s\n", yytext); }
"=="|"!="|"<"|">"|"<="|">="|"="|"+"|"-"|"("|")"|"."|""|"/" { printf("OPERATOR: %s\n", yytext); }
"," {printf("COMMA: %s\n", yytext);}
";" {printf("SEMICOLON: %s\n", yytext);}
"@"|"!"|"#"|"$"|"%"|"&" {printf("SPECIAL CHARACTERS: %s\n", yytext);}
\"(\\.|[^"])*\" { /* Ignore strings */ }
" " {printf("SPACE: %s\n", yytext);}
. { printf("ERROR: Unrecognized token: %s\n", yytext); }

%%

int yywrap(){return 0;}

int main()
{
    yyin = fopen("test.c","r");
    yylex();
    return 0;
}

