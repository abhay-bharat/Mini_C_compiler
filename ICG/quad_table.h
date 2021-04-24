#ifndef QUAD_TABLE
#define QUAD_TABLE

struct quad{
	//int sl_no;
	char[20] op;
	char[20] arg1;
    char[20] arg2;
    char[20] result;
    struct quad* next;
};
typedef struct quad ir_quad;

void insert(char* op, char* a1, char* a2, char* result);
ir_quad* create_node(char* op, char* a1, char* a2, char* result);
void display_ir(ir_quad* head);