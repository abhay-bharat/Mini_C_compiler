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
    #include<limits.h>
    #include<ctype.h>
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
    int is_array = 0;
    //keep track of data type of identifiers
    char* curr_data_type;
    int is_declaration = 0;

    char ICG_stack[100][20];
    int ICG_top = 0;

    double ICG_value_stack[100];
    int ICG_value_top = 0;

    int label_stack[10];
    int label_top = 1;

    int temp_var_num = 0;
    int inst_line_num = 0;
    int dec_label = 0;
    double val_assign;
    int loop_constants[2];
    int temporary = 0;

    FILE *ICG;


    void push_ICG(char* text);

    void gencode();
    void gencode_unary();
    void gencode_if();
    void gencode_if_if();
    void gencode_if_else();
    void gencode_while();
    void gencode_while_block();
    void gencode_array(char* data_type);
    void gencode_function(char *lexeme);

    //space variable to beautify the syntax tree output
    int space = 0;


#line 131 "y.tab.c"

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
#line 63 "parser.y"

    int ival;
    char* str;
    node_t *tbEntry;
    double dval;

#line 300 "y.tab.c"

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
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

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
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   111,   113,   114,   116,   117,   119,   121,
     122,   125,   126,   129,   130,   132,   135,   135,   138,   139,
     140,   141,   142,   143,   144,   147,   148,   151,   152,   153,
     154,   155,   158,   159,   162,   163,   164,   166,   167,   170,
     171,   173,   174,   176,   177,   180,   181,   183,   184,   187,
     188,   189,   190,   191,   192,   197,   197,   201,   202,   210,
     211,   212,   213,   216,   216,   217,   219,   219,   220,   222,
     222,   223,   225,   225,   226,   226,   227,   227,   228,   228,
     229,   229,   230,   230,   231,   234,   234,   235,   235,   236,
     238,   238,   239,   239,   240,   240,   241,   243,   243,   244,
     244,   245,   247,   248,   249,   249,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   261,   262,   264,   266,   267,
     273,   273,   275,   275,   276,   279,   279,   280,   281,   290
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
  "arrayDims", "varInit", "$@1", "type", "pointer", "constants", "funcDec",
  "funcOnlyDec", "funcName", "funcDef", "funcCall", "params", "paramList",
  "paramID", "args", "argList", "assignmentOp", "expression", "$@2",
  "incDecExpression", "logicalExpression", "$@3", "andExpression", "$@4",
  "notExpression", "$@5", "relExpression", "$@6", "$@7", "$@8", "$@9",
  "$@10", "$@11", "sumExpression", "$@12", "$@13", "prodExpression",
  "$@14", "$@15", "$@16", "unaryExpression", "$@17", "$@18", "factor",
  "$@19", "statement", "expressionStmt", "blockStmt", "stmtList",
  "selectionStmt", "$@20", "else", "$@21", "iterationStmt", "$@22",
  "returnStmt", "breakStmt", "contStmt", YY_NULLPTR
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

