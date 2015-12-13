#include "loads.h"


/********************TESTADA ok************************************************/
void fload (OPERAND_STACK **pilha, ITEM_VECTOR **vetor, int index_vector){
	ITEM_VECTOR *aux = (*vetor);
	while((aux->index_item != index_vector)&&( aux != NULL)){
		aux = aux->prox;
	}
	if(aux != NULL){
        OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
        newItem->operand_type = TYPE_FLOAT;
        (newItem->type).float_number = (aux->type).float_number;
        newItem->prox = NULL;

        PushOperandoPilha(&(*pilha), newItem);
	}
	/*printVetor(*vetor);*/
}
/*********************TESTADA ok**********************************************/
void iload (OPERAND_STACK **pilha, ITEM_VECTOR **vetor, int index_vector){
	ITEM_VECTOR *aux = (*vetor);
	while((aux != NULL)&&(aux->index_item != index_vector)){
		aux = aux->prox;
	}
	if(aux!=NULL){
        OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
        newItem->operand_type = TYPE_INT;
        (newItem->type).int_number = (aux->type).int_number;
        newItem->prox = NULL;
        PushOperandoPilha(&(*pilha), newItem);
	}
	/*printVetor(*vetor);*/
}
/**********************TESTADA ok**********************************************/

void lload (OPERAND_STACK **pilha, ITEM_VECTOR **vetor, int index_vector){
	ITEM_VECTOR *aux = (*vetor);

	while((aux->index_item != index_vector)&&( aux != NULL)){
		aux = aux->prox;
	}
	if (aux!=NULL){
        OPERAND_STACK *newItem1 = malloc(sizeof(OPERAND_STACK));
        newItem1->operand_type = TYPE_LONG;
        (newItem1->type).u_int_number = (aux->type).u_int_number;
        newItem1->prox = NULL;
        OPERAND_STACK *newItem2 = malloc(sizeof(OPERAND_STACK));
        newItem2->operand_type = TYPE_LONG;
        (newItem2->type).u_int_number = (aux->prox->type).u_int_number;
        newItem2->prox = NULL;
        PushOperandoPilha(&(*pilha), newItem1);
        PushOperandoPilha(&(*pilha), newItem2);
	}
	/*printVetor(*vetor);*/
}
/********************ERRO!!!!!*********************************************/
/*
void dload (OPERAND_STACK **pilha, ITEM_VECTOR **vetor, int index_vector){
	ITEM_VECTOR *aux = (*vetor);
    unsigned int *iAux = calloc(2,sizeof(unsigned int)), *p1;;
    printf("DLOAD;");
	while((aux->index_item != index_vector)&&( aux != NULL)){
		aux = aux->prox;
	}
	printf("DLOAD;");
	if (aux!=NULL){
	    iAux[0]= (aux->type).u_int_number;
	    iAux[1]= (aux->prox->type).u_int_number;
        OPERAND_STACK *newItem1 = malloc(sizeof(OPERAND_STACK));
        newItem1->operand_type = TYPE_INT_U;
        *p1=&(newItem1->type).u_int_number;
        memcpy(p1,iAux[0],4);
        newItem1->prox = NULL;
        OPERAND_STACK *newItem2 = malloc(sizeof(OPERAND_STACK));
        newItem2->operand_type = TYPE_INT_U;
        *p1=&(newItem2->type).u_int_number;
        memcpy(p1,iAux[1],4);
        newItem2->prox = NULL;
        PushOperandoPilha(&(*pilha), newItem1);
        PushOperandoPilha(&(*pilha), newItem2);
	}
	printf("dload");
}*/
/**********************TESTADA ok**********************************************/

void iaload (OPERAND_STACK **epilha){
	int pindexint, *parrayint;
	OPERAND_STACK *pindex = PopOperandoPilha(&(*epilha));
	OPERAND_STACK *parray = PopOperandoPilha(&(*epilha));
	parrayint=(parray->type).vector_ref;
	pindexint=(pindex->type).int_number;
	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_INT;
	(newItem->type).int_number=parrayint[pindexint];
	newItem->prox = NULL;
	PushOperandoPilha(&(*epilha), newItem);
}

