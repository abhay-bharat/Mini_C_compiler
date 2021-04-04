#include<stdio.h>

int main()
{
	
	int x;
    int a[0];
    int a = x + 1;
    //printf("hello world");
    if(1)
    a = 10;
    while(a < 10)
    {
        --a;
    }
    if(1)
    {
        a = 10;
    }
    else{
        if(1)
        a = 1;
    }
    break;
    int b = 10;
    while(b > 10)
    {
        if(b < 5)
        {
            b += 10;
            continue;
        }
    }
    continue;
	int x;
	{
		int a = 0;
	}
	a = 10;

}

/*
 
%{
    //header files
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include"symbol_table.h"

    //initialise symbol table
    symtab_t* SymbolTable = NULL;

    int yyerror(char* err);
    int yylex(void);

    //keep track of data type of identifiers
    char* curr_data_type;
%}

//data types of tokens
%union{
    int ival;
    char* str;
    node_t *tbEntry;
    double dval;
}

//tokens
//operators
%token T_ADD T_SUBTRACT T_MULTIPLY T_DIVIDE T_ADD_ASSIGN T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN  T_MOD
//relational operators
%token T_GREATER_THAN T_LESSER_THAN T_LESSER_EQ T_GREATER_EQ T_NOT_EQ T_EQUAL
//keywords
%token T_VOID T_IF T_ELSE T_FOR T_DO T_WHILE T_GOTO T_BREAK T_CONTINUE T_RETURN T_SWITCH T_CASE T_DEFAULT  T_MAIN
//data types
%token T_INT T_FLOAT T_DOUBLE T_SHORT T_LONG T_LONG_INT T_CHAR T_SIGNED T_UNSIGNED T_BOOL
//logical operators
%token T_LG_OR T_LG_AND T_NOT
//assignment operators
%token T_ASSIGN T_DECREMENT T_INCREMENT
//constants
%token <dval> T_HEX_CONSTANT T_DEC_CONSTANT T_INT_CONSTANT T_BOOL_CONSTANT
%token <str> T_STRING
//identifier
%token <tbEntry> T_IDENTIFIER
//start symbol
%start program

//precedence and associativity of operators
%left ','
%right T_ASSIGN
%left T_LG_OR
%left T_LG_AND
%left T_EQUAL T_NOT_EQ
%left T_LESSER_THAN T_GREATER_THAN T_LESSER_EQ T_GREATER_EQ
%left T_ADD T_SUBTRACT
%left T_MULTIPLY T_DIVIDE T_MOD
%right T_NOT

%nonassoc T_IFX
%nonassoc T_ELSE

%%

program : declarations; //handle define and macros in lex
declarations : declarations declaration
             | declaration
             |
             ;
declaration : varDec ';'
            | funcDec
            ;
varDec  : type varDecList
        ;
varDecList : varDecList ',' varDecType 
           | varDecType
           ;
//type of var dec : only declaration, initialisation
varDecType  : varOnlyDec
            | varInit
            ;

varOnlyDec  : T_IDENTIFIER {$1->data_type = strdup(curr_data_type);} 
            | T_IDENTIFIER '[' T_INT_CONSTANT ']' 
            ;
varInit :   varOnlyDec T_ASSIGN assignmentExpression;

type    : type pointer
        | T_INT {curr_data_type = strdup("INT");}
        | T_FLOAT {curr_data_type = strdup("FLOAT");}
        | T_DOUBLE {curr_data_type = strdup("DOUBLE");}
        | T_CHAR {curr_data_type = strdup("CHAR");}
        | T_LONG_INT
        | T_VOID
        | T_BOOL
        ;

pointer : T_MULTIPLY pointer
        | T_MULTIPLY
        ;

constants   : T_HEX_CONSTANT
            | T_DEC_CONSTANT
            | T_INT_CONSTANT
            | T_BOOL_CONSTANT
            | T_STRING 
            ;

funcDec : funcOnlyDec ';'
        | funcDef
        ;

funcOnlyDec :   type funcName '(' params ')';
funcName    : T_MAIN
            | T_IDENTIFIER
            ;
funcDef : funcOnlyDec blockStmt ;
funcCall : T_IDENTIFIER '(' args ')' ';' ;

params : paramList
       | 
       ;
paramList : paramList ',' type paramID
          | paramID
          ;
paramID : T_IDENTIFIER
        | T_IDENTIFIER '[' ']'
        ;

args : argList
     |
     ;
argList : argList ',' expression
        | expression
        ;

assignmentOp : T_ADD_ASSIGN
             | T_SUB_ASSIGN
             | T_MUL_ASSIGN
             | T_DIV_ASSIGN
             | T_MOD_ASSIGN
             | T_ASSIGN
             ;
ternaryOpExpression : logicalExpression '?' expression ':' ternaryOpExpression
                    | logicalExpression
                    ;
expression : T_IDENTIFIER assignmentOp assignmentExpression
           | T_MULTIPLY T_IDENTIFIER assignmentOp assignmentExpression
           | incDecExpression
           | logicalExpression
           ;

assignmentExpression : ternaryOpExpression 
                     | T_IDENTIFIER assignmentOp assignmentExpression;

incDecExpression : T_INCREMENT T_IDENTIFIER
                 | T_IDENTIFIER T_INCREMENT
                 | T_DECREMENT T_IDENTIFIER
                 | T_IDENTIFIER T_DECREMENT
                 ;

logicalExpression : logicalExpression T_LG_OR andExpression
                  | andExpression
                  ;
andExpression : andExpression T_LG_AND notExpression
              | notExpression
              ;
notExpression : T_NOT notExpression
              | relExpression
              ;
relExpression :  sumExpression T_GREATER_THAN sumExpression
                | sumExpression T_LESSER_THAN sumExpression
                | sumExpression T_LESSER_EQ sumExpression
                | sumExpression T_GREATER_EQ sumExpression
                | sumExpression T_NOT_EQ sumExpression
                | sumExpression T_EQUAL sumExpression
                | sumExpression
                ;

sumExpression : sumExpression T_ADD prodExpression
              | sumExpression T_SUBTRACT prodExpression
              | prodExpression
              ;
prodExpression : prodExpression T_MULTIPLY unaryExpression
               | prodExpression T_DIVIDE unaryExpression
               | prodExpression T_MOD unaryExpression
               | unaryExpression
               ;
unaryExpression : T_ADD unaryExpression
                | T_SUBTRACT unaryExpression
                | factor
                ;
factor  : T_IDENTIFIER
        | '(' expression ')'
        | constants
        ;

statement : expressionStmt
          | blockStmt
          | selectionStmt
          | iterationStmt
          | returnStmt
          | breakStmt
          | funcCall
          | varDec ';'
          ;
expressionStmt : expression ';'
               | ';'
               ;
blockStmt : '{' stmtList '}' 
          ;
stmtList : statement stmtList
         | 
         ;
selectionStmt : T_IF '(' logicalExpression ')' statement %prec T_IFX
              | T_IF '(' logicalExpression ')' statement T_ELSE statement
              ;
iterationStmt : T_WHILE '(' logicalExpression ')' statement;
returnStmt : T_RETURN expressionStmt;
breakStmt : T_BREAK ';' ;
/*
expression : ternaryOpExpression
                  | logicalExpression
                  | relExpression
                  | arithExpression
                  | unaryExpression
                  | factor
                  ;
logicalExpression : expression T_LG_OR expression
                  | expression T_LG_AND expression
                  | T_NOT expression
                  ;
relExpression   : expression T_GREATER_THAN expression
                | expression T_LESSER_THAN expression
                | expression T_LESSER_EQ expression
                | expression T_GREATER_EQ expression
                | expression T_NOT_EQ expression
                | expression T_EQUAL expression
                ;
arithExpression : expression T_ADD expression 
                | expression T_SUBTRACT expression 
                | expression T_MULTIPLY expression 
                | expression T_DIVIDE expression 
                | expression T_MOD expression 
                ;
unaryExpression : T_ADD expression
                | T_SUBTRACT expression
                ;
factor  : T_IDENTIFIER
        | '(' expression ')'
        | constants
        ;
expression : T_IDENTIFIER assignmentOp rValExpression
           | T_INCREMENT T_IDENTIFIER
           | T_DECREMENT T_IDENTIFIER
           | expression
           |
           ; 

%%

void display_symbolTable()
{
    Display(SymbolTable);
}
extern FILE* yyin;
extern int yylineno;
extern char* yytext;
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

*/
