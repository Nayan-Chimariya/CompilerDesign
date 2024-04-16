%{ 
#include<stdio.h>
%}
%%
[0-9]+ {printf("It is a number\n");printf("\nEnter any Character: ");}
[a-zA-Z]+ {printf("It is a character\n");printf("\nEnter any Character: ");}
[+-/*=]+ {printf("It is an operator\n");printf("\nEnter any Character: ");}
. {printf("It is neither a number nor a character not an operator\n");printf("\nEnter any Character: ");}
%%
int yywrap(){return 0;}
int main(){
printf("Enter any Character: ");
yylex();
return 0;
}