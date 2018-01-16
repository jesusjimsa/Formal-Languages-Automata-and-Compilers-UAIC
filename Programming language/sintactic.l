%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"

	int i;
%}

NUMBER [0-9]+
SBINARY 0|1
LETTER [a-zA-Z]
WORD [a-zA-Z]+
STRING_CONTENT (.*?)
SPACE [ ]*

%option yylineno

%%

"<"			{return CS_LESS;}
">"			{return CS_GREATER;}
"and"|"AND"	{return CS_AND;}
"or"|"OR"	{return CS_OR;}
"=="		{return CS_EQUAL;}
"!="		{return CS_DIFFERENT;}
"not"|"NOT"	{return CS_NOT;}
"="			{return S_EQUAL;}
"+"			{return S_ADD;}
"-"			{return S_SUB;}
"/"			{return S_DIV;}
"%"			{return S_MOD;}
"++"		{return S_INCREMENTO;}
"--"		{return S_DECREMENTO;}
"("			{return O_BRACKETS;}
")"			{return C_BRACKETS;}
"{"			{return O_CURLY;}
"}"			{return C_CURLY;}
"["			{return O_SQUAREB;}
"]"			{return C_SQUAREB;}
"&"			{return S_PARAMETER;}
"'"			{return SQUOT;}
"\""		{return QUOTATION;}
";"			{return SEMICOLON;}
","			{return S_COMMA;}
"*"			{return S_ASTERISK;}
"int"		{return S_INTEGER;}
"char"		{return S_CHAR;}
"unsigned"	{return S_UNSIGNED;}
"function"	{return S_DEFFUNCTION;}
"principal"	{return S_PRINCIPAL;}
"const"		{return S_CONSTANT;}
"arguments"	{return S_ARGUMENTS;}
"if"		{return CS_IF;}
"then"		{return CS_THEN;}
"else"		{return CS_ELSE;}
"while"		{return CS_WHILE;}
"for"		{return CS_WHILE;}
"struct"	{return S_STRUCT;}
"print"		{return S_PRINT;}

"true"|"false"|{SBINARY}	 			{return BINARY;}

"exit"|"quit"|"bye"	{printf("Closing program\n"); exit(0);}

{NUMBER}					{yylval.num = atoi(yytext); return NUM;}
{SPACE}{LETTER}{SPACE}		{
								for(i = 0; i < strlen(yytext); i++){
									if(yytext[i] != ' '){	// The blank space character
										yylval.id = yytext[i];
										return ID;
									}
								}
							}
{WORD}						{
								if((yylval.string = malloc(strlen(yytext) * 2)) != NULL){	// Twice, just in case
									strcpy(yylval.string, yytext);
									return FUNC_NAME;
								}
								else{
									perror("Error in malloc\n");
									exit(0);
								}
							}
"\""{STRING_CONTENT}"\""	{
								if((yylval.string = malloc(strlen(yytext) * 2)) != NULL){	// Twice, just in case
									strcpy(yylval.string, yytext);
									return STRING;
								}
								else{
									perror("Error in malloc\n");
									exit(0);
								}
							}

[\n\t]	;	// Ignores line breaks

%%