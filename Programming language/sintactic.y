%{
	void yerror(char *s);
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>

	extern int yylineno;

	void yyerror(char *s) {
		fprintf(stderr, "line %d: %s\n", yylineno, s);
	}

	int yylex();

	const int MAX_NUM_FUNCS = 1024;
	const int MAX_NUM_VARS = 52;
	const char *NAME_INT = "int";
	const char *NAME_STRING = "string";

	char *vars[MAX_NUM_VARS];		// 52 variables, one for each letter of the alphabet, upper and lower
	char funcs[MAX_NUM_FUNCS][1024];	// 1024 is the maximun lenght of a function signature
	char *strings[MAX_NUM_VARS];
	int nums[MAX_NUM_VARS];
	char vars_initialized[MAX_NUM_VARS];

	// For using this the compiler needs -std=C11
	// gcc -Wall -std=c11 y.tab.c -o language
	enum t_typename{
		TYPENAME_STRING,
		TYPENAME_CONST_STRING,
		TYPENAME_INT,
		TYPENAME_CONST_INT,
		TYPENAME_UNSIGNED_INT,
		TYPENAME_CONST_UNSIGNED_INT,
		TYPENAME_OTHER
	};

	#define typename(x) _Generic((x), char: TYPENAME_STRING, \
								const char: TYPENAME_CONST_STRING, \
								int: TYPENAME_INT, \
								const int: TYPENAME_CONST_INT, \
								unsigned int: TYPENAME_UNSIGNED_INT, \
								const unsigned int: TYPENAME_CONST_UNSIGNED_INT, \
								default: TYPENAME_OTHER)

	#define true (1 == 1)
	#define false (!true)

	int computeSymbolIndex(char token){
		int idx = -1;

		if(islower(token)) {
			idx = token - 'a' + 26;
		}
		else{
			if(isupper(token)){
				idx = token - 'A';
			}
		}

		return idx;
	}

	void checkVariable(char idx, int is_initialized){
		int bucket = computeSymbolIndex(idx);

		if(strcmp(vars[bucket], "\0")){	// This means this one already had a type, so it was already declared
			perror("This variable was already declared\n");
			printf("Variable affected: %c\n", idx);
			exit(0);
		}

		if(is_initialized){
			vars_initialized[bucket] = idx;
		}
	}

	void checkFunctionSignature(char *name){
		char hash = '#';

		for(int i = 0; i < MAX_NUM_FUNCS; i++){
			if(!strcmp(name, funcs[i])){	// This means they have the same name
				perror("This function was already declared\n");
			}

			if(!strcmp(&hash, funcs[i])){
				strcpy(funcs[i], name);
				break;	// We don't need more iterations
			}
		}
	}

	int variable_is_defined(char idx){
		int bucket = computeSymbolIndex(idx);

		return strcmp(vars[bucket], "\0"); // This means this one already had a type, so it was already declared
	}

	int variable_is_initialized(char idx){
		int bucket = computeSymbolIndex(idx);

		for(int i = 0; i < MAX_NUM_VARS; i++){
			if(idx == vars_initialized[bucket]){
				return true;
			}
		}

		return false;
	}

	int function_is_defined(char *name){
		for(int i = 0; i < MAX_NUM_FUNCS; i++){
			if(strcmp(name,funcs[i])){
				return true;
			}
		}

		return false;
	}

	/* returns the value of a given symbol */
	char *symbolType(char symbol){
		int bucket = computeSymbolIndex(symbol);

		return vars[bucket];
	}

	/* returns the value of a given symbol (strings) */
	char *symbolValString(char symbol){
		int bucket = computeSymbolIndex(symbol);

		return strings[bucket];
	}

	/* returns the value of a given symbol (numbers) */
	int symbolValInt(char symbol){
		int bucket = computeSymbolIndex(symbol);

		return nums[bucket];
	}

	/* updates the value of a given symbol (numbers) */
	void updateSymbolValInt(char symbol, int val){
		int bucket = computeSymbolIndex(symbol);

		nums[bucket] = val;
	}

	/* updates the value of a given symbol (strings) */
	void updateSymbolValString(char symbol, char *val){
		int bucket = computeSymbolIndex(symbol);

		strcpy(strings[bucket], val);
	}

	void declareSymbol(char idx, const char *type){
		int bucket = computeSymbolIndex(idx);

		strcpy(vars[bucket], type);
	}
