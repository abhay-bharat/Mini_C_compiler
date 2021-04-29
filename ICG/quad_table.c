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