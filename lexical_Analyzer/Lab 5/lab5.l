%{
#include<stdio.h>	
%}

%%
abc {printf("ABC");} printf("\n\nEnter any Character: ");
. {printf("unknown: %s\n",yytext);}
%%

int yywrap(){return 0;}
int main()
{
    printf("\n\nEnter any Character: ");
    yylex();
    return 0;	
}
   