/**********************TESTADA ok**********************************************/
void faload (OPERAND_STACK **epilha){
	float *parrayfloat;
	int pindexfloat;
	OPERAND_STACK *pindex = PopOperandoPilha(&(*epilha));
	OPERAND_STACK *parray = PopOperandoPilha(&(*epilha));;
	parrayfloat = (float*)(parray->type).vector_ref;
	pindexfloat = (pindex->type).int_number;
	/*printf("%d", pindexfloat);*/
	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_FLOAT;
	(newItem->type).float_number=parrayfloat[pindexfloat];
	newItem->prox = NULL;
	PushOperandoPilha(&(*epilha), newItem);
}
/**********************TESTADA ok***********************************************/

void laload (OPERAND_STACK **epilha){
	long long int *parrayui, *p;
	int pindexui;
	unsigned int *paux;

	unsigned int *iAux = calloc(2, sizeof(unsigned int));

	OPERAND_STACK *pindex = PopOperandoPilha(&(*epilha));
	OPERAND_STACK *parray = PopOperandoPilha(&(*epilha));
	parrayui = (long long int *)(parray->type).vector_ref;
	pindexui = (pindex->type).int_number;
	p = &parrayui[pindexui];
	memcpy(iAux,p,8);
	OPERAND_STACK *newItem1 = malloc(sizeof(OPERAND_STACK));
	newItem1->operand_type = TYPE_LONG;
	OPERAND_STACK *newItem2 = malloc(sizeof(OPERAND_STACK));
	newItem2->operand_type = TYPE_LONG;
	paux = &((newItem1->type).u_int_number);
	memcpy(paux,iAux,4);
	(newItem1->type).u_int_number = *paux;
	paux = &((newItem2->type).u_int_number);
	memcpy(paux, &iAux[1],4);
    (newItem2->type).u_int_number = *paux;
	PushOperandoPilha(&(*epilha), newItem1);
	PushOperandoPilha(&(*epilha), newItem2);
}

/******************************************************************************/
void caload (OPERAND_STACK **epilha){
	char *parraychar;
	int pindexchar;
	OPERAND_STACK *pindex = PopOperandoPilha(&(*epilha));
	OPERAND_STACK *parray = PopOperandoPilha(&(*epilha));;
	parraychar = (char*)(parray->type).vector_ref;
	pindexchar=(pindex->type).int_number;
	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_INT;
	(newItem->type).int_number = parraychar[pindexchar];
	newItem->prox = NULL;
	PushOperandoPilha(&(*epilha), newItem);
}

/******************************************************************************/

/*-----------------TESTADA OK--------------------------------------------*/
void saload (OPERAND_STACK **epilha){
	short *parrayshort, *paux1;
	int pindexshort, *paux2;
	OPERAND_STACK *pindex = PopOperandoPilha(&(*epilha));
	OPERAND_STACK *parray = PopOperandoPilha(&(*epilha));;
	parrayshort=(short *)(parray->type).vector_ref;
	pindexshort=(pindex->type).int_number;
	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_SHORT;
	paux1 = &(parrayshort[pindexshort]);
	*paux2 = (newItem->type).int_number;
	memcpy(paux2,paux1,2);
	(newItem->type).int_number = *paux2;
	newItem->prox = NULL;
	PushOperandoPilha(&(*epilha), newItem);
}
/*--------------TESTADA OK--------------------------------------------*/

