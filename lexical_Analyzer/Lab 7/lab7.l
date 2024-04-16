%{
#include<stdio.h>
int character=0,word=0,line=0;	
%}

%%
[a-zA-Z]	{character++;}
[\t ' ']	{word++;}
\n	{line++;}
.	{}
%%
int yywrap(){return 0;}
int main()
{
yyin = fopen("sample.txt","r");
yylex();
printf("File contents ...\n");
printf("Characters = %d\n",character);
printf("lines = %d\n",line);
printf("Words = %d\n",word);	
return 0;
}
