%{
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
    void gencode_if_1();
    void gencode_if_2();
    void gencode_if_3();
    void gencode_if_else_1();
    void gencode_while();
    void gencode_while_block();
    void gencode_array(char* data_type);
    void gencode_function(char *lexeme);

    //space variable to beautify the syntax tree output
    int space = 0;

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
%token <tbEntry> T_HEX_CONSTANT T_DEC_CONSTANT T_INT_CONSTANT 
%token <tbEntry> T_STRING T_BOOL_CONSTANT
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

%type<tbEntry> varOnlyDec
%type<tbEntry> factor expression expressionStmt  incDecExpression logicalExpression andExpression notExpression relExpression sumExpression prodExpression unaryExpression constants
%type<ival> arrayDims;
%%

program : declarations //handle define and macros in lex
        | 
        ; 
declarations : declaration declarations
             | declaration
             ;
declaration : varDec ';' {is_declaration = 0;}
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

varOnlyDec  : T_IDENTIFIER {$1->data_type = strdup(curr_data_type); $$ = $1; push_ICG($1->lexem);}
            | T_IDENTIFIER arrayDims {$1->data_type = strdup(curr_data_type); $$ = $1; $1->arr_dim = $2; push_ICG($1->lexem);}
            ;
arrayDims :'[' T_INT_CONSTANT ']' { if($2->value < 1){printf("\nLine : %d ERROR : Arrays can't have dimension lesser than 1\n\n", yylineno);} 
                                    $2->is_array = 1; $$ = (int)($2->value);} 
          ;
varInit :   varOnlyDec T_ASSIGN {is_declaration = 0; push_ICG("=");} 
                       expression {gencode(); $1->value = val_assign; typeCheck($1, $4); is_declaration = 1;};

type    : type pointer
        | T_INT {curr_data_type = strdup("INT"); is_declaration = 1;}
        | T_FLOAT {curr_data_type = strdup("FLOAT"); is_declaration = 1;}
        | T_DOUBLE {curr_data_type = strdup("DOUBLE"); is_declaration = 1;}
        | T_CHAR {curr_data_type = strdup("CHAR"); is_declaration = 1;}
        | T_VOID {curr_data_type = strdup("VOID"); is_declaration = 1;}
        | T_BOOL {curr_data_type = strdup("BOOL"); is_declaration = 1;}
        ;

pointer : T_MULTIPLY pointer
        | T_MULTIPLY
        ;

constants   : T_HEX_CONSTANT  {printf("%f \n", $1->value);  $$ = $1; push_ICG($1->lexem);}
            | T_DEC_CONSTANT  {printf("%f \n", $1->value); $$ = $1; push_ICG($1->lexem);}
            | T_INT_CONSTANT  {printf("%d \n", (int)$1->value); $$ = $1; push_ICG($1->lexem);}
            | T_BOOL_CONSTANT {printf("%f \n", $1->value); $$ = $1; push_ICG($1->lexem);}
            | T_STRING        {printf("%f \n", $1->value); $$ = $1; push_ICG($1->lexem);}
            ;

funcDec : funcOnlyDec ';'
        | funcDef
        ;

funcOnlyDec :   type funcName '(' params ')';
funcName    : T_MAIN {gencode_function("main"); is_declaration = 0;push_ICG("main");}
            | T_IDENTIFIER  {checkScope($1->lexem, scope); push_ICG($1->lexem);}
            ;
funcDef : funcOnlyDec blockStmt {fprintf(ICG, "func end\n");};
funcCall : T_IDENTIFIER '(' args ')' ';'  {checkScope($1->lexem, scope); push_ICG($1->lexem);}
         ;

params : paramList
       | 
       ;
paramList : paramList ',' type paramID
          | paramID
          ;
paramID : T_IDENTIFIER  {checkScope($1->lexem, scope); push_ICG($1->lexem);}
        | T_IDENTIFIER '[' ']' {checkScope($1->lexem, scope); push_ICG($1->lexem);}
        ;

args : argList
     |
     ;
argList : argList ',' expression
        | expression
        ;

assignmentOp : T_ADD_ASSIGN {push_ICG("+="); for(int i = 0; i < space; ++i)printf("\t"); printf("+=\n"); ++space;}
             | T_SUB_ASSIGN {push_ICG("-="); for(int i = 0; i < space; ++i)printf("\t"); printf("-=\n"); ++space;}
             | T_MUL_ASSIGN {push_ICG("*="); for(int i = 0; i < space; ++i)printf("\t"); printf("*=\n"); ++space;}
             | T_DIV_ASSIGN {push_ICG("/="); for(int i = 0; i < space; ++i)printf("\t"); printf("/=\n"); ++space;}
             | T_MOD_ASSIGN {push_ICG("%="); for(int i = 0; i < space; ++i)printf("\t"); printf("%%=\n"); ++space;}
             | T_ASSIGN { push_ICG("="); for(int i = 0; i < space; ++i)printf("\t"); printf("=\n"); ++space; }
             ;
// ternaryOpExpression : logicalExpression '?' expression ':' ternaryOpExpression
//                     | logicalExpression
//                     ;
expression : T_IDENTIFIER {if(checkScope($1->lexem, scope) == 0){return -1;}
                          push_ICG($1->lexem);
                          for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tid=%s\n", $1->lexem);} 
              assignmentOp expression { typeCheck($1, $4); $$=$1; gencode(); $1->value = val_assign;}
           | incDecExpression {$$ = $1;}
           | logicalExpression {$$ = $1;}
           ;


// assignmentExpression : ternaryOpExpression 
//                      | T_IDENTIFIER {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tid=%s\n", $1->lexem);} assignmentOp assignmentExpression {checkScope($1->lexem, scope);}
//                      ;

incDecExpression : T_INCREMENT T_IDENTIFIER {checkScope($2->lexem, scope); push_ICG($2->lexem); $$ = $2; $2->value = $2->value + 1; fprintf(ICG, "%s = %s + 1\n", $2->lexem, $2->lexem);}
                 | T_IDENTIFIER T_INCREMENT {checkScope($1->lexem, scope); push_ICG($1->lexem); $$ = $1; $1->value = $1->value + 1; fprintf(ICG, "%s = %s + 1\n", $1->lexem, $1->lexem);}
                 | T_DECREMENT T_IDENTIFIER {checkScope($2->lexem, scope); push_ICG($2->lexem); $$ = $2; $2->value = $2->value - 1; fprintf(ICG, "%s = %s - 1\n", $2->lexem, $2->lexem);}
                 | T_IDENTIFIER T_DECREMENT {checkScope($1->lexem, scope); push_ICG($1->lexem); $$ = $1; $1->value = $1->value - 1; fprintf(ICG, "%s = %s + 1\n", $1->lexem, $1->lexem);}
                 ;

logicalExpression : logicalExpression T_LG_OR {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("|| \n"); } andExpression {typeCheck($1, $4);$$ = $1;push_ICG("||"); gencode();}
                  | andExpression  {$$ = $1;}
                  ;
andExpression : andExpression T_LG_AND {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("&& \n"); } notExpression  {typeCheck($1, $4);$$ = $1;push_ICG("&&"); gencode();}     
              | notExpression {$$ = $1;}
              ;
notExpression : T_NOT {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("^ \n"); } notExpression  {$$ = $3;push_ICG("!");}
              | relExpression  {$$ = $1;}
              ;
relExpression :  sumExpression T_GREATER_THAN {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("> \n"); } sumExpression {typeCheck($1, $4);$$ = $1;push_ICG(">"); gencode();}   
                | sumExpression T_LESSER_THAN {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("< \n"); } sumExpression {typeCheck($1, $4);$$ = $1;push_ICG("<"); gencode();}   
                | sumExpression T_LESSER_EQ {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("<= \n"); } sumExpression {typeCheck($1, $4);$$ = $1;push_ICG("<="); gencode();}     
                | sumExpression T_GREATER_EQ {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf(">= \n"); } sumExpression  {typeCheck($1, $4);$$ = $1;push_ICG(">="); gencode();}   
                | sumExpression T_NOT_EQ {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("!= \n"); } sumExpression  {typeCheck($1, $4);$$ = $1;push_ICG("!="); gencode();}       
                | sumExpression T_EQUAL {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("== \n"); } sumExpression  {typeCheck($1, $4);$$ = $1;push_ICG("=="); gencode();}        
                | sumExpression {$$ = $1;}
                ;

sumExpression : sumExpression T_ADD { for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("+\n"); } prodExpression  {$$ = $1;typeCheck($1, $4);push_ICG("+"); gencode();}
              | sumExpression T_SUBTRACT {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("-\n"); } prodExpression  {typeCheck($1, $4);$$ = $1;push_ICG("-"); gencode();}
              | prodExpression  {$$ = $1;}
              ;
prodExpression : prodExpression T_MULTIPLY {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("*\n"); } unaryExpression  {typeCheck($1, $4);$$ = $1;push_ICG("*"); gencode();}
               | prodExpression T_DIVIDE {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("/\n"); } unaryExpression  {typeCheck($1, $4);$$ = $1;push_ICG("/"); gencode();}
               | prodExpression T_MOD {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("/\n"); } unaryExpression {typeCheck($1, $4);$$ = $1;push_ICG("%"); gencode();}
               | unaryExpression {$$ = $1;}
               ;
unaryExpression : T_ADD {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("+ \n");} unaryExpression  {$$ = $3; push_ICG("+"); gencode_unary();}
                | T_SUBTRACT {for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("- \n");} unaryExpression   {$$ = $3; push_ICG("-"); gencode_unary();}  
                | factor  {$$ = $1;}
                ;
factor  : T_IDENTIFIER {if(checkScope($1->lexem, scope) == 0){return -1;} push_ICG($1->lexem); for(int i = 0; i < space; ++i)printf("\t"); ++space; printf("\tid=%s\n", $1->lexem); $$ = $1;} 
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
expressionStmt : expression ';' {ICG_top = 0;}
               | ';' {ICG_top = 0;}
               ;
blockStmt : '{' stmtList '}' 
          ;
stmtList : stmtList statement
         | 
         ;
// selectionStmt : T_IF '(' logicalExpression ')' {gencode_if();} statement %prec T_IFX
//               | T_IF '(' logicalExpression ')' {gencode_if();} statement {gencode_if_else();} T_ELSE statement
//               ;

selectionStmt : T_IF '(' logicalExpression ')' {gencode_if_1();} blockStmt else {gencode_if_3();}
              ;
else :  T_ELSE {gencode_if_else_1();} statement
     |
     ;

iterationStmt : T_WHILE '(' logicalExpression ')' {gencode_while(); is_loop = 1;} statement {gencode_while_block();is_loop = 0;};
returnStmt : T_RETURN expressionStmt;
breakStmt : T_BREAK ';' {
                          if(!is_loop)
                          {
                            printf("Line : %d ERROR : break outside loop\n", yylineno);
                            return(-1);
                          }
                          fprintf(ICG, "goto L%d\n", loop_constants[0]);
                        }
                        ;
contStmt : T_CONTINUE ';' {
                            if(!is_loop)
                            {
                              printf("Line : %d ERROR : continue outside loop\n", yylineno);
                            }
                            fprintf(ICG, "goto L%d\n", loop_constants[1]);
                          }
                          ;

// identifier : T_IDENTIFIER
//               {
//                 if(!is_declaration)
//                 {
//                   $1 = exists(SymbolTable, yytext, scope);
//                   if($1 == NULL)
//                   {
//                     printf("Line : %d ERROR : variable %s not declared\n", yylineno, yytext);
//                     return -1;
//                   }
//                 }
//                 push_ICG($1->lexem);
//                 $$ = $1;
//               }

%%


void display_symbolTable()
{
    Display(SymbolTable);
}

int typeCheck(node_t* a, node_t* b){
	
  //printf("types: %s %s\n", a->data_type, b->data_type);
	// if(strcmp(a->data_type, b->data_type)!=0){
	// 	printf("\nLine : %d Type Mismatch: Performing operation on types %s and %s\n", yylineno, a->data_type, b->data_type);
	// 	exit(0);
	// }

	// else 
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

void gencode_if_1()
{
  label_stack[label_top++] = ++dec_label;
  fprintf(ICG, "if %s goto L%d\n", ICG_stack[--ICG_top], dec_label);
  gencode_if_2();
}

void gencode_if_2()
{
  ++dec_label;
  fprintf(ICG, "goto L%d\n", dec_label);
  fprintf(ICG, "L%d :\n", label_stack[--label_top]);
  label_stack[label_top++] = dec_label;
}

void gencode_if_3()
{
  fprintf(ICG, "L%d :\n", label_stack[--label_top]);
}

void gencode_if_else_1()
{
  ++dec_label;
  fprintf(ICG, "goto L%d\n", dec_label);
  fprintf(ICG, "L%d :\n", label_stack[--label_top]);
  label_stack[label_top++] = dec_label;

  //fprintf(ICG,"L%d :\n",label_stack[--label_top]);
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

