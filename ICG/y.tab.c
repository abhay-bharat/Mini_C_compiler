/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    //header files
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include"symbol_table.h"


    extern int scope, columnNo;
    //initialise symbol table
    symtab_t* SymbolTable = NULL;
    symtab_t* ConstantTable = NULL;
    int yyerror(char* err);
    int yylex(void);
    extern FILE* yyin;
    extern int yylineno;
    extern char* yytext;
    int is_loop = 0;
    //keep track of data type of identifiers
    char* curr_data_type;

    //space variable to beautify the syntax tree output
    int space = 0;


#line 96 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    T_STRING = 307,
    T_BOOL_CONSTANT = 308,
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
#define T_STRING 307
#define T_BOOL_CONSTANT 308
#define T_IDENTIFIER 309
#define T_IFX 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

    int ival;
    char* str;
    node_t *tbEntry;
    double dval;

#line 265 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      60,    61,     2,     2,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    63,     2,     2,     2,     2,
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
       0,    75,    75,    76,    78,    79,    81,    82,    84,    86,
      87,    90,    91,    94,    95,    97,    97,    98,   100,   102,
     103,   104,   105,   106,   107,   108,   111,   112,   115,   116,
     117,   118,   119,   122,   123,   126,   127,   128,   130,   131,
     134,   135,   137,   138,   140,   141,   144,   145,   147,   148,
     151,   152,   153,   154,   155,   156,   161,   161,   164,   165,
     173,   174,   175,   176,   179,   179,   180,   182,   182,   183,
     185,   185,   186,   188,   188,   189,   189,   190,   190,   191,
     191,   192,   192,   193,   193,   194,   197,   197,   198,   198,
     199,   201,   201,   202,   202,   203,   204,   206,   206,   207,
     207,   208,   210,   211,   212,   212,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   224,   225,   227,   229,   230,
     232,   233,   235,   235,   236,   237,   244
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
  "T_HEX_CONSTANT", "T_DEC_CONSTANT", "T_INT_CONSTANT", "T_STRING",
  "T_BOOL_CONSTANT", "T_IDENTIFIER", "','", "T_IFX", "';'", "'['", "']'",
  "'('", "')'", "'{'", "'}'", "$accept", "program", "declarations",
  "declaration", "varDec", "varDecList", "varDecType", "varOnlyDec",
  "arrayDims", "$@1", "varInit", "type", "pointer", "constants", "funcDec",
  "funcOnlyDec", "funcName", "funcDef", "funcCall", "params", "paramList",
  "paramID", "args", "argList", "assignmentOp", "expression", "$@2",
  "incDecExpression", "logicalExpression", "$@3", "andExpression", "$@4",
  "notExpression", "$@5", "relExpression", "$@6", "$@7", "$@8", "$@9",
  "$@10", "$@11", "sumExpression", "$@12", "$@13", "prodExpression",
  "$@14", "$@15", "unaryExpression", "$@16", "$@17", "factor", "$@18",
  "statement", "expressionStmt", "blockStmt", "stmtList", "selectionStmt",
  "iterationStmt", "$@19", "returnStmt", "breakStmt", "contStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    44,   310,    59,    91,    93,
      40,    41,   123,   125
};
# endif

