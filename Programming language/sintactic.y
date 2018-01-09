%{
	void yerror(char *s);
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	const int MAX_NUM_VARS_FUNCS = 1024;
	char vars[MAX_NUM_VARS_FUNCS][256];		// 256 is the maximun lenght of a variable name
	char funcs[MAX_NUM_VARS_FUNCS][1024];	// 1024 is the maximun lenght of a function signature

	// For using this the compiler needs -std=C11
	// gcc -Wall -std=C11 sintactic.y -o language
	enum t_typename{
		TYPENAME_STRING,
		TYPENAME_CONST_STRING,
		TYPENAME_INT,
		TYPENAME_CONST_INT,
		TYPENAME_UNSIGNED_INT,
		TYPENAME_CONST_UNSIGNED_INT,
		TYPENAME_OTHER
	};

	#define typename(x) _Generic((x),	/* Get the name of a type */
			char: TYPENAME_STRING,
			const char: TYPENAME_CONST_STRING,
			int: TYPENAME_INT,
			const int: TYPENAME_CONST_INT,
			unsigned int: TYPENAME_UNSIGNED_INT,
			const unsigned int: TYPENAME_CONST_UNSIGNED_INT,
			default: TYPENAME_OTHER
			)
	
	#define true (1 == 1)
	#define false (!true)
%}

// Characters
%token O_BRACKETS	C_BRACKETS
%token O_CURLY	C_CURLY
%token O_SQUAREB	C_SQUAREB
%token QUOTATION
%token SQUOT
%token S_EQUAL
%token S_SUB
%token S_DIV
%token S_MOD
%token SEMICOLON	S_COMMA
%token S_ADD
%token S_ASTERISK
%token S_INCREMENTO		S_DECREMENTO
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
%token CS_IF	CS_THEN		CS_ELSE
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

//%start START

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

VARIABLE: INT ID S_EQUAL NUM					{checkVariable($2);}
	| CHAR ID S_EQUAL STRING					{checkVariable($2);}
	| VAR_TYPE ID								{checkVariable($2);}
	| VAR_TYPE ID S_COMMA VARIABLE				{checkVariable($2);}
	| INT ID S_EQUAL NUM S_COMMA VARIABLE		{checkVariable($2);}
	| CHAR ID S_EQUAL STRING S_COMMA VARIABLE	{checkVariable($2);}
	| INT ID S_EQUAL NUM						{checkVariable($2);}
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
	;

CHAR: S_CHAR
	| S_CONSTANT S_CHAR
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

OPERATIONS: ID S_EQUAL S_DEFINITION	{assign($1, $3);}
	| ID S_EQUAL ID S_INCREMENTO	{$1 = $3 + 1;}
	| ID S_EQUAL ID S_DECREMENTO	{$1 = $3 - 1;}
	| ID S_INCREMENTO				{$1 = $1 + 1;}
	| ID S_DECREMENTO				{$1 = $1 - 1;}
	| ST_PLUS
	| ST_SUBSTRACTION
	| ST_MULTIPLICATION
	| ST_DIVISION
	| ST_MODULE
	| OP_BINARY
	;