%}

%union {int num; char id; char *string; int bool;}
%type <bool>CONDITION
%type <bool>ST_AND
%type <bool>ST_OR
%type <bool>ST_NOT
%type <bool>OP_BINARY
%type <string>SIGNATURE

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
%token <num>S_INTEGER
%token <id>S_CHAR
%token S_VARIABLE
%token S_PARAMETER
%token <num>S_CONSTANT_INT
%token S_CONSTANT_CHAR
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
%token <num>NUM
%token <id>ID
%token <string>FUNC_NAME
%token <bool>BINARY
%token <string>STRING

%start START

%%
START: BEGIN
	| FUNCION
	| DECLARATION_VARIABLES
	| OPERATIONS
	| PRINTING
	| USER_DEF
	| ST_IF
	| ST_WHILE
	| ST_FOR
	| STRING_OP
	| CONDITION
	| BEGIN START
	| FUNCION START
	| DECLARATION_VARIABLES START
	| OPERATIONS START
	| PRINTING START
	| USER_DEF START
	| ST_IF START
	| ST_WHILE START
	| ST_FOR START
	| STRING_OP START
	| CONDITION START
	;

BEGIN: FUNCIONES;

FUNCIONES: FUNCION_PRINCIPAL
	| FUNCION FUNCIONES
	;

FUNCION_PRINCIPAL: S_PRINCIPAL O_CURLY EXPRESIONS C_CURLY
	| S_PRINCIPAL O_BRACKETS S_ARGUMENTS C_BRACKETS O_CURLY EXPRESIONS C_CURLY
	;

FUNCION: S_DEFFUNCTION SIGNATURE O_CURLY EXPRESIONS C_CURLY		{checkFunctionSignature($2);};

SIGNATURE: FUNC_NAME O_BRACKETS C_BRACKETS
	| FUNC_NAME O_BRACKETS PARAMETERS C_BRACKETS
	;

PARAMETERS: VAR_TYPE ID
	| VAR_TYPE S_PARAMETER ID
	| VAR_TYPE ID S_COMMA PARAMETERS
	| VAR_TYPE S_PARAMETER ID S_COMMA PARAMETERS
	;

EXPRESIONS: DECLARATION_VARIABLES
	| CALL_FUNCTIONS
	| OPERATIONS
	| EXPRESIONS OPERATIONS
	| EXPRESIONS CALL_FUNCTIONS
	| EXPRESIONS DECLARATION_VARIABLES
	;

DECLARATION_VARIABLES:VARIABLE
	| VARIABLE DECLARATION_VARIABLES
	;

