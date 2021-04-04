/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

    //header files
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include"symbol_table.h"


    extern int scope, columnNo;
    //initialise symbol table
    symtab_t* SymbolTable = NULL;

    int yyerror(char* err);
    int yylex(void);
    extern FILE* yyin;
    extern int yylineno;
    extern char* yytext;
    int is_loop = 0;
    //keep track of data type of identifiers
    char* curr_data_type;

#line 88 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_ADD = 258,
    T_SUBTRACT = 259,
    T_MULTIPLY = 260,
    T_DIVIDE = 261,
    T_ADD_ASSIGN = 262,
    T_SUB_ASSIGN = 263,
    T_MUL_ASSIGN = 264,
    T_DIV_ASSIGN = 265,
    T_MOD_ASSIGN = 266,
    T_MOD = 267,
    T_GREATER_THAN = 268,
    T_LESSER_THAN = 269,
    T_LESSER_EQ = 270,
    T_GREATER_EQ = 271,
    T_NOT_EQ = 272,
    T_EQUAL = 273,
    T_VOID = 274,
    T_IF = 275,
    T_ELSE = 276,
    T_FOR = 277,
    T_DO = 278,
    T_WHILE = 279,
    T_GOTO = 280,
    T_BREAK = 281,
    T_CONTINUE = 282,
    T_RETURN = 283,
    T_SWITCH = 284,
    T_CASE = 285,
    T_DEFAULT = 286,
    T_MAIN = 287,
    T_INT = 288,
    T_FLOAT = 289,
    T_DOUBLE = 290,
    T_SHORT = 291,
    T_LONG = 292,
    T_LONG_INT = 293,
    T_CHAR = 294,
    T_SIGNED = 295,
    T_UNSIGNED = 296,
    T_BOOL = 297,
    T_LG_OR = 298,
    T_LG_AND = 299,
    T_NOT = 300,
    T_ASSIGN = 301,
    T_DECREMENT = 302,
    T_INCREMENT = 303,
    T_HEX_CONSTANT = 304,
    T_DEC_CONSTANT = 305,
    T_INT_CONSTANT = 306,
    T_BOOL_CONSTANT = 307,
    T_STRING = 308,
    T_IDENTIFIER = 309,
    T_IFX = 310
  };
#endif
/* Tokens.  */
#define T_ADD 258
#define T_SUBTRACT 259
#define T_MULTIPLY 260
#define T_DIVIDE 261
#define T_ADD_ASSIGN 262
#define T_SUB_ASSIGN 263
#define T_MUL_ASSIGN 264
#define T_DIV_ASSIGN 265
#define T_MOD_ASSIGN 266
#define T_MOD 267
#define T_GREATER_THAN 268
#define T_LESSER_THAN 269
#define T_LESSER_EQ 270
#define T_GREATER_EQ 271
#define T_NOT_EQ 272
#define T_EQUAL 273
#define T_VOID 274
#define T_IF 275
#define T_ELSE 276
#define T_FOR 277
#define T_DO 278
#define T_WHILE 279
#define T_GOTO 280
#define T_BREAK 281
#define T_CONTINUE 282
#define T_RETURN 283
#define T_SWITCH 284
#define T_CASE 285
#define T_DEFAULT 286
#define T_MAIN 287
#define T_INT 288
#define T_FLOAT 289
#define T_DOUBLE 290
#define T_SHORT 291
#define T_LONG 292
#define T_LONG_INT 293
#define T_CHAR 294
#define T_SIGNED 295
#define T_UNSIGNED 296
#define T_BOOL 297
#define T_LG_OR 298
#define T_LG_AND 299
#define T_NOT 300
#define T_ASSIGN 301
#define T_DECREMENT 302
#define T_INCREMENT 303
#define T_HEX_CONSTANT 304
#define T_DEC_CONSTANT 305
#define T_INT_CONSTANT 306
#define T_BOOL_CONSTANT 307
#define T_STRING 308
#define T_IDENTIFIER 309
#define T_IFX 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "parser.y" /* yacc.c:355  */

    int ival;
    char* str;
    node_t *tbEntry;
    double dval;