ST_PLUS: ID S_EQUAL ID S_ADD ID		{
										switch(typename($1)){
											case TYPENAME_INT:
												if(typename($3) == TYPENAME_INT || typename($3) == TYPENAME_CONST_INT || typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename($5) == TYPENAME_INT || typename($5) == TYPENAME_CONST_INT || typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
														$1 = $3 + $5;
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
														$1 = $3 + $5;
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_STRING:
												if(typename($3) == TYPENAME_STRING || typename($3) == TYPENAME_CONST_STRING){
													if(typename($5) == TYPENAME_STRING || typename($5) == TYPENAME_CONST_STRING){
														$1 = $3;
														strcat($1, $5);
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	| ID S_EQUAL ID S_ADD NUM		{
										switch(typename($1)){
											case TYPENAME_INT:
												if(typename($3) == TYPENAME_INT || typename($3) == TYPENAME_CONST_INT || typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 + $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 + $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_STRING:
												perror("You can't add a number to a string\n");
												exit(0);

												break; // Unnecesary, but here it is :)
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	| ID S_EQUAL NUM S_ADD ID		{
										switch(typename($1)){
											case TYPENAME_INT:
												if(typename($5) == TYPENAME_INT || typename($5) == TYPENAME_CONST_INT || typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 + $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 + $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_STRING:
												perror("You can't add a number to a string\n");
												exit(0);

												break; // Unnecesary, but here it is :)
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	| ID S_EQUAL NUM S_ADD NUM		{
										switch(typename($1)){
											case TYPENAME_INT:
											case TYPENAME_UNSIGNED_INT:
												$1 = $3 + $5;

												break;
											case TYPENAME_STRING:
												perror("You can't add a number to a string\n");
												exit(0);

												break; // Unnecesary, but here it is :)
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	;

ST_SUBSTRACTION: ID S_EQUAL ID S_SUB ID	{
											switch(typename($1)){
												case TYPENAME_INT:
													if(typename($3) == TYPENAME_INT || typename($3) == TYPENAME_CONST_INT || typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
														if(typename($5) == TYPENAME_INT || typename($5) == TYPENAME_CONST_INT || typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
															$1 = $3 - $5;
														}
														else{
															perror("Wrong types\n");
															exit(0);
														}
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}

													break;
												case TYPENAME_UNSIGNED_INT:
													if(typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
														if(typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
															$1 = $3 - $5;
														}
														else{
															perror("Wrong types\n");
															exit(0);
														}
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}

													break;
												case TYPENAME_STRING:
													perror("You can't substract one string from another\n");
													exit(0);

													break;
												case TYPENAME_CONST_INT:
												case TYPENAME_CONST_UNSIGNED_INT:
												case TYPENAME_CONST_STRING:
													perror("You can't change the value of a constant!\n");
													exit(0);

													break;	// Unnecesary, but here it is :)
											}
										}
		| ID S_EQUAL ID S_SUB NUM		{
											switch(typename($1)){
												case TYPENAME_INT:
													if(typename($3) == TYPENAME_INT || typename($3) == TYPENAME_CONST_INT || typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
														$1 = $3 - $5;
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}

													break;
												case TYPENAME_UNSIGNED_INT:
													if(typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
														$1 = $3 - $5;
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}

													break;
												case TYPENAME_STRING:
													perror("You can't substract one string from another\n");
													exit(0);

													break; // Unnecesary, but here it is :)
												case TYPENAME_CONST_INT:
												case TYPENAME_CONST_UNSIGNED_INT:
												case TYPENAME_CONST_STRING:
													perror("You can't change the value of a constant!\n");
													exit(0);

													break;	// Unnecesary, but here it is :)
											}
										}
	| ID S_EQUAL NUM S_SUB ID			{
											switch(typename($1)){
												case TYPENAME_INT:
													if(typename($5) == TYPENAME_INT || typename($5) == TYPENAME_CONST_INT || typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
														$1 = $3 - $5;
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}

													break;
												case TYPENAME_UNSIGNED_INT:
													if(typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
														$1 = $3 - $5;
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}

													break;
												case TYPENAME_STRING:
													perror("You can't substract one string from another\n");
													exit(0);

													break; // Unnecesary, but here it is :)
												case TYPENAME_CONST_INT:
												case TYPENAME_CONST_UNSIGNED_INT:
												case TYPENAME_CONST_STRING:
													perror("You can't change the value of a constant!\n");
													exit(0);

													break;	// Unnecesary, but here it is :)
											}
										}
	| ID S_EQUAL NUM S_SUB NUM			{
											switch(typename($1)){
												case TYPENAME_INT:
												case TYPENAME_UNSIGNED_INT:
													$1 = $3 - $5;

													break;
												case TYPENAME_STRING:
													perror("You can't substract one string from another\n");
													exit(0);

													break; // Unnecesary, but here it is :)
												case TYPENAME_CONST_INT:
												case TYPENAME_CONST_UNSIGNED_INT:
												case TYPENAME_CONST_STRING:
													perror("You can't change the value of a constant!\n");
													exit(0);

													break;	// Unnecesary, but here it is :)
											}
										}
	;

ST_MULTIPLICATION: ID S_EQUAL ID S_ASTERISK ID	{
													switch(typename($1)){
														case TYPENAME_INT:
															if(typename($3) == TYPENAME_INT || typename($3) == TYPENAME_CONST_INT || typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
																if(typename($5) == TYPENAME_INT || typename($5) == TYPENAME_CONST_INT || typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
																	$1 = $3 * $5;
																}
																else{
																	perror("Wrong types\n");
																	exit(0);
																}
															}
															else{
																perror("Wrong types\n");
																exit(0);
															}

															break;
														case TYPENAME_UNSIGNED_INT:
															if(typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
																if(typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
																	$1 = $3 * $5;
																}
																else{
																	perror("Wrong types\n");
																	exit(0);
																}
															}
															else{
																perror("Wrong types\n");
																exit(0);
															}

															break;
														case TYPENAME_STRING:
															perror("You can't multiply one string with another\n");
															exit(0);

															break;
														case TYPENAME_CONST_INT:
														case TYPENAME_CONST_UNSIGNED_INT:
														case TYPENAME_CONST_STRING:
															perror("You can't change the value of a constant!\n");
															exit(0);

															break;	// Unnecesary, but here it is :)
													}
												}
	| ID S_EQUAL ID S_ASTERISK NUM				{
													switch(typename($1)){
														case TYPENAME_INT:
															if(typename($3) == TYPENAME_INT || typename($3) == TYPENAME_CONST_INT || typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
																$1 = $3 * $5;
															}
															else{
																perror("Wrong types\n");
																exit(0);
															}

															break;
														case TYPENAME_UNSIGNED_INT:
															if(typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
																$1 = $3 * $5;
															}
															else{
																perror("Wrong types\n");
																exit(0);
															}

															break;
														case TYPENAME_STRING:
															perror("You can't multiply one string with another\n");
															exit(0);

															break; // Unnecesary, but here it is :)
														case TYPENAME_CONST_INT:
														case TYPENAME_CONST_UNSIGNED_INT:
														case TYPENAME_CONST_STRING:
															perror("You can't change the value of a constant!\n");
															exit(0);

															break;	// Unnecesary, but here it is :)
													}
												}
	| ID S_EQUAL NUM S_ASTERISK ID				{
													switch(typename($1)){
														case TYPENAME_INT:
															if(typename($5) == TYPENAME_INT || typename($5) == TYPENAME_CONST_INT || typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
																$1 = $3 * $5;
															}
															else{
																perror("Wrong types\n");
																exit(0);
															}

															break;
														case TYPENAME_UNSIGNED_INT:
															if(typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
																$1 = $3 * $5;
															}
															else{
																perror("Wrong types\n");
																exit(0);
															}

															break;
														case TYPENAME_STRING:
															perror("You can't multiply one string with another\n");
															exit(0);

															break; // Unnecesary, but here it is :)
														case TYPENAME_CONST_INT:
														case TYPENAME_CONST_UNSIGNED_INT:
														case TYPENAME_CONST_STRING:
															perror("You can't change the value of a constant!\n");
															exit(0);

															break;	// Unnecesary, but here it is :)
													}
												}
	| ID S_EQUAL NUM S_ASTERISK NUM				{
													switch(typename($1)){
														case TYPENAME_INT:
														case TYPENAME_UNSIGNED_INT:
															$1 = $3 * $5;

															break;
														case TYPENAME_STRING:
															perror("You can't multiply one string with another\n");
															exit(0);

															break; // Unnecesary, but here it is :)
														case TYPENAME_CONST_INT:
														case TYPENAME_CONST_UNSIGNED_INT:
														case TYPENAME_CONST_STRING:
															perror("You can't change the value of a constant!\n");
															exit(0);

															break;	// Unnecesary, but here it is :)
													}
												}
	;

ST_DIVISION: ID S_EQUAL ID S_DIV ID	{
										switch(typename($1)){
											case TYPENAME_INT:
												if(typename($3) == TYPENAME_INT || typename($3) == TYPENAME_CONST_INT || typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename($5) == TYPENAME_INT || typename($5) == TYPENAME_CONST_INT || typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
														$1 = $3 / $5;
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
														$1 = $3 / $5;
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_STRING:
												perror("You can't divide one string with another\n");
												exit(0);

												break;
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	| ID S_EQUAL ID S_DIV NUM		{
										switch(typename($1)){
											case TYPENAME_INT:
												if(typename($3) == TYPENAME_INT || typename($3) == TYPENAME_CONST_INT || typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 / $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 / $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_STRING:
												perror("You can't divide one string with another\n");
												exit(0);

												break; // Unnecesary, but here it is :)
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	| ID S_EQUAL NUM S_DIV ID		{
										switch(typename($1)){
											case TYPENAME_INT:
												if(typename($5) == TYPENAME_INT || typename($5) == TYPENAME_CONST_INT || typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 / $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 / $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_STRING:
												perror("You can't divide one string with another\n");
												exit(0);

												break; // Unnecesary, but here it is :)
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	| ID S_EQUAL NUM S_DIV NUM		{
										switch(typename($1)){
											case TYPENAME_INT:
											case TYPENAME_UNSIGNED_INT:
												$1 = $3 / $5;

												break;
											case TYPENAME_STRING:
												perror("You can't divide one string with another\n");
												exit(0);

												break; // Unnecesary, but here it is :)
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	;

ST_MODULE: ID S_EQUAL ID S_MOD ID	{
										switch(typename($1)){
											case TYPENAME_INT:
												if(typename($3) == TYPENAME_INT || typename($3) == TYPENAME_CONST_INT || typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename($5) == TYPENAME_INT || typename($5) == TYPENAME_CONST_INT || typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
														$1 = $3 % $5;
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
														$1 = $3 % $5;
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_STRING:
												perror("You can't do the module to a string\n");
												exit(0);

												break;
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	| ID S_EQUAL ID S_MOD NUM		{
										switch(typename($1)){
											case TYPENAME_INT:
												if(typename($3) == TYPENAME_INT || typename($3) == TYPENAME_CONST_INT || typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 % $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename($3) == TYPENAME_UNSIGNED_INT || typename($3) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 % $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_STRING:
												perror("You can't do the module to a string\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	| ID S_EQUAL NUM S_MOD ID		{
										switch(typename($1)){
											case TYPENAME_INT:
												if(typename($5) == TYPENAME_INT || typename($5) == TYPENAME_CONST_INT || typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 % $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename($5) == TYPENAME_UNSIGNED_INT || typename($5) == TYPENAME_CONST_UNSIGNED_INT){
													$1 = $3 % $5;
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_STRING:
												perror("You can't do the module to a string\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	| ID S_EQUAL NUM S_MOD NUM		{
										switch(typename($1)){
											case TYPENAME_INT:
											case TYPENAME_UNSIGNED_INT:
												$1 = $3 % $5;

												break;
											case TYPENAME_STRING:
												perror("You can't do the module to a string\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
											case TYPENAME_CONST_INT:
											case TYPENAME_CONST_UNSIGNED_INT:
											case TYPENAME_CONST_STRING:
												perror("You can't change the value of a constant!\n");
												exit(0);

												break;	// Unnecesary, but here it is :)
										}
									}
	;

OP_BINARY: ST_AND
	| ST_OR
	| ST_NOT
	;

ST_AND: ID S_EQUAL ID CS_AND ID			{$1 = $3 && $5;}
	| ID S_EQUAL ID CS_AND BINARY		{$1 = $3 && $5;}
	| ID S_EQUAL BINARY CS_AND ID		{$1 = $3 && $5;}
	| ID S_EQUAL BINARY CS_AND BINARY	{$1 = $3 && $5;}
	;

ST_OR: ID S_EQUAL ID CS_OR ID			{$1 = $3 || $5;}
	| ID S_EQUAL ID CS_OR BINARY		{$1 = $3 || $5;}
	| ID S_EQUAL BINARY CS_OR ID		{$1 = $3 || $5;}
	| ID S_EQUAL BINARY CS_OR BINARY	{$1 = $3 || $5;}
	;

ST_NOT: ID S_EQUAL CS_NOT ID		{$1 != $3;}
	| ID S_EQUAL CS_NOT BINARY		{$1 != $3;}
	| ID S_EQUAL CS_NOT OP_BINARY	{$1 != $3;}
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

/*
	There is an option for every possible case, in other cases there
	will be an error message
*/
void assign(int var, int val){
	var = val;
}

void assign(const char *var, char *val){
	perror("You can't change the value of a constant!\n");
	exit(0);
}

void assign(unsigned int var, unsigned int val){
	var = val;
}

void assign(const unsigned int var, const unsigned int val){
	perror("You can't change the value of a constant!\n");
	exit(0);
}

void assign(char *var, char *val){
	var = val;
}

void assign(const int var, int val){
	perror("You can't change the value of a constant!\n");
	exit(0);
}

int checkTypeInt()

int main(){
	for(int i = 0; i < MAX_NUM_VARS_FUNCS; i++){
		vars[i] = '#';
		funcs[i] = '#'
	}

	yyparse();
}