VARIABLE: INT ID S_EQUAL NUM SEMICOLON					{checkVariable($2, true); declareSymbol($2, NAME_INT); updateSymbolValInt($2, $4);}
	| INT ID S_EQUAL NUM S_ADD NUM SEMICOLON			{checkVariable($2, true); declareSymbol($2, NAME_INT); updateSymbolValInt($2, $4 + $6);}
	| INT ID S_EQUAL ID S_ADD NUM SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($4), NAME_INT)){
																updateSymbolValInt($2, symbolValInt($4) + $6);
															}
															else{
																printf("%c is not a number\n", $4);
																exit(0);
															}
														}
	| INT ID S_EQUAL NUM S_ADD ID SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($6), NAME_INT)){
																updateSymbolValInt($2, $4 + symbolValInt($6));
															}
															else{
																printf("%c is not a number\n", $6);
																exit(0);
															}
														}
	| INT ID S_EQUAL ID S_ADD ID SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($4), NAME_INT)){
																if(!strcmp(symbolType($4), NAME_INT)){
																	updateSymbolValInt($2, symbolValInt($4) + symbolValInt($6));
																}
																else{
																	printf("%c is not a number\n", $6);
																	exit(0);
																}
															}
															else{
																printf("%c is not a number\n", $4);
																exit(0);
															}
														}
	| INT ID S_EQUAL NUM S_SUB NUM SEMICOLON			{checkVariable($2, true); declareSymbol($2, NAME_INT); updateSymbolValInt($2, $4 - $6);}
	| INT ID S_EQUAL ID S_SUB NUM SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($4), NAME_INT)){
																updateSymbolValInt($2, symbolValInt($4) - $6);
															}
															else{
																printf("%c is not a number\n", $4);
																exit(0);
															}
														}
	| INT ID S_EQUAL NUM S_SUB ID SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($6), NAME_INT)){
																updateSymbolValInt($2, $4 - symbolValInt($6));
															}
															else{
																printf("%c is not a number\n", $6);
																exit(0);
															}
														}
	| INT ID S_EQUAL ID S_SUB ID SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($4), NAME_INT)){
																if(!strcmp(symbolType($4), NAME_INT)){
																	updateSymbolValInt($2, symbolValInt($4) - symbolValInt($6));
																}
																else{
																	printf("%c is not a number\n", $6);
																	exit(0);
																}
															}
															else{
																printf("%c is not a number\n", $4);
																exit(0);
															}
														}
	| INT ID S_EQUAL NUM S_ASTERISK NUM SEMICOLON			{checkVariable($2, true); declareSymbol($2, NAME_INT); updateSymbolValInt($2, $4 * $6);}
	| INT ID S_EQUAL ID S_ASTERISK NUM SEMICOLON			{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($4), NAME_INT)){
																updateSymbolValInt($2, symbolValInt($4) * $6);
															}
															else{
																printf("%c is not a number\n", $4);
																exit(0);
															}
														}
	| INT ID S_EQUAL NUM S_ASTERISK ID SEMICOLON			{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($6), NAME_INT)){
																updateSymbolValInt($2, $4 * symbolValInt($6));
															}
															else{
																printf("%c is not a number\n", $6);
																exit(0);
															}
														}
	| INT ID S_EQUAL ID S_ASTERISK ID SEMICOLON			{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($4), NAME_INT)){
																if(!strcmp(symbolType($4), NAME_INT)){
																	updateSymbolValInt($2, symbolValInt($4) * symbolValInt($6));
																}
																else{
																	printf("%c is not a number\n", $6);
																	exit(0);
																}
															}
															else{
																printf("%c is not a number\n", $4);
																exit(0);
															}
														}
	| INT ID S_EQUAL NUM S_DIV NUM SEMICOLON			{checkVariable($2, true); declareSymbol($2, NAME_INT); updateSymbolValInt($2, $4 / $6);}
	| INT ID S_EQUAL ID S_DIV NUM SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($4), NAME_INT)){
																updateSymbolValInt($2, symbolValInt($4) / $6);
															}
															else{
																printf("%c is not a number\n", $4);
																exit(0);
															}
														}
	| INT ID S_EQUAL NUM S_DIV ID SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($6), NAME_INT)){
																updateSymbolValInt($2, $4 / symbolValInt($6));
															}
															else{
																printf("%c is not a number\n", $6);
																exit(0);
															}
														}
	| INT ID S_EQUAL ID S_DIV ID SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($4), NAME_INT)){
																if(!strcmp(symbolType($4), NAME_INT)){
																	updateSymbolValInt($2, symbolValInt($4) / symbolValInt($6));
																}
																else{
																	printf("%c is not a number\n", $6);
																	exit(0);
																}
															}
															else{
																printf("%c is not a number\n", $4);
																exit(0);
															}
														}
	| INT ID S_EQUAL NUM S_MOD NUM SEMICOLON			{checkVariable($2, true); declareSymbol($2, NAME_INT); updateSymbolValInt($2, $4 % $6);}
	| INT ID S_EQUAL ID S_MOD NUM SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($4), NAME_INT)){
																updateSymbolValInt($2, symbolValInt($4) % $6);
															}
															else{
																printf("%c is not a number\n", $4);
																exit(0);
															}
														}
	| INT ID S_EQUAL NUM S_MOD ID SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($6), NAME_INT)){
																updateSymbolValInt($2, $4 % symbolValInt($6));
															}
															else{
																printf("%c is not a number\n", $6);
																exit(0);
															}
														}
	| INT ID S_EQUAL ID S_MOD ID SEMICOLON				{
															checkVariable($2, true);
															declareSymbol($2, NAME_INT);
															
															if(!strcmp(symbolType($4), NAME_INT)){
																if(!strcmp(symbolType($4), NAME_INT)){
																	updateSymbolValInt($2, symbolValInt($4) % symbolValInt($6));
																}
																else{
																	printf("%c is not a number\n", $6);
																	exit(0);
																}
															}
															else{
																printf("%c is not a number\n", $4);
																exit(0);
															}
														}
	| CHAR ID S_EQUAL STRING SEMICOLON					{checkVariable($2, true); declareSymbol($2, NAME_STRING); updateSymbolValString($2, $4);}
	| INT ID SEMICOLON									{checkVariable($2, false); declareSymbol($2, NAME_INT);}
	| CHAR ID SEMICOLON									{checkVariable($2, false); declareSymbol($2, NAME_STRING);}
	| INT ID S_COMMA VARIABLE SEMICOLON					{checkVariable($2, false); declareSymbol($2, NAME_INT);}
	| CHAR ID S_COMMA VARIABLE SEMICOLON				{checkVariable($2, false); declareSymbol($2, NAME_STRING);}
	| INT ID S_EQUAL NUM S_COMMA VARIABLE SEMICOLON		{checkVariable($2, true); declareSymbol($2, NAME_INT); updateSymbolValInt($2, $4);}
	| CHAR ID S_EQUAL STRING S_COMMA VARIABLE SEMICOLON	{checkVariable($2, true); declareSymbol($2, NAME_STRING); updateSymbolValString($2, $4);}
	| INT ID O_SQUAREB NUM C_SQUAREB SEMICOLON			{printf("Array detected\n");}
	| VAR_TYPE ID O_SQUAREB C_SQUAREB SEMICOLON			{printf("Array detected\n");}
	;