void dload (OPERAND_STACK **epilha, ITEM_VECTOR **vetor, int index_vector){
	ITEM_VECTOR *aux = (*vetor);
    unsigned int *iAux = calloc(2,sizeof(unsigned int));
	while((aux != NULL)&&(aux->index_item != index_vector)){
		aux = aux->prox;
	}
	if (aux!=NULL){

	    iAux[0]= (aux->type).u_int_number;
	    iAux[1]= (aux->prox->type).u_int_number;
	    
        OPERAND_STACK *newItem1 = malloc(sizeof(OPERAND_STACK));
        newItem1->operand_type = TYPE_DOUBLE;
       (newItem1->type).u_int_number=iAux[0];
        newItem1->prox = NULL;
        OPERAND_STACK *newItem2 = malloc(sizeof(OPERAND_STACK));
        newItem2->operand_type = TYPE_DOUBLE;
        (newItem2->type).u_int_number=iAux[1];
        newItem2->prox = NULL;
        PushOperandoPilha(&(*epilha), newItem1);
        PushOperandoPilha(&(*epilha), newItem2);
	}
	/*printVetor(*vetor);*/
}
/*----------------------TESTADA OK-------------------------------*/
void aload (OPERAND_STACK **epilha, ITEM_VECTOR **vetor, int index_vector){
	ITEM_VECTOR *aux = (*vetor);

	while((aux->index_item != index_vector)&&( aux != NULL)){
		aux = aux->prox;
	}
	if (aux!=NULL){
	    OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
        newItem->operand_type = TYPE_ARRAY;
        (newItem->type).object_ref = (CLASS *)(aux->type).vector_ref;
        newItem->prox = NULL;
        /*printf("-> >%d< <-\n",*(newItem->type).vector_ref );*/
        PushOperandoPilha(&(*epilha), newItem);
	}
	/*printVetor(*vetor);*/
}
/******************************************************************************/
void newarray(OPERAND_STACK **epilha, u1 atype){
    u1 count;
    OPERAND_STACK *pcount = PopOperandoPilha(&(*epilha));
    OPERAND_STACK *parrayref;
    void *vetor;
    count = (pcount->type).int_number;
    short int end= 0xfd00|count;
    switch (atype){
        case 4:/*Boolean*/
            vetor = (u1 *)calloc(count+2,sizeof(u1));
            u1 *aux = (u1*)vetor;
            aux[count] = 0xfd;
            aux[count+1] = count;
            break;
        case 5:/*Char*/
            vetor = calloc(count+2,sizeof(u1));
            u1 *aux2 = (u1*)vetor;
            aux2[count] = 0xfd;
            aux2[count+1] = count;
            break;
        case 6:/*Float*/
            vetor = calloc(count+1,sizeof(float));
            float *aux3 = (float*)vetor;
            memcpy(&aux3[count],&end,2);
            break;
        case 7:/*Double*/
            vetor = calloc(count+1,sizeof(double));
            double *aux4 = (double*)vetor;
            memcpy(&aux4[count],&end,2);
            break;
        case 8:/*Byte*/
            vetor = calloc(count+2,sizeof(u1));
            u1 *aux5 = (u1*)vetor;
            aux5[count] = 0xfd;
            aux5[count+1] = count;
            break;
        case 9:/*Short*/
            vetor = calloc(count+1,sizeof(short int));
            short int *aux6 = (short int*)vetor;
            memcpy(&aux6[count],&end,2);
            break;
        case 10:/*Int*/
            vetor = calloc(count+1,sizeof(int));
            int *aux7 = (int*)vetor;
            memcpy(&aux7[count],&end,2);
            break;
        case 11:/*Long*/
            vetor = calloc(count+1,sizeof(long long int));
            long long int *aux8 = (long long int*)vetor;
            memcpy(&aux8[count],&end,2);
            break;
    }

    parrayref = malloc(sizeof(OPERAND_STACK));
    parrayref->operand_type = TYPE_ARRAY;
    parrayref->type.vector_ref = vetor;
    parrayref->prox = NULL;

    PushOperandoPilha(epilha,parrayref);
}

void arraylength(OPERAND_STACK **epilha)
{
    OPERAND_STACK *parrayref,*length;
    parrayref = PopOperandoPilha(epilha);

    u1 *aux;

    aux = (u1*)parrayref->type.vector_ref;

    int i=0;
    /*while(aux[i] != 0xfd)*/
    int teste = (int)aux[i];
    while(teste != 253)
    {
        i++;
    }
    u1 byte = aux[i+1];

    length = malloc(sizeof(OPERAND_STACK));
    length->operand_type = TYPE_INT;
    length->type.int_number = (int)byte;
    length->prox = NULL;

    PushOperandoPilha(epilha,length);
}

void aaload (OPERAND_STACK **epilha){
	int pindexint;
	CLASS *(*parrayobj);
	OPERAND_STACK *pindex = PopOperandoPilha(&(*epilha));
	OPERAND_STACK *parray = PopOperandoPilha(&(*epilha));
	
	parrayobj = (CLASS**)(parray->type).object_ref;
	pindexint = (pindex->type).int_number;
	
	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_OBJ_REF;
	
	(newItem->type).object_ref = parrayobj[pindexint];
	newItem->prox = NULL;
	PushOperandoPilha(&(*epilha), newItem);
}