#define YYPACT_NINF (-167)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     153,  -167,  -167,  -167,  -167,  -167,  -167,    12,  -167,   153,
     -38,     8,  -167,   -37,  -167,  -167,  -167,  -167,  -167,  -167,
      38,   -19,  -167,     7,  -167,  -167,   -10,  -167,  -167,  -167,
    -167,    14,  -167,     3,  -167,    35,     4,    45,    37,  -167,
      89,    47,    46,    53,  -167,  -167,  -167,    50,    51,    56,
      59,    78,  -167,    65,    67,   137,  -167,    89,  -167,    71,
       0,  -167,    72,  -167,    79,    83,  -167,  -167,   160,    36,
    -167,  -167,   149,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,   143,  -167,    74,  -167,   153,    23,    23,    30,
      30,  -167,  -167,  -167,    30,  -167,  -167,  -167,  -167,    70,
     148,    80,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,     5,  -167,  -167,  -167,   -26,   -14,
    -167,    81,    84,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
      89,  -167,    30,    30,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,  -167,  -167,  -167,   103,    89,
    -167,    83,  -167,    36,    36,    18,    18,    18,    18,    18,
      18,  -167,  -167,  -167,   100,    52,  -167,  -167,   119,  -167,
    -167,  -167,    52,  -167
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    23,    19,    20,    21,    22,    24,     0,     2,     5,
       0,     0,     7,     0,    33,     1,     4,     6,    26,    35,
      13,     8,    10,    11,    12,    18,     0,    32,   119,    37,
      25,     0,    14,     0,    16,    40,   104,     0,    13,     9,
     104,    43,     0,    39,    42,    97,    99,     0,     0,     0,
       0,   104,    69,     0,     0,   102,   116,   104,   117,     0,
       0,   113,     0,    57,    58,    65,    68,    71,    84,    89,
      96,   101,     0,   118,   106,   107,   108,   109,   110,   111,
     112,    15,   102,    17,     0,    34,     0,   104,   104,   104,
     104,   128,   129,   127,   104,    61,    59,    62,    60,   104,
       0,     0,   114,   115,    63,    66,    85,    87,    72,    74,
      76,    78,    80,    82,    90,    92,    94,    27,    28,    29,
      31,    30,   105,    44,     0,   102,    98,   100,     0,     0,
      70,     0,    45,    48,    49,    50,    51,    52,    53,    54,
     104,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,    41,   120,   125,     0,   104,
      56,    64,    67,    86,    88,    73,    75,    77,    79,    81,
      83,    91,    93,    95,     0,   104,    38,    47,   124,   126,
     122,   121,   104,   123
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,   162,  -167,     6,  -167,   146,  -167,  -167,  -167,
    -167,     2,   163,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,    58,  -167,  -167,  -167,   -39,  -167,  -167,   -45,  -167,
      54,  -167,   -80,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,    19,  -167,  -167,   -42,  -167,  -167,  -167,   -84,  -167,
    -167,  -167,  -167,  -166,   129,   -13,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    59,    21,    22,    23,    32,    24,
      40,    60,    25,   122,    12,    13,    26,    14,    61,    42,
      43,    44,   131,   132,   140,    62,   100,    63,    64,   142,
      65,   143,    66,    94,    67,   146,   147,   148,   149,   150,
     151,    68,   144,   145,    69,   152,   153,   154,    70,    87,
      88,    71,    72,    73,    74,    75,    36,    76,   174,   181,
     182,    77,   175,    78,    79,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    83,    11,   126,   127,    18,    10,    45,    46,   179,
      18,    11,    15,    18,   130,    10,   183,   104,   101,    17,
      27,   106,   107,     1,    47,    28,    45,    46,    48,   104,
      49,    50,    51,    45,    46,   156,    33,     2,     3,     4,
      19,   114,   115,     5,   128,   129,     6,   157,   116,    52,
      35,    53,    54,    34,    38,    45,    46,    38,    55,    41,
     133,    56,    20,   162,    57,    37,    28,    58,   171,   172,
     173,     1,    47,    45,    46,    52,    48,   125,    49,    50,
      51,    45,    46,    57,   125,     2,     3,     4,   124,    41,
      57,     5,    45,    46,     6,    31,    31,    52,   -36,    53,
      54,   160,   163,   164,    81,    84,    55,    85,    86,    56,
      89,    90,    57,    91,    28,    52,    92,    53,    54,    95,
     177,    96,   104,    52,    82,    53,    54,   105,   102,   103,
      57,   -46,    82,   123,    52,    56,    53,    54,    57,   159,
     180,   141,   158,    82,   -55,   -55,   -55,   -55,   -55,    57,
     -55,   -55,   -55,   -55,   -55,   134,   135,   136,   137,   138,
     176,   178,    28,   106,   107,   165,   166,   167,   168,   169,
     170,    16,     1,   108,   109,   110,   111,   112,   113,    39,
      93,    30,   155,   -55,    97,    98,     2,     3,     4,   -55,
      97,    98,     5,     0,   139,     6,   161,    99,   117,   118,
     119,   120,   121
};

