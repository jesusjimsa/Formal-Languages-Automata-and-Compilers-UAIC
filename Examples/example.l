/* Build a lex file that recognises a language like this on */
/* (a^(3n+2))u, u in {b,c}*, u contains 2 of b and ends in cc, n >= 1 */
/* %% */
/* \.aa(aaa)+[bc]*c[bc]*cc\. {ECHO;} */
/* %% */

%{
	#include "stdio.h"

	int cadenas = 0;
%}


%%
aa(aaa)+(b|c)*b(b|c)*b(b|c)*cc	{printf("Detected: %s\n", yytext); cadenas++;}

.|\n	{/* Ignores all other words */}
%%

int main(){
	yylex();
	printf("The detector found %d coincidences\n", cadenas);
}