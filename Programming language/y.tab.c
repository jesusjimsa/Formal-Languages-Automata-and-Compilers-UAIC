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
     BINARY = 302,
     STRING = 303
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
#define BINARY 302
#define STRING 303




/* Copy the first part of user declarations.  */
#line 1 "Programming language/sintactic.y"

	void yerror(char *s);
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	void yyerror(const char* msg) {
    	fprintf(stderr, "%s\n", msg);
	}

	int yylex();

	const int MAX_NUM_VARS_FUNCS = 1024;
	char vars[MAX_NUM_VARS_FUNCS][256];		// 256 is the maximun lenght of a variable name
	char funcs[MAX_NUM_VARS_FUNCS][1024];	// 1024 is the maximun lenght of a function signature
	char vars_initialized[MAX_NUM_VARS_FUNCS][256];
	
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

	#define typename(x) _Generic((x), char: TYPENAME_STRING, const char: TYPENAME_CONST_STRING, int: TYPENAME_INT, const int: TYPENAME_CONST_INT, unsigned int: TYPENAME_UNSIGNED_INT, const unsigned int: TYPENAME_CONST_UNSIGNED_INT, default: TYPENAME_OTHER)

	#define true (1 == 1)
	#define false (!true)

	void checkVariable(char *name, int is_initialized){
		char hash = '#';

		for(int i = 0; i < MAX_NUM_VARS_FUNCS; i++){
			if(!strcmp(name, vars[i])){	// This means they have the same name
				perror("This variable was already declared\n");
			}

			if(!strcmp(&hash, vars[i])){
				strcpy(vars[i], name);
				
				if(is_initialized){
					strcpy(vars_initialized[i], name);
				} //HERE
				
				i = MAX_NUM_VARS_FUNCS + 10;	// We don't need more iterations
			}
		}
	}

	void checkFunctionSignature(char *name){
		char hash = '#';

		for(int i = 0; i < MAX_NUM_VARS_FUNCS; i++){
			if(!strcmp(name, funcs[i])){	// This means they have the same name
				perror("This function was already declared\n");
			}

			if(!strcmp(&hash, funcs[i])){
				strcpy(funcs[i], name);
				i = MAX_NUM_VARS_FUNCS + 10;	// We don't need more iterations
			}
		}
	}

	int variable_is_defined(char *name){
		for(int i = 0; i < MAX_NUM_VARS_FUNCS; i++){
			if(strcmp(name, vars[i])){
				return true;
			}
		}
	
		return false;
	}

	int variable_is_initialized(char *name){
		for(int i = 0; i < MAX_NUM_VARS_FUNCS; i++){
			if(strcmp(name,vars_initialized[i])){
				return true;
			}
		}

		return false;
	}

	int function_is_defined(char *name){
		for(int i = 0; i < MAX_NUM_VARS_FUNCS; i++){
			if(strcmp(name,funcs[i])){
				return true;
			}
		}

		return false;
	}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 302 "Programming language/y.tab.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    15,    23,    29,    33,
      38,    41,    45,    50,    56,    58,    60,    62,    64,    66,
      69,    74,    79,    82,    87,    94,   101,   106,   111,   117,
     122,   124,   126,   128,   131,   134,   138,   140,   143,   145,
     147,   149,   154,   158,   160,   164,   169,   173,   177,   179,
     181,   185,   190,   195,   198,   201,   203,   205,   207,   209,
     211,   213,   219,   225,   231,   237,   243,   249,   255,   261,
     267,   273,   279,   285,   291,   297,   303,   309,   315,   321,
     327,   333,   335,   337,   339,   343,   347,   351,   355,   359,
     363,   367,   371,   375,   379
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    52,    -1,    53,    51,    -1,
      29,     5,    56,     6,    -1,    29,     3,    30,     4,     5,
      56,     6,    -1,    28,    54,     5,    56,     6,    -1,    46,
       3,     4,    -1,    46,     3,    55,     4,    -1,    59,    46,
      -1,    59,    26,    46,    -1,    59,    46,    16,    55,    -1,
      59,    26,    46,    16,    55,    -1,    57,    -1,    63,    -1,
      66,    -1,    56,    -1,    58,    -1,    58,    57,    -1,    60,
      46,    11,    45,    -1,    61,    46,    11,    48,    -1,    59,
      46,    -1,    59,    46,    16,    58,    -1,    60,    46,    11,
      45,    16,    58,    -1,    61,    46,    11,    48,    16,    58,
      -1,    60,    46,    11,    45,    -1,    61,    46,    11,    48,
      -1,    59,    46,     7,    45,     8,    -1,    59,    46,     7,
       8,    -1,    60,    -1,    61,    -1,    22,    -1,    27,    22,
      -1,    24,    22,    -1,    27,    24,    22,    -1,    23,    -1,
      27,    23,    -1,    45,    -1,    48,    -1,    47,    -1,    25,
      46,    11,    64,    -1,    46,    11,    64,    -1,    64,    -1,
      46,     3,     4,    -1,    46,     3,    65,     4,    -1,    46,
      16,    65,    -1,    62,    16,    65,    -1,    46,    -1,    62,
      -1,    46,    11,    45,    -1,    46,    11,    46,    19,    -1,
      46,    11,    46,    20,    -1,    46,    19,    -1,    46,    20,
      -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,    72,    -1,    46,    11,    46,    17,    46,    -1,    46,
      11,    46,    17,    45,    -1,    46,    11,    45,    17,    46,
      -1,    46,    11,    45,    17,    45,    -1,    46,    11,    46,
      12,    46,    -1,    46,    11,    46,    12,    45,    -1,    46,
      11,    45,    12,    46,    -1,    46,    11,    45,    12,    45,
      -1,    46,    11,    46,    18,    46,    -1,    46,    11,    46,
      18,    45,    -1,    46,    11,    45,    18,    46,    -1,    46,
      11,    45,    18,    45,    -1,    46,    11,    46,    13,    46,
      -1,    46,    11,    46,    13,    45,    -1,    46,    11,    45,
      13,    46,    -1,    46,    11,    45,    13,    45,    -1,    46,
      11,    46,    14,    46,    -1,    46,    11,    46,    14,    45,
      -1,    46,    11,    45,    14,    46,    -1,    46,    11,    45,
      14,    45,    -1,    73,    -1,    74,    -1,    75,    -1,    46,
      36,    46,    -1,    46,    36,    47,    -1,    47,    36,    46,
      -1,    47,    36,    47,    -1,    46,    37,    46,    -1,    46,
      37,    47,    -1,    47,    37,    46,    -1,    47,    37,    47,
      -1,    46,    42,    46,    -1,    46,    42,    47,    -1,    46,
      42,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   150,   150,   152,   153,   156,   157,   160,   162,   163,
     166,   167,   168,   169,   172,   173,   174,   175,   178,   179,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     194,   195,   198,   199,   200,   201,   204,   205,   208,   209,
     210,   213,   214,   215,   218,   224,   232,   233,   234,   235,
     238,   262,   274,   286,   294,   302,   303,   304,   305,   306,
     307,   310,   392,   441,   490,   518,   587,   636,   685,   713,
     782,   831,   880,   908,   977,  1026,  1075,  1103,  1172,  1222,
    1271,  1299,  1300,  1301,  1304,  1320,  1328,  1341,  1344,  1362,
    1370,  1383,  1386,  1404,  1412
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
  "CS_GREATER", "CS_NOT", "S_STRUCT", "S_PRINT", "NUM", "ID", "BINARY",
  "STRING", "$accept", "BEGIN", "FUNCIONES", "FUNCION_PRINCIPAL",
  "FUNCION", "SIGNATURE", "PARAMETERS", "EXPRESIONS",
  "DECLARATION_VARIABLES", "VARIABLE", "VAR_TYPE", "INT", "CHAR",
  "S_DEFINITION", "CALL_FUNCTIONS", "FUNCTION_DEFINITION",
  "PARAMETERS_WDECLARATION", "OPERATIONS", "ST_PLUS", "ST_SUBSTRACTION",
  "ST_MULTIPLICATION", "ST_DIVISION", "ST_MODULE", "OP_BINARY", "ST_AND",
  "ST_OR", "ST_NOT", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    54,    54,
      55,    55,    55,    55,    56,    56,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    60,    60,    60,    60,    61,    61,    62,    62,
      62,    63,    63,    63,    64,    64,    65,    65,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    68,    68,    68,    68,    69,
      69,    69,    69,    70,    70,    70,    70,    71,    71,    71,
      71,    72,    72,    72,    73,    73,    73,    73,    74,    74,
      74,    74,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     4,     7,     5,     3,     4,
       2,     3,     4,     5,     1,     1,     1,     1,     1,     2,
       4,     4,     2,     4,     6,     6,     4,     4,     5,     4,
       1,     1,     1,     2,     2,     3,     1,     2,     1,     1,
       1,     4,     3,     1,     3,     4,     3,     3,     1,     1,
       3,     4,     4,     2,     2,     1,     1,     1,     1,     1,
       1,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     1,     4,     0,     0,     0,    32,    36,     0,     0,
       0,     0,     0,     0,    14,    18,     0,     0,     0,    15,
      43,    16,    55,    56,    57,    58,    59,    60,    81,    82,
      83,     8,     0,     0,    30,    31,     0,     0,    34,     0,
      33,    37,     0,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     5,    19,    22,     0,     0,     9,     0,    10,
       7,     0,     0,    35,    44,    38,    48,    40,    39,    49,
       0,    50,     0,    42,    84,    85,    88,    89,    92,    93,
      94,    86,    87,    90,    91,     0,     0,     0,     0,    11,
       0,     0,     0,    41,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    52,    29,
       0,    23,    20,    21,     0,    12,     6,    46,    47,    68,
      67,    76,    75,    80,    79,    64,    63,    72,    71,    66,
      65,    74,    73,    78,    77,    62,    61,    70,    69,    28,
       0,     0,    13,    24,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     8,    42,    23,    24,    25,
      26,    27,    28,    79,    29,    30,    80,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
       0,    -8,    80,    35,   -94,   -94,     0,    57,    61,    77,
     -14,   -94,   -94,    46,   -14,    82,   -94,   -94,    70,    38,
      19,     3,    15,   104,   -94,    40,    78,    79,    81,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   122,    -9,   -94,   -94,   123,   125,   -94,   117,
     -94,   -94,   109,     1,    10,   -94,   -94,    25,    31,    44,
      47,    49,   -94,   -94,     8,   121,   124,   -94,    87,   118,
     -94,   -14,    90,   -94,   -94,   -94,   126,   -94,   -94,   127,
     133,    13,    62,   -94,   -94,   -94,   -94,   -94,    17,    15,
     -94,   -94,   -94,   -94,   -94,    -1,    40,    93,    91,   128,
      40,   134,   138,   -94,   -27,   -27,   -94,    52,    54,    56,
      58,    60,    63,    69,    71,    73,    75,   -94,   -94,   -94,
     137,   -94,   130,   131,    40,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
      40,    40,   -94,   -94,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   142,   -94,   -94,   -94,   -88,   -10,   129,   -93,
     -13,   -12,   -11,   -94,   -94,   -38,    18,   -94,   -94,   -94,
     -94,   -94,   -94,    92,   -94,   -94,   -94
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,    44,    45,   121,    46,    74,    53,   119,    16,    17,
      18,    19,   125,    20,    54,    95,    83,    68,    75,    76,
      77,    78,    55,    56,    96,   107,   108,   109,     1,     2,
     110,   111,    21,    22,   103,    11,   152,    69,     7,    57,
      58,    50,    51,    52,   120,    59,    75,    76,    77,    78,
      41,    60,    61,    57,    58,    81,    82,   153,   154,    59,
      13,   101,    16,    17,    18,    53,    14,    20,    16,    17,
      18,    84,    85,    20,   112,   113,   114,    86,    87,   115,
     116,   117,   118,     9,    49,    10,    47,    43,    44,    45,
      88,    89,    48,    91,    92,    93,    94,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    15,   139,   140,
      62,    43,    44,    45,   141,   142,   143,   144,   145,   146,
     147,   148,   127,   128,    64,    65,    67,    66,    72,    70,
      71,    73,    97,    99,   100,    98,   102,   106,   122,   123,
     126,    53,   104,   105,   124,   149,   150,   151,    12,     0,
       0,    90,     0,     0,    63
};