VAR_TYPE: INT
	| CHAR
	;

INT: S_INTEGER
	| S_CONSTANT_INT
	;

CHAR: S_CHAR
	| S_CONSTANT_CHAR
	;

S_DEFINITION: NUM
	| STRING
	| BINARY
	;

CALL_FUNCTIONS: S_VARIABLE ID S_EQUAL FUNCTION_DEFINITION
	| ID S_EQUAL FUNCTION_DEFINITION
	| FUNCTION_DEFINITION
	;

FUNCTION_DEFINITION:FUNC_NAME O_BRACKETS C_BRACKETS  			{
																	if(!function_is_defined($1)){
																		perror("The function was not declared\n");
																		exit(0);
																	}
																}
	| FUNC_NAME O_BRACKETS PARAMETERS_WDECLARATION C_BRACKETS 	{
																	if(!function_is_defined($1)){
																		perror("The function was not declared\n");
																		exit(0);
																	}
																}
	;

PARAMETERS_WDECLARATION: ID S_COMMA PARAMETERS_WDECLARATION
	| S_DEFINITION S_COMMA PARAMETERS_WDECLARATION
	| ID
	| S_DEFINITION
	;

OPERATIONS: ID S_EQUAL NUM SEMICOLON		{
												if(!variable_is_defined($1)){
													perror("The variable was not declared\n");
													exit(0);
												}

												updateSymbolValInt($1, $3);
											}
	| ID S_EQUAL ID S_INCREMENTO SEMICOLON	{
												if(!variable_is_defined($3)){
													perror("The variable was not declared\n");
													exit(0);
												}
												if(!variable_is_initialized($3)){
													perror("The variable was not initialized\n");
													exit(0);
												}

												updateSymbolValInt($1, symbolValInt($3) + 1);
											}
	| ID S_EQUAL ID S_DECREMENTO SEMICOLON	{
												if(!variable_is_defined($3)){
													perror("The variable was not declared\n");
													exit(0);
												}
												if(!variable_is_initialized($3)){
													perror("The variable was not initialized\n");
													exit(0);
												}

												updateSymbolValInt($1, symbolValInt($3) - 1);
											}
	| ID S_INCREMENTO SEMICOLON				{
												if(!variable_is_defined($1)){
													perror("The variable was not declared\n");
													exit(0);
												}

												updateSymbolValInt($1, symbolValInt($1) + 1);
											}
	| ID S_DECREMENTO SEMICOLON				{
												if(!variable_is_defined($1)){
													perror("The variable was not declared\n");
													exit(0);
												}

												updateSymbolValInt($1, symbolValInt($1) - 1);
											}
	| ST_PLUS SEMICOLON
	| ST_SUBSTRACTION SEMICOLON
	| ST_MULTIPLICATION SEMICOLON
	| ST_DIVISION SEMICOLON
	| ST_MODULE SEMICOLON
	| OP_BINARY SEMICOLON
	| STRING_OP
	;