static const yytype_int16 yycheck[] =
{
      13,    40,     0,    87,    88,     5,     0,     3,     4,   175,
       5,     9,     0,     5,    94,     9,   182,    43,    57,    57,
      57,     3,     4,    19,    20,    62,     3,     4,    24,    43,
      26,    27,    28,     3,     4,    61,    55,    33,    34,    35,
      32,     5,     6,    39,    89,    90,    42,    61,    12,    45,
      60,    47,    48,    46,    54,     3,     4,    54,    54,    54,
      99,    57,    54,   143,    60,    51,    62,    63,   152,   153,
     154,    19,    20,     3,     4,    45,    24,    54,    26,    27,
      28,     3,     4,    60,    54,    33,    34,    35,    86,    54,
      60,    39,     3,     4,    42,    58,    58,    45,    60,    47,
      48,   140,   144,   145,    59,    58,    54,    61,    55,    57,
      60,    60,    60,    57,    62,    45,    57,    47,    48,    54,
     159,    54,    43,    45,    54,    47,    48,    44,    57,    57,
      60,    61,    54,    59,    45,    57,    47,    48,    60,    55,
      21,    61,    61,    54,     7,     8,     9,    10,    11,    60,
       7,     8,     9,    10,    11,     7,     8,     9,    10,    11,
      57,   174,    62,     3,     4,   146,   147,   148,   149,   150,
     151,     9,    19,    13,    14,    15,    16,    17,    18,    33,
      51,    18,   124,    46,    47,    48,    33,    34,    35,    46,
      47,    48,    39,    -1,    46,    42,   142,    60,    49,    50,
      51,    52,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    33,    34,    35,    39,    42,    65,    66,    67,
      68,    75,    78,    79,    81,     0,    66,    57,     5,    32,
      54,    69,    70,    71,    73,    76,    80,    57,    62,   119,
      76,    58,    72,    55,    46,    60,   120,    51,    54,    70,
      74,    54,    83,    84,    85,     3,     4,    20,    24,    26,
      27,    28,    45,    47,    48,    54,    57,    60,    63,    68,
      75,    82,    89,    91,    92,    94,    96,    98,   105,   108,
     112,   115,   116,   117,   118,   119,   121,   125,   127,   128,
     129,    59,    54,    89,    58,    61,    55,   113,   114,    60,
      60,    57,    57,   118,    97,    54,    54,    47,    48,    60,
      90,    89,    57,    57,    43,    44,     3,     4,    13,    14,
      15,    16,    17,    18,     5,     6,    12,    49,    50,    51,
      52,    53,    77,    59,    75,    54,   112,   112,    92,    92,
      96,    86,    87,    89,     7,     8,     9,    10,    11,    46,
      88,    61,    93,    95,   106,   107,    99,   100,   101,   102,
     103,   104,   109,   110,   111,    85,    61,    61,    61,    55,
      89,    94,    96,   108,   108,   105,   105,   105,   105,   105,
     105,   112,   112,   112,   122,   126,    57,    89,   119,   117,
      21,   123,   124,   117
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    72,    74,    73,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    77,    77,    77,
      77,    77,    78,    78,    79,    80,    80,    81,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    88,    88,    88,    88,    90,    89,    89,    89,    91,
      91,    91,    91,    93,    92,    92,    95,    94,    94,    97,
      96,    96,    99,    98,   100,    98,   101,    98,   102,    98,
     103,    98,   104,    98,    98,   106,   105,   107,   105,   105,
     109,   108,   110,   108,   111,   108,   108,   113,   112,   114,
     112,   112,   115,   115,   116,   115,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   118,   118,   119,   120,   120,
     122,   121,   124,   123,   123,   126,   125,   127,   128,   129
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     2,     3,
       1,     1,     1,     1,     2,     3,     0,     4,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     5,     1,     1,     2,     5,     1,
       0,     4,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     2,
       2,     2,     2,     0,     4,     1,     0,     4,     1,     0,
       3,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     1,     0,     4,     0,     4,     1,
       0,     4,     0,     4,     0,     4,     1,     0,     3,     0,
       3,     1,     1,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     3,     2,     0,
       0,     7,     0,     3,     0,     0,     6,     2,     2,     2
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
  case 6:
#line 116 "parser.y"
                         {is_declaration = 0;}
#line 1637 "y.tab.c"
    break;

  case 13:
#line 129 "parser.y"
                           {(yyvsp[0].tbEntry)->data_type = strdup(curr_data_type); (yyval.tbEntry) = (yyvsp[0].tbEntry); push_ICG((yyvsp[0].tbEntry)->lexem);}
#line 1643 "y.tab.c"
    break;

  case 14:
#line 130 "parser.y"
                                     {(yyvsp[-1].tbEntry)->data_type = strdup(curr_data_type); (yyval.tbEntry) = (yyvsp[-1].tbEntry); (yyvsp[-1].tbEntry)->arr_dim = (yyvsp[0].ival); push_ICG((yyvsp[-1].tbEntry)->lexem);}
#line 1649 "y.tab.c"
    break;

  case 15:
#line 132 "parser.y"
                                  { if((yyvsp[-1].tbEntry)->value < 1){printf("\nLine : %d ERROR : Arrays can't have dimension lesser than 1\n\n", yylineno);} 
                                    (yyvsp[-1].tbEntry)->is_array = 1; (yyval.ival) = (int)((yyvsp[-1].tbEntry)->value);}
#line 1656 "y.tab.c"
    break;

  case 16:
#line 135 "parser.y"
                                {is_declaration = 0; push_ICG("=");}
#line 1662 "y.tab.c"
    break;

  case 17:
#line 136 "parser.y"
                                  {gencode(); (yyvsp[-3].tbEntry)->value = val_assign; typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry)); is_declaration = 1;}
#line 1668 "y.tab.c"
    break;

  case 19:
#line 139 "parser.y"
                {curr_data_type = strdup("INT"); is_declaration = 1;}
#line 1674 "y.tab.c"
    break;

  case 20:
#line 140 "parser.y"
                  {curr_data_type = strdup("FLOAT"); is_declaration = 1;}
#line 1680 "y.tab.c"
    break;

  case 21:
#line 141 "parser.y"
                   {curr_data_type = strdup("DOUBLE"); is_declaration = 1;}
