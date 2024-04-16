%{
    #include <stdio.h>
%}

%%
int|float|char|void { printf("%s: keyword\n", yytext); }
\"(\\.|[^"])*\" { /* Ignore strings */ }
[a-zA-Z_][a-zA-Z0-9_]* { printf("%s: id %\n", yytext);} 
[+-/*=]+ {printf("%s: operator %\n", yytext);} 
 . {}
%%

int yywrap(){
    return 1;
}
int main()
{
    printf("Enter code: ");
    yylex();
    return 0;
}
