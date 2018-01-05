%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
%}

NUMBER [0-9]+
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
"="			{return EQUAL;}
"+"			{return ADD;}
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
"*"			{return S_ASTERISK;}
"int"		{return S_INTEGER;}
"char"		{return S_CHAR;}
"const"		{return S_CONSTANTE;}
"main"		{return S_MAIN;}
"if"		{return CS_IF;}
"then"		{return CS_THEN;}
"else"		{return CS_ELSE;}
"while"		{return CS_WHILE;}
"for"		{return CS_WHILE;}
"struct"	{return S_STRUCT;}
"print"		{return S_PRINT;}
"DEFINE"	{return W_DEFINE;}

"+="|"-="|"*="|"=¬"										{return S_ASSIGNMENT;}
"0"|"1"|"True"|"False"									{return S_NBINARIO;}
"stdio.h"|"iostream"|"math"|"string.h"					{return LIBRARIES;}
"int"|"void"|"bool"|"char"|"double"|"float"				{return S_VARIABLE;}
"+"|"-"|"*"|"/"|"%"|"~"|"&"|"and"|"or"|"xor"|"nand"|"^" {return OPERATION;}

"exit"|"quit"|"bye"	{printf("Closing program\n"); exit(0);}

{NUMBER}			{return NUM;}
{LETTER}			{return ID;}
"\""{LETTER}"\""	{return STRING}

%%