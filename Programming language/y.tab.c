/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     O_BRACKETS = 258,
     C_BRACKETS = 259,
     O_CURLY = 260,
     C_CURLY = 261,
     O_SQUAREB = 262,
     C_SQUAREB = 263,
     QUOTATION = 264,
     SQUOT = 265,
     S_EQUAL = 266,
     S_SUB = 267,
     S_DIV = 268,
     S_MOD = 269,
     SEMICOLON = 270,
     S_COMMA = 271,
     S_ADD = 272,
     S_ASTERISK = 273,
     S_INCREMENTO = 274,
     S_DECREMENTO = 275,
     OPERATION = 276,
     S_INTEGER = 277,
     S_CHAR = 278,
     S_UNSIGNED = 279,
     S_VARIABLE = 280,
     S_PARAMETER = 281,
     S_CONSTANT = 282,
     S_DEFFUNCTION = 283,
     S_PRINCIPAL = 284,
     S_ARGUMENTS = 285,
     CS_IF = 286,
     CS_THEN = 287,
     CS_ELSE = 288,
     CS_WHILE = 289,
     CS_FOR = 290,
     CS_AND = 291,
     CS_OR = 292,
     CS_EQUAL = 293,
     CS_DIFFERENT = 294,
     CS_LESS = 295,
     CS_GREATER = 296,
     CS_NOT = 297,
     S_STRUCT = 298,
     S_PRINT = 299,
     NUM = 300,
     ID = 301,
     FUNC_NAME = 302,
     BINARY = 303,
     STRING = 304
   };
#endif
/* Tokens.  */
#define O_BRACKETS 258
#define C_BRACKETS 259
#define O_CURLY 260
#define C_CURLY 261
#define O_SQUAREB 262
#define C_SQUAREB 263
#define QUOTATION 264
#define SQUOT 265
#define S_EQUAL 266
#define S_SUB 267
#define S_DIV 268
#define S_MOD 269
#define SEMICOLON 270
#define S_COMMA 271
#define S_ADD 272
#define S_ASTERISK 273
#define S_INCREMENTO 274
#define S_DECREMENTO 275
#define OPERATION 276
#define S_INTEGER 277
#define S_CHAR 278
#define S_UNSIGNED 279
#define S_VARIABLE 280
#define S_PARAMETER 281
#define S_CONSTANT 282
#define S_DEFFUNCTION 283
#define S_PRINCIPAL 284
#define S_ARGUMENTS 285
#define CS_IF 286
#define CS_THEN 287
#define CS_ELSE 288
#define CS_WHILE 289
#define CS_FOR 290
#define CS_AND 291
#define CS_OR 292
#define CS_EQUAL 293
#define CS_DIFFERENT 294
#define CS_LESS 295
#define CS_GREATER 296
#define CS_NOT 297
#define S_STRUCT 298
#define S_PRINT 299
#define NUM 300
#define ID 301
#define FUNC_NAME 302
#define BINARY 303
#define STRING 304




