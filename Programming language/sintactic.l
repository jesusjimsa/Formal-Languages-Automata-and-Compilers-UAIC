%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
%}

NUMBER [0-9]+
SBINARY [0-1]+
LETTER [a-zA-Z]+

%%

"#"			{return P_HASH;}
"<"			{return CS_LESS;}
">"			{return CS_GREATER;}
"and"|"AND"	{return CS_AND;}
"or"|"OR"	{return CS_OR;}
"=="		{return CS_EQUAL;}
"!="		{return CS_DIFFERENT}
"not"|"NOT"	{return CS_NOT;}
"="			{return S_EQUAL;}
"+"			{return ADD;}
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
","			{return COMMA;}
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
"DEFINE"	{return W_DEFINE;}


"True"|"False"|{SBINARY}	 			{return BINARY;}
"stdio.h"|"iostream"|"math"|"string.h"	{return LIBRARIES;}

"exit"|"quit"|"bye"	{printf("Closing program\n"); exit(0);}

{NUMBER}			{return NUM;}
{LETTER}			{return ID;}
"\""{LETTER}"\""	{return STRING}

%%