#line 245 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      60,    61,     2,     2,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    57,
       2,     2,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,    65,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    69,    71,    72,    74,    75,    77,    79,
      80,    83,    84,    87,    88,    90,    90,    91,    93,    95,
      96,    97,    98,    99,   100,   101,   104,   105,   108,   109,
     110,   111,   112,   115,   116,   119,   120,   121,   123,   124,
     127,   128,   130,   131,   133,   134,   137,   138,   140,   141,
     144,   145,   146,   147,   148,   149,   151,   152,   154,   155,
     156,   157,   161,   162,   165,   166,   167,   168,   171,   172,
     174,   175,   177,   178,   180,   181,   182,   183,   184,   185,
     186,   189,   190,   191,   193,   194,   195,   196,   198,   199,
     200,   202,   203,   204,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   216,   217,   219,   221,   222,   224,   225,
     227,   227,   228,   229,   236
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ADD", "T_SUBTRACT", "T_MULTIPLY",
  "T_DIVIDE", "T_ADD_ASSIGN", "T_SUB_ASSIGN", "T_MUL_ASSIGN",
  "T_DIV_ASSIGN", "T_MOD_ASSIGN", "T_MOD", "T_GREATER_THAN",
  "T_LESSER_THAN", "T_LESSER_EQ", "T_GREATER_EQ", "T_NOT_EQ", "T_EQUAL",
  "T_VOID", "T_IF", "T_ELSE", "T_FOR", "T_DO", "T_WHILE", "T_GOTO",
  "T_BREAK", "T_CONTINUE", "T_RETURN", "T_SWITCH", "T_CASE", "T_DEFAULT",
  "T_MAIN", "T_INT", "T_FLOAT", "T_DOUBLE", "T_SHORT", "T_LONG",
  "T_LONG_INT", "T_CHAR", "T_SIGNED", "T_UNSIGNED", "T_BOOL", "T_LG_OR",
  "T_LG_AND", "T_NOT", "T_ASSIGN", "T_DECREMENT", "T_INCREMENT",
  "T_HEX_CONSTANT", "T_DEC_CONSTANT", "T_INT_CONSTANT", "T_BOOL_CONSTANT",
  "T_STRING", "T_IDENTIFIER", "','", "T_IFX", "';'", "'['", "']'", "'('",
  "')'", "'?'", "':'", "'{'", "'}'", "$accept", "program", "declarations",
  "declaration", "varDec", "varDecList", "varDecType", "varOnlyDec",
  "arrayDims", "$@1", "varInit", "type", "pointer", "constants", "funcDec",
  "funcOnlyDec", "funcName", "funcDef", "funcCall", "params", "paramList",
  "paramID", "args", "argList", "assignmentOp", "ternaryOpExpression",
  "expression", "assignmentExpression", "incDecExpression",
  "logicalExpression", "andExpression", "notExpression", "relExpression",
  "sumExpression", "prodExpression", "unaryExpression", "factor",
  "statement", "expressionStmt", "blockStmt", "stmtList", "selectionStmt",
  "iterationStmt", "$@2", "returnStmt", "breakStmt", "contStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    44,   310,    59,    91,    93,
      40,    41,    63,    58,   123,   125
};
# endif

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,  -108,  -108,  -108,  -108,  -108,  -108,    26,  -108,    -3,
     -24,     2,  -108,    -9,  -108,  -108,  -108,  -108,  -108,  -108,
     -40,    -5,  -108,     1,  -108,  -108,    17,  -108,    18,  -108,
    -108,    29,  -108,    44,   109,    49,    37,    37,    51,    48,
      63,    54,    67,    80,   135,    87,    98,  -108,  -108,  -108,
    -108,  -108,   157,  -108,    97,    86,    10,  -108,  -108,    96,
    -108,   112,   133,  -108,  -108,   103,   170,  -108,  -108,    18,
    -108,  -108,    91,  -108,  -108,  -108,  -108,  -108,   119,   121,
    -108,     3,  -108,  -108,   -35,   123,   122,   136,  -108,  -108,
    -108,  -108,     3,   135,   135,  -108,  -108,   163,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
      97,   109,   129,  -108,  -108,   135,   135,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,  -108,  -108,
     134,   109,    97,   143,  -108,    -3,   109,   -26,    15,   132,
     139,  -108,  -108,  -108,   133,  -108,   170,   170,    89,    89,
      89,    89,    89,    89,  -108,  -108,  -108,   121,  -108,   144,
    -108,    20,  -108,    18,  -108,   149,    97,  -108,   135,  -108,
     187,    18,  -108,  -108,  -108,    18,  -108,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    24,    20,    21,    22,    23,    25,     0,     2,     5,
       0,     0,     7,     0,    34,     1,     4,     6,    27,    36,
      13,     8,    10,    11,    12,    19,     0,    33,   107,    38,
      26,     0,    14,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      31,    32,    91,   104,     0,     0,     0,    93,   101,     0,
      60,    61,    69,    71,    73,    80,    83,    87,    90,   107,
      94,    95,     0,    96,    97,    98,    99,   100,     0,    13,
       9,    91,    62,    18,    57,    44,     0,    40,    43,    91,
      88,    89,     0,     0,     0,   113,   114,    91,   112,    72,
      66,    64,    50,    51,    52,    53,    54,    55,    67,    65,
      47,     0,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   105,
      17,     0,     0,     0,    35,     0,     0,     0,     0,     0,
      46,    49,    58,    92,    68,    70,    81,    82,    74,    75,
      76,    77,    78,    79,    84,    85,    86,     0,    63,     0,
      45,     0,    59,     0,   110,     0,     0,    16,     0,    42,
     108,     0,    39,    48,    56,     0,   111,   109
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   203,  -108,    19,  -108,   180,  -108,    57,  -108,
    -108,     0,   197,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,    55,  -108,  -108,   -38,    50,   -51,  -107,  -108,   -32,
     104,   -43,  -108,    77,    -8,   -31,  -108,   -49,   177,   208,
     153,  -108,  -108,  -108,  -108,  -108,  -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    55,    21,    22,    23,    32,   157,
      24,    56,    25,    57,    12,    13,    26,    14,    58,    86,
      87,    88,   139,   140,   111,    82,    59,    83,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   171,    75,    76,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,    99,    84,   112,   142,    90,    91,    18,   115,    11,
     102,   103,   104,   105,   106,    18,     1,   115,    31,    10,
     -37,    36,    37,    38,   158,    18,    15,   132,    10,   162,
       2,     3,     4,    17,    19,   163,     5,     1,    39,     6,
      36,    37,    40,   131,    41,    42,    43,    34,    27,   107,
      33,     2,     3,     4,   136,    28,    20,     5,   115,   141,
       6,   137,   138,    44,    79,    45,    46,    47,    48,    49,
      50,    51,    52,   145,    85,    53,   164,    35,    54,    84,
      78,   159,    28,    36,    37,    38,    47,    48,    49,    50,
      51,    89,   117,   118,   154,   155,   156,    54,    79,    84,
      36,    37,    38,    85,    84,    92,   117,   118,    93,   146,
     147,    95,    36,    37,   170,   173,   119,   120,   121,   122,
     123,   124,   176,    94,    96,    44,   177,    45,    46,    47,
      48,    49,    50,    51,    97,   161,    84,    53,    36,    37,
      54,   100,    44,   113,    45,    46,    47,    48,    49,    50,
      51,    97,   101,   114,    44,   115,   129,    54,    47,    48,
      49,    50,    51,    81,   102,   103,   104,   105,   106,    54,
     102,   103,   104,   105,   106,   125,   126,   116,   130,    31,
      44,   133,   127,   134,    47,    48,    49,    50,    51,    89,
     143,   135,   -15,   165,   166,    54,   148,   149,   150,   151,
     152,   153,   160,   107,   108,   109,   172,   168,   175,   107,
     108,   109,    16,    80,   167,    30,   169,   110,   174,   144,
      98,    29,   128
};

