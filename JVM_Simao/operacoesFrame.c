#include "operacoesFrame.h"

void cria_Frame(FRAME **new_frame, METHOD *method, CLASS *classi, ConstantPoolItem *constPool){
	(*new_frame) = malloc(sizeof(FRAME));
    CODE *code = (method->attributes->type).code;
	
    (*new_frame)->max_stack_depth = code->max_stack;
    (*new_frame)->max_local_variables = code->max_locals;
    (*new_frame)->code_Size = code->code_length;
    (*new_frame)->pc = 0;
	
	char *strCode;
	strCode = malloc(code->code_length);
	(*new_frame)->code = strCode;
	
    (*new_frame)->this_method = method;
    (*new_frame)->this_class = classi;
    (*new_frame)->ref_Const_Pool = constPool;
    (*new_frame)->operand_stack = NULL;
    (*new_frame)->local_vector = NULL;
	(*new_frame)->prox = NULL;
	
}