#define YYPACT_NINF (-142)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-120)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     149,  -142,  -142,  -142,  -142,  -142,  -142,     9,  -142,   149,
     -30,    24,  -142,   -36,  -142,  -142,  -142,  -142,  -142,  -142,
      53,   -21,  -142,   -16,  -142,  -142,    -9,  -142,    13,  -142,
    -142,     3,  -142,    11,   106,    23,  -142,  -142,    21,    29,
      28,    35,    87,  -142,    44,    47,    -3,  -142,   106,    55,
      15,  -142,    64,  -142,    85,    86,  -142,  -142,   189,    91,
    -142,  -142,   126,    13,  -142,  -142,    66,  -142,  -142,  -142,
    -142,  -142,    72,    78,  -142,   148,  -142,    80,    76,    88,
    -142,    46,    46,     8,     8,  -142,  -142,  -142,     8,  -142,
    -142,  -142,  -142,    79,   154,    81,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
      46,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,    90,
      93,  -142,   149,  -142,  -142,  -142,   -25,   -19,  -142,    84,
      94,  -142,  -142,  -142,  -142,  -142,  -142,  -142,   106,  -142,
       8,     8,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,  -142,    78,  -142,    20,    60,  -142,    89,   106,
    -142,    86,  -142,    91,    91,   112,   112,   112,   112,   112,
     112,  -142,  -142,  -142,  -142,   129,    60,  -142,  -142,    60,
    -142,  -142
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    24,    20,    21,    22,    23,    25,     0,     2,     5,
       0,     0,     7,     0,    34,     1,     4,     6,    27,    36,
      13,     8,    10,    11,    12,    19,     0,    33,   104,    38,
      26,     0,    14,     0,   104,    41,    97,    99,     0,     0,
       0,     0,   104,    70,     0,     0,   102,   116,   104,     0,
       0,   113,     0,    58,    59,    66,    69,    72,    85,    90,
      96,   101,     0,   104,   106,   107,     0,   108,   109,   110,
     111,   112,     0,    13,     9,   102,    18,    44,     0,    40,
      43,   104,   104,   104,   104,   125,   126,   124,   104,    62,
      60,    63,    61,   104,     0,     0,   114,   115,    64,    67,
      86,    88,    73,    75,    77,    79,    81,    83,    91,    93,
     104,    28,    29,    30,    32,    31,   105,   118,   117,    17,
       0,    35,     0,   102,    98,   100,     0,     0,    71,     0,
      46,    49,    50,    51,    52,    53,    54,    55,   104,   103,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,    95,     0,    45,     0,   104,   122,     0,   104,
      57,    65,    68,    87,    89,    74,    76,    78,    80,    82,
      84,    92,    94,    16,    42,   120,   104,    39,    48,   104,
     123,   121
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,   158,  -142,    19,  -142,   147,  -142,    32,  -142,
    -142,     1,   163,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,    31,  -142,  -142,  -142,   -34,  -142,  -142,   -61,  -142,
      49,  -142,   -75,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,    25,  -142,  -142,   -24,  -142,  -142,   -79,  -142,  -142,
    -142,  -142,  -141,   145,   177,   134,  -142,  -142,  -142,  -142,
    -142,  -142
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    49,    21,    22,    23,    32,   153,
      24,    50,    25,   116,    12,    13,    26,    14,    51,    78,
      79,    80,   129,   130,   138,    52,    94,    53,    54,   140,
      55,   141,    56,    88,    57,   144,   145,   146,   147,   148,
     149,    58,   142,   143,    59,   150,   151,    60,    81,    82,
      61,    62,    63,    64,    65,    66,    67,    68,   176,    69,
      70,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    11,   124,   125,   -56,   -56,   -56,   -56,   -56,    15,
      11,    36,    37,   128,    95,   175,    36,    37,    98,    10,
      18,    27,   126,   127,    98,    18,    28,    17,    10,    18,
      34,   152,     1,    38,    33,   180,   156,    39,   181,    40,
      41,    42,   157,   -56,    91,    92,     2,     3,     4,    36,
      37,    35,     5,    43,    72,     6,    19,    93,    43,   131,
      44,    45,   123,    36,    37,    73,   162,    46,    48,    73,
      47,   171,   172,    48,    77,    28,  -119,    77,    20,     1,
      38,    83,    36,    37,    39,    85,    40,    41,    42,    84,
      36,    37,    86,     2,     3,     4,   108,   109,    89,     5,
     123,    90,     6,   110,   160,    43,    48,    44,    45,    36,
      37,    31,    96,   -37,    46,   100,   101,    47,   163,   164,
      48,    97,    28,   155,    43,   178,    44,    45,    98,   118,
      99,   119,    43,    75,    44,    45,    31,   121,   120,    48,
     -47,    75,   139,   122,    47,   158,   177,    48,   -15,   159,
     179,    43,   154,    44,    45,   -56,   -56,   -56,   -56,   -56,
      75,   132,   133,   134,   135,   136,    48,    16,     1,   165,
     166,   167,   168,   169,   170,   111,   112,   113,   114,   115,
      74,    30,     2,     3,     4,   173,   174,    87,     5,   161,
      29,     6,   100,   101,   -56,    91,    92,   117,     0,     0,
     137,     0,   102,   103,   104,   105,   106,   107
};

