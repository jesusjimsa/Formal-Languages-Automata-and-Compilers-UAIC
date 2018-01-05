%{
	void yerror(char *s);
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
%}

// Characters
%token O_BRACKETS	C_BRACKETS
%token O_CURLY	C_CURLY
%token QUOTATION
%token SQUOT
%token EQUAL
%token SEMICOLON
%token ADD

// Control statements
%token CS_IF
%token CS_THEN
%token CS_ELSE
%token CS_WHILE
%token CS_FOR
%token CS_AND	CS_OR	CS_EQUAL	CS_DIFFERENT	CS_LESS	CS_GREATER	CS_NOT

// User defined data types
%token S_STRUCT

// Print function
%token S_PRINT

// Others
%token S_MAIN
%token NUM
%token ID
%token STRING

%start START

%%

ST_IF: CS_IF O_BRACKETS CONDITION C_BRACKETS CS_THEN ST1 SEMICOLON CS_ELSE ST1 SEMICOLON
	| CS_IF O_BRACKETS CONDITION C_BRACKETS CS_THEN ST1 SEMICOLON
	;

ST_WHILE: CS_WHILE O_BRACKETS CONDITION C_BRACKETS O_CURLY ST1 C_CURLY;

ST_FOR: CS_FOR O_BRACKETS ID EQUAL NUM SEMICOLON CONDITION SEMICOLON ID S_INCREMENTO C_BRACKETS O_CURLY ST1 C_CURLY
	| CS_FOR O_BRACKETS ID EQUAL NUM SEMICOLON CONDITION SEMICOLON ID S_DECREMENTO C_BRACKETS O_CURLY ST1 C_CURLY
	| CS_FOR O_BRACKETS ID EQUAL NUM SEMICOLON CONDITION SEMICOLON ID OPERATION ID_NUM C_BRACKETS O_CURLY ST1 C_CURLY
	;

ST1: ST_IF
	| ST_WHILE
	| ST_FOR
	| ACT_CS
	;

CONDITION: ID_NUM CS_EQUAL ID_NUM	{$1 == $3;}
	| ID_NUM CS_GREATER ID_NUM		{$1 > $3}
	| ID_NUM CS_LESS ID_NUM			{$1 < $3}
	| ID_NUM CS_DIFFERENT ID_NUM	{$1 != $3}
	| CONDITION CS_AND CONDITION	{$1 && $3}
	| CONDITION CS_OR CONDITION		{$1 || $3}
	| CS_NOT CONDITION				{!$1}
	| ID_NUM						{$1}
	;

ACT_CS: ID_NUM OPERATION ID_NUM;

PRINTING: S_PRINT STRING	{printf("Printing %s\n", $2);}
	| S_PRINT NUM			{printf("Printing %d\n", $2);}
	;

STRING_OP: ID EQUAL STRING			{$1 = $3}
	| ID EQUAL STRING ADD STRING	{$1 = $3; strcat($1, $5);}
	;

USER_DEF: S_STRUCT ID O_CURLY DATA C_CURLY;

DATA: VARIABLE SEMICOLON DATA
	| VARIABLE SEMICOLON
	;

ID_NUM: ID
	| NUM
%%