ST_PLUS: ID S_EQUAL ID S_ADD ID		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($5)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized($3)){
											perror("The variable was not initializedkkkk\n");
											exit(0);
										}
										if(!variable_is_initialized($5)){
											perror("The variable was not initialized\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											if(!strcmp(symbolType($3), NAME_INT)){
												if(!strcmp(symbolType($5), NAME_INT)){
													updateSymbolValInt($1, symbolValInt($3) + symbolValInt($5));
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
										}
										else{
											if(!strcmp(symbolType($1), NAME_STRING)){
												if(!strcmp(symbolType($3), NAME_STRING)){
													if(!strcmp(symbolType($5), NAME_STRING)){
														updateSymbolValString($1, "\0");
														updateSymbolValString($1, strcat(symbolValString($1), symbolValString($3)));
														updateSymbolValString($1, strcat(symbolValString($1), symbolValString($5)));
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
											}
											else{
												perror("Wrong types\n");
												exit(0);
											}
										}
									}
	| ID S_EQUAL ID S_ADD NUM		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized($3)){
											perror("The variable was not initialized\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											if(!strcmp(symbolType($3), NAME_INT)){
												updateSymbolValInt($1, symbolValInt($3) + $5);
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
									}
	| ID S_EQUAL NUM S_ADD ID		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($5)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized($5)){
											perror("The variable was not initialized\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											if(!strcmp(symbolType($5), NAME_INT)){
													updateSymbolValInt($1, $3 + symbolValInt($5));
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
									}
	| ID S_EQUAL NUM S_ADD NUM		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											updateSymbolValInt($1, symbolValInt($3) + symbolValInt($5));
										}
										else{
											perror("Wrong types\n");
											exit(0);
										}
									}
	;

ST_SUBSTRACTION: ID S_EQUAL ID S_SUB ID	{
											if(!variable_is_defined($1)){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined($3)){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined($5)){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_initialized($3)){
												perror("The variable was not initialized\n");
												exit(0);
											}
											if(!variable_is_initialized($5)){
												perror("The variable was not initialized\n");
												exit(0);
											}

											if(!strcmp(symbolType($1), NAME_INT)){
												if(!strcmp(symbolType($3), NAME_INT)){
													if(!strcmp(symbolType($5), NAME_INT)){
														updateSymbolValInt($1, symbolValInt($3) - symbolValInt($5));
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
											}
											else{
												perror("Wrong types\n");
												exit(0);
											}
										}
		| ID S_EQUAL ID S_SUB NUM		{
											if(!variable_is_defined($1)){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined($3)){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_initialized($3)){
												perror("The variable was not initialized\n");
												exit(0);
											}

											if(!strcmp(symbolType($1), NAME_INT)){
												if(!strcmp(symbolType($3), NAME_INT)){
													updateSymbolValInt($1, symbolValInt($3) - $5);
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
										}
	| ID S_EQUAL NUM S_SUB ID			{
											if(!variable_is_defined($1)){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined($5)){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_initialized($5)){
												perror("The variable was not initialized\n");
												exit(0);
											}

											if(!strcmp(symbolType($1), NAME_INT)){
												if(!strcmp(symbolType($5), NAME_INT)){
													updateSymbolValInt($1, $3 - symbolValInt($5));
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
										}
	| ID S_EQUAL NUM S_SUB NUM			{
											if(!variable_is_defined($1)){
												perror("The variable was not declared\n");
												exit(0);
											}

											if(!strcmp(symbolType($1), NAME_INT)){
													updateSymbolValInt($1, $3 - $5);
											}
											else{
												perror("Wrong types\n");
												exit(0);
											}
										}
	;

ST_MULTIPLICATION: ID S_EQUAL ID S_ASTERISK ID	{
													if(!variable_is_defined($1)){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined($3)){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined($5)){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_initialized($3)){
														perror("The variable was not initialized\n");
														exit(0);
													}
													if(!variable_is_initialized($5)){
														perror("The variable was not initialized\n");
														exit(0);
													}

													if(!strcmp(symbolType($1), NAME_INT)){
														if(!strcmp(symbolType($3), NAME_INT)){
															if(!strcmp(symbolType($5), NAME_INT)){
																updateSymbolValInt($1, symbolValInt($3) * symbolValInt($5));
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
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
	| ID S_EQUAL ID S_ASTERISK NUM				{
													if(!variable_is_defined($1)){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined($3)){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_initialized($3)){
														perror("The variable was not initialized\n");
														exit(0);
													}

													if(!strcmp(symbolType($1), NAME_INT)){
														if(!strcmp(symbolType($3), NAME_INT)){
															updateSymbolValInt($1, symbolValInt($3) * $5);
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
												}
	| ID S_EQUAL NUM S_ASTERISK ID				{
													if(!variable_is_defined($1)){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined($5)){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_initialized($5)){
														perror("The variable was not initialized\n");
														exit(0);
													}

													if(!strcmp(symbolType($1), NAME_INT)){
														if(!strcmp(symbolType($5), NAME_INT)){
															updateSymbolValInt($1, $3 * symbolValInt($5));
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
												}
	| ID S_EQUAL NUM S_ASTERISK NUM				{
													if(!variable_is_defined($1)){
														perror("The variable was not declared\n");
														exit(0);
													}

													if(!strcmp(symbolType($1), NAME_INT)){
														updateSymbolValInt($1, $3 * $5);
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
	;

ST_DIVISION: ID S_EQUAL ID S_DIV ID	{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($5)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized($3)){
											perror("The variable was not initialized\n");
											exit(0);
										}
										if(!variable_is_initialized($5)){
											perror("The variable was not initialized\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											if(!strcmp(symbolType($3), NAME_INT)){
												if(!strcmp(symbolType($5), NAME_INT)){
													updateSymbolValInt($1, symbolValInt($3) / symbolValInt($5));
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
										}
										else{
											perror("Wrong types\n");
											exit(0);
										}
									}
	| ID S_EQUAL ID S_DIV NUM		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized($3)){
											perror("The variable was not initialized\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											if(!strcmp(symbolType($3), NAME_INT)){
												updateSymbolValInt($1, symbolValInt($3) / $5);
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
									}
	| ID S_EQUAL NUM S_DIV ID		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($5)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized($5)){
											perror("The variable was not initialized\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											if(!strcmp(symbolType($5), NAME_INT)){
												updateSymbolValInt($1, $3 / symbolValInt($5));
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
									}
	| ID S_EQUAL NUM S_DIV NUM		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											updateSymbolValInt($1, $3 / $5);
										}
										else{
											perror("Wrong types\n");
											exit(0);
										}
									}
	;

ST_MODULE: ID S_EQUAL ID S_MOD ID	{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($5)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized($3)){
											perror("The variable was not initialized\n");
											exit(0);
										}
										if(!variable_is_initialized($5)){
											perror("The variable was not initialized\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											if(!strcmp(symbolType($3), NAME_INT)){
												if(!strcmp(symbolType($5), NAME_INT)){
													updateSymbolValInt($1, symbolValInt($3) % symbolValInt($5));
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
										}
										else{
											perror("Wrong types\n");
											exit(0);
										}
									}
	| ID S_EQUAL ID S_MOD NUM		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized($3)){
											perror("The variable was not initialized\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											if(!strcmp(symbolType($3), NAME_INT)){
												updateSymbolValInt($1, symbolValInt($3) % $5);
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
									}
	| ID S_EQUAL NUM S_MOD ID		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined($5)){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized($5)){
											perror("The variable was not initialized\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
											if(!strcmp(symbolType($5), NAME_INT)){
												updateSymbolValInt($1, $3 % symbolValInt($5));
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
									}
	| ID S_EQUAL NUM S_MOD NUM		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!strcmp(symbolType($1), NAME_INT)){
													updateSymbolValInt($1, $3 % $5);
										}
										else{
											perror("Wrong types\n");
											exit(0);
										}
									}
	;

OP_BINARY: ST_AND
	| ST_OR
	| ST_NOT
	;

ST_AND: ID CS_AND ID		{
								if(!variable_is_defined($1)){
									perror("The variable was not declared\n");
									exit(0);
								}
								if(!variable_is_defined($3)){
									perror("The variable was not declared\n");
									exit(0);
								}
								if(!variable_is_initialized($3)){
									perror("The variable was not initialized\n");
									exit(0);
								}

								$$ = symbolValInt($1) && symbolValInt($3);
							}
	| ID CS_AND BINARY		{
								if(!variable_is_defined($1)){
									perror("The variable was not declared\n");
									exit(0);
								}

								$$ = symbolValInt($1) && $3;
							}
	| BINARY CS_AND ID		{
								if(!variable_is_defined($3)){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized($3)){
									perror("The variable was not initialized\n");
									exit(0);
								}

								$$ = $1 && symbolValInt($3);
							}
	| BINARY CS_AND BINARY	{$$ = $1 && $3;}
	;

ST_OR: ID CS_OR ID			{
								if(!variable_is_defined($1)){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_defined($3)){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized($3)){
									perror("The variable was not initialized\n");
									exit(0);
								}

								$$ = symbolValInt($1) || symbolValInt($3);
							}
	| ID CS_OR BINARY		{
								if(!variable_is_defined($1)){
									perror("The variable was not declared\n");
									exit(0);
								}

								$$ = symbolValInt($1) || $3;
							}
	| BINARY CS_OR ID		{
								if(!variable_is_defined($3)){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized($3)){
									perror("The variable was not initialized\n");
									exit(0);
								}

								$$ = $1 || symbolValInt($3);
							}
	| BINARY CS_OR BINARY	{$$ = $1 || $3;}
	;

ST_NOT: ID CS_NOT ID		{
								if(!variable_is_defined($1)){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_defined($3)){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized($3)){
									perror("The variable was not initialized\n");
									exit(0);
								}

								$$ = symbolValInt($1) != symbolValInt($3);
							}
	| ID CS_NOT BINARY		{
								if(!variable_is_defined($1)){
									perror("The variable was not declared\n");
									exit(0);
								}

								$$ = symbolValInt($1) != $3;
							}
	| ID CS_NOT OP_BINARY	{$$ = symbolValInt($1) != $3;}
	;

ST_IF: CS_IF O_BRACKETS CONDITION C_BRACKETS CS_THEN O_CURLY ST1 C_CURLY SEMICOLON CS_ELSE O_CURLY ST1 C_CURLY	{printf("if detectado\n");}
	| CS_IF O_BRACKETS CONDITION C_BRACKETS CS_THEN O_CURLY ST1 C_CURLY					{printf("if detectado\n");}
	;

ST_WHILE: CS_WHILE O_BRACKETS CONDITION C_BRACKETS O_CURLY ST1 C_CURLY SEMICOLON	{printf("While loop detected\n");}
	;

ST_FOR: CS_FOR O_BRACKETS ID S_EQUAL NUM SEMICOLON CONDITION SEMICOLON OPERATIONS C_BRACKETS O_CURLY ST1 C_CURLY SEMICOLON	{printf("for detectado\n");}
	;

ST1: ST_IF
	| ST_WHILE
	| ST_FOR
	| OPERATIONS
	| PRINTING
	;

CONDITION: ID CS_EQUAL ID			{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = symbolValInt($1) == symbolValInt($3);
									}
	| ID CS_EQUAL NUM				{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = symbolValInt($1) == $3;
									}
	| NUM CS_EQUAL ID				{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = $1 == symbolValInt($3);
									}
	| NUM CS_EQUAL NUM				{$$ = $1 == $3;}
	| ID CS_GREATER ID				{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = symbolValInt($1) > symbolValInt($3);
									}
	| ID CS_GREATER NUM				{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = symbolValInt($1) > $3;
									}
	| NUM CS_GREATER ID				{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = $1 > symbolValInt($3);
									}
	| NUM CS_GREATER NUM			{$$ = $1 > $3;}
	| ID CS_LESS ID					{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = symbolValInt($1) < symbolValInt($3);
									}
	| ID CS_LESS NUM				{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = symbolValInt($1) < $3;
									}
	| NUM CS_LESS ID				{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = $1 < symbolValInt($3);
									}
	| NUM CS_LESS NUM				{$$ = $1 < $3;}
	| ID CS_DIFFERENT ID			{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = symbolValInt($1) != symbolValInt($3);
									}
	| ID CS_DIFFERENT NUM			{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = symbolValInt($1) != $3;
									}
	| NUM CS_DIFFERENT ID			{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = $1 != symbolValInt($3);
									}
	| NUM CS_DIFFERENT NUM			{$$ = $1 != $3;}
	| CONDITION CS_AND CONDITION	{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = $1 && $3;
									}
	| CONDITION CS_OR CONDITION		{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined($3)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = $1 || $3;
									}
	| CS_NOT CONDITION				{
										if(!variable_is_defined($2)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = !$2;
									}
	| ID						{
										if(!variable_is_defined($1)){
											perror("The variable was not declared\n");
											exit(0);
										}

										$$ = symbolValInt($1);
									}
	| NUM						{$$ = $1;}
	;

PRINTING: S_PRINT STRING SEMICOLON	{printf("Printing %s\n", $2);}
	| S_PRINT NUM SEMICOLON			{printf("Printing %d\n", $2);}
	| S_PRINT ID SEMICOLON			{
										if(!strcmp(symbolType($2), NAME_INT)){
											printf("Printing %d\n", symbolValInt($2));
										}
										else{
											if(!strcmp(symbolType($2), NAME_STRING)){
												printf("Printing %s\n", symbolValString($2));
											}
											else{
												perror("Variable not declared\n");
												exit(0);
											}
										}
									}
	;

STRING_OP: ID S_EQUAL STRING SEMICOLON			{
													if(!variable_is_defined($1)){
														perror("The variable was not declared\n");
														exit(0);
													}

													if(!strcmp(symbolType($1), NAME_STRING)){
														updateSymbolValString($1, $3);
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
	| ID S_EQUAL STRING S_ADD STRING SEMICOLON	{
													if(!variable_is_defined($1)){
														perror("The variable was not declared\n");
														exit(0);
													}

													if(!strcmp(symbolType($1), NAME_STRING)){
														updateSymbolValString($1, strcat($3, $5));
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
	| ID S_EQUAL ID S_ADD STRING SEMICOLON		{
													if(!variable_is_defined($1)){
														perror("The variable was not declared\n");
														exit(0);
													}

													if(!variable_is_defined($3)){
														perror("The variable was not declared\n");
														exit(0);
													}

													if(!strcmp(symbolType($1), NAME_STRING)){
														updateSymbolValString($1, "\0");
														updateSymbolValString($1, strcat(symbolValString($1), symbolValString($3)));
														updateSymbolValString($1, strcat(symbolValString($1), $5));
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
	| ID S_EQUAL STRING S_ADD ID SEMICOLON		{
													if(!variable_is_defined($1)){
														perror("The variable was not declared\n");
														exit(0);
													}

													if(!variable_is_defined($5)){
														perror("The variable was not declared\n");
														exit(0);
													}

													if(!strcmp(symbolType($1), NAME_STRING)){
														updateSymbolValString($1, "\0");
														updateSymbolValString($1, strcat(symbolValString($1), $3));
														updateSymbolValString($1, strcat(symbolValString($1), symbolValString($5)));
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
	| CHAR ID S_EQUAL ID S_ADD ID SEMICOLON		{
													checkVariable($2, false);
													declareSymbol($2, NAME_STRING);

													if(!strcmp(symbolType($2), NAME_STRING)){
														if(!strcmp(symbolType($4), NAME_STRING)){
															if(!strcmp(symbolType($6), NAME_STRING)){
																updateSymbolValString($2, strcat(symbolValString($4), symbolValString($6)));
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
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
	;

USER_DEF: S_STRUCT ID O_CURLY DATA C_CURLY;

DATA: VARIABLE DATA
	| VARIABLE

%%

int main(int argc, char* argv[]){
	const char HASH = '#';
	const char *EMPTY = "\0";
	int i;

	for(i = 0; i < MAX_NUM_FUNCS; i++){
		strcpy(funcs[i], &HASH);
	}

	for(i = 0; i < MAX_NUM_VARS; i++){
		if((vars[i] = malloc(10)) != NULL){
			strcpy(vars[i], EMPTY);
		}
		else{
			perror("Error at malloc\n");
			exit(0);
		}

		if((strings[i] = malloc(1000)) != NULL){		// At the beginning they all have 1000 characters, this can change if needed
			strcpy(strings[i], EMPTY);
		}
		else{
			perror("Error at malloc\n");
		}

		nums[i] = 0;
	}

	printf("For files already written, use this method --> bin/language < <file with language>\n");
	printf("\n––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n\n");

	yyparse();
}