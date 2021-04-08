#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE
 
struct node{
    int ptr;
    char* token_name;
    char* lexem; //holds the variable name used in the program
    char* data_type;
    int scope; //holds the number indicating the scope of the variable
    int line_no;
    int column_st;
    int column_end;
    struct node *next;
};
typedef struct node node_t;

struct symtab{
  node_t *head;
};
typedef struct symtab symtab_t;

node_t* create_node(int sl_no, char *tok, char *lex, int scope, int line_no, int col_start, int col_end);
void display_token(node_t *node);
node_t* exists(symtab_t*, char*, int);
void insert(symtab_t *table, char *tok_nam, char *lex, int scope, int line_no, int col_start, int col_end);
void Display(symtab_t *table);
//Functions used in parser for semantic analysis
int checkScope(char* var, int curr_scope);
int check_variable(symtab_t* table, char* var);
int typeCheck(char *type1, char *type2);

#if 0
node_t* create_node(int sl_no, char *tok, char *lex){
  node_t *node = (node_t*)malloc(sizeof(node_t));
  node->ptr = sl_no;
  strcpy(node->token_name,tok);
  strcpy(node->lexem,lex);

  return node;
}

void display_token(node_t *node){
  printf("<%s, %d>\n", node->token_name, node->ptr);
}
node_t* exists(char* tok_name){
  return NULL;
}
void insert(symtab_t *table, char *tok_nam, char *lex){
  node_t *get_row = exists(tok_nam);
  if(!get_row){
    ++sl_no;
    node_t *new_node = create_node(sl_no, tok_nam, lex);
    if(table->head == NULL){
      table->head = new_node;
    }
    else{
      node_t *temp = table->head;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = new_node;
    }
    display_token(new_node);
  }
  else{
    display_token(get_row);
  }
}

void Display(symtab_t *table){
  printf("Print here the entire symbol table\n");
}
#endif
#endif