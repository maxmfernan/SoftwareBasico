#include "operacoesPilhas.h"

void InicializaOperand (OPERAND_STACK **epilha) {
	*epilha = NULL;
}

void InicializaFrame (FRAME **epilha) {
	*epilha = NULL;
}

void InicializaPilha (void **epilha) {
	*epilha = NULL;
}

int PilhaFrameVazia (FRAME *pilha) {
	return (pilha == NULL);
}

int PilhaOperandVazia (OPERAND_STACK *pilha) {
	return (pilha == NULL);
}

int PilhaVazia (void *pilha) {
	return (pilha == NULL);
}

u4 TopoFramePilha(FRAME *pilha) {
	if(pilha != NULL) {
		return pilha->pc;
	}
	else {
		return -1;
	}

}
u1 TopoOperandPilha(OPERAND_STACK *pilha) {
	if(pilha != NULL) {
		return pilha->operand_type;
	}
	else {
		return '0';
	}
}

void PushOperandoPilha(OPERAND_STACK **epilha, OPERAND_STACK *new_operand) {
	if ((*epilha) == NULL) {
		*epilha = new_operand;
	}
	else {

		new_operand->prox = (*epilha);
		*epilha = new_operand;
	}
}

void PushFramePilha(FRAME **epilha, FRAME *new_frame) {
	if ((*epilha) == NULL) {
		*epilha = new_frame;
	}
	else {
		
		new_frame->prox = (*epilha);
		*epilha = new_frame;
	}
}

OPERAND_STACK* PopOperandoPilha(OPERAND_STACK **epilha) {
	if ((*epilha) != NULL) {
		OPERAND_STACK *aux = *epilha;
		*epilha = (*epilha)->prox;
		return aux;
	}
	else {
		return NULL;
	}
}

FRAME* PopFramePilha(FRAME **epilha) {
	
	if ((*epilha) != NULL) {
		FRAME *aux = *epilha;
		*epilha = (*epilha)->prox;
		return aux;
	}
	else {
		return NULL;
	}

}

OPERAND_STACK *coloca(void *new_item, int tipo){
    OPERAND_STACK *item, new_operand1;
    unsigned int aux[0];

    item = &new_operand1;
    memcpy (aux,new_item,4);
    new_operand1.type.u_int_number = aux[0];
    new_operand1.prox = NULL;
    new_operand1.operand_type = tipo;


    return item;
}
OPERAND_STACK *divide(void *new_item, int tipo){
    OPERAND_STACK *item, new_operand1, new_operand2;
    unsigned int aux[1];

    item = &new_operand1;
    memcpy (aux,new_item,8);
    new_operand1.type.u_int_number = aux[1];
    new_operand1.prox = &new_operand2;
    new_operand1.operand_type = TYPE_INT_U;

    new_operand2.type.u_int_number = aux[0];
    new_operand2.prox = NULL;
    new_operand2.operand_type = TYPE_INT_U;


    return item;
}