/* Copy the first part of user declarations.  */
#line 1 "Programming language/sintactic.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 164 "Programming language/sintactic.y"
{int num; char id; char *string; int bool;}
/* Line 193 of yacc.c.  */
#line 359 "Programming language/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 372 "Programming language/y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNRULES -- Number of states.  */
#define YYNSTATES  308

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    26,    29,    32,    35,    38,    41,    44,
      47,    50,    53,    55,    57,    60,    65,    73,    79,    83,
      88,    91,    95,   100,   106,   108,   110,   112,   115,   118,
     121,   123,   126,   132,   138,   142,   146,   152,   158,   166,
     174,   180,   185,   187,   189,   191,   194,   197,   201,   203,
     206,   208,   210,   212,   217,   221,   223,   227,   232,   236,
     240,   242,   244,   249,   255,   261,   265,   269,   272,   275,
     278,   281,   284,   287,   293,   299,   305,   311,   317,   323,
     329,   335,   341,   347,   353,   359,   365,   371,   377,   383,
     389,   395,   401,   407,   409,   411,   413,   417,   421,   425,
     429,   433,   437,   441,   445,   449,   453,   457,   468,   476,
     484,   499,   514,   530,   532,   534,   536,   538,   542,   546,
     550,   554,   558,   562,   566,   570,   574,   578,   582,   586,
     590,   594,   598,   602,   606,   610,   613,   615,   617,   621,
     625,   629,   634,   641,   648,   655,   661,   665,   668,   670
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    -1,    55,    -1,    59,    -1,    68,
      -1,    83,    -1,    85,    -1,    78,    -1,    79,    -1,    80,
      -1,    84,    -1,    52,    51,    -1,    55,    51,    -1,    59,
      51,    -1,    68,    51,    -1,    83,    51,    -1,    85,    51,
      -1,    78,    51,    -1,    79,    51,    -1,    80,    51,    -1,
      84,    51,    -1,    53,    -1,    54,    -1,    55,    53,    -1,
      29,     5,    58,     6,    -1,    29,     3,    30,     4,     5,
      58,     6,    -1,    28,    56,     5,    58,     6,    -1,    47,
       3,     4,    -1,    47,     3,    57,     4,    -1,    61,    46,
      -1,    61,    26,    46,    -1,    61,    46,    16,    57,    -1,
      61,    26,    46,    16,    57,    -1,    59,    -1,    65,    -1,
      68,    -1,    58,    68,    -1,    58,    65,    -1,    58,    59,
      -1,    60,    -1,    60,    59,    -1,    62,    46,    11,    45,
      15,    -1,    63,    46,    11,    49,    15,    -1,    62,    46,
      15,    -1,    63,    46,    15,    -1,    62,    46,    16,    60,
      15,    -1,    63,    46,    16,    60,    15,    -1,    62,    46,
      11,    45,    16,    60,    15,    -1,    63,    46,    11,    49,
      16,    60,    15,    -1,    61,    46,     7,    45,     8,    -1,
      61,    46,     7,     8,    -1,    62,    -1,    63,    -1,    22,
      -1,    27,    22,    -1,    24,    22,    -1,    27,    24,    22,
      -1,    23,    -1,    27,    23,    -1,    45,    -1,    49,    -1,
      48,    -1,    25,    46,    11,    66,    -1,    46,    11,    66,
      -1,    66,    -1,    47,     3,     4,    -1,    47,     3,    67,
       4,    -1,    46,    16,    67,    -1,    64,    16,    67,    -1,
      46,    -1,    64,    -1,    46,    11,    45,    15,    -1,    46,
      11,    46,    19,    15,    -1,    46,    11,    46,    20,    15,
      -1,    46,    19,    15,    -1,    46,    20,    15,    -1,    69,
      15,    -1,    70,    15,    -1,    71,    15,    -1,    72,    15,
      -1,    73,    15,    -1,    74,    15,    -1,    46,    11,    46,
      17,    46,    -1,    46,    11,    46,    17,    45,    -1,    46,
      11,    45,    17,    46,    -1,    46,    11,    45,    17,    45,
      -1,    46,    11,    46,    12,    46,    -1,    46,    11,    46,
      12,    45,    -1,    46,    11,    45,    12,    46,    -1,    46,
      11,    45,    12,    45,    -1,    46,    11,    46,    18,    46,
      -1,    46,    11,    46,    18,    45,    -1,    46,    11,    45,
      18,    46,    -1,    46,    11,    45,    18,    45,    -1,    46,
      11,    46,    13,    46,    -1,    46,    11,    46,    13,    45,
      -1,    46,    11,    45,    13,    46,    -1,    46,    11,    45,
      13,    45,    -1,    46,    11,    46,    14,    46,    -1,    46,
      11,    46,    14,    45,    -1,    46,    11,    45,    14,    46,
      -1,    46,    11,    45,    14,    45,    -1,    75,    -1,    76,
      -1,    77,    -1,    46,    36,    46,    -1,    46,    36,    48,
      -1,    48,    36,    46,    -1,    48,    36,    48,    -1,    46,
      37,    46,    -1,    46,    37,    48,    -1,    48,    37,    46,
      -1,    48,    37,    48,    -1,    46,    42,    46,    -1,    46,
      42,    48,    -1,    46,    42,    74,    -1,    31,     3,    82,
       4,    32,    81,    15,    33,    81,    15,    -1,    31,     3,
      82,     4,    32,    81,    15,    -1,    34,     3,    82,     4,
       5,    81,     6,    -1,    35,     3,    46,    11,    45,    15,
      82,    15,    46,    19,     4,     5,    81,     6,    -1,    35,
       3,    46,    11,    45,    15,    82,    15,    46,    20,     4,
       5,    81,     6,    -1,    35,     3,    46,    11,    45,    15,
      82,    15,    46,    21,    87,     4,     5,    81,     6,    -1,
      78,    -1,    79,    -1,    80,    -1,    68,    -1,    46,    38,
      46,    -1,    46,    38,    45,    -1,    45,    38,    46,    -1,
      45,    38,    45,    -1,    46,    41,    46,    -1,    46,    41,
      45,    -1,    45,    41,    46,    -1,    45,    41,    45,    -1,
      46,    40,    46,    -1,    46,    40,    45,    -1,    45,    40,
      46,    -1,    45,    40,    45,    -1,    46,    39,    46,    -1,
      46,    39,    45,    -1,    45,    39,    46,    -1,    45,    39,
      45,    -1,    82,    36,    82,    -1,    82,    37,    82,    -1,
      42,    82,    -1,    46,    -1,    45,    -1,    44,    49,    15,
      -1,    44,    45,    15,    -1,    44,    46,    15,    -1,    46,
      11,    49,    15,    -1,    46,    11,    49,    17,    49,    15,
      -1,    46,    11,    46,    17,    49,    15,    -1,    46,    11,
      49,    17,    46,    15,    -1,    43,    46,     5,    86,     6,
      -1,    60,    15,    86,    -1,    60,    15,    -1,    46,    -1,
      45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   222,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   244,   246,   247,   250,   251,   254,   256,   257,
     260,   261,   262,   263,   266,   267,   268,   269,   270,   271,
     274,   275,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   290,   291,   294,   295,   296,   297,   300,   301,
     304,   305,   306,   309,   310,   311,   314,   320,   328,   329,
     330,   331,   334,   364,   377,   390,   399,   408,   409,   410,
     411,   412,   413,   416,   523,   586,   649,   684,   773,   836,
     899,   935,  1024,  1087,  1150,  1186,  1275,  1338,  1401,  1437,
    1526,  1590,  1653,  1689,  1690,  1691,  1694,  1710,  1718,  1731,
    1734,  1752,  1760,  1773,  1776,  1794,  1802,  1805,  1806,  1809,
    1811,  1812,  1813,  1816,  1817,  1818,  1819,  1822,  1835,  1848,
    1861,  1874,  1887,  1900,  1913,  1926,  1939,  1952,  1965,  1978,
    1991,  2004,  2017,  2030,  2043,  2056,  2064,  2072,  2083,  2084,
    2085,  2101,  2130,  2160,  2201,  2244,  2246,  2247,  2250,  2251
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "O_BRACKETS", "C_BRACKETS", "O_CURLY",
  "C_CURLY", "O_SQUAREB", "C_SQUAREB", "QUOTATION", "SQUOT", "S_EQUAL",
  "S_SUB", "S_DIV", "S_MOD", "SEMICOLON", "S_COMMA", "S_ADD", "S_ASTERISK",
  "S_INCREMENTO", "S_DECREMENTO", "OPERATION", "S_INTEGER", "S_CHAR",
  "S_UNSIGNED", "S_VARIABLE", "S_PARAMETER", "S_CONSTANT", "S_DEFFUNCTION",
  "S_PRINCIPAL", "S_ARGUMENTS", "CS_IF", "CS_THEN", "CS_ELSE", "CS_WHILE",
  "CS_FOR", "CS_AND", "CS_OR", "CS_EQUAL", "CS_DIFFERENT", "CS_LESS",
  "CS_GREATER", "CS_NOT", "S_STRUCT", "S_PRINT", "NUM", "ID", "FUNC_NAME",
  "BINARY", "STRING", "$accept", "START", "BEGIN", "FUNCIONES",
  "FUNCION_PRINCIPAL", "FUNCION", "SIGNATURE", "PARAMETERS", "EXPRESIONS",
  "DECLARATION_VARIABLES", "VARIABLE", "VAR_TYPE", "INT", "CHAR",
  "S_DEFINITION", "CALL_FUNCTIONS", "FUNCTION_DEFINITION",
  "PARAMETERS_WDECLARATION", "OPERATIONS", "ST_PLUS", "ST_SUBSTRACTION",
  "ST_MULTIPLICATION", "ST_DIVISION", "ST_MODULE", "OP_BINARY", "ST_AND",
  "ST_OR", "ST_NOT", "ST_IF", "ST_WHILE", "ST_FOR", "ST1", "CONDITION",
  "PRINTING", "STRING_OP", "USER_DEF", "DATA", "ID_NUM", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    53,    53,    54,    54,    55,    56,    56,
      57,    57,    57,    57,    58,    58,    58,    58,    58,    58,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    62,    62,    63,    63,
      64,    64,    64,    65,    65,    65,    66,    66,    67,    67,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      70,    71,    71,    71,    71,    72,    72,    72,    72,    73,
      73,    73,    73,    74,    74,    74,    75,    75,    75,    75,
      76,    76,    76,    76,    77,    77,    77,    78,    78,    79,
      80,    80,    80,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    83,    83,
      83,    84,    84,    84,    84,    85,    86,    86,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     2,     4,     7,     5,     3,     4,
       2,     3,     4,     5,     1,     1,     1,     2,     2,     2,
       1,     2,     5,     5,     3,     3,     5,     5,     7,     7,
       5,     4,     1,     1,     1,     2,     2,     3,     1,     2,
       1,     1,     1,     4,     3,     1,     3,     4,     3,     3,
       1,     1,     4,     5,     5,     3,     3,     2,     2,     2,
       2,     2,     2,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,    10,     7,     7,
      14,    14,    15,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     3,     3,
       3,     4,     6,     6,     6,     5,     3,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    54,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,    22,    23,     3,     4,
      40,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     8,     9,    10,     6,    11,     7,
      56,    55,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,    12,    13,    22,    14,    41,     0,
       0,     0,    15,    77,    78,    79,    80,    81,    82,    18,
      19,    20,    16,    21,    17,    57,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    65,    36,     0,   147,   146,
       0,     0,     0,     0,   149,   150,   148,     0,     0,     0,
      75,    76,   106,   107,   110,   111,   114,   115,   116,   108,
     109,   112,   113,     0,     0,    44,     0,     0,    45,     0,
      28,     0,     0,    52,    53,     0,     0,     0,     0,     0,
      25,    39,    38,    37,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   151,     0,    51,     0,     0,     0,     0,
       0,    29,     0,    30,    27,     0,     0,     0,    64,    66,
      60,    70,    62,    61,    71,     0,   130,   129,   142,   141,
     138,   137,   134,   133,   128,   127,   140,   139,   136,   135,
     132,   131,     0,   143,   144,     0,     0,   157,   155,    90,
      89,    98,    97,   102,   101,    86,    85,    94,    93,    88,
      87,    96,    95,   100,    99,    84,    83,     0,    92,    91,
      73,    74,     0,     0,    50,    42,     0,    46,    43,     0,
      47,    31,     0,     0,    63,     0,     0,     0,    67,     0,
     126,   123,   124,   125,     0,     0,     0,   156,   153,   154,
     152,     0,     0,     0,    32,    26,    68,    69,     0,   118,
     119,     0,    48,    49,    33,     0,     0,     0,     0,   117,
       0,     0,     0,     0,     0,   159,   158,     0,     0,     0,
       0,     0,     0,     0,   120,   121,     0,   122
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    45,   131,    92,    19,
      20,    21,    22,    23,   194,    94,    95,   195,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,   264,   100,    37,    38,    39,   159,   297
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -235
static const yytype_int16 yypact[] =
{
     181,  -235,  -235,    -7,    26,   -26,    79,    69,   116,   122,
      88,   118,   109,     1,   140,   181,  -235,  -235,   181,   181,
     125,   115,   153,   173,   181,   196,   208,   228,   293,   308,
     309,  -235,  -235,  -235,   181,   181,   181,   181,   181,   181,
    -235,  -235,  -235,   246,   276,   320,   297,   217,   144,   144,
     280,   323,   314,   315,   316,   168,   317,   318,   -17,    50,
     127,   180,   209,  -235,  -235,  -235,  -235,  -235,  -235,   327,
      90,   128,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,    56,   217,   331,   290,
     158,   334,    19,  -235,  -235,  -235,  -235,   144,   244,   248,
      16,    18,   328,   125,  -235,  -235,  -235,   263,    57,   243,
    -235,  -235,  -235,  -235,  -235,  -235,   100,     1,  -235,  -235,
    -235,  -235,  -235,     2,   295,  -235,   125,   289,  -235,   125,
    -235,   337,   -14,  -235,  -235,   108,   338,   333,   151,    13,
    -235,  -235,  -235,  -235,    27,    67,   134,   142,   191,   202,
     216,   221,   245,   310,   144,   144,   340,   301,   332,   342,
     247,   249,   251,  -235,   253,   255,   257,   259,   261,   200,
     264,   335,   336,  -235,   -23,  -235,   341,   296,   339,   298,
     343,  -235,   306,   344,  -235,   217,   312,    73,  -235,  -235,
    -235,   345,  -235,  -235,   346,   349,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,   187,    27,    27,   187,   348,   125,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,   350,  -235,  -235,
    -235,  -235,   351,   352,  -235,  -235,   125,  -235,  -235,   125,
    -235,   353,   125,   135,  -235,   270,    78,    78,  -235,   165,
    -235,  -235,  -235,  -235,   355,   358,   144,  -235,  -235,  -235,
    -235,   356,   357,   125,  -235,  -235,  -235,  -235,   272,   322,
    -235,    -1,  -235,  -235,  -235,   187,   311,   359,   211,  -235,
     364,   369,   274,   370,   371,  -235,  -235,   373,   187,   187,
     374,   372,   375,   187,  -235,  -235,   376,  -235
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,   235,  -235,   362,  -235,  -235,  -235,  -234,   -85,   -19,
     -96,   -82,   -81,   -80,  -235,   -79,  -129,    65,   -47,  -235,
    -235,  -235,  -235,  -235,   324,  -235,  -235,  -235,  -204,  -196,
    -188,  -181,   -46,  -235,  -235,  -235,   139,  -235
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      96,    68,   135,   101,   132,   133,   134,   158,   261,   188,
     175,   261,   182,   142,   286,    40,   262,   189,   274,   262,
     153,    44,   156,   242,   263,   140,   243,   263,    93,   112,
     178,   113,   183,   180,   265,   154,   155,    61,    62,   284,
      96,     1,     2,     3,    89,   143,     4,   176,    41,    42,
      43,   144,   154,   155,   154,   155,   142,   254,   190,   191,
     130,   192,   193,   154,   155,    90,    91,    13,    93,   166,
     167,   168,    48,   141,   169,   170,   171,   172,     1,     2,
       3,   261,    46,     4,    47,   166,   167,   168,   143,   262,
     255,   170,   171,   172,   261,   261,   114,   263,   115,   261,
     253,   124,   262,   262,   287,   125,   126,   262,   213,   214,
     263,   263,   196,   197,   184,   263,   141,   301,   302,    49,
      55,   158,   306,   190,   191,    50,   192,   193,    56,    57,
       1,     2,     3,    89,    51,     4,    58,    59,    96,   127,
      63,   275,    60,   128,   129,    58,    59,     1,     2,     3,
     271,    60,     4,   272,    90,    91,    13,     1,     2,     3,
      89,    69,     4,    52,    53,   260,    93,    54,   260,   138,
     132,   133,   134,   116,   142,   117,   278,    56,    57,   198,
     199,    90,    91,    13,    56,    57,    97,   200,   201,    98,
      99,   132,   133,   134,    58,    59,   107,   187,    91,    70,
      60,    58,    59,     1,     2,     3,   143,    60,     4,     5,
       6,    73,     7,   107,   108,     8,     9,   109,     7,    71,
     281,     8,     9,    74,    10,    11,   119,    12,   120,    13,
     290,   291,   292,   259,   141,    13,   202,   203,   260,     1,
       2,     3,    89,    75,     4,   235,   236,   204,   205,   237,
      64,   260,   260,    65,    67,   121,   260,   122,   173,    72,
     174,   206,   207,    90,    91,    13,   208,   209,    85,    79,
      80,    81,    82,    83,    84,   160,   161,   162,   163,    86,
     164,   165,   145,   146,   147,   148,   149,   150,   151,   152,
     210,   211,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    76,   238,
     239,   245,   246,   248,   249,   235,   236,   107,   187,   295,
     296,   276,   277,    77,    78,    87,   102,    88,   103,   104,
     105,   106,   110,   111,   123,   136,   137,   139,   179,   157,
     177,   181,   212,   185,   186,   215,   216,   217,   218,   244,
     240,   241,   251,   258,   247,   285,   267,   288,   250,    91,
     252,   256,   257,   266,   280,   268,   269,   270,   293,   273,
     279,   282,   283,   294,   289,   298,   299,   300,   304,   303,
      66,   305,   307,     0,   118
};

