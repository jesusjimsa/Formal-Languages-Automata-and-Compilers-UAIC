/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 164 "Programming language/sintactic.y"
{int num; char id; char *string; int bool;}
/* Line 1529 of yacc.c.  */
#line 149 "Programming language/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