static const yytype_int16 yycheck[] =
{
      34,     0,    81,    82,     7,     8,     9,    10,    11,     0,
       9,     3,     4,    88,    48,   156,     3,     4,    43,     0,
       5,    57,    83,    84,    43,     5,    62,    57,     9,     5,
      46,   110,    19,    20,    55,   176,    61,    24,   179,    26,
      27,    28,    61,    46,    47,    48,    33,    34,    35,     3,
       4,    60,    39,    45,    51,    42,    32,    60,    45,    93,
      47,    48,    54,     3,     4,    54,   141,    54,    60,    54,
      57,   150,   151,    60,    54,    62,    63,    54,    54,    19,
      20,    60,     3,     4,    24,    57,    26,    27,    28,    60,
       3,     4,    57,    33,    34,    35,     5,     6,    54,    39,
      54,    54,    42,    12,   138,    45,    60,    47,    48,     3,
       4,    58,    57,    60,    54,     3,     4,    57,   142,   143,
      60,    57,    62,   122,    45,   159,    47,    48,    43,    63,
      44,    59,    45,    54,    47,    48,    58,    61,    58,    60,
      61,    54,    61,    55,    57,    61,    57,    60,    58,    55,
      21,    45,    59,    47,    48,     7,     8,     9,    10,    11,
      54,     7,     8,     9,    10,    11,    60,     9,    19,   144,
     145,   146,   147,   148,   149,    49,    50,    51,    52,    53,
      33,    18,    33,    34,    35,   153,   155,    42,    39,   140,
      13,    42,     3,     4,    46,    47,    48,    63,    -1,    -1,
      46,    -1,    13,    14,    15,    16,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    33,    34,    35,    39,    42,    65,    66,    67,
      68,    75,    78,    79,    81,     0,    66,    57,     5,    32,
      54,    69,    70,    71,    74,    76,    80,    57,    62,   118,
      76,    58,    72,    55,    46,    60,     3,     4,    20,    24,
      26,    27,    28,    45,    47,    48,    54,    57,    60,    68,
      75,    82,    89,    91,    92,    94,    96,    98,   105,   108,
     111,   114,   115,   116,   117,   118,   119,   120,   121,   123,
     124,   125,    51,    54,    70,    54,    89,    54,    83,    84,
      85,   112,   113,    60,    60,    57,    57,   117,    97,    54,
      54,    47,    48,    60,    90,    89,    57,    57,    43,    44,
       3,     4,    13,    14,    15,    16,    17,    18,     5,     6,
      12,    49,    50,    51,    52,    53,    77,   119,    63,    59,
      58,    61,    55,    54,   111,   111,    92,    92,    96,    86,
      87,    89,     7,     8,     9,    10,    11,    46,    88,    61,
      93,    95,   106,   107,    99,   100,   101,   102,   103,   104,
     109,   110,   111,    73,    59,    75,    61,    61,    61,    55,
      89,    94,    96,   108,   108,   105,   105,   105,   105,   105,
     105,   111,   111,    72,    85,   116,   122,    57,    89,    21,
     116,   116
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    73,    72,    72,    74,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    78,    78,    79,    80,    80,    81,    82,
      83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    88,    88,    88,    90,    89,    89,    89,
      91,    91,    91,    91,    93,    92,    92,    95,    94,    94,
      97,    96,    96,    99,    98,   100,    98,   101,    98,   102,
      98,   103,    98,   104,    98,    98,   106,   105,   107,   105,
     105,   109,   108,   110,   108,   108,   108,   112,   111,   113,
     111,   111,   114,   114,   115,   114,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   118,   119,   119,
     120,   120,   122,   121,   123,   124,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     2,     3,
       1,     1,     1,     1,     2,     0,     5,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     5,     1,     1,     2,     5,
       1,     0,     4,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     1,
       2,     2,     2,     2,     0,     4,     1,     0,     4,     1,
       0,     3,     1,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     1,     0,     4,     0,     4,
       1,     0,     4,     0,     4,     3,     1,     0,     3,     0,
       3,     1,     1,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     3,     2,     0,
       5,     7,     0,     6,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 94 "parser.y"
                           {(yyvsp[0].tbEntry)->data_type = strdup(curr_data_type); (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1601 "y.tab.c"
    break;

  case 14:
#line 95 "parser.y"
                                     {(yyvsp[-1].tbEntry)->data_type = strdup(curr_data_type); (yyval.str) = (yyvsp[-1].tbEntry)->data_type;}
#line 1607 "y.tab.c"
    break;

  case 15:
#line 97 "parser.y"
                                   { if((yyvsp[-1].dval) < 1){printf("\nLine : %d ERROR : Arrays can't have dimension lesser than 1\n\n", yylineno);}}
#line 1613 "y.tab.c"
    break;

  case 17:
#line 98 "parser.y"
                                   { if((yyvsp[-1].dval) < 1){printf("\nLine : %d ERROR : Arrays can't have dimension lesser than 1\n\n", yylineno);}}
#line 1619 "y.tab.c"
    break;

  case 18:
#line 100 "parser.y"
                                           {typeCheck((yyvsp[-2].str), (yyvsp[0].str));}
#line 1625 "y.tab.c"
    break;

  case 20:
#line 103 "parser.y"
                {curr_data_type = strdup("INT");}
#line 1631 "y.tab.c"
    break;

  case 21:
#line 104 "parser.y"
                  {curr_data_type = strdup("FLOAT");}
#line 1637 "y.tab.c"
    break;

  case 22:
#line 105 "parser.y"
                   {curr_data_type = strdup("DOUBLE");}
#line 1643 "y.tab.c"
    break;

  case 23:
#line 106 "parser.y"
                 {curr_data_type = strdup("CHAR");}
#line 1649 "y.tab.c"
    break;

  case 24:
#line 107 "parser.y"
                 {curr_data_type = strdup("VOID");}
#line 1655 "y.tab.c"
    break;

  case 25:
#line 108 "parser.y"
                 {curr_data_type = strdup("BOOL");}
#line 1661 "y.tab.c"
    break;

  case 28:
#line 115 "parser.y"
                              {printf("%f \n", (yyvsp[0].dval));  (yyval.str) = strdup("HEX");}
#line 1667 "y.tab.c"
    break;

  case 29:
#line 116 "parser.y"
                              {printf("%f \n", (yyvsp[0].dval)); (yyval.str) = strdup("FLOAT");}
#line 1673 "y.tab.c"
    break;

  case 30:
#line 117 "parser.y"
                              {printf("%d \n", (int)(yyvsp[0].dval)); (yyval.str) = strdup("INT");}
#line 1679 "y.tab.c"
    break;

  case 31:
#line 118 "parser.y"
                              {printf("%s \n", (yyvsp[0].str)); (yyval.str) = strdup("BOOL");}
#line 1685 "y.tab.c"
    break;

  case 32:
#line 119 "parser.y"
                              {printf("%s \n", (yyvsp[0].str)); (yyval.str) = strdup("CHAR");}
#line 1691 "y.tab.c"
    break;

  case 37:
#line 128 "parser.y"
                            {checkScope((yyvsp[0].tbEntry)->lexem, scope);}
#line 1697 "y.tab.c"
    break;

  case 39:
#line 131 "parser.y"
                                          {checkScope((yyvsp[-4].tbEntry)->lexem, scope);}
#line 1703 "y.tab.c"
    break;

  case 44:
#line 140 "parser.y"
                        {checkScope((yyvsp[0].tbEntry)->lexem, scope);}
#line 1709 "y.tab.c"
    break;

  case 45:
#line 141 "parser.y"
                               {checkScope((yyvsp[-2].tbEntry)->lexem, scope);}
#line 1715 "y.tab.c"
    break;

  case 55:
#line 156 "parser.y"
                        { for(int i = 0; i < space; ++i)printf("\t"); printf("=\n"); ++space; }
#line 1721 "y.tab.c"
    break;

  case 56:
#line 161 "parser.y"
                          {if(checkScope((yyvsp[0].tbEntry)->lexem, scope) == 0){return -1;}
                          for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tid=%s\n", (yyvsp[0].tbEntry)->lexem);}
#line 1728 "y.tab.c"
    break;

  case 57:
#line 163 "parser.y"
                                      {!typeCheck((yyvsp[-3].tbEntry)->data_type,(yyvsp[0].str));(yyval.str) = (yyvsp[-3].tbEntry)->data_type;}
#line 1734 "y.tab.c"
    break;

  case 58:
#line 164 "parser.y"
                              {(yyval.str) = (yyvsp[0].str);}
#line 1740 "y.tab.c"
    break;

  case 59:
#line 165 "parser.y"
                               {(yyval.str) = (yyvsp[0].str);}
#line 1746 "y.tab.c"
    break;

  case 60:
#line 173 "parser.y"
                                            {checkScope((yyvsp[0].tbEntry)->lexem, scope); (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1752 "y.tab.c"
    break;

  case 61:
#line 174 "parser.y"
                                            {checkScope((yyvsp[-1].tbEntry)->lexem, scope); (yyval.str) = (yyvsp[-1].tbEntry)->data_type;}
#line 1758 "y.tab.c"
    break;

  case 62:
#line 175 "parser.y"
                                            {checkScope((yyvsp[0].tbEntry)->lexem, scope); (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1764 "y.tab.c"
    break;

  case 63:
#line 176 "parser.y"
                                            {checkScope((yyvsp[-1].tbEntry)->lexem, scope); (yyval.str) = (yyvsp[-1].tbEntry)->data_type;}
#line 1770 "y.tab.c"
    break;

  case 64:
#line 179 "parser.y"
                                              {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("|| \n"); }
#line 1776 "y.tab.c"
    break;

  case 65:
#line 179 "parser.y"
                                                                                                                                     {(yyval.str) = (yyvsp[-3].str);}
#line 1782 "y.tab.c"
    break;

  case 66:
#line 180 "parser.y"
                                   {(yyval.str) = (yyvsp[0].str);}
#line 1788 "y.tab.c"
    break;

  case 67:
#line 182 "parser.y"
                                       {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("&& \n"); }
#line 1794 "y.tab.c"
    break;

  case 68:
#line 182 "parser.y"
                                                                                                                               {(yyval.str) = (yyvsp[-3].str);}
#line 1800 "y.tab.c"
    break;

  case 69:
#line 183 "parser.y"
                              {(yyval.str) = (yyvsp[0].str);}
#line 1806 "y.tab.c"
    break;

  case 70:
#line 185 "parser.y"
                      {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("^ \n"); }
#line 1812 "y.tab.c"
    break;

  case 71:
#line 185 "parser.y"
                                                                                                             {(yyval.str) = (yyvsp[0].str);}
#line 1818 "y.tab.c"
    break;

  case 72:
#line 186 "parser.y"
                               {(yyval.str) = (yyvsp[0].str);}
#line 1824 "y.tab.c"
    break;

  case 73:
#line 188 "parser.y"
                                              {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("> \n"); }
#line 1830 "y.tab.c"
    break;

  case 74:
#line 188 "parser.y"
                                                                                                                                    {typeCheck((yyvsp[-3].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-3].str);}
#line 1836 "y.tab.c"
    break;

  case 75:
#line 189 "parser.y"
                                              {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("< \n"); }
#line 1842 "y.tab.c"
    break;

  case 76:
#line 189 "parser.y"
                                                                                                                                    {typeCheck((yyvsp[-3].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-3].str);}
#line 1848 "y.tab.c"
    break;

  case 77:
#line 190 "parser.y"
                                            {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("<= \n"); }
#line 1854 "y.tab.c"
    break;

  case 78:
#line 190 "parser.y"
                                                                                                                                   {typeCheck((yyvsp[-3].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-3].str);}
#line 1860 "y.tab.c"
    break;

  case 79:
#line 191 "parser.y"
                                             {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf(">= \n"); }
#line 1866 "y.tab.c"
    break;

  case 80:
#line 191 "parser.y"
                                                                                                                                     {typeCheck((yyvsp[-3].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-3].str);}
#line 1872 "y.tab.c"
    break;

  case 81:
#line 192 "parser.y"
                                         {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("!= \n"); }
#line 1878 "y.tab.c"
    break;

  case 82:
#line 192 "parser.y"
                                                                                                                                 {typeCheck((yyvsp[-3].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-3].str);}
#line 1884 "y.tab.c"
    break;

  case 83:
#line 193 "parser.y"
                                        {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("== \n"); }
#line 1890 "y.tab.c"
    break;

  case 84:
#line 193 "parser.y"
                                                                                                                                {typeCheck((yyvsp[-3].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-3].str);}
#line 1896 "y.tab.c"
    break;

  case 85:
#line 194 "parser.y"
                                {(yyval.str) = (yyvsp[0].str);}
#line 1902 "y.tab.c"
    break;

  case 86:
#line 197 "parser.y"
                                    { for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("+\n"); }
#line 1908 "y.tab.c"
    break;

  case 87:
#line 197 "parser.y"
                                                                                                                            {typeCheck((yyvsp[-3].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-3].str);}
#line 1914 "y.tab.c"
    break;

  case 88:
#line 198 "parser.y"
                                         {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("-\n"); }
#line 1920 "y.tab.c"
    break;

  case 89:
#line 198 "parser.y"
                                                                                                                                {typeCheck((yyvsp[-3].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-3].str);}
#line 1926 "y.tab.c"
    break;

  case 90:
#line 199 "parser.y"
                                {(yyval.str) = (yyvsp[0].str);}
#line 1932 "y.tab.c"
    break;

  case 91:
#line 201 "parser.y"
                                           {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("*\n"); }
#line 1938 "y.tab.c"
    break;

  case 92:
#line 201 "parser.y"
                                                                                                                                   {typeCheck((yyvsp[-3].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-3].str);}
#line 1944 "y.tab.c"
    break;

  case 93:
#line 202 "parser.y"
                                         {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("/\n"); }
#line 1950 "y.tab.c"
    break;

  case 94:
#line 202 "parser.y"
                                                                                                                                 {typeCheck((yyvsp[-3].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-3].str);}
#line 1956 "y.tab.c"
    break;

  case 95:
#line 203 "parser.y"
                                                      {typeCheck((yyvsp[-2].str), (yyvsp[0].str));(yyval.str) = (yyvsp[-2].str);}
#line 1962 "y.tab.c"
    break;

  case 96:
#line 204 "parser.y"
                                 {(yyval.str) = (yyvsp[0].str);}
#line 1968 "y.tab.c"
    break;

  case 97:
#line 206 "parser.y"
                        {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("+ \n");}
#line 1974 "y.tab.c"
    break;

  case 98:
#line 206 "parser.y"
                                                                                                                {(yyval.str) = (yyvsp[0].str);}
#line 1980 "y.tab.c"
    break;

  case 99:
#line 207 "parser.y"
                             {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("- \n");}
#line 1986 "y.tab.c"
    break;

  case 100:
#line 207 "parser.y"
                                                                                                                      {(yyval.str) = (yyvsp[0].str);}
#line 1992 "y.tab.c"
    break;

  case 101:
#line 208 "parser.y"
                          {(yyval.str) = (yyvsp[0].str);}
#line 1998 "y.tab.c"
    break;

  case 102:
#line 210 "parser.y"
                       {if(checkScope((yyvsp[0].tbEntry)->lexem, scope) == 0){return -1;}; for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tid=%s\n", (yyvsp[0].tbEntry)->lexem); (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 2004 "y.tab.c"
    break;

  case 103:
#line 211 "parser.y"
                              {(yyval.str) = (yyvsp[-1].str);}
#line 2010 "y.tab.c"
    break;

  case 104:
#line 212 "parser.y"
          {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tconstant = "); }
#line 2016 "y.tab.c"
    break;

  case 105:
#line 212 "parser.y"
                                                                                                      {(yyval.str) = (yyvsp[0].str);}
#line 2022 "y.tab.c"
    break;

  case 122:
#line 235 "parser.y"
                                                  {is_loop = 1;}
#line 2028 "y.tab.c"
    break;

  case 123:
#line 235 "parser.y"
                                                                           {is_loop = 0;}
#line 2034 "y.tab.c"
    break;

  case 125:
#line 237 "parser.y"
                        {
                          if(!is_loop)
                          {
                            printf("Line : %d ERROR : break outside loop\n", yylineno);
                          }
                        }
#line 2045 "y.tab.c"
    break;

  case 126:
#line 244 "parser.y"
                          {if(!is_loop)
                          {
                            printf("Line : %d ERROR : continue outside loop\n", yylineno);
                          }
                          }
#line 2055 "y.tab.c"
    break;


#line 2059 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 251 "parser.y"



void display_symbolTable()
{
    Display(SymbolTable);
}

int typeCheck(char *type1, char *type2){
	
  //printf("types: %s %s\n", a, b);
	if(strcmp(type1,type2)!=0){
		printf("\nLine : %d Type Mismatch: Performing operation on types %s and %s\n", yylineno, type1, type2);
		exit(0);
	}

	else 
		return 1;
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

int checkScope(char* var, int curr_scope){
  int var_node_exists = check_variable(SymbolTable, var);
  
  if(!var_node_exists){
      //yyerror("Variable not declared");
      printf("\nLine : %d ERROR : Variable '%s' not declared\n", yylineno, var);
      return 0;
  }
  else{
    node_t* temp = exists(SymbolTable, var, curr_scope);
    if(temp && temp->data_type == NULL && temp->scope > curr_scope){
        ("Variable out of scope");
        printf("\nLine : %d ERROR : Variable '%s' out of scope\n", yylineno, var);
        return 0;
    }
  }
  return 1;
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
    printf("Line no: %d Error message: %s\n", yylineno, err);
    return 0;
} 