static const yytype_int16 yycheck[] =
{
      13,    13,    13,    96,    14,     4,     3,     8,    22,    23,
      24,    25,   100,    27,    11,     7,    54,    26,    45,    46,
      47,    48,    19,    20,    16,    12,    13,    14,    28,    29,
      17,    18,    46,    47,    72,     0,   124,    46,    46,    36,
      37,    22,    23,    24,    45,    42,    45,    46,    47,    48,
       4,    36,    37,    36,    37,    45,    46,   150,   151,    42,
       3,    71,    22,    23,    24,     3,     5,    27,    22,    23,
      24,    46,    47,    27,    12,    13,    14,    46,    47,    17,
      18,    19,    20,     3,    46,     5,     4,   100,   100,   100,
      46,    47,    22,    46,    47,    46,    47,    45,    46,    45,
      46,    45,    46,    45,    46,    45,    46,    30,    45,    46,
       6,   124,   124,   124,    45,    46,    45,    46,    45,    46,
      45,    46,   104,   105,    46,    46,     4,    46,    11,     6,
       5,    22,    11,    46,    16,    11,    46,     4,    45,    48,
       6,     3,    16,    16,    16,     8,    16,    16,     6,    -1,
      -1,    59,    -1,    -1,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    29,    50,    51,    52,    53,    46,    54,     3,
       5,     0,    51,     3,     5,    30,    22,    23,    24,    25,
      27,    46,    47,    56,    57,    58,    59,    60,    61,    63,
      64,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     4,    55,    59,    60,    61,    56,     4,    22,    46,
      22,    23,    24,     3,    11,    19,    20,    36,    37,    42,
      36,    37,     6,    57,    46,    46,    46,     4,    26,    46,
       6,     5,    11,    22,     4,    45,    46,    47,    48,    62,
      65,    45,    46,    64,    46,    47,    46,    47,    46,    47,
      72,    46,    47,    46,    47,     7,    16,    11,    11,    46,
      16,    56,    46,    64,    16,    16,     4,    12,    13,    14,
      17,    18,    12,    13,    14,    17,    18,    19,    20,     8,
      45,    58,    45,    48,    16,    55,     6,    65,    65,    45,
      46,    45,    46,    45,    46,    45,    46,    45,    46,    45,
      46,    45,    46,    45,    46,    45,    46,    45,    46,     8,
      16,    16,    55,    58,    58
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
        case 7:
#line 160 "Programming language/sintactic.y"
    {checkFunctionSignature((yyvsp[(2) - (5)]));}
    break;

  case 20:
#line 182 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (4)]), true);}
    break;

  case 21:
#line 183 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (4)]), true);}
    break;

  case 22:
#line 184 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (2)]), false);}
    break;

  case 23:
#line 185 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (4)]), true);}
    break;

  case 24:
#line 186 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (6)]), true);}
    break;

  case 25:
#line 187 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (6)]), true);}
    break;

  case 26:
#line 188 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (4)]), true);}
    break;

  case 27:
#line 189 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (4)]), true);}
    break;

  case 28:
#line 190 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (5)]), true);}
    break;

  case 29:
#line 191 "Programming language/sintactic.y"
    {checkVariable((yyvsp[(2) - (4)]), true);}
    break;

  case 44:
#line 218 "Programming language/sintactic.y"
    {
															if(!function_is_defined((yyvsp[(1) - (3)]))){
																perror("The function was not declared\n");
																exit(0);
															}
														}
    break;

  case 45:
#line 224 "Programming language/sintactic.y"
    {
															if(!function_is_defined((yyvsp[(1) - (4)]))){
																perror("The function was not declared\n");
																exit(0);
															}
														}
    break;

  case 50:
#line 238 "Programming language/sintactic.y"
    {
										switch(typename((yyvsp[(1) - (3)]))){
											case TYPENAME_INT:
												(yyvsp[(1) - (3)]) = (yyvsp[(3) - (3)]);

												break;
											case TYPENAME_UNSIGNED_INT:
												if((yyvsp[(3) - (3)]) > 0){
													(yyvsp[(1) - (3)]) = (yyvsp[(3) - (3)]);
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
										}
									}
    break;

  case 51:
#line 262 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(3) - (4)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (4)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										(yyvsp[(1) - (4)]) = (yyvsp[(3) - (4)]) + 1;
									}
    break;

  case 52:
#line 274 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(3) - (4)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (4)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										(yyvsp[(1) - (4)]) = (yyvsp[(3) - (4)]) - 1;
									}
    break;

  case 53:
#line 286 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (2)]))){
											perror("The variable was not declared\n");
											exit(0);
										}

										(yyvsp[(1) - (2)]) = (yyvsp[(1) - (2)]) + 1;
									}
    break;

  case 54:
#line 294 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (2)]))){
											perror("The variable was not declared\n");
											exit(0);
										}

										(yyvsp[(1) - (2)]) = (yyvsp[(1) - (2)]) - 1;
									}
    break;

  case 61:
#line 310 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename((yyvsp[(5) - (5)])) == TYPENAME_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) + (yyvsp[(5) - (5)]);
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
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) + (yyvsp[(5) - (5)]);
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
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_STRING || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_STRING){
													if(typename((yyvsp[(5) - (5)])) == TYPENAME_STRING || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_STRING){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]);
														strcat((yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
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
										}					}
    break;

  case 62:
#line 392 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) + (yyvsp[(5) - (5)]);
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) + (yyvsp[(5) - (5)]);
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
    break;

  case 63:
#line 441 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
												if(typename((yyvsp[(5) - (5)])) == TYPENAME_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) + (yyvsp[(5) - (5)]);
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) + (yyvsp[(5) - (5)]);
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
    break;

  case 64:
#line 490 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
											case TYPENAME_UNSIGNED_INT:
												(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) + (yyvsp[(5) - (5)]);

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
    break;

  case 65:
#line 518 "Programming language/sintactic.y"
    {
											if(!variable_is_defined((yyvsp[(1) - (5)]))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined((yyvsp[(3) - (5)]))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined((yyvsp[(5) - (5)]))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_initialized((yyvsp[(3) - (5)]))){
												perror("The variable was not initialized\n");
												exit(0);
											}
											if(!variable_is_initialized((yyvsp[(5) - (5)]))){
												perror("The variable was not initialized\n");
												exit(0);
											}

											switch(typename((yyvsp[(1) - (5)]))){
												case TYPENAME_INT:
													if(typename((yyvsp[(3) - (5)])) == TYPENAME_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														if(typename((yyvsp[(5) - (5)])) == TYPENAME_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
															(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) - (yyvsp[(5) - (5)]);
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
													if(typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														if(typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
															(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) - (yyvsp[(5) - (5)]);
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
    break;

  case 66:
#line 587 "Programming language/sintactic.y"
    {
											if(!variable_is_defined((yyvsp[(1) - (5)]))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined((yyvsp[(3) - (5)]))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_initialized((yyvsp[(3) - (5)]))){
												perror("The variable was not initialized\n");
												exit(0);
											}

											switch(typename((yyvsp[(1) - (5)]))){
												case TYPENAME_INT:
													if(typename((yyvsp[(3) - (5)])) == TYPENAME_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) - (yyvsp[(5) - (5)]);
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}

													break;
												case TYPENAME_UNSIGNED_INT:
													if(typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) - (yyvsp[(5) - (5)]);
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
    break;

  case 67:
#line 636 "Programming language/sintactic.y"
    {
											if(!variable_is_defined((yyvsp[(1) - (5)]))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_defined((yyvsp[(5) - (5)]))){
												perror("The variable was not declared\n");
												exit(0);
											}
											if(!variable_is_initialized((yyvsp[(5) - (5)]))){
												perror("The variable was not initialized\n");
												exit(0);
											}

											switch(typename((yyvsp[(1) - (5)]))){
												case TYPENAME_INT:
													if(typename((yyvsp[(5) - (5)])) == TYPENAME_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) - (yyvsp[(5) - (5)]);
													}
													else{
														perror("Wrong types\n");
														exit(0);
													}

													break;
												case TYPENAME_UNSIGNED_INT:
													if(typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) - (yyvsp[(5) - (5)]);
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
    break;

  case 68:
#line 685 "Programming language/sintactic.y"
    {
											if(!variable_is_defined((yyvsp[(1) - (5)]))){
												perror("The variable was not declared\n");
												exit(0);
											}

											switch(typename((yyvsp[(1) - (5)]))){
												case TYPENAME_INT:
												case TYPENAME_UNSIGNED_INT:
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) - (yyvsp[(5) - (5)]);

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
    break;

  case 69:
#line 713 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (5)]))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined((yyvsp[(3) - (5)]))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined((yyvsp[(5) - (5)]))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_initialized((yyvsp[(3) - (5)]))){
														perror("The variable was not initialized\n");
														exit(0);
													}
													if(!variable_is_initialized((yyvsp[(5) - (5)]))){
														perror("The variable was not initialized\n");
														exit(0);
													}

													switch(typename((yyvsp[(1) - (5)]))){
														case TYPENAME_INT:
															if(typename((yyvsp[(3) - (5)])) == TYPENAME_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
																if(typename((yyvsp[(5) - (5)])) == TYPENAME_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
																	(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) * (yyvsp[(5) - (5)]);
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
															if(typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
																if(typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
																	(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) * (yyvsp[(5) - (5)]);
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
    break;

  case 70:
#line 782 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (5)]))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined((yyvsp[(3) - (5)]))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_initialized((yyvsp[(3) - (5)]))){
														perror("The variable was not initialized\n");
														exit(0);
													}

													switch(typename((yyvsp[(1) - (5)]))){
														case TYPENAME_INT:
															if(typename((yyvsp[(3) - (5)])) == TYPENAME_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
																(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) * (yyvsp[(5) - (5)]);
															}
															else{
																perror("Wrong types\n");
																exit(0);
															}

															break;
														case TYPENAME_UNSIGNED_INT:
															if(typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
																(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) * (yyvsp[(5) - (5)]);
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
    break;

  case 71:
#line 831 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (5)]))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_defined((yyvsp[(5) - (5)]))){
														perror("The variable was not declared\n");
														exit(0);
													}
													if(!variable_is_initialized((yyvsp[(5) - (5)]))){
														perror("The variable was not initialized\n");
														exit(0);
													}

													switch(typename((yyvsp[(1) - (5)]))){
														case TYPENAME_INT:
															if(typename((yyvsp[(5) - (5)])) == TYPENAME_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
																(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) * (yyvsp[(5) - (5)]);
															}
															else{
																perror("Wrong types\n");
																exit(0);
															}

															break;
														case TYPENAME_UNSIGNED_INT:
															if(typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
																(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) * (yyvsp[(5) - (5)]);
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
    break;

  case 72:
#line 880 "Programming language/sintactic.y"
    {
													if(!variable_is_defined((yyvsp[(1) - (5)]))){
														perror("The variable was not declared\n");
														exit(0);
													}

													switch(typename((yyvsp[(1) - (5)]))){
														case TYPENAME_INT:
														case TYPENAME_UNSIGNED_INT:
															(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) * (yyvsp[(5) - (5)]);

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
    break;

  case 73:
#line 908 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename((yyvsp[(5) - (5)])) == TYPENAME_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) / (yyvsp[(5) - (5)]);
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
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) / (yyvsp[(5) - (5)]);
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
    break;

  case 74:
#line 977 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) / (yyvsp[(5) - (5)]);
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) / (yyvsp[(5) - (5)]);
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
    break;

  case 75:
#line 1026 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
												if(typename((yyvsp[(5) - (5)])) == TYPENAME_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) / (yyvsp[(5) - (5)]);
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) / (yyvsp[(5) - (5)]);
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
    break;

  case 76:
#line 1075 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
											case TYPENAME_UNSIGNED_INT:
												(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) / (yyvsp[(5) - (5)]);

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
    break;

  case 77:
#line 1103 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename((yyvsp[(5) - (5)])) == TYPENAME_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) % (yyvsp[(5) - (5)]);
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
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													if(typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
														(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) % (yyvsp[(5) - (5)]);
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
    break;

  case 78:
#line 1172 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(3) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(3) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}


										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) % (yyvsp[(5) - (5)]);
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename((yyvsp[(3) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(3) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) % (yyvsp[(5) - (5)]);
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
    break;

  case 79:
#line 1222 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_defined((yyvsp[(5) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}
										if(!variable_is_initialized((yyvsp[(5) - (5)]))){
											perror("The variable was not initialized\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
												if(typename((yyvsp[(5) - (5)])) == TYPENAME_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) % (yyvsp[(5) - (5)]);
												}
												else{
													perror("Wrong types\n");
													exit(0);
												}

												break;
											case TYPENAME_UNSIGNED_INT:
												if(typename((yyvsp[(5) - (5)])) == TYPENAME_UNSIGNED_INT || typename((yyvsp[(5) - (5)])) == TYPENAME_CONST_UNSIGNED_INT){
													(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) % (yyvsp[(5) - (5)]);
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
    break;

  case 80:
#line 1271 "Programming language/sintactic.y"
    {
										if(!variable_is_defined((yyvsp[(1) - (5)]))){
											perror("The variable was not declared\n");
											exit(0);
										}

										switch(typename((yyvsp[(1) - (5)]))){
											case TYPENAME_INT:
											case TYPENAME_UNSIGNED_INT:
												(yyvsp[(1) - (5)]) = (yyvsp[(3) - (5)]) % (yyvsp[(5) - (5)]);

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
    break;

  case 84:
#line 1304 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}
								if(!variable_is_defined((yyvsp[(3) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}
								if(!variable_is_initialized((yyvsp[(3) - (3)]))){
									perror("The variable was not initialized\n");
									exit(0);
								}

								return (yyvsp[(1) - (3)]) && (yyvsp[(3) - (3)]);
							}
    break;

  case 85:
#line 1320 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}

								return (yyvsp[(1) - (3)]) && (yyvsp[(3) - (3)]);
							}
    break;

  case 86:
#line 1328 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(3) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized((yyvsp[(3) - (3)]))){
									perror("The variable was not initialized\n");
									exit(0);
								}

								return (yyvsp[(1) - (3)]) && (yyvsp[(3) - (3)]);
							}
    break;

  case 87:
#line 1341 "Programming language/sintactic.y"
    {(yyvsp[(1) - (3)]) && (yyvsp[(3) - (3)]);}
    break;

  case 88:
#line 1344 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_defined((yyvsp[(3) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized((yyvsp[(3) - (3)]))){
									perror("The variable was not initialized\n");
									exit(0);
								}

								return (yyvsp[(1) - (3)]) || (yyvsp[(3) - (3)]);
							}
    break;

  case 89:
#line 1362 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}

								return (yyvsp[(1) - (3)]) || (yyvsp[(3) - (3)]);
							}
    break;

  case 90:
#line 1370 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(3) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized((yyvsp[(3) - (3)]))){
									perror("The variable was not initialized\n");
									exit(0);
								}

								return (yyvsp[(1) - (3)]) || (yyvsp[(3) - (3)]);
							}
    break;

  case 91:
#line 1383 "Programming language/sintactic.y"
    {(yyvsp[(1) - (3)]) || (yyvsp[(3) - (3)]);}
    break;

  case 92:
#line 1386 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_defined((yyvsp[(3) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}

								if(!variable_is_initialized((yyvsp[(3) - (3)]))){
									perror("The variable was not initialized\n");
									exit(0);
								}

								return (yyvsp[(1) - (3)]) != (yyvsp[(3) - (3)]);
							}
    break;

  case 93:
#line 1404 "Programming language/sintactic.y"
    {
								if(!variable_is_defined((yyvsp[(1) - (3)]))){
									perror("The variable was not declared\n");
									exit(0);
								}

								return (yyvsp[(1) - (3)]) != (yyvsp[(3) - (3)]);
							}
    break;

  case 94:
#line 1412 "Programming language/sintactic.y"
    {(yyvsp[(1) - (3)]) != (yyvsp[(3) - (3)]);}
    break;


/* Line 1267 of yacc.c.  */
#line 3021 "Programming language/y.tab.c"
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


#line 1651 "Programming language/sintactic.y"


int main(){
	char hash = '#';

	for(int i = 0; i < MAX_NUM_VARS_FUNCS; i++){
		strcpy(vars[i], &hash);
		strcpy(funcs[i], &hash);
	}

	yyparse();
}