#line 1686 "y.tab.c"
    break;

  case 22:
#line 142 "parser.y"
                 {curr_data_type = strdup("CHAR"); is_declaration = 1;}
#line 1692 "y.tab.c"
    break;

  case 23:
#line 143 "parser.y"
                 {curr_data_type = strdup("VOID"); is_declaration = 1;}
#line 1698 "y.tab.c"
    break;

  case 24:
#line 144 "parser.y"
                 {curr_data_type = strdup("BOOL"); is_declaration = 1;}
#line 1704 "y.tab.c"
    break;

  case 27:
#line 151 "parser.y"
                              {printf("%f \n", (yyvsp[0].tbEntry)->value);  (yyval.tbEntry) = (yyvsp[0].tbEntry); push_ICG((yyvsp[0].tbEntry)->lexem);}
#line 1710 "y.tab.c"
    break;

  case 28:
#line 152 "parser.y"
                              {printf("%f \n", (yyvsp[0].tbEntry)->value); (yyval.tbEntry) = (yyvsp[0].tbEntry); push_ICG((yyvsp[0].tbEntry)->lexem);}
#line 1716 "y.tab.c"
    break;

  case 29:
#line 153 "parser.y"
                              {printf("%d \n", (int)(yyvsp[0].tbEntry)->value); (yyval.tbEntry) = (yyvsp[0].tbEntry); push_ICG((yyvsp[0].tbEntry)->lexem);}
#line 1722 "y.tab.c"
    break;

  case 30:
#line 154 "parser.y"
                              {printf("%f \n", (yyvsp[0].tbEntry)->value); (yyval.tbEntry) = (yyvsp[0].tbEntry); push_ICG((yyvsp[0].tbEntry)->lexem);}
#line 1728 "y.tab.c"
    break;

  case 31:
#line 155 "parser.y"
                              {printf("%f \n", (yyvsp[0].tbEntry)->value); (yyval.tbEntry) = (yyvsp[0].tbEntry); push_ICG((yyvsp[0].tbEntry)->lexem);}
#line 1734 "y.tab.c"
    break;

  case 35:
#line 163 "parser.y"
                     {gencode_function("main"); is_declaration = 0;push_ICG("main");}
#line 1740 "y.tab.c"
    break;

  case 36:
#line 164 "parser.y"
                            {checkScope((yyvsp[0].tbEntry)->lexem, scope); push_ICG((yyvsp[0].tbEntry)->lexem);}
#line 1746 "y.tab.c"
    break;

  case 37:
#line 166 "parser.y"
                                {fprintf(ICG, "func end\n");}
#line 1752 "y.tab.c"
    break;

  case 38:
#line 167 "parser.y"
                                          {checkScope((yyvsp[-4].tbEntry)->lexem, scope); push_ICG((yyvsp[-4].tbEntry)->lexem);}
#line 1758 "y.tab.c"
    break;

  case 43:
#line 176 "parser.y"
                        {checkScope((yyvsp[0].tbEntry)->lexem, scope); push_ICG((yyvsp[0].tbEntry)->lexem);}
#line 1764 "y.tab.c"
    break;

  case 44:
#line 177 "parser.y"
                               {checkScope((yyvsp[-2].tbEntry)->lexem, scope); push_ICG((yyvsp[-2].tbEntry)->lexem);}
#line 1770 "y.tab.c"
    break;

  case 49:
#line 187 "parser.y"
                            {push_ICG("+=");}
#line 1776 "y.tab.c"
    break;

  case 50:
#line 188 "parser.y"
                            {push_ICG("-=");}
#line 1782 "y.tab.c"
    break;

  case 51:
#line 189 "parser.y"
                            {push_ICG("*=");}
#line 1788 "y.tab.c"
    break;

  case 52:
#line 190 "parser.y"
                            {push_ICG("/=");}
#line 1794 "y.tab.c"
    break;

  case 53:
#line 191 "parser.y"
                            {push_ICG("%=");}
#line 1800 "y.tab.c"
    break;

  case 54:
#line 192 "parser.y"
                        { push_ICG("="); for(int i = 0; i < space; ++i)printf("\t"); printf("=\n"); ++space; }
#line 1806 "y.tab.c"
    break;

  case 55:
