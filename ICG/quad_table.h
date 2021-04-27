#ifndef QUAD_TABLE
#define QUAD_TABLE

struct quad{
	//int sl_no;
	int op_code;
	char op[20];
	char arg1[20];
    char arg2[20];
    char result[20];
    struct quad* next;
};
typedef struct quad ir_quad;

void insert_ir(int op_code, char* op, char* a1, char* a2, char* result);
ir_quad* create_node_ir(int op_code, char* op, char* a1, char* a2, char* result);
void display_ir();

#endif