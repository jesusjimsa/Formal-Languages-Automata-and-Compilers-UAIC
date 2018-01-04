%{
	#include <stdio.h>
	#include <stdlib.h>
%}

NUMBER [0-9]+
LETTER [a-zA-Z]+

%%

"<"			{return CS_LESS;}
">"			{return CS_GREATER;}
"and"|"AND"	{return CS_AND;}
"or"|"OR"	{return CS_OR;}
"=="		{return CS_EQUAL;}
"!="		{return CS_DIFFERENT}
"not"|"NOT"	{return CS_NOT;}
"="			{return EQUAL;}
"("			{return O_BRACKETS;}
")"			{return C_BRACKETS;}
"{"			{return O_CURLY;}
"}"			{return C_CURLY;}
"'"			{return SQUOT;}
"\""		{return QUOTATION;}
";"			{return SEMICOLON;}
"main"		{return S_MAIN;}
"if"		{return CS_IF;}
"then"		{return CS_THEN;}
"else"		{return CS_ELSE;}
"while"		{return CS_WHILE;}
"for"		{return CS_WHILE;}
"struct"	{return S_STRUCT;}
"print"		{return S_PRINT;}

"exit"|"quit"|"bye"	{printf("Closing program\n"); exit(0);}

{NUMBER}	{return NUM;}
{LETTER}	{return ID;}

%%