#line 197 "parser.y"
                          {if(checkScope((yyvsp[0].tbEntry)->lexem, scope) == 0){return -1;}
                          push_ICG((yyvsp[0].tbEntry)->lexem);
                          for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tid=%s\n", (yyvsp[0].tbEntry)->lexem);}
#line 1814 "y.tab.c"
    break;

  case 56:
#line 200 "parser.y"
                                      { (yyval.tbEntry)=(yyvsp[-3].tbEntry); gencode(); (yyvsp[-3].tbEntry)->value = val_assign;}
#line 1820 "y.tab.c"
    break;

  case 57:
#line 201 "parser.y"
                              {(yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 1826 "y.tab.c"
    break;

  case 58:
#line 202 "parser.y"
                               {(yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 1832 "y.tab.c"
    break;

  case 59:
#line 210 "parser.y"
                                            {checkScope((yyvsp[0].tbEntry)->lexem, scope); push_ICG((yyvsp[0].tbEntry)->lexem); (yyval.tbEntry) = (yyvsp[0].tbEntry); (yyvsp[0].tbEntry)->value = (yyvsp[0].tbEntry)->value + 1; fprintf(ICG, "%s = %s + 1\n", (yyvsp[0].tbEntry)->lexem, (yyvsp[0].tbEntry)->lexem);}
#line 1838 "y.tab.c"
    break;

  case 60:
#line 211 "parser.y"
                                            {checkScope((yyvsp[-1].tbEntry)->lexem, scope); push_ICG((yyvsp[-1].tbEntry)->lexem); (yyval.tbEntry) = (yyvsp[-1].tbEntry); (yyvsp[-1].tbEntry)->value = (yyvsp[-1].tbEntry)->value + 1; fprintf(ICG, "%s = %s + 1\n", (yyvsp[-1].tbEntry)->lexem, (yyvsp[-1].tbEntry)->lexem);}
#line 1844 "y.tab.c"
    break;

  case 61:
#line 212 "parser.y"
                                            {checkScope((yyvsp[0].tbEntry)->lexem, scope); push_ICG((yyvsp[0].tbEntry)->lexem); (yyval.tbEntry) = (yyvsp[0].tbEntry); (yyvsp[0].tbEntry)->value = (yyvsp[0].tbEntry)->value - 1; fprintf(ICG, "%s = %s - 1\n", (yyvsp[0].tbEntry)->lexem, (yyvsp[0].tbEntry)->lexem);}
#line 1850 "y.tab.c"
    break;

  case 62:
#line 213 "parser.y"
                                            {checkScope((yyvsp[-1].tbEntry)->lexem, scope); push_ICG((yyvsp[-1].tbEntry)->lexem); (yyval.tbEntry) = (yyvsp[-1].tbEntry); (yyvsp[-1].tbEntry)->value = (yyvsp[-1].tbEntry)->value - 1; fprintf(ICG, "%s = %s + 1\n", (yyvsp[-1].tbEntry)->lexem, (yyvsp[-1].tbEntry)->lexem);}
#line 1856 "y.tab.c"
    break;

  case 63:
#line 216 "parser.y"
                                              {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("|| \n"); }
#line 1862 "y.tab.c"
    break;

  case 64:
#line 216 "parser.y"
                                                                                                                                     {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("||"); gencode();}
#line 1868 "y.tab.c"
    break;

  case 65:
#line 217 "parser.y"
                                   {(yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 1874 "y.tab.c"
    break;

  case 66:
#line 219 "parser.y"
                                       {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("&& \n"); }
#line 1880 "y.tab.c"
    break;

  case 67:
#line 219 "parser.y"
                                                                                                                               {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("&&"); gencode();}
#line 1886 "y.tab.c"
    break;

  case 68:
#line 220 "parser.y"
                              {(yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 1892 "y.tab.c"
    break;

  case 69:
#line 222 "parser.y"
                      {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("^ \n"); }
#line 1898 "y.tab.c"
    break;

  case 70:
#line 222 "parser.y"
                                                                                                             {(yyval.tbEntry) = (yyvsp[0].tbEntry);push_ICG("!");}
#line 1904 "y.tab.c"
    break;

  case 71:
#line 223 "parser.y"
                               {(yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 1910 "y.tab.c"
    break;

  case 72:
#line 225 "parser.y"
                                              {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("> \n"); }
#line 1916 "y.tab.c"
    break;

  case 73:
#line 225 "parser.y"
                                                                                                                                    {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG(">"); gencode();}
#line 1922 "y.tab.c"
    break;

  case 74:
#line 226 "parser.y"
                                              {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("< \n"); }
#line 1928 "y.tab.c"
    break;

  case 75:
#line 226 "parser.y"
                                                                                                                                    {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("<"); gencode();}
#line 1934 "y.tab.c"
    break;

  case 76:
#line 227 "parser.y"
                                            {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("<= \n"); }
#line 1940 "y.tab.c"
    break;

  case 77:
#line 227 "parser.y"
                                                                                                                                   {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("<="); gencode();}
#line 1946 "y.tab.c"
    break;

  case 78:
#line 228 "parser.y"
                                             {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf(">= \n"); }
#line 1952 "y.tab.c"
    break;

  case 79:
#line 228 "parser.y"
                                                                                                                                     {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG(">="); gencode();}
#line 1958 "y.tab.c"
    break;

  case 80:
#line 229 "parser.y"
                                         {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("!= \n"); }
#line 1964 "y.tab.c"
    break;

  case 81:
#line 229 "parser.y"
                                                                                                                                 {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("!="); gencode();}
#line 1970 "y.tab.c"
    break;

  case 82:
#line 230 "parser.y"
                                        {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("== \n"); }
#line 1976 "y.tab.c"
    break;

  case 83:
#line 230 "parser.y"
                                                                                                                                {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("=="); gencode();}
#line 1982 "y.tab.c"
    break;

  case 84:
#line 231 "parser.y"
                                {(yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 1988 "y.tab.c"
    break;

  case 85:
#line 234 "parser.y"
                                    { for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("+\n"); }
#line 1994 "y.tab.c"
    break;

  case 86:
#line 234 "parser.y"
                                                                                                                            {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("+"); gencode();}
#line 2000 "y.tab.c"
    break;

  case 87:
#line 235 "parser.y"
                                         {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("-\n"); }
#line 2006 "y.tab.c"
    break;

  case 88:
#line 235 "parser.y"
                                                                                                                                {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("-"); gencode();}
#line 2012 "y.tab.c"
    break;

  case 89:
#line 236 "parser.y"
                                {(yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 2018 "y.tab.c"
    break;

  case 90:
#line 238 "parser.y"
                                           {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("*\n"); }
#line 2024 "y.tab.c"
    break;

  case 91:
#line 238 "parser.y"
                                                                                                                                   {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("*"); gencode();}
#line 2030 "y.tab.c"
    break;

  case 92:
#line 239 "parser.y"
                                         {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("/\n"); }
#line 2036 "y.tab.c"
    break;

  case 93:
#line 239 "parser.y"
                                                                                                                                 {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("/"); gencode();}
#line 2042 "y.tab.c"
    break;

  case 94:
#line 240 "parser.y"
                                      {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("/\n"); }
#line 2048 "y.tab.c"
    break;

  case 95:
#line 240 "parser.y"
                                                                                                                             {typeCheck((yyvsp[-3].tbEntry), (yyvsp[0].tbEntry));(yyval.tbEntry) = (yyvsp[-3].tbEntry);push_ICG("%"); gencode();}
#line 2054 "y.tab.c"
    break;

  case 96:
#line 241 "parser.y"
                                 {(yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 2060 "y.tab.c"
    break;

  case 97:
#line 243 "parser.y"
                        {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("+ \n");}
#line 2066 "y.tab.c"
    break;

  case 98:
#line 243 "parser.y"
                                                                                                                {(yyval.tbEntry) = (yyvsp[0].tbEntry); push_ICG("+"); gencode_unary();}
#line 2072 "y.tab.c"
    break;

  case 99:
#line 244 "parser.y"
                             {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("- \n");}
#line 2078 "y.tab.c"
    break;

  case 100:
#line 244 "parser.y"
                                                                                                                      {(yyval.tbEntry) = (yyvsp[0].tbEntry); push_ICG("-"); gencode_unary();}
#line 2084 "y.tab.c"
    break;

  case 101:
#line 245 "parser.y"
                          {(yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 2090 "y.tab.c"
    break;

  case 102:
#line 247 "parser.y"
                       {if(checkScope((yyvsp[0].tbEntry)->lexem, scope) == 0){return -1;} push_ICG((yyvsp[0].tbEntry)->lexem); for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tid=%s\n", (yyvsp[0].tbEntry)->lexem); (yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 2096 "y.tab.c"
    break;

  case 103:
#line 248 "parser.y"
                              {(yyval.tbEntry) = (yyvsp[-1].tbEntry);}
#line 2102 "y.tab.c"
    break;

  case 104:
#line 249 "parser.y"
          {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tconstant = "); }
#line 2108 "y.tab.c"
    break;

  case 105:
#line 249 "parser.y"
                                                                                                      {(yyval.tbEntry) = (yyvsp[0].tbEntry);}
#line 2114 "y.tab.c"
    break;

  case 115:
#line 261 "parser.y"
                                {ICG_top = 0;}
#line 2120 "y.tab.c"
    break;

  case 116:
#line 262 "parser.y"
                     {ICG_top = 0;}
#line 2126 "y.tab.c"
    break;

  case 120:
#line 273 "parser.y"
                                               {gencode_if();}
#line 2132 "y.tab.c"
    break;

  case 122:
#line 275 "parser.y"
               {gencode_if_else();}
#line 2138 "y.tab.c"
    break;

  case 125:
#line 279 "parser.y"
                                                  {gencode_while(); is_loop = 1;}
#line 2144 "y.tab.c"
    break;

  case 126:
#line 279 "parser.y"
                                                                                            {gencode_while_block();is_loop = 0;}
#line 2150 "y.tab.c"
    break;

  case 128:
#line 281 "parser.y"
                        {
                          if(!is_loop)
                          {
                            printf("Line : %d ERROR : break outside loop\n", yylineno);
                            return(-1);
                          }
                          fprintf(ICG, "goto L%d\n", loop_constants[0]);
                        }
#line 2163 "y.tab.c"
    break;

  case 129:
#line 290 "parser.y"
                          {
                            if(!is_loop)
                            {
                              printf("Line : %d ERROR : continue outside loop\n", yylineno);
                            }
                            fprintf(ICG, "goto L%d\n", loop_constants[1]);
                          }
#line 2175 "y.tab.c"
    break;


#line 2179 "y.tab.c"

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
#line 314 "parser.y"



void display_symbolTable()
{
    Display(SymbolTable);
}

int typeCheck(node_t* a, node_t* b){
	
  //printf("types: %s %s\n", a, b);
	if(strcmp(a->data_type, b->data_type)!=0){
		printf("\nLine : %d Type Mismatch: Performing operation on types %s and %s\n", yylineno, a->data_type, b->data_type);
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

int checkScope(char* var, int scope){
  int var_node_exists = check_variable(SymbolTable, var);
  
  if(!var_node_exists){
      printf("\nLine : %d ERROR : Variable '%s' not declared\n", yylineno, var);
      return 0;
  }
  else{
    node_t* temp = exists(SymbolTable, var, scope);
    if(temp && temp->data_type == NULL && temp->scope > scope){
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
    ConstantTable = (symtab_t*)malloc(sizeof(symtab_t));
    SymbolTable->head = NULL;
    ConstantTable->head = NULL;

    yyin = fopen(argv[1], "r");

    ICG = fopen("ICG.code", "w");

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
    fclose(ICG);
    return 0;
}

int yyerror(char* err)
{
    printf("Line no: %d Error message: %s\n", yylineno, err);
    return 0;
}

void push_ICG(char* text)
{
  strcpy(ICG_stack[ICG_top++], text);
}

void push_value(double value)
{
  ICG_value_stack[ICG_value_top++] = value;
}

void gencode()
{
  char *rhs = ICG_stack[--ICG_top]; 
  char *op = ICG_stack[--ICG_top];
  char *lhs = ICG_stack[--ICG_top];

  //printf("lhs : %s op : %s rhs : %s\n", lhs, op, rhs);
  
  node_t* lhs_node;
  node_t* rhs_node;
  node_t* op_node;

  if(strcmp(op, "=") == 0)
  {
    fprintf(ICG, "%s = %s\n", lhs, rhs);
    if(isalpha(rhs[0]))
    {
      rhs_node = exists(SymbolTable, rhs, scope);
      if(rhs_node == NULL)
      {
        val_assign = ICG_value_stack[--ICG_value_top];
      }
      else
      {
        val_assign = rhs_node -> value;
      }
    }
    else 
    {
      val_assign = atof(rhs);
    }
  }

  else if (strcmp(op, "+=") == 0)
  {
    if(isalpha(rhs[0]))
    {
      rhs_node = exists(SymbolTable, rhs, scope);
      lhs_node = exists(SymbolTable, lhs, scope);
      if(rhs_node == NULL)
      {
        val_assign = lhs_node -> value + ICG_value_stack[--ICG_value_top];
      }
      else
      {
        val_assign = lhs_node -> value + rhs_node -> value;
      }
    }
    else 
    {
      val_assign = lhs_node -> value + atof(rhs);
    }
    fprintf(ICG,"%s = %s + %s\n",lhs, lhs, rhs);
  }

  else if (strcmp(op, "-=") == 0)
  {
    if(isalpha(rhs[0]))
    {
      rhs_node = exists(SymbolTable, rhs, scope);
      lhs_node = exists(SymbolTable, lhs, scope);
      if(rhs_node == NULL)
      {
        val_assign = lhs_node -> value - ICG_value_stack[--ICG_value_top];
      }
      else
      {
        val_assign = lhs_node -> value - rhs_node -> value;
      }
    }
    else 
    {
      val_assign = lhs_node -> value - atof(rhs);
    }
    fprintf(ICG,"%s = %s - %s\n",lhs, lhs, rhs);
  }

  else if (strcmp(op, "*=") == 0)
  {
    if(isalpha(rhs[0]))
    {
      rhs_node = exists(SymbolTable, rhs, scope);
      lhs_node = exists(SymbolTable, lhs, scope);
      if(rhs_node == NULL)
      {
        val_assign = lhs_node -> value * ICG_value_stack[--ICG_value_top];
      }
      else
      {
        val_assign = lhs_node -> value * rhs_node -> value;
      }
    }
    else 
    {
      val_assign = lhs_node -> value * atof(rhs);
    }
    fprintf(ICG,"%s = %s * %s\n",lhs, lhs, rhs);
  }

  else if (strcmp(op, "/=") == 0)
  {
    if(isalpha(rhs[0]))
    {
      rhs_node = exists(SymbolTable, rhs, scope);
      lhs_node = exists(SymbolTable, lhs, scope);
      if(rhs_node == NULL)
      {
        val_assign = lhs_node -> value / ICG_value_stack[--ICG_value_top];
      }
      else
      {
        val_assign = lhs_node -> value / rhs_node -> value;
      }
    }
    else 
    {
      val_assign = lhs_node -> value / atof(rhs);
    }
    fprintf(ICG,"%s = %s / %s\n",lhs, lhs, rhs);
  }

  else
  {
    char temp_var[3] = "t0\0";
    temp_var[1] = (char)(temp_var_num + '0');
    temp_var[2] = '\0';
    ++temp_var_num;
    double var3, var2;

    if(isalpha(lhs[0]))
    {
      lhs_node = exists(SymbolTable, lhs, scope);
      if(lhs_node == NULL)
        var3 = ICG_value_stack[--ICG_value_top];
      else
        var3 = lhs_node -> value;
    }
    else
      var3 = atof(lhs);
    
    if(isalpha(op[0]))
    {
      op_node = exists(SymbolTable, op, scope);
      if(lhs_node == NULL)
        var2 = ICG_value_stack[--ICG_value_top];
      else
        var2 = op_node -> value;
    }
    else
      var2 = atof(op);

    
      fprintf(ICG, "%s = %s %s %s\n", temp_var, lhs, rhs, op);
      if(strcmp(rhs, "+") == 0)
        val_assign = var3 + var2;
      else if(strcmp(rhs, "-") == 0)
        val_assign = var3 - var2;
      else if(strcmp(rhs, "*") == 0)
        val_assign = var3 * var2;
      else if(strcmp(rhs, "/") == 0)
        val_assign = var3 / var2;
    

    push_ICG(temp_var);
    push_value(val_assign);
  }
  inst_line_num++;
}

void gencode_unary()
{
  inst_line_num++;
  char* op1 = ICG_stack[--ICG_top];
  char* op2 = ICG_stack[--ICG_top];

  char temp_var[3] = "t0\0";
  temp_var[1] = (char)(temp_var_num + '0');
  temp_var[2] = '\0';
  ++temp_var_num;

  fprintf(ICG, "%s = %s %s\n", temp_var, op1, op2);
  push_ICG(temp_var);
  ++inst_line_num;
}

void gencode_if()
{
  label_stack[label_top++] = ++dec_label;
  fprintf(ICG, "if %s goto L%d\n", ICG_stack[--ICG_top], dec_label);
  gencode_if_if();
}

void gencode_if_if()
{
  ++dec_label;
  fprintf(ICG, "goto L%d\n", dec_label);
  fprintf(ICG, "L%d :\n", label_stack[--label_top]);
  label_stack[label_top++] = dec_label;
}

void gencode_if_else()
{
  fprintf(ICG,"L%d :\n",label_stack[--label_top]);
}

void gencode_while()
{
  fprintf(ICG,"L%d :\n",++dec_label);
  loop_constants[0] = dec_label;
  label_stack[label_top++] = dec_label;
  label_stack[label_top++] = ++dec_label;
  fprintf(ICG,"if %s goto L%d\n",ICG_stack[--ICG_top], dec_label);

  ++dec_label;
  fprintf(ICG,"goto L%d\n",dec_label);
  loop_constants[1]= dec_label;
  fprintf(ICG,"L%d :\n",label_stack[--label_top]);
  label_stack[label_top++] = dec_label;
}

void gencode_while_block()
{
    int label_false = label_stack[--label_top];
    int label_true = label_stack[--label_top];
    fprintf(ICG,"goto L%d\n",label_true);
    fprintf(ICG,"L%d :\n",label_false);
}

void gencode_function(char *lexeme)
{
    fprintf(ICG,"func begin %s\n",lexeme);
}

void gencode_array(char *data_type)
{
    
  char temp[3] = "t0\0";
  temp[1] = (char)(temp_var_num + '0');
  temp[2] = '\0';
  temp_var_num++;
    
  char temp1[3] = "t0\0";
  temp1[1] = (char)(temp_var_num + '0');
  temp1[2] = '\0';
  temp_var_num++;

  char *op1 = ICG_stack[--ICG_top];
  char *op2 = ICG_stack[--ICG_top];
    
  strcat(op2,"[");
  if(strcmp(data_type,"INT") == 0 || strcmp(data_type,"FLOAT")==0)
    fprintf(ICG,"%s = 4 * %s\n",temp,op1);
  strcat(op2,temp);
  strcat(op2,"]");

  fprintf(ICG,"%s = %s\n",temp1,op2);

  push_ICG(temp1);
}