static const yytype_uint8 yycheck[] =
{
       0,    44,    34,    54,   111,    36,    37,     5,    43,     9,
       7,     8,     9,    10,    11,     5,    19,    43,    58,     0,
      60,     3,     4,     5,   131,     5,     0,    62,     9,   136,
      33,    34,    35,    57,    32,    61,    39,    19,    20,    42,
       3,     4,    24,    81,    26,    27,    28,    46,    57,    46,
      55,    33,    34,    35,    92,    64,    54,    39,    43,   110,
      42,    93,    94,    45,    54,    47,    48,    49,    50,    51,
      52,    53,    54,   116,    54,    57,    61,    60,    60,   111,
      51,   132,    64,     3,     4,     5,    49,    50,    51,    52,
      53,    54,     3,     4,   125,   126,   127,    60,    54,   131,
       3,     4,     5,    54,   136,    54,     3,     4,    60,   117,
     118,    57,     3,     4,   163,   166,    13,    14,    15,    16,
      17,    18,   171,    60,    57,    45,   175,    47,    48,    49,
      50,    51,    52,    53,    54,   135,   168,    57,     3,     4,
      60,    54,    45,    57,    47,    48,    49,    50,    51,    52,
      53,    54,    54,    57,    45,    43,    65,    60,    49,    50,
      51,    52,    53,    54,     7,     8,     9,    10,    11,    60,
       7,     8,     9,    10,    11,     5,     6,    44,    59,    58,
      45,    58,    12,    61,    49,    50,    51,    52,    53,    54,
      61,    55,    58,    61,    55,    60,   119,   120,   121,   122,
     123,   124,    59,    46,    47,    48,    57,    63,    21,    46,
      47,    48,     9,    33,   157,    18,   161,    60,   168,   115,
      43,    13,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    33,    34,    35,    39,    42,    67,    68,    69,
      70,    77,    80,    81,    83,     0,    68,    57,     5,    32,
      54,    71,    72,    73,    76,    78,    82,    57,    64,   105,
      78,    58,    74,    55,    46,    60,     3,     4,     5,    20,
      24,    26,    27,    28,    45,    47,    48,    49,    50,    51,
      52,    53,    54,    57,    60,    70,    77,    79,    84,    92,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   110,   111,   112,    51,    54,
      72,    54,    91,    93,    95,    54,    85,    86,    87,    54,
     101,   101,    54,    60,    60,    57,    57,    54,   104,    97,
      54,    54,     7,     8,     9,    10,    11,    46,    47,    48,
      60,    90,    92,    57,    57,    43,    44,     3,     4,    13,
      14,    15,    16,    17,    18,     5,     6,    12,   106,    65,
      59,    90,    62,    58,    61,    55,    90,    95,    95,    88,
      89,    92,    93,    61,    96,    97,   100,   100,    99,    99,
      99,    99,    99,    99,   101,   101,   101,    75,    93,    92,
      59,    77,    93,    61,    61,    61,    55,    74,    63,    87,
     103,   109,    57,    92,    91,    21,   103,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    69,    69,    70,    71,
      71,    72,    72,    73,    73,    75,    74,    74,    76,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    79,    79,
      79,    79,    79,    80,    80,    81,    82,    82,    83,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    91,    91,    92,    92,
      92,    92,    93,    93,    94,    94,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    99,    99,    99,   100,   100,   100,   100,   101,   101,
     101,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   105,   106,   106,   107,   107,
     109,   108,   110,   111,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     2,     3,
       1,     1,     1,     1,     2,     0,     5,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     5,     1,     1,     2,     5,
       1,     0,     4,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     5,     1,     3,     4,
       1,     1,     1,     3,     2,     2,     2,     2,     3,     1,
       3,     1,     2,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     3,     2,     0,     5,     7,
       0,     6,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 13:
#line 87 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].tbEntry)->data_type = strdup(curr_data_type);}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].tbEntry)->data_type = strdup(curr_data_type);}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-1].dval) < 1){printf("\nLine : %d ERROR : Arrays can't have dimension lesser than 1\n\n", yylineno);}}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 91 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-1].dval) < 1){printf("\nLine : %d ERROR : Arrays can't have dimension lesser than 1\n\n", yylineno);}}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 96 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("INT");}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 97 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("FLOAT");}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 98 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("DOUBLE");}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 99 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("CHAR");}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 100 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("VOID");}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 101 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("BOOL");}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 108 "parser.y" /* yacc.c:1646  */
    {printf("\n %f \n", (yyvsp[0].dval)); }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 109 "parser.y" /* yacc.c:1646  */
    {printf("\n %f \n", (yyvsp[0].dval)); }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 110 "parser.y" /* yacc.c:1646  */
    {printf("\n %f \n", (yyvsp[0].dval)); }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 112 "parser.y" /* yacc.c:1646  */
    {printf("\n %s \n", (yyvsp[0].str)); }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 121 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].tbEntry)->lexem, scope);}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 124 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[-4].tbEntry)->lexem, scope);}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 133 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].tbEntry)->lexem, scope);}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 134 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[-2].tbEntry)->lexem, scope);}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 154 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[-2].tbEntry)->lexem, scope);}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 155 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[-2].tbEntry)->lexem, scope);}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 162 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[-2].tbEntry)->lexem, scope);}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 165 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].tbEntry)->lexem, scope);}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 166 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[-1].tbEntry)->lexem, scope);}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 167 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].tbEntry)->lexem, scope);}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 168 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[-1].tbEntry)->lexem, scope);}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 189 "parser.y" /* yacc.c:1646  */
    { printf("\n+\n"); }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 190 "parser.y" /* yacc.c:1646  */
    {printf("\n-\n"); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 193 "parser.y" /* yacc.c:1646  */
    {printf("\n*\n"); }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 194 "parser.y" /* yacc.c:1646  */
    {printf("\n / \n"); }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 202 "parser.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].tbEntry)->lexem, scope); printf("\nid=%s\n", (yyvsp[0].tbEntry)->lexem);}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 227 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 227 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 229 "parser.y" /* yacc.c:1646  */
    {
                          if(!is_loop)
                          {
                            printf("Line : %d ERROR : break outside loop\n", yylineno);
                          }
                        }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 236 "parser.y" /* yacc.c:1646  */
    {if(!is_loop)
                          {
                            printf("Line : %d ERROR : continue outside loop\n", yylineno);
                          }
                          }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1705 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 286 "parser.y" /* yacc.c:1906  */



void display_symbolTable()
{
    Display(SymbolTable);
}

int check_variable(symtab_t* table, char* var){
  int found = 0;
  if(table->head == NULL)
    return 0;
  else{
    node_t* temp = table->head;
    while(temp != NULL){
      if(strcmp(temp->lexem, var) == 0 && (temp->data_type != NULL)){
        found = 1;
        break;
      }
      temp = temp->next;
    }
  }
  return found;
}

void checkScope(char* var, int curr_scope){
  int var_node_exists = check_variable(SymbolTable, var);
  
  if(!var_node_exists){
      //yyerror("Variable not declared");
      printf("\nLine : %d ERROR : Variable '%s' not declared\n", yylineno, var);
  }
  else{
    node_t* temp = exists(SymbolTable, var, curr_scope);
    if(temp && temp->data_type == NULL && temp->scope > curr_scope){
        //yyerror("Variable out of scope");
        printf("\nLine : %d ERROR : Variable '%s' out of scope\n", yylineno, var);
    }
  }
}

int main(int argc, char* argv[])
{
    SymbolTable = (symtab_t*)malloc(sizeof(symtab_t));
    SymbolTable->head = NULL;

    yyin = fopen(argv[1], "r");
    if(!yyparse())
    {
        printf("\nParsing Complete\n");
        display_symbolTable();
    }
    else
    {
        printf("\nParsing Failed\n");
    }
    fclose(yyin);
    return 0;
}

int yyerror(char* err)
{
    printf("Line no: %d Error message: %s Token: %s\n", yylineno, err, yytext);
    return 0;
} 
