//for IR code optimization, read ICG.code file and process the file to generate the optimised IR
#include <stdio.h>
#include <stdlib.h>

// void const_propagation_optim(FILE* ir_fp, FILE* op_fp){
// 	//currently does only one constant propagation
// 	char* instrn_line = NULL;
// 	char ch;
// 	while(!feof(ir_fp)){
// 		int flag = 0;
// 		instrn_line = malloc(100*sizeof(char));
// 		int val = 0;
// 		char variable[3];
// 		while((ch = fgetc(ir_fp)) != '\n'){
// 			*instrn_line = ch;
// 			++instrn_line;
// 			if(ch == '=')
// 				flag = 1;
// 		}
// 		//if flag is set impling that it has assignment and can be possible candidate for constant propagation
// 		if(flag){
// 			if(has_constant_propagation(instrn_line)){
// 				//store that constant along with the variable in the temp variables
// 			}
// 		}
// 	}
// }

// int main(){
// 	FILE* icg_fp = fopen("ICG.code", "r");
// 	FILE* op_fp = fopen("ICG_optimised.code", "w");
// 	if(icg_fp == NULL)
// 		printf("Error while opening file\n");
// 	printf("\n----------------------------------------------------------------\n");
//   	printf("\t\tIntermediate Code");
//   	printf("\n----------------------------------------------------------------\n\n");
// 	display(icg_fp);

// 	//constant propagation optimisation 
// 	const_propagation_optim(icg_fp, op_fp);
// 	fclose(icg_fp);
// 	fclose(op_fp);
// 	return 0;
// }

void display(FILE* icg_fp){
	char ch;
	while(!feof(icg_fp)){
		ch = fgetc(icg_fp);
		printf("%c", ch);
	}
}

//code to remove the constant assignment instruction
void reset_pointer(ir_quad* head, ir_quad* const_node){
	ir_quad* curr = head;
	ir_quad* prev = curr;
	while(curr != NULL && curr != const_node){
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(const_node);
}

//replaces the variable with the constant in the instruction using it
void perform_const_propagation(ir_quad* head, ir_quad* const_node){
	ir_quad* temp = head;
	while(temp != NULL){
		if(temp != const_node){
			// int flag = 0;
			//check whether arg1 or arg2 have that variable which is constant propagated
			if(temp->arg1 != NULL && !strcmp(temp->arg1, const_node->result)){
				strcpy(temp->arg1, const_node->arg1);
				// flag = 1; 
			}
			else if(temp->arg2 != NULL && !strcmp(temp->arg2, const_node->result)){
				strcpy(temp->arg2, const_node->arg1);
				// flag = 1;
			}
		}
		temp = temp->next;
	}
	//reset the pointers after all the constant propagations have been done
	//removing the const_node
	reset_pointer(head, const_node);
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

void const_propagation(ir_quad* head){
	ir_quad* temp = head;
	//store all the pointers to the node performing constant assignment instruction
	ir_quad* arr_ptr[20] = {[0 ... 19] = NULL}; //array of pointers to the node
	int cnt = 0;
	while(temp != NULL){
		if(check_assignment_only(temp)){
			arr_ptr[cnt] = temp;
			++cnt; 
		}
		temp = temp->next;
	}
	// temp = head;
	//now take one by one assignment instruction and perform constant propagation
	for(int i = 0; i < cnt; ++i){
		ir_quad* temp_node = arr_ptr[i];
		//use this constant for propagation
		perform_const_propagation(head, temp_node);
	}
}

void const_folding(ir_quad* head){
	/* Implementation pending */
}

void store_in_file(ir_quad* head, FILE* fp){
	/* Implementation pending */
}

void code_optimisation(ir_quad* quad_head){
	//opening the icg code and display it
	FILE* icg_fp = fopen("ICG.code", "r");
	if(icg_fp == NULL)
		printf("Error while opening file\n");
	printf("\n----------------------------------------------------------------\n");
  	printf("\t\tIntermediate Code");
  	printf("\n----------------------------------------------------------------\n\n");
	display(icg_fp);

	//perform constant propagation 
	const_propagation(quad_head);

	//perform constant folding
	const_folding(quad_head);

	//store the optimised code quadruple representation into the file
	FILE* ir_op_fp = fopen("ICG_optimised.code", "w");
	store_in_file(quad_head, ir_op_fp);

	//display the optimised code 
	printf("\n----------------------------------------------------------------\n");
  	printf("\t\tIntermediate Optimised Code");
  	printf("\n----------------------------------------------------------------\n\n");
	display(ir_op_fp);

	//close the files opened
	fclose(icg_fp);
	fclose(ir_op_fp);
}
