/* Name: Jesús Jiménez Sánchez */
/* Group 2 */

%{
	#include <stdio.h>
%}

%%
"/*"[a-z]*(((aa)*)|((bb)*b))[a-z]*(((bb)*b)|((aa)*))[a-z]*"*/"	{ECHO;}

[137][0-9]*([13579][13579][13579])*	{printf("%s\n", yytext);}

.|\n	{/* Ignore the rest */}
%%

int main(){
	FILE *g;

	if(!(g = fopen("out.txt", "w"))){
		fprintf(stderr,"eroare creare fisier!");
	}
	else{
		yyout = g;
	}

	yylex();
}