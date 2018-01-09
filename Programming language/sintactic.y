%{
	void yerror(char *s);
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	const int MAX_NUM_VARS_FUNCS = 1024;
	char vars[MAX_NUM_VARS_FUNCS][256];		// 256 is the maximun lenght of a variable name
	char funcs[MAX_NUM_VARS_FUNCS][1024];	// 1024 is the maximun lenght of a function signature
%}

// Characters
%token O_BRACKETS	C_BRACKETS
%token O_CURLY	C_CURLY
%token O_SQUAREB	C_SUAREB
%token QUOTATION
%token SQUOT
%token S_EQUAL
%token S_SUB
%token S_DIV
%token S_MOD
%token SEMICOLON S_COMMA
%token S_ADD
%token S_ASTERISK
%token S_INCREMENTO	S_DECREMENTO
%token OPERATION


// Types and functions
%token S_INTEGER
%token S_CHAR
%token S_UNSIGNED
%token S_VARIABLE
%token S_PARAMETER
%token S_CONSTANT
%token S_DEFFUNCTION
%token S_PRINCIPAL
%token S_ARGUMENTS

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
%token NUM
%token ID
%token BINARY
%token STRING

%start START

%%
BEGIN: FUNCIONES;

FUNCIONES: FUNCION_PRINCIPAL
	| FUNCION FUNCIONES
	;

FUNCION_PRINCIPAL: S_PRINCIPAL O_CURLY EXPRESIONS C_CURLY
	| S_PRINCIPAL O_BRACKETS S_ARGUMENTS C_BRACKETS O_CURLY EXPRESIONS C_CURLY 
	;

FUNCION: S_DEFFUNCTION SIGNATURE O_CURLY EXPRESIONS C_CURLY		{checkFunctionSignature($2);};

SIGNATURE: ID O_BRACKETS C_BRACKETS 
	| ID O_BRACKETS PARAMETERS C_BRACKETS
	;

PARAMETERS: VAR_TYPE ID
	| VAR_TYPE S_PARAMETER ID
	| VAR_TYPE ID S_COMMA PARAMETERS
	| VAR_TYPE S_PARAMETER ID S_COMMA PARAMETERS
	;

EXPRESIONS: DECLARATION_VARIABLES
	| CALL_FUNCTIONS
	| OPERATIONS
	| EXPRESIONS
	;

DECLARATION_VARIABLES:VARIABLE
	| VARIABLE DECLARATION_VARIABLES
	;

VARIABLE: INT ID S_EQUAL NUMBER					{checkVariable($2);}
	| CHAR ID S_EQUAL STRING					{checkVariable($2);}
	| VAR_TYPE ID								{checkVariable($2);}
	| VAR_TYPE ID S_COMMA VARIABLE				{checkVariable($2);}
	| INT ID S_EQUAL NUMBER S_COMMA VARIABLE	{checkVariable($2);}
	| CHAR ID S_EQUAL STRING S_COMMA VARIABLE	{checkVariable($2);}
	| INT ID S_EQUAL NUMBER						{checkVariable($2);}
	| CHAR ID S_EQUAL STRING					{checkVariable($2);}
	| VAR_TYPE ID O_SQUAREB NUM C_SQUAREB		{checkVariable($2);}
	| VAR_TYPE ID O_SQUAREB C_SQUAREB			{checkVariable($2);}
	;

VAR_TYPE: INT
	| CHAR
	;

INT: S_INTEGER
	| S_CONSTANT S_INTEGER
	| S_UNSIGNED S_INTEGER
	| S_CONSTANT S_UNSIGNED S_INTEGER
	| S_INTEGER S_ASTERISK
	| S_CONSTANT S_INTEGER S_ASTERISK
	;

CHAR: S_CHAR
	| S_CONSTANTE S_CHAR
	;

S_DEFINITION: NUM
	| STRING
	| BINARY
	;

CALL_FUNCTIONS: S_VARIABLE ID S_EQUAL FUNCTION_DEFINITION
	| ID S_EQUAL FUNCTION_DEFINITION
	| FUNCTION_DEFINITION
	;

FUNCTION_DEFINITION:ID O_BRACKETS C_BRACKETS
	| ID O_BRACKETS PARAMETERS_WDECLARATION C_BRACKETS
	;
	
PARAMETERS_WDECLARATION: ID S_COMMA PARAMETERS_WDECLARATION
	| S_DEFINITION S_COMMA PARAMETERS_WDECLARATION
	| ID
	| S_DEFINITION
	;

OPERATIONS: ID S_EQUAL S_DEFINITION
	| ID S_EQUAL ID S_INCREMENTO	{$1 = $2 + 1;}
	| ID S_EQUAL ID S_DECREMENTO	{$1 = $2 - 1;}
	| ST_PLUS
	| ST_SUBSTRACTION
	| ST_MULTIPLICATION
	| ST_DIVISION
	| ST_MODULE
	| OP_BINARY
	;

ST_PLUS: ID S_EQUAL ID S_ADD ID		{$1 = $2 + $3;}
	| ID S_EQUAL ID S_ADD NUM		{$1 = $2 + $3;}
	| ID S_EQUAL NUM S_ADD ID		{$1 = $2 + $3;}
	| ID S_EQUAL NUM S_ADD NUM		{$1 = $2 + $3;}
	;

ST_SUBSTRACTION: ID S_EQUAL ID S_SUB ID	{$1 = $2 - $3;}
	| ID S_EQUAL ID S_SUB NUM			{$1 = $2 - $3;}
	| ID S_EQUAL NUM S_SUB ID			{$1 = $2 - $3;}
	| ID S_EQUAL NUM S_SUB NUM			{$1 = $2 - $3;}
	;

