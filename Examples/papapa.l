/* [a-z]*o[a-z]*	{ECHO;} [a-zA-Z]* [:digit:] */
/* */

%{
	#include "stdio.h"

	int contador_palabras = 0;	
%}

%%
[0-9]+	{
			/* yytext is a string containing the matched text. */
			printf("Saw an integer: %s\n", yytext);
		}

no[a-zA-Z]*	{printf("Jeje, ha dicho no: %s\n", yytext);}

[^ \t\n]+   ++contador_palabras;

.|\n    {    /* Ignore all other characters. */    } 
%%

int main(){
	yylex();
	printf("Hay %d palabras\n", contador_palabras);
}