static const yytype_int16 yycheck[] =
{
      47,    20,    87,    49,    86,    86,    86,   103,   212,   138,
       8,   215,    26,    92,    15,    22,   212,     4,   252,   215,
       4,    47,     4,    46,   212,     6,    49,   215,    47,    46,
     126,    48,    46,   129,   215,    36,    37,    36,    37,   273,
      87,    22,    23,    24,    25,    92,    27,    45,    22,    23,
      24,    97,    36,    37,    36,    37,   135,   186,    45,    46,
       4,    48,    49,    36,    37,    46,    47,    48,    87,    12,
      13,    14,     3,    92,    17,    18,    19,    20,    22,    23,
      24,   285,     3,    27,     5,    12,    13,    14,   135,   285,
      17,    18,    19,    20,   298,   299,    46,   285,    48,   303,
     185,    11,   298,   299,   285,    15,    16,   303,   154,   155,
     298,   299,    45,    46,     6,   303,   135,   298,   299,     3,
      11,   217,   303,    45,    46,     3,    48,    49,    19,    20,
      22,    23,    24,    25,    46,    27,    36,    37,   185,    11,
       0,     6,    42,    15,    16,    36,    37,    22,    23,    24,
     246,    42,    27,   249,    46,    47,    48,    22,    23,    24,
      25,    46,    27,    45,    46,   212,   185,    49,   215,    11,
     252,   252,   252,    46,   253,    48,    11,    19,    20,    45,
      46,    46,    47,    48,    19,    20,    42,    45,    46,    45,
      46,   273,   273,   273,    36,    37,    45,    46,    47,    46,
      42,    36,    37,    22,    23,    24,   253,    42,    27,    28,
      29,    15,    31,    45,    46,    34,    35,    49,    31,    46,
     266,    34,    35,    15,    43,    44,    46,    46,    48,    48,
      19,    20,    21,    46,   253,    48,    45,    46,   285,    22,
      23,    24,    25,    15,    27,    45,    46,    45,    46,    49,
      15,   298,   299,    18,    19,    46,   303,    48,    15,    24,
      17,    45,    46,    46,    47,    48,    45,    46,    22,    34,
      35,    36,    37,    38,    39,    12,    13,    14,    15,     3,
      17,    18,    38,    39,    40,    41,    38,    39,    40,    41,
      45,    46,    45,    46,    45,    46,    45,    46,    45,    46,
      45,    46,    45,    46,    45,    46,    45,    46,    15,    45,
      46,    15,    16,    15,    16,    45,    46,    45,    46,    45,
      46,   256,   257,    15,    15,     5,    46,    30,     5,    15,
      15,    15,    15,    15,     7,     4,    46,     3,    49,    11,
      45,     4,    32,     5,    11,     5,    45,    15,     6,     8,
      15,    15,    46,     4,    15,    33,   217,    46,    15,    47,
      16,    16,    16,    15,     6,    15,    15,    15,     4,    16,
      15,    15,    15,     4,    15,     5,     5,     4,     6,     5,
      18,     6,     6,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    23,    24,    27,    28,    29,    31,    34,    35,
      43,    44,    46,    48,    51,    52,    53,    54,    55,    59,
      60,    61,    62,    63,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    83,    84,    85,
      22,    22,    23,    24,    47,    56,     3,     5,     3,     3,
       3,    46,    45,    46,    49,    11,    19,    20,    36,    37,
      42,    36,    37,     0,    51,    51,    53,    51,    59,    46,
      46,    46,    51,    15,    15,    15,    15,    15,    15,    51,
      51,    51,    51,    51,    51,    22,     3,     5,    30,    25,
      46,    47,    58,    59,    65,    66,    68,    42,    45,    46,
      82,    82,    46,     5,    15,    15,    15,    45,    46,    49,
      15,    15,    46,    48,    46,    48,    46,    48,    74,    46,
      48,    46,    48,     7,    11,    15,    16,    11,    15,    16,
       4,    57,    61,    62,    63,    58,     4,    46,    11,     3,
       6,    59,    65,    68,    82,    38,    39,    40,    41,    38,
      39,    40,    41,     4,    36,    37,     4,    11,    60,    86,
      12,    13,    14,    15,    17,    18,    12,    13,    14,    17,
      18,    19,    20,    15,    17,     8,    45,    45,    60,    49,
      60,     4,    26,    46,     6,     5,    11,    46,    66,     4,
      45,    46,    48,    49,    64,    67,    45,    46,    45,    46,
      45,    46,    45,    46,    45,    46,    45,    46,    45,    46,
      45,    46,    32,    82,    82,     5,    45,    15,     6,    45,
      46,    45,    46,    45,    46,    45,    46,    45,    46,    45,
      46,    45,    46,    45,    46,    45,    46,    49,    45,    46,
      15,    15,    46,    49,     8,    15,    16,    15,    15,    16,
      15,    46,    16,    58,    66,    17,    16,    16,     4,    46,
      68,    78,    79,    80,    81,    81,    15,    86,    15,    15,
      15,    60,    60,    16,    57,     6,    67,    67,    11,    15,
       6,    82,    15,    15,    57,    33,    15,    81,    46,    15,
      19,    20,    21,     4,     4,    45,    46,    87,     5,     5,
       4,    81,    81,     5,     6,     6,    81,     6
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 27:
#line 254 "Programming language/sintactic.y"
    {checkFunctionSignature((yyvsp[(2) - (5)].string));}
    break;

  case 42:
#line 278 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (5)].id), true); declareSymbol((yyvsp[(2) - (5)].id), NAME_INT); updateSymbolValInt((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].num));}
    break;

  case 43:
#line 279 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (5)].id), true); declareSymbol((yyvsp[(2) - (5)].id), NAME_STRING); updateSymbolValString((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].string));}
    break;

  case 44:
#line 280 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (3)].id), false); declareSymbol((yyvsp[(2) - (3)].id), NAME_INT);}
    break;

  case 45:
#line 281 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (3)].id), false); declareSymbol((yyvsp[(2) - (3)].id), NAME_STRING);}
    break;

  case 46:
#line 282 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (5)].id), false); declareSymbol((yyvsp[(2) - (5)].id), NAME_INT);}
    break;

  case 47:
#line 283 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (5)].id), false); declareSymbol((yyvsp[(2) - (5)].id), NAME_STRING);}
    break;

  case 48:
#line 284 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (7)].id), true); declareSymbol((yyvsp[(2) - (7)].id), NAME_INT); updateSymbolValInt((yyvsp[(2) - (7)].id), (yyvsp[(4) - (7)].num));}
    break;

  case 49:
#line 285 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (7)].id), true); declareSymbol((yyvsp[(2) - (7)].id), NAME_STRING); updateSymbolValString((yyvsp[(2) - (7)].id), (yyvsp[(4) - (7)].string));}
    break;

  case 50:
#line 286 "Programming language/sintactic.y"
    {/* checkVariable($2, true); */}
    break;

  case 51:
#line 287 "Programming language/sintactic.y"
    {/* checkVariable($2, true); */}
    break;

  case 66:
#line 314 "Programming language/sintactic.y"
    {
																	if(!function_is_defined((yyvsp[(1) - (3)].string))){
																		perror("The function was not declared\n");
																		exit(0);
																	}
																}
    break;

  case 67:
#line 320 "Programming language/sintactic.y"
    {
																	if(!function_is_defined((yyvsp[(1) - (4)].string))){
																		perror("The function was not declared\n");
																		exit(0);
																	}
																}
    break;

  case 72:
#line 334 "Programming language/sintactic.y"
    {
													/* switch(typename($1)){
														case TYPENAME_INT:
															$1 = $3;

															break;
														case TYPENAME_UNSIGNED_INT:
															if($3 > 0){
																$1 = $3;
															}
															else{
																perror("You are trying to assign a negative number to an unsigned integer\n");
																exit(0);
															}

															break;
														case TYPENAME_CONST_INT:
														case TYPENAME_CONST_UNSIGNED_INT:
															perror("You can't change the value of a constant!\n");
															exit(0);

															break;
													} */
													if(!variable_is_defined((yyvsp[(1) - (4)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}
													
													updateSymbolValInt((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].num));
												}
    break;

  case 73:
#line 364 "Programming language/sintactic.y"
    {
												if(!variable_is_defined((yyvsp[(3) - (5)].id))){
													perror("The variable was not declared\n");
													exit(0);
												}
												if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
													perror("The variable was not initialized\n");
													exit(0);
												}

												// $1 = $3 + 1;
												updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) + 1);
											}
    break;

  case 74:
#line 377 "Programming language/sintactic.y"
    {
												if(!variable_is_defined((yyvsp[(3) - (5)].id))){
													perror("The variable was not declared\n");
													exit(0);
												}
												if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
													perror("The variable was not initialized\n");
													exit(0);
												}

												// $1 = $3 - 1;
												updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) - 1);
											}
    break;

  case 75:
#line 390 "Programming language/sintactic.y"
    {
												if(!variable_is_defined((yyvsp[(1) - (3)].id))){
													perror("The variable was not declared\n");
													exit(0);
												}

												// $1 = $1 + 1;
												updateSymbolValInt((yyvsp[(1) - (3)].id), symbolValInt((yyvsp[(1) - (3)].id)) + 1);
											}
    break;

  case 76:
#line 399 "Programming language/sintactic.y"
    {
												if(!variable_is_defined((yyvsp[(1) - (3)].id))){
													perror("The variable was not declared\n");
													exit(0);
												}

												// $1 = $1 - 1;
												updateSymbolValInt((yyvsp[(1) - (3)].id), symbolValInt((yyvsp[(1) - (3)].id)) - 1);
											}
    break;

  case 83:
#line 416 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											if(!strcmp(symbolType((yyvsp[(3) - (5)].id)), NAME_INT)){
												if(!strcmp(symbolType((yyvsp[(5) - (5)].id)), NAME_INT)){
													updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) + symbolValInt((yyvsp[(5) - (5)].id)));
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
											if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_STRING)){
												updateSymbolValString((yyvsp[(1) - (5)].id), strcat(symbolValString((yyvsp[(3) - (5)].id)), symbolValString((yyvsp[(5) - (5)].id))));
											}
											else{
												perror("Wrong types\n");
												exit(0);
											}
										}

									}
    break;

  case 84:
#line 523 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											if(!strcmp(symbolType((yyvsp[(3) - (5)].id)), NAME_INT)){
												updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) + (yyvsp[(5) - (5)].num));
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
    break;

  case 85:
#line 586 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											if(!strcmp(symbolType((yyvsp[(5) - (5)].id)), NAME_INT)){
													updateSymbolValInt((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].num) + symbolValInt((yyvsp[(5) - (5)].id)));
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
    break;

  case 86:
#line 649 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].num)) + symbolValInt((yyvsp[(5) - (5)].num)));
										}
										else{
											perror("Wrong types\n");
											exit(0);
										}
									}
    break;

  case 87:
#line 684 "Programming language/sintactic.y"
    {
											if(!variable_is_defined((yyvsp[(1) - (5)].id))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined((yyvsp[(3) - (5)].id))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined((yyvsp[(5) - (5)].id))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
												perror("The variable was not initialized\n");
												exit(0);
											}
											if(!variable_is_initialized((yyvsp[(5) - (5)].id))){
												perror("The variable was not initialized\n");
												exit(0);
											}

											/* switch(typename($1)){
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
											} */

											if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
												if(!strcmp(symbolType((yyvsp[(3) - (5)].id)), NAME_INT)){
													if(!strcmp(symbolType((yyvsp[(5) - (5)].id)), NAME_INT)){
														updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) - symbolValInt((yyvsp[(5) - (5)].id)));
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
    break;

  case 88:
#line 773 "Programming language/sintactic.y"
    {
											if(!variable_is_defined((yyvsp[(1) - (5)].id))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined((yyvsp[(3) - (5)].id))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
												perror("The variable was not initialized\n");
												exit(0);
											}

											/* switch(typename($1)){
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
											} */

											if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
												if(!strcmp(symbolType((yyvsp[(3) - (5)].id)), NAME_INT)){
													updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) - (yyvsp[(5) - (5)].num));
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
    break;

  case 89:
#line 836 "Programming language/sintactic.y"
    {
											if(!variable_is_defined((yyvsp[(1) - (5)].id))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined((yyvsp[(5) - (5)].id))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_initialized((yyvsp[(5) - (5)].id))){
												perror("The variable was not initialized\n");
												exit(0);
											}

											/* switch(typename($1)){
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
											} */

											if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
												if(!strcmp(symbolType((yyvsp[(5) - (5)].id)), NAME_INT)){
													updateSymbolValInt((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].num) - symbolValInt((yyvsp[(5) - (5)].id)));
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
    break;

  case 90:
#line 899 "Programming language/sintactic.y"
    {
											if(!variable_is_defined((yyvsp[(1) - (5)].id))){
												perror("The variable was not declared\n");
												exit(0);
											}

											/* switch(typename($1)){
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
											} */

											if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
													updateSymbolValInt((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].num) - (yyvsp[(5) - (5)].num));
											}
											else{
												perror("Wrong types\n");
												exit(0);
											}
										}
    break;

  case 91:
#line 935 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (5)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined((yyvsp[(3) - (5)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined((yyvsp[(5) - (5)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
														perror("The variable was not initialized\n");
														exit(0);
													}
													if(!variable_is_initialized((yyvsp[(5) - (5)].id))){
														perror("The variable was not initialized\n");
														exit(0);
													}

													/* switch(typename($1)){
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
													} */

													if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
														if(!strcmp(symbolType((yyvsp[(3) - (5)].id)), NAME_INT)){
															if(!strcmp(symbolType((yyvsp[(5) - (5)].id)), NAME_INT)){
																updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) * symbolValInt((yyvsp[(5) - (5)].id)));
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
    break;

  case 92:
#line 1024 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (5)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined((yyvsp[(3) - (5)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
														perror("The variable was not initialized\n");
														exit(0);
													}

													/* switch(typename($1)){
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
													} */

													if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
														if(!strcmp(symbolType((yyvsp[(3) - (5)].id)), NAME_INT)){
															updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) * (yyvsp[(5) - (5)].num));
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
    break;

  case 93:
#line 1087 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (5)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined((yyvsp[(5) - (5)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_initialized((yyvsp[(5) - (5)].id))){
														perror("The variable was not initialized\n");
														exit(0);
													}

													/* switch(typename($1)){
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
													} */

													if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
														if(!strcmp(symbolType((yyvsp[(5) - (5)].id)), NAME_INT)){
															updateSymbolValInt((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].num) * symbolValInt((yyvsp[(5) - (5)].id)));
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
    break;

  case 94:
#line 1150 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (5)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}

													/* switch(typename($1)){
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
													} */

													if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
														updateSymbolValInt((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].num) * (yyvsp[(5) - (5)].num));
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
    break;

  case 95:
#line 1186 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											if(!strcmp(symbolType((yyvsp[(3) - (5)].id)), NAME_INT)){
												if(!strcmp(symbolType((yyvsp[(5) - (5)].id)), NAME_INT)){
													updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) / symbolValInt((yyvsp[(5) - (5)].id)));
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
    break;

  case 96:
#line 1275 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											if(!strcmp(symbolType((yyvsp[(3) - (5)].id)), NAME_INT)){
												updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) / (yyvsp[(5) - (5)].num));
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
    break;

  case 97:
#line 1338 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											if(!strcmp(symbolType((yyvsp[(5) - (5)].id)), NAME_INT)){
												updateSymbolValInt((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].num) / symbolValInt((yyvsp[(5) - (5)].id)));
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
    break;

  case 98:
#line 1401 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											updateSymbolValInt((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].num) / (yyvsp[(5) - (5)].num));
										}
										else{
											perror("Wrong types\n");
											exit(0);
										}
									}
    break;

  case 99:
#line 1437 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											if(!strcmp(symbolType((yyvsp[(3) - (5)].id)), NAME_INT)){
												if(!strcmp(symbolType((yyvsp[(5) - (5)].id)), NAME_INT)){
													updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) % symbolValInt((yyvsp[(5) - (5)].id)));
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
    break;

  case 100:
#line 1526 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}


										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											if(!strcmp(symbolType((yyvsp[(3) - (5)].id)), NAME_INT)){
												updateSymbolValInt((yyvsp[(1) - (5)].id), symbolValInt((yyvsp[(3) - (5)].id)) % (yyvsp[(5) - (5)].num));
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
    break;

  case 101:
#line 1590 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)].id))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
											if(!strcmp(symbolType((yyvsp[(5) - (5)].id)), NAME_INT)){
												updateSymbolValInt((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].num) % symbolValInt((yyvsp[(5) - (5)].id)));
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
    break;

  case 102:
#line 1653 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										/* switch(typename($1)){
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
										} */

										if(!strcmp(symbolType((yyvsp[(1) - (5)].id)), NAME_INT)){
													updateSymbolValInt((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].num) % (yyvsp[(5) - (5)].num));
										}
										else{
											perror("Wrong types\n");
											exit(0);
										}
									}
    break;

  case 106:
#line 1694 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}
								if(!variable_is_defined((yyvsp[(3) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}
								if(!variable_is_initialized((yyvsp[(3) - (3)].id))){
									perror("The variable was not initialized\n");
									exit(0);
								}

								return symbolValInt((yyvsp[(1) - (3)].id)) && symbolValInt((yyvsp[(3) - (3)].id));
							}
    break;

  case 107:
#line 1710 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}

								return symbolValInt((yyvsp[(1) - (3)].id)) && (yyvsp[(3) - (3)].bool);
							}
    break;

  case 108:
#line 1718 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(3) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized((yyvsp[(3) - (3)].id))){
									perror("The variable was not initialized\n");
									exit(0);
								}

								return (yyvsp[(1) - (3)].bool) && symbolValInt((yyvsp[(3) - (3)].id));
							}
    break;

  case 109:
#line 1731 "Programming language/sintactic.y"
    {return (yyvsp[(1) - (3)].bool) && (yyvsp[(3) - (3)].bool);}
    break;

  case 110:
#line 1734 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_defined((yyvsp[(3) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized((yyvsp[(3) - (3)].id))){
									perror("The variable was not initialized\n");
									exit(0);
								}

								return symbolValInt((yyvsp[(1) - (3)].id)) || symbolValInt((yyvsp[(3) - (3)].id));
							}
    break;

  case 111:
#line 1752 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}

								return symbolValInt((yyvsp[(1) - (3)].id)) || (yyvsp[(3) - (3)].bool);
							}
    break;

  case 112:
#line 1760 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(3) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized((yyvsp[(3) - (3)].id))){
									perror("The variable was not initialized\n");
									exit(0);
								}

								return (yyvsp[(1) - (3)].bool) || symbolValInt((yyvsp[(3) - (3)].id));
							}
    break;

  case 113:
#line 1773 "Programming language/sintactic.y"
    {return (yyvsp[(1) - (3)].bool) || (yyvsp[(3) - (3)].bool);}
    break;

  case 114:
#line 1776 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_defined((yyvsp[(3) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized((yyvsp[(3) - (3)].id))){
									perror("The variable was not initialized\n");
									exit(0);
								}

								return symbolValInt((yyvsp[(1) - (3)].id)) != symbolValInt((yyvsp[(3) - (3)].id));
							}
    break;

  case 115:
#line 1794 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)].id))){
									perror("The variable was not declared\n");
									exit(0);
								}

								return symbolValInt((yyvsp[(1) - (3)].id)) != (yyvsp[(3) - (3)].bool);
							}
    break;

  case 116:
#line 1802 "Programming language/sintactic.y"
    {return symbolValInt((yyvsp[(1) - (3)].id)) != (yyvsp[(3) - (3)].bool);}
    break;

  case 127:
#line 1822 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return symbolValInt((yyvsp[(1) - (3)].id)) == symbolValInt((yyvsp[(3) - (3)].id));
									}
    break;

  case 128:
#line 1835 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return symbolValInt((yyvsp[(1) - (3)].id)) == (yyvsp[(3) - (3)].num);
									}
    break;

  case 129:
#line 1848 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (3)].num) == symbolValInt((yyvsp[(3) - (3)].id));
									}
    break;

  case 130:
#line 1861 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (3)].num) == (yyvsp[(3) - (3)].num);
									}
    break;

  case 131:
#line 1874 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return symbolValInt((yyvsp[(1) - (3)].id)) > symbolValInt((yyvsp[(3) - (3)].id));
									}
    break;

  case 132:
#line 1887 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return symbolValInt((yyvsp[(1) - (3)].id)) > (yyvsp[(3) - (3)].num);
									}
    break;

  case 133:
#line 1900 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (3)].num) > symbolValInt((yyvsp[(3) - (3)].id));
									}
    break;

  case 134:
#line 1913 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (3)].num) > (yyvsp[(3) - (3)].num);
									}
    break;

  case 135:
#line 1926 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return symbolValInt((yyvsp[(1) - (3)].id)) < symbolValInt((yyvsp[(3) - (3)].id));
									}
    break;

  case 136:
#line 1939 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return symbolValInt((yyvsp[(1) - (3)].id)) < (yyvsp[(3) - (3)].num);
									}
    break;

  case 137:
#line 1952 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (3)].num) < symbolValInt((yyvsp[(3) - (3)].id));
									}
    break;

  case 138:
#line 1965 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (3)].num) < (yyvsp[(3) - (3)].num);
									}
    break;

  case 139:
#line 1978 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return symbolValInt((yyvsp[(1) - (3)].id)) != symbolValInt((yyvsp[(3) - (3)].id));
									}
    break;

  case 140:
#line 1991 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return symbolValInt((yyvsp[(1) - (3)].id)) != (yyvsp[(3) - (3)].num);
									}
    break;

  case 141:
#line 2004 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (3)].num) != symbolValInt((yyvsp[(3) - (3)].id));
									}
    break;

  case 142:
#line 2017 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (3)].num) != (yyvsp[(3) - (3)].num);
									}
    break;

  case 143:
#line 2030 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].bool))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].bool))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (3)].bool) && (yyvsp[(3) - (3)].bool);
									}
    break;

  case 144:
#line 2043 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (3)].bool))){
											perror("The variable was not declared\n");
											exit(0);
										}

										if(!variable_is_defined((yyvsp[(3) - (3)].bool))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (3)].bool) || (yyvsp[(3) - (3)].bool);
									}
    break;

  case 145:
#line 2056 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(2) - (2)].bool))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return !(yyvsp[(2) - (2)].bool);
									}
    break;

  case 146:
#line 2064 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (1)].id))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return symbolValInt((yyvsp[(1) - (1)].id));
									}
    break;

  case 147:
#line 2072 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (1)].num))){
											perror("The variable was not declared\n");
											exit(0);
										}

										return (yyvsp[(1) - (1)].num);
									}
    break;

  case 148:
#line 2083 "Programming language/sintactic.y"
    {printf("Printing %s\n", (yyvsp[(2) - (3)].string));}
    break;

  case 149:
#line 2084 "Programming language/sintactic.y"
    {printf("Printing %d\n", (yyvsp[(2) - (3)].num));}
    break;

  case 150:
#line 2085 "Programming language/sintactic.y"
    {
										if(!strcmp(symbolType((yyvsp[(2) - (3)].id)), NAME_INT)){
											printf("Printing %d\n", symbolValInt((yyvsp[(2) - (3)].id)));
										}
										else{
											if(!strcmp(symbolType((yyvsp[(2) - (3)].id)), NAME_STRING)){
												printf("Printing %s\n", symbolValString((yyvsp[(2) - (3)].id)));
											}
											else{
												perror("Variable not declared\n");
												exit(0);
											}
										}
									}
    break;

  case 151:
#line 2101 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (4)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}

													/* switch(typename($1)){
														case TYPENAME_STRING:
															$1 = $3;

															break;
														case TYPENAME_CONST_STRING:
															perror("You can't change the value of a constant!\n");
															exit(0);

															break;
														default:
															perror("You can't assign a string to this type of data\n");
															exit(0);
													} */

													if(!strcmp(symbolType((yyvsp[(1) - (4)].id)), NAME_STRING)){
														updateSymbolValString((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].string));
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
    break;

  case 152:
#line 2130 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (6)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}

													/* switch(typename($1)){
														case TYPENAME_STRING:
															$1 = $3;
															strcat($1, $5);

															break;
														case TYPENAME_CONST_STRING:
															perror("You can't change the value of a constant!\n");
															exit(0);

															break;
														default:
															perror("You can't assign a string to this type of data\n");
															exit(0);
													} */

													if(!strcmp(symbolType((yyvsp[(1) - (6)].id)), NAME_STRING)){
														updateSymbolValString((yyvsp[(1) - (6)].id), strcat((yyvsp[(3) - (6)].string), (yyvsp[(5) - (6)].string)));
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
    break;

  case 153:
#line 2160 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (6)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}

													if(!variable_is_defined((yyvsp[(3) - (6)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}

													/* switch(typename($1)){
														case TYPENAME_STRING:
															if(typename($3) == TYPENAME_STRING || typename($3) == TYPENAME_CONST_STRING){
																$1 = $3;
																strcat($1, $5);
															}
															else{
																perror("There has been a problem with variables, revise the types\n");
																exit(0);
															}

															break;
														case TYPENAME_CONST_STRING:
															perror("You can't change the value of a constant!\n");
															exit(0);

															break;
														default:
															perror("You can't assign a string to this type of data\n");
															exit(0);
													} */

													if(!strcmp(symbolType((yyvsp[(1) - (6)].id)), NAME_STRING)){
														updateSymbolValString((yyvsp[(1) - (6)].id), strcat(symbolValString((yyvsp[(3) - (6)].id)), (yyvsp[(5) - (6)].string)));
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
    break;

  case 154:
#line 2201 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (6)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}

													if(!variable_is_defined((yyvsp[(5) - (6)].id))){
														perror("The variable was not declared\n");
														exit(0);
													}

													/* switch(typename($1)){
														case TYPENAME_STRING:
															if(typename($5) == TYPENAME_STRING || typename($5) == TYPENAME_CONST_STRING){
																$1 = $3;
																strcat($1, $5);
															}
															else{
																perror("There has been a problem with variables, revise the types\n");
																exit(0);
															}

															break;
														case TYPENAME_CONST_STRING:
															perror("You can't change the value of a constant!\n");
															exit(0);

															break;
														default:
															perror("You can't assign a string to this type of data\n");
															exit(0);
													} */

													if(!strcmp(symbolType((yyvsp[(1) - (6)].id)), NAME_STRING)){
														updateSymbolValString((yyvsp[(1) - (6)].id), strcat((yyvsp[(3) - (6)].string), symbolValString((yyvsp[(5) - (6)].id))));
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}
												}
    break;


/* Line 1267 of yacc.c.  */
#line 4061 "Programming language/y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 2252 "Programming language/sintactic.y"


int main(int argc, char* argv[]){
	const char HASH = '#';
	const char *EMPTY = "\0";
	int i;

	for(i = 0; i < MAX_NUM_FUNCS; i++){
		//strcpy(vars[i], &HASH);
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
