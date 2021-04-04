%{
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

program : declarations //handle define and macros in lex
        | 
        ; 
declarations : declaration declarations
             | declaration
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
            | T_IDENTIFIER arrayDims {$1->data_type = strdup(curr_data_type);}
            ;
arrayDims : '[' T_INT_CONSTANT ']' { if($2 < 1){printf("\nLine : %d ERROR : Arrays can't have dimension lesser than 1\n\n", yylineno);}} arrayDims
          | '[' T_INT_CONSTANT ']' { if($2 < 1){printf("\nLine : %d ERROR : Arrays can't have dimension lesser than 1\n\n", yylineno);}} 
          ;
varInit :   varOnlyDec T_ASSIGN assignmentExpression;

type    : type pointer
        | T_INT {curr_data_type = strdup("INT");}
        | T_FLOAT {curr_data_type = strdup("FLOAT");}
        | T_DOUBLE {curr_data_type = strdup("DOUBLE");}
        | T_CHAR {curr_data_type = strdup("CHAR");}
        | T_VOID {curr_data_type = strdup("VOID");}
        | T_BOOL {curr_data_type = strdup("BOOL");}
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
            | T_IDENTIFIER  {checkScope($1->lexem, scope);}
            ;
funcDef : funcOnlyDec blockStmt ;
funcCall : T_IDENTIFIER '(' args ')' ';'  {checkScope($1->lexem, scope);}
         ;

params : paramList
       | 
       ;
paramList : paramList ',' type paramID
          | paramID
          ;
paramID : T_IDENTIFIER  {checkScope($1->lexem, scope);}
        | T_IDENTIFIER '[' ']' {checkScope($1->lexem, scope);}
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
expression : T_IDENTIFIER assignmentOp assignmentExpression {checkScope($1->lexem, scope);}
           | T_MULTIPLY T_IDENTIFIER assignmentOp assignmentExpression {checkScope($2->lexem, scope);}
           | incDecExpression
           | logicalExpression
           ;


assignmentExpression : ternaryOpExpression 
                     | T_IDENTIFIER assignmentOp assignmentExpression {checkScope($1->lexem, scope);}
                     ;

incDecExpression : T_INCREMENT T_IDENTIFIER {checkScope($2->lexem, scope);}
                 | T_IDENTIFIER T_INCREMENT {checkScope($1->lexem, scope);}
                 | T_DECREMENT T_IDENTIFIER {checkScope($2->lexem, scope);}
                 | T_IDENTIFIER T_DECREMENT {checkScope($1->lexem, scope);}
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
factor  : T_IDENTIFIER {checkScope($1->lexem, scope);}
        | '(' expression ')'
        | constants
        ;
statement : expressionStmt
          | blockStmt
          | selectionStmt
          | iterationStmt
          | returnStmt
          | breakStmt
          | contStmt
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
iterationStmt : T_WHILE '(' logicalExpression ')' {is_loop = 1;} statement {is_loop = 0;};
returnStmt : T_RETURN expressionStmt;
breakStmt : T_BREAK ';' {
                          if(!is_loop)
                          {
                            printf("Line : %d ERROR : break outside loop\n", yylineno);
                          }
                        }
                        ;
contStmt : T_CONTINUE ';' {if(!is_loop)
                          {
                            printf("Line : %d ERROR : continue outside loop\n", yylineno);
                          }
                          }
                          ;

/*
generalExpression : ternaryOpExpression
                  | logicalExpression
                  | relExpression
                  | arithExpression
                  | unaryExpression
                  | factor
                  | assignmentExpression
                  | expression
                  ;
assignmentExpression : T_IDENTIFIER assignmentOp generalExpression {checkScope($1->lexem, scope);}
                     ;
logicalExpression : generalExpression T_LG_OR generalExpression
                  | generalExpression T_LG_AND generalExpression
                  | T_NOT generalExpression
                  ;
relExpression   : generalExpression T_GREATER_THAN generalExpression
                | generalExpression T_LESSER_THAN generalExpression
                | generalExpression T_LESSER_EQ generalExpression
                | generalExpression T_GREATER_EQ generalExpression
                | generalExpression T_NOT_EQ generalExpression
                | generalExpression T_EQUAL generalExpression
                ;
arithExpression : generalExpression T_ADD generalExpression 
                | generalExpression T_SUBTRACT generalExpression 
                | generalExpression T_MULTIPLY generalExpression 
                | generalExpression T_DIVIDE generalExpression 
                | generalExpression T_MOD generalExpression 
                ;
unaryExpression : T_ADD generalExpression
                | T_SUBTRACT generalExpression
                ;
factor  : T_IDENTIFIER {checkScope($1->lexem, scope);}
        | '(' generalExpression ')'
        | constants
        ;
expression : T_IDENTIFIER assignmentOp generalExpression {checkScope($1->lexem, scope);}
           | T_INCREMENT T_IDENTIFIER {checkScope($2->lexem, scope);}
           | T_DECREMENT T_IDENTIFIER {checkScope($2->lexem, scope);}
           | expression
           |
           ;
*/
%%


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
