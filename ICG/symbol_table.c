#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

int sl_no = 0;


node_t *create_node(int sl_no, char *tok, char *lex, double value, int scope,int line, int col_s, int col_e)
{
  node_t *node = (node_t *)malloc(sizeof(node_t));
  node->ptr = sl_no;
  // strcpy(node->token_name, tok);
  // strcpy(node->lexem, lex);
  node->token_name = strdup(tok);
  node->lexem = strdup(lex);
  node->scope = scope; 
  node->column_st = col_s;
  node->column_end = col_e;
  node->line_no = line;
  node->data_type = NULL;
  node->value = value;
  return node;
}

void display_token(node_t *node)
{
  printf("<%s, %d>\n", node->token_name, node->ptr);
}

node_t *exists(symtab_t *table, char *lex, int scope)
{
  node_t *temp = table->head;
  while (temp != NULL)
  {
    if (strcmp(temp->lexem, lex) == 0 && temp->scope >= scope) //need to handle this, because can have different scope in different section of program. This would only if used during declaration
      return temp;
    temp = temp->next;
  }
  return NULL;
}

void insert(symtab_t *table, char *tok_nam, char *lex, double value, int scope,int line, int col_s, int col_e)
{
  node_t *get_row = exists(table, lex, scope);
  if (!get_row)
  {
    ++sl_no;
    node_t *new_node = create_node(sl_no, tok_nam, lex, value, scope,line, col_s, col_e);
    if (table->head == NULL)
    {
      table->head = new_node;
    }
    else
    {
      node_t *temp = table->head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = new_node;
    }
    //display_token(new_node);
  }
  else
  {
    //display_token(get_row);
  }
}

void Display(symtab_t *table)
{
  printf("\n****************************************************************************\n");
  printf("\t\t\t SYMBOL TABLE \t\t\t");
  printf("\n****************************************************************************\n\n");
  printf("|\tpointer\t|\ttoken_name\t|\tlexeme\t|   data_type   |\t Scope \t|   Line no.    | Column_start  |  Column_end   |\n");
  printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
  node_t *temp = table->head;
  node_t* prev = temp;
  while(temp != NULL){
    if(temp->data_type){
    printf("|\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", temp->ptr, temp->token_name, temp->lexem, temp->data_type, temp->scope, temp->line_no, temp->column_st, temp->column_end);
    prev = temp;
    temp = temp->next;
    }
    else{
      node_t* temp_1 = temp;
      prev->next = temp_1->next;
      free(temp_1);
      temp = prev->next;
    }
  }
}
