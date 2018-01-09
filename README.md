# Formal Languages Automata and Compilers UAIC

## Design of an original programming language

Design an original programming language and provide a syntactic analyzer for it, using YACC. Your
language should be statically typed and should include:

* variable declarations, constant declarations (different kind of constants), function declarations
and definitions
* user defined data types (similar to classes in object orientated languages, but with your own
syntax); provide specific syntax for working with these types
* array types
* control statements (if, for, while, etc.), assignment statements
* arithmetic and boolean expressions with complex operands
* operations with string types
* function calls which can have as parameters: expressions, other function calls, identifiers,
constants, etc.
* A predefined function called print which has a parameter of an integer type

Besides the syntactic analysis of the program, you should also provide semantic analysis as follows:

- you should check that any variable that appears in a program has been previously defined;
- a variable should not be declared more than once;
- a variable appearing in the right side of an expression should have been initialized explicitly.
- a function is not defined more than once with the same signature
- a function that is called in the program has been defined
- type checking - make sure that:
	- the left side of an assignment has the same type as the right side
	- the parameters of a function call have the types from the function definition

Error messages should be provided if these conditions do not hold.  
You must provide the evaluation of arithmetic expressions in a program; if a program in syntactically
and semantically correct, for every call of the form print(expr), the actual value of expr will be printed,
otherwise only the errors will showed.
