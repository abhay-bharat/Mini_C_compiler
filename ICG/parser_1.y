%{
    //header files
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include"symbol_table.h"
    #include "quad_table.h"


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

    ir_quad* quad_ptr_head = NULL;
    //int serial_no = 0;

    //for goto label address(limit: 0 to 9)
    int goto_l = 1; 
    char[3] label = "L0\0";

    //for temparary variables(range: 0 to 9)
    int temp_sl_no = 0;
    char[3] temp = "t0\0"; 
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
%token <dval> T_HEX_CONSTANT T_DEC_CONSTANT T_INT_CONSTANT 
%token <str> T_STRING T_BOOL_CONSTANT
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

%type<str> varOnlyDec
%type<str> factor expression expressionStmt  incDecExpression logicalExpression andExpression notExpression relExpression sumExpression prodExpression unaryExpression constants

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

varOnlyDec  : T_IDENTIFIER {$1->data_type = strdup(curr_data_type); $$ = $1->data_type;}
            | T_IDENTIFIER arrayDims {$1->data_type = strdup(curr_data_type); $$ = $1->data_type;}
            ;
arrayDims : '[' T_INT_CONSTANT ']' { if($2 < 1){printf("\nLine : %d ERROR : Arrays can't have dimension lesser than 1\n\n", yylineno);}} arrayDims
          | '[' T_INT_CONSTANT ']' { if($2 < 1){printf("\nLine : %d ERROR : Arrays can't have dimension lesser than 1\n\n", yylineno);}} 
          ;
varInit :   varOnlyDec T_ASSIGN expression {typeCheck($1, $3);};

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

constants   : T_HEX_CONSTANT  {printf("%f \n", $1);  $$ = strdup("HEX");}
            | T_DEC_CONSTANT  {printf("%f \n", $1); $$ = strdup("FLOAT");}
            | T_INT_CONSTANT  {printf("%d \n", (int)$1); $$ = strdup("INT");}
            | T_BOOL_CONSTANT {printf("%s \n", $1); $$ = strdup("BOOL");}
            | T_STRING        {printf("%s \n", $1); $$ = strdup("CHAR");}
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
             | T_ASSIGN { for(int i = 0; i < space; ++i)printf("\t"); printf("=\n"); ++space; }
             ;
// ternaryOpExpression : logicalExpression '?' expression ':' ternaryOpExpression
//                     | logicalExpression
//                     ;
expression : T_IDENTIFIER {if(checkScope($1->lexem, scope) == 0){return -1;}
                          for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tid=%s\n", $1->lexem);} 
              assignmentOp expression {!typeCheck($1->data_type,$4);$$ = $1->data_type;}
           | incDecExpression {$$ = $1;}
           | logicalExpression {$$ = $1;}
           ;


// assignmentExpression : ternaryOpExpression 
//                      | T_IDENTIFIER {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tid=%s\n", $1->lexem);} assignmentOp assignmentExpression {checkScope($1->lexem, scope);}
//                      ;

incDecExpression : T_INCREMENT T_IDENTIFIER {checkScope($2->lexem, scope); $$ = $2->data_type;}
                 | T_IDENTIFIER T_INCREMENT {checkScope($1->lexem, scope); $$ = $1->data_type;}
                 | T_DECREMENT T_IDENTIFIER {checkScope($2->lexem, scope); $$ = $2->data_type;}
                 | T_IDENTIFIER T_DECREMENT {checkScope($1->lexem, scope); $$ = $1->data_type;}
                 ;

logicalExpression : logicalExpression T_LG_OR {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("|| \n"); } andExpression {$$ = $1;}
                  | andExpression  {$$ = $1;}
                  ;
andExpression : andExpression T_LG_AND {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("&& \n"); } notExpression  {$$ = $1;}     
              | notExpression {$$ = $1;}
              ;
notExpression : T_NOT {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("^ \n"); } notExpression  {$$ = $3;}
              | relExpression  {$$ = $1;}
              ;
relExpression :  sumExpression T_GREATER_THAN {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("> \n"); } sumExpression {typeCheck($1, $4);$$ = $1;}   
                | sumExpression T_LESSER_THAN {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("< \n"); } sumExpression {typeCheck($1, $4);$$ = $1;}   
                | sumExpression T_LESSER_EQ {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("<= \n"); } sumExpression {typeCheck($1, $4);$$ = $1;}     
                | sumExpression T_GREATER_EQ {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf(">= \n"); } sumExpression  {typeCheck($1, $4);$$ = $1;}   
                | sumExpression T_NOT_EQ {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("!= \n"); } sumExpression  {typeCheck($1, $4);$$ = $1;}       
                | sumExpression T_EQUAL {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("== \n"); } sumExpression  {typeCheck($1, $4);$$ = $1;}        
                | sumExpression {$$ = $1;}
                ;

sumExpression : sumExpression T_ADD { for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("+\n"); } prodExpression  {typeCheck($1, $4);$$ = $1;}
              | sumExpression T_SUBTRACT {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("-\n"); } prodExpression  {typeCheck($1, $4);$$ = $1;}
              | prodExpression  {$$ = $1;}
              ;
prodExpression : prodExpression T_MULTIPLY {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("*\n"); } unaryExpression  {typeCheck($1, $4);$$ = $1;}
               | prodExpression T_DIVIDE {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("/\n"); } unaryExpression  {typeCheck($1, $4);$$ = $1;}
               | prodExpression T_MOD unaryExpression {typeCheck($1, $3);$$ = $1;}
               | unaryExpression {$$ = $1;}
               ;
unaryExpression : T_ADD {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("+ \n");} unaryExpression  {$$ = $3;}
                | T_SUBTRACT {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("- \n");} unaryExpression   {$$ = $3;}  
                | factor  {$$ = $1;}
                ;
factor  : T_IDENTIFIER {if(checkScope($1->lexem, scope) == 0){return -1;}; for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tid=%s\n", $1->lexem); $$ = $1->data_type;} 
        | '(' expression ')'  {$$ = $2;}
        | {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tconstant = "); } constants  {$$ = $2;}
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

%%


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


//Function definitions for the intermediate code generation
ir_quad* create_node(char* op, char* a1, char* a2, char* result){
  ir_quad* node = (ir_quad*)malloc(sizeof(ir_quad));
  node->op = op;
  node->arg1 = a1;
  node->arg2 = a2;
  node->result = result;
  node->next = NULL;
  
  return node;
}

//this insert function is to be appropriately called by the specialised insert functions for each
//type based on the type of instruction, the fields of the quad node is allocated
//then using this quad_table, appropriate kind of displays will be called generating the IR
 
void insert(char* op, char* a1, char* a2, char* result){
  ir_quad* node = create_node(op, a1, a2, result);
  if(quad_ptr_head == NULL){
    quad_ptr_head = node;
  }
  else{
    ir_quad* temp = quad_ptr_head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = node;
  }
}