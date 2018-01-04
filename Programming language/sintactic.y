%{
    void yerror(char *s);
    #include <stdio.h>
    #include <stdlib.h>

%}

// Characters
%token O_BRACKETS	C_BRACKETS
%token O_CURLY	C_CURLY
%token QUOTATION
%token SQUOT
%token EQUAL
%token SEMICOLON

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

%start START

%%

ST_IF: CS_IF O_BRACKETS CONDITION C_BRACKETS CS_THEN ST1_IF SEMICOLON CS_ELSE ST1_IF SEMICOLON
	| CS_IF O_BRACKETS CONDITION C_BRACKETS CS_THEN ST1_IF SEMICOLON
	;

ST1_IF: ST_IF
	| ACT_IF
	| ST_WHILE
	| ST_FOR
    ;

CONDITION: ID_NUM CS_EQUAL ID_NUM
	| ID_NUM CS_GREATER ID_NUM
	| ID_NUM CS_LESS ID_NUM
	| ID_NUM CS_DIFFERENT ID_NUM
	| CONDITION CS_AND CONDITION
	| CONDITION CS_OR CONDITION
	| CS_NOT CONDITION
	| ID_NUM
	;

ACT_IF: ID_NUM OPERATION ID_NUM;

ID_NUM: ID
	| NUM
	;
%%