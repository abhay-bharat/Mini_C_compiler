#include "quad_table.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>


ir_quad* create_quad_node(char* op, char* arg1, char* arg2, char* result)
{
    ir_quad* new_node = (ir_quad*)malloc(sizeof(ir_quad));
    if(op != NULL)  new_node->op = strdup(op);
    else    new_node->op = NULL;
    if(arg1 != NULL)    new_node->arg1 = strdup(arg1);
    else    new_node->arg1 = NULL;
    if(arg2 != NULL)    new_node->arg2 = strdup(arg2);
    else    new_node->arg2= NULL;
    if(result != NULL)  new_node->result = strdup(result);
    else    new_node->result = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_ir(quad_head* quad, char* op, char* a1, char* a2, char* result)
{
    ir_quad* new_node = create_quad_node(op, a1, a2, result);
    if(quad->head == NULL)
    {
        quad->head = new_node;
    }
    else
    {
        ir_quad* temp = quad->head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display_ir(quad_head* quad)
{
    if(quad->head == NULL)
        return;
    printf("\n\n****************************************************************************\n");
    printf("\t\t\t Quadruple table \t\t\t");
    printf("\n****************************************************************************\n\n");
    printf("|\top\t|\targ1\t|\targ2\t|\tresult\t|\n");
    printf("-----------------------------------------------------------------\n");
    ir_quad* temp = quad->head;
    while(temp != NULL)
    {
        printf("|\t%s\t|\t%s\t|\t%s\t|\t%s\t|\n", temp->op, temp->arg1, temp->arg2, temp->result);
        temp = temp->next;
    }
    

}

///////////////////////////////////
//Intermediate Code optimisation//
/////////////////////////////////

//code to remove the constant assignment instruction
void reset_pointer(quad_head* quad, ir_quad* const_node){
  ir_quad* curr = quad->head;
  ir_quad* prev = curr;
  while(curr != NULL && curr != const_node){
    prev = curr;
    curr = curr->next;
  }
  if(curr == quad->head)
    quad->head = prev->next;
  else
    prev->next = curr->next;
  free(const_node);
}

bool is_reassignment(ir_quad* prev, ir_quad* curr, int* assign_flag){
    //first check if the current node is an assignment type instruction
    if(!check_assignment_only(curr))
        return false;
    else{ //check if the same variable is beign reassgined
        if(strcmp(prev->result, curr->result) == 0){
            *assign_flag = 1;
            return true;
        }
        else
            return false;
    }
}

//replaces the variable with the constant in the instruction using it
//Also handles constant assignment deadcode elimination
void perform_const_propagation(quad_head* quad, ir_quad* const_node){
  ir_quad* temp = const_node->next;
  int flag = 0;
  int reassigned = 0;
  //is_reassignment function is needed because, if the variable gets reassigned while performing constant propagation
  //then further nodes using that variable should get the new value
  //so halt when found reassignment
  while(temp != NULL && !is_reassignment(const_node, temp, &reassigned)){
      //check whether arg1 or arg2 have that variable which is constant propagated
      if(temp->arg1 != NULL && !strcmp(temp->arg1, const_node->result)){
        strcpy(temp->arg1, const_node->arg1);
        flag = 1; 
      }
      else if(temp->arg2 != NULL && !strcmp(temp->arg2, const_node->result)){
        strcpy(temp->arg2, const_node->arg1);
        flag = 1;
      }
    temp = temp->next;
  }
  //reset the pointers after all the constant propagations have been done
  //removing the const_node
  if(flag || reassigned)
    reset_pointer(quad, const_node);
}

//can be integer, float, double 
bool is_number(char* s){
  //works if null character ('\0') is stored at the end
  while(*s){
    char c = *s;
    switch(c){
    case '.' : break;
    case '+' : break;
    case '-' : break;
    default : if(c < '0' || c > '9') //checks the ASCII value
          return false;
    }
    ++s;
  }
  return true;
}

bool check_assignment_only(ir_quad* node){
  if(strcmp(node->op,"=") != 0)
    return false;
  else{
    if(node->arg1 != NULL && node->arg2 == NULL && is_number(node->arg1)){ //eg. u = 1 =>: =, 1, null, u
      return true;
    }
    else
      return false;
  }
}

void const_propagation(quad_head* quad){
  if(quad->head == NULL)
    return;
  ir_quad* temp = quad->head;
  //store all the pointers to the node performing constant assignment instruction
  while(temp != NULL){
    if(check_assignment_only(temp)){
        perform_const_propagation(quad, temp);
    }
    temp = temp->next;
  }
}

void deadcode_elimination(quad_head* quad){

}

void const_folding(quad_head* quad){
  /* Implementation pending */
}

void code_optimisation(quad_head* quad){

  //perform deadcode elimination(does only for unnecessary assignments)
  deadcode_elimination(quad);

  //perform constant propagation 
  const_propagation(quad);

  //perform constant folding
  const_folding(quad);
}