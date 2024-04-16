%{
#include<stdio.h>
int v=0,c=0;	
%}

%%
[aAeEiIoOuU]	{v++;}
[a-zA-Z]	{c++;}
\n	{return 0;}
%%
int yywrap(){return 0;}
int main()
{
printf("enter any string: ");
yylex();
printf("Vowels = %d\n",v);
printf("Consonants = %d\n",c);	
return 0;
}
   