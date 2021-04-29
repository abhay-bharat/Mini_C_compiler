#ifndef QUAD_TABLE
#define QUAD_TABLE
#include<stdbool.h>

struct quad{
	char* op;
	char* arg1;
    char* arg2;
    char* result;
    struct quad* next;
};
typedef struct quad ir_quad;

struct quad_head{
	ir_quad* head;
};
typedef struct quad_head quad_head;

ir_quad* create_quad_node(char* op, char* arg1, char* arg2, char* result);
void insert_ir(quad_head* quad, char* op, char* a1, char* a2, char* result);
void display_ir(quad_head* quad);
//Code optimisation functions 
void code_optimisation(quad_head* quad);
bool check_assignment_only(ir_quad* node);
bool is_number(char* s);
void perform_const_propagation(quad_head* quad, ir_quad* const_node);
bool is_reassignment(ir_quad* prev, ir_quad* curr, int* assign_flag);

#endif