%{ 
#include<stdio.h>
%}
%%
[0-9]+ {printf("It is a number: %s",yytext);printf("\n\nEnter any Character to check whether it is number or not: ");}
. {printf("It is not a number: %s",yytext);printf("\n\nEnter any Character to check whether it is number or not: ");}
%%
int yywrap(){}
main(){
printf("Enter any Character to check whether it is number or not: ");
yylex();
}