ST_MULTIPLICATION: ID S_EQUAL ID S_ASTERISK ID	{$1 = $2 * $3;}
	| ID S_EQUAL ID S_ASTERISK NUM				{$1 = $2 * $3;}
	| ID S_EQUAL NUM S_ASTERISK ID				{$1 = $2 * $3;}
	| ID S_EQUAL NUM S_ASTERISK NUM				{$1 = $2 * $3;}
	;

ST_DIVISION:ID S_EQUAL ID S_DIV ID	{$1 = $2 / $3;}
	| ID S_EQUAL ID S_DIV NUM		{$1 = $2 / $3;}
	| ID S_EQUAL NUM S_DIV ID		{$1 = $2 / $3;}
	| ID S_EQUAL NUM S_DIV NUM		{$1 = $2 / $3;}
	;

ST_MODULE:ID S_EQUAL ID S_MOD ID	{$1 = $2 % $3;}
	| ID S_EQUAL ID S_MOD NUM		{$1 = $2 % $3;}
	| ID S_EQUAL NUM S_MOD ID		{$1 = $2 % $3;}
	| ID S_EQUAL NUM S_MOD NUM		{$1 = $2 % $3;}
	;

OP_BINARY:ST_AND
	|ST_OR
	|ST_NOT
	;

ST_AND:ID S_EQUAL ID CS_AND ID			{$1 = $2 && $3;}
	| ID S_EQUAL ID CS_AND BINARY		{$1 = $2 && $3;}
	| ID S_EQUAL BINARY CS_AND ID		{$1 = $2 && $3;}
	| ID S_EQUAL BINARY CS_AND BINARY	{$1 = $2 && $3;}
	;

ST_OR:ID S_EQUAL ID CS_OR ID			{$1 = $2 || $3;}
	| ID S_EQUAL ID CS_OR BINARY		{$1 = $2 || $3;}
	| ID S_EQUAL BINARY CS_OR ID		{$1 = $2 || $3;}
	| ID S_EQUAL BINARY CS_OR BINARY	{$1 = $2 || $3;}
	;

ST_NOT: ID S_EQUAL CS_NOT ID		{$1 != $2;}
	| ID S_EQUAL CS_NOT BINARY		{$1 != $2;}
	| ID S_EQUAL CS_NOT OP_BINARY	{$1 != $2;}
	;

ST_IF: CS_IF O_BRACKETS CONDITION C_BRACKETS CS_THEN ST1 SEMICOLON CS_ELSE ST1 SEMICOLON
	| CS_IF O_BRACKETS CONDITION C_BRACKETS CS_THEN ST1 SEMICOLON
	;

ST_WHILE: CS_WHILE O_BRACKETS CONDITION C_BRACKETS O_CURLY ST1 C_CURLY;

ST_FOR: CS_FOR O_BRACKETS ID S_EQUAL NUM SEMICOLON CONDITION SEMICOLON ID S_INCREMENTO C_BRACKETS O_CURLY ST1 C_CURLY
	| CS_FOR O_BRACKETS ID S_EQUAL NUM SEMICOLON CONDITION SEMICOLON ID S_DECREMENTO C_BRACKETS O_CURLY ST1 C_CURLY
	| CS_FOR O_BRACKETS ID S_EQUAL NUM SEMICOLON CONDITION SEMICOLON ID OPERATION ID_NUM C_BRACKETS O_CURLY ST1 C_CURLY
	;

ST1: ST_IF
	| ST_WHILE
	| ST_FOR
	| OPERATIONS
	;

CONDITION: ID_NUM CS_EQUAL ID_NUM	{$1 == $3;}
	| ID_NUM CS_GREATER ID_NUM		{$1 > $3;}
	| ID_NUM CS_LESS ID_NUM			{$1 < $3;}
	| ID_NUM CS_DIFFERENT ID_NUM	{$1 != $3;}
	| CONDITION CS_AND CONDITION	{$1 && $3;}
	| CONDITION CS_OR CONDITION		{$1 || $3;}
	| CS_NOT CONDITION				{!$1;}
	| ID_NUM						{$1;}
	;

PRINTING: S_PRINT STRING	{printf("Printing %s\n", $2);}
	| S_PRINT NUM			{printf("Printing %d\n", $2);}
	;

STRING_OP: ID S_EQUAL STRING			{$1 = $3;}
	| ID S_EQUAL STRING S_ADD STRING	{$1 = $3; strcat($1, $5);}
	;

USER_DEF: S_STRUCT ID O_CURLY DATA C_CURLY;

DATA: VARIABLE SEMICOLON DATA
	| VARIABLE SEMICOLON
	;

ID_NUM: ID
	| NUM
%%

void checkVariable(char *name){
	int already_declared = 0;

	for(int i = 0; i < MAX_NUM_VARS_FUNCS; i++){
		if(!strcmp(&name, &vars[i])){	// This means they have the same name
			perror("This variable was already declared\n");
		}

		if(!strcmp('#', &vars[i])){
			vars[i] = &name;
			i = MAX_NUM_VARS_FUNCS + 10;	// We don't need more iterations
		}
	}
}

void checkFunctionSignature(char *name){
	int already_declared = 0;

	for(int i = 0; i < MAX_NUM_VARS_FUNCS; i++){
		if(!strcmp(&name, &funcs[i])){	// This means they have the same name
			perror("This function was already declared\n");
		}

		if(!strcmp('#', &funcs[i])){
			funcs[i] = &name;
			i = MAX_NUM_VARS_FUNCS + 10;	// We don't need more iterations
		}
	}
}

int main(){
	for(int i = 0; i < MAX_NUM_VARS_FUNCS; i++){
		vars[i] = '#';
		funcs[i] = '#'
	}

	yyparse();
}