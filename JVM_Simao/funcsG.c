/*
 *  funcsG.c
 *
 *
 *  Created by Carolina Oliveira on 7/21/12.
 *  Copyright 2012 UnB. All rights reserved.
 *
 */

#include "funcsG.h"

/*returns*/

void areturn(FRAME **freime){

    FRAME *aux1, *aux3;
    OPERAND_STACK *op1, *item;


    aux3 = *freime;

    aux1 = PopFramePilha(&aux3);

    op1 = aux1->operand_stack;

    item = PopOperandoPilha(&op1);

    PushOperandoPilha(&(aux3->operand_stack), item);

    free(aux1);

    *freime = aux3;

}


void dreturn(FRAME **freime){

    FRAME *aux1, *aux3;
    OPERAND_STACK *op1, *item, *item2 , *new_operand1, *new_operand2;


    aux3 = *freime;

    aux1 = PopFramePilha(&aux3);

    op1 = aux1->operand_stack;

    item = PopOperandoPilha(&op1);
    item2= PopOperandoPilha(&op1);

    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item2->type.u_int_number;
    new_operand1->prox = NULL;
    new_operand1->operand_type = TYPE_INT_U;
    PushOperandoPilha(&(aux3->operand_stack), new_operand1);

    new_operand2->type.u_int_number = item->type.u_int_number;
    new_operand2->prox = NULL;
    new_operand2->operand_type = TYPE_INT_U;
    PushOperandoPilha(&(aux3->operand_stack), new_operand2);

    free(aux1);

    *freime = aux3;


}



void freturn(FRAME **freime){

    FRAME *aux1, *aux3;
    OPERAND_STACK *op1, *item, *new_operand1;


    aux3 = *freime;

    aux1 = PopFramePilha(&aux3);

    op1 = aux1->operand_stack;

    item = PopOperandoPilha(&op1);

    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.float_number = item->type.float_number;
    new_operand1->prox = NULL;
    new_operand1->operand_type = TYPE_FLOAT;
    PushOperandoPilha(&(aux3->operand_stack), new_operand1);

    free(aux1);

    *freime = aux3;

}




/*ireturn: */
void ireturn(FRAME **freime){

    FRAME *aux1, *aux3;
    OPERAND_STACK *op1, *item, *new_operand1;


    aux3 = *freime;

    aux1 = PopFramePilha(&aux3);

    op1 = aux1->operand_stack;

    item = PopOperandoPilha(&op1);

    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.int_number = item->type.int_number;
    new_operand1->prox = NULL;
    new_operand1->operand_type = TYPE_INT;
    PushOperandoPilha(&(aux3->operand_stack), new_operand1);

    free(aux1);

    *freime = aux3;

}
/*--------------------------*/




/*lreturn: */
void lreturn(FRAME **freime){

    FRAME *aux1, *aux3;
    OPERAND_STACK *op1, *item, *item2 , *new_operand1, *new_operand2;


    aux3 = *freime;

    aux1 = PopFramePilha(&aux3);

    op1 = aux1->operand_stack;

    item = PopOperandoPilha(&op1);
    item2= PopOperandoPilha(&op1);

    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item2->type.u_int_number;
    new_operand1->prox = NULL;
    new_operand1->operand_type = TYPE_INT_U;
    PushOperandoPilha(&(aux3->operand_stack), new_operand1);

    new_operand2->type.u_int_number = item->type.u_int_number;
    new_operand2->prox = NULL;
    new_operand2->operand_type = TYPE_INT_U;
    PushOperandoPilha(&(aux3->operand_stack), new_operand2);

    free(aux1);

    *freime = aux3;

}
/*--------------------------*/




/*returne: */
void returne(FRAME **freime){

    FRAME *aux1, *aux3;

    aux1 = PopFramePilha(freime);

}
/*--------------------------*/






/*Operacoes Aritmeticas*/

/*doubles_arith*/
void dadd(OPERAND_STACK **op_stack){

    double *d1, *d2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    d1 = malloc(sizeof(double));
    d2 = malloc(sizeof(double));

    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d2,item,8);

    *d1 = (*d1) + (*d2);
    /*printf("valor : %f\n",*d1);*/
    /*getchar()*/
    memcpy (item,d1,8);
    
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

}




void ddiv(OPERAND_STACK **op_stack){

    double *d1, *d2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    d1 = malloc(sizeof(double));
    d2 = malloc(sizeof(double));

    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d2,item,8);

    *d1 = (*d2) / (*d1);
    memcpy (item,d1,8);
    
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

	*op_stack = aux3;

}



void dmul(OPERAND_STACK **op_stack){

    double *d1, *d2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    d1 = malloc(sizeof(double));
    d2 = malloc(sizeof(double));

    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d2,item,8);

    *d1 = (*d1) * (*d2);
    memcpy (item,d1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

	*op_stack = aux3;

}



void dneg(OPERAND_STACK **op_stack){

    double *d1;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    d1 = malloc(sizeof(double));

    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d1,item,8);

    *d1 = -(*d1);
    memcpy (item,d1,8);
    
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;


}



void drem_nova(OPERAND_STACK **op_stack){

    double *d1, *d2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    d1 = malloc(sizeof(double));
    d2 = malloc(sizeof(double));

    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d2,item,8);

    *d1 = fmod((*d2), (*d1));
    memcpy (item,d1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lf", *d1);*/

}



void dsub(OPERAND_STACK **op_stack){

    double *d1, *d2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    d1 = malloc(sizeof(double));
    d2 = malloc(sizeof(double));

    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[1] = aux2->type.u_int_number;
    item[0] = aux1->type.u_int_number;
    memcpy(d2,item,8);

    *d1 = (*d2) - (*d1);
    memcpy (item,d1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lf", *d1);*/

}







/*int_arith*/
/*ineg: */
void ineg(OPERAND_STACK **op_stack){

    int *i1;
    OPERAND_STACK *aux1, *aux3, *new_operand1;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    *i1 = -(*i1);

    memcpy (item,i1,4);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.int_number = *item;
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    (*op_stack) = aux3;

    /*printf("%d", *i1);*/

}
/*--------------------------*/




/*ishl: */
void ishl(OPERAND_STACK **op_stack){

    int *i1, *i2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    i2 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    *item = aux2->type.int_number;
    memcpy(i2,item,4);

    *i1 <<= 27;
    *i1 >>= 27;

    *i1 = (*i2) << (*i1);
    memcpy (item,i1,4);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.int_number = *item;
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    *op_stack = aux3;

    /*printf("%d", *i1);*/

}
/*--------------------------*/



/*ishr: */
void ishr(OPERAND_STACK **op_stack){

    int *i1, *i2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    i2 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    *item = aux2->type.int_number;
    memcpy(i2,item,4);

    *i1 <<= 27;
    *i1 >>= 27;
    
    *i2 >>= (*i1);

    memcpy (item,i2,4);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.int_number = *item;
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    *op_stack = aux3;

    /*printf("%d", *i1);*/

}
/*--------------------------*/




/*isub: */
void isub(OPERAND_STACK **op_stack){

    int *i1, *i2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    i2 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    *item = aux2->type.int_number;
    memcpy(i2,item,4);

    *i1 = (*i2) - (*i1);
    memcpy (item,i1,4);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.int_number = *item;
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    *op_stack = aux3;

    /*printf("%d\n", (*op_stack)->type.int_number);*/

}
/*--------------------------*/




/*Long_Arith*/

/*ladd: */
void ladd(OPERAND_STACK **op_stack){

    long long int *l1, *l2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux1 = PopOperandoPilha(op_stack);
    aux2 = PopOperandoPilha(op_stack);

    l1 = malloc(sizeof(long long int));
    l2 = malloc(sizeof(long long int));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    aux1 = PopOperandoPilha(op_stack);
    aux2 = PopOperandoPilha(op_stack);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l2,item,8);

    *l1 = (*l1) + (*l2);
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(op_stack, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(op_stack, new_operand2);

    /*printf("%lld", *l1);*/

}
/*--------------------------*/




void land(OPERAND_STACK **op_stack){

    long long int *l1, *l2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    l1 = malloc(sizeof(long long int));
    l2 = malloc(sizeof(long long int));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l2,item,8);

    *l1 = (*l1) & (*l2);
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lld", *l1);*/

}




/*ldiv: */
void ldivi(OPERAND_STACK **op_stack){
    long long int *l1, *l2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;


    aux1 = PopOperandoPilha(op_stack);
    aux2 = PopOperandoPilha(op_stack);

    l1 = malloc(sizeof(long long int));
    l2 = malloc(sizeof(long long int));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    aux1 = PopOperandoPilha(op_stack);
    aux2 = PopOperandoPilha(op_stack);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l2,item,8);

    *l1 = (*l2) / (*l1);
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(op_stack, new_operand1);

    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(op_stack, new_operand2);


    /*printf("%lld", *l1);*/

}
/*--------------------------*/




/*lmul: */
void lmul(OPERAND_STACK **op_stack){

    long long int *l1, *l2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    /*aux3 = *op_stack;*/

    aux1 = PopOperandoPilha(op_stack);
    aux2 = PopOperandoPilha(op_stack);

    l1 = malloc(sizeof(long long int));
    l2 = malloc(sizeof(long long int));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    aux1 = PopOperandoPilha(op_stack);
    aux2 = PopOperandoPilha(op_stack);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l2,item,8);

    *l1 = (*l1) * (*l2);
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = TYPE_LONG;
    PushOperandoPilha(op_stack, new_operand1);

    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = TYPE_LONG;
    PushOperandoPilha(op_stack, new_operand2);

    /**op_stack = aux3;*/

    /*printf("%lld\n", *l1);*/

}
/*--------------------------*/




/*lneg: */
void lneg(OPERAND_STACK **op_stack){

    long long int *l1;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    l1 = malloc(sizeof(long long int));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    *l1 = -(*l1);
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lld", *l1);*/

}
/*--------------------------*/




/*lor: */
void lor(OPERAND_STACK **op_stack){

    long long int *l1, *l2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    l1 = malloc(sizeof(long long int));
    l2 = malloc(sizeof(long long int));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l2,item,8);

    *l1 = (*l1) | (*l2);
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lld", *l1);*/

}
/*--------------------------*/




/*lrem: */
void lrem(OPERAND_STACK **op_stack){

    long long int *l1, *l2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    l1 = malloc(sizeof(long long int));
    l2 = malloc(sizeof(long long int));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l2,item,8);

    *l1 = (*l2) % (*l1);
    memcpy (item,l1,8);
    
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lld", *l1);*/

}
/*--------------------------*/




/*lshl: */
void lshl(OPERAND_STACK **op_stack){

    long long int *l1;
    int *i1;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    l1 = malloc(sizeof(long long int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    *i1 <<= 26;
    *i1 >>= 26;

    *l1 = (*l1) << (*i1);
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lld", *l1);*/

}
/*--------------------------*/




/*lshr: */
void lshr(OPERAND_STACK **op_stack){

    long long int *l1;
    int *i1;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    l1 = malloc(sizeof(long long int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    *i1 <<= 26;
    *i1 >>= 26;

    *l1 = (*l1) >> (*i1);
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lld", *l1);*/

}
/*--------------------------*/




/*lsub: */
void lsub(OPERAND_STACK **op_stack){

    long long int *l1, *l2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    l1 = malloc(sizeof(long long int));
    l2 = malloc(sizeof(long long int));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l2,item,8);

    *l1 = (*l2) - (*l1);
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lld", *l1);*/

}
/*--------------------------*/




/*lushr: */
void lushr(OPERAND_STACK **op_stack){

    unsigned long long int *l1;
    int *i1;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    l1 = malloc(sizeof(unsigned long int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    *i1 <<= 26;
    *i1 >>= 26;


    if((*l1) < 0){
        *l1 = (*l1) >> (*i1);
        *l1 *= -1;
    }
    else{
        *l1 = (*l1) >> (*i1);
    }
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lld", *l1);*/

}
/*--------------------------*/




/*lxor: */
void lxor(OPERAND_STACK **op_stack){

    long long int *l1, *l2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1, *new_operand2;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    l1 = malloc(sizeof(long long int));
    l2 = malloc(sizeof(long long int));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l2,item,8);

    *l1 = (*l2) ^ (*l1);
    memcpy (item,l1,8);
    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand2 = malloc(sizeof(OPERAND_STACK));
    new_operand1->type.u_int_number = item[0];
    new_operand1->prox = NULL;
    new_operand1->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand1);

    new_operand2->type.u_int_number = item[1];
    new_operand2->prox = NULL;
    new_operand2->operand_type = aux1->operand_type;
    PushOperandoPilha(&aux3, new_operand2);

    *op_stack = aux3;

    /*printf("%lld", *l1);*/

}
/*--------------------------*/








/*Comparacoes*/

void dcmpg(OPERAND_STACK **op_stack){

    double *d1, *d2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    d1 = malloc(sizeof(double));
    d2 = malloc(sizeof(double));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(d1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(d2,item,8);

    if ( ((*d1) != (*d1)) || ((*d2) != (*d2))){
        new_operand1->type.int_number = 1;
        printf("NaN");
    }else{
        if((*d1) > (*d2)){
            new_operand1->type.int_number = -1;
            printf("1");
        }else{
            if((*d1) < (*d2)){
                new_operand1->type.int_number = 1;
                printf("-1");
            }else{
                new_operand1->type.int_number = 0;
                printf("0");
            }
        }
    }

    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->prox = NULL;
    new_operand1->operand_type = TYPE_INT;
    PushOperandoPilha(&aux3, new_operand1);

    *op_stack = aux3;

}




void dcmpl(OPERAND_STACK **op_stack){

    double *d1, *d2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    d1 = malloc(sizeof(double));
    d2 = malloc(sizeof(double));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(d1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(d2,item,8);

    if ( ((*d1) != (*d1)) || ((*d2) != (*d2))){
        new_operand1->type.int_number = -1;
        printf("NaN");
    }else{
        if((*d1) > (*d2)){
            new_operand1->type.int_number = -1;
            printf("1");
        }else{
            if((*d1) < (*d2)){
                new_operand1->type.int_number = 1;
                printf("-1");
            }else{
                new_operand1->type.int_number = 0;
                printf("0");
            }
        }
    }

    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->prox = NULL;
    new_operand1->operand_type = TYPE_INT;
    PushOperandoPilha(&aux3, new_operand1);

	*op_stack = aux3;

}



void fcmpg(OPERAND_STACK **op_stack){

    float *f1, *f2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    f1 = malloc(sizeof(float));
    f2 = malloc(sizeof(float));

    *item = aux1->type.float_number;
    memcpy(f1,item,4);

    *item = aux2->type.float_number;
    memcpy(f2,item,4);

    if ( ((*f1) != (*f1)) || ((*f2) != (*f2))){
        new_operand1->type.int_number = 1;
        printf("NaN");
    }else{
        if((*f1) > (*f2)){
            new_operand1->type.int_number = -1;
            printf("1");
        }else{
            if((*f1) < (*f2)){
                new_operand1->type.int_number = 1;
                printf("-1");
            }else{
                new_operand1->type.int_number = 0;
                printf("0");
            }
        }
    }

    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->prox = NULL;
    new_operand1->operand_type = TYPE_INT;
    PushOperandoPilha(&aux3, new_operand1);

    *op_stack = aux3;

}



void fcmpl(OPERAND_STACK **op_stack){

    float *f1, *f2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    f1 = malloc(sizeof(float));
    f2 = malloc(sizeof(float));

    *item = aux1->type.float_number;
    memcpy(f1,item,4);

    *item = aux2->type.float_number;
    memcpy(f2,item,4);

    if ( ((*f1) != (*f1)) || ((*f2) != (*f2))){
        new_operand1->type.int_number = -1;
        printf("NaN");
    }else{
        if((*f1) > (*f2)){
            new_operand1->type.int_number = -1;
            printf("1");
        }else{
            if((*f1) < (*f2)){
                new_operand1->type.int_number = 1;
                printf("-1");
            }else{
                new_operand1->type.int_number = 0;
                printf("0");
            }
        }
    }


    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->prox = NULL;
    new_operand1->operand_type = TYPE_INT;
    PushOperandoPilha(&aux3, new_operand1);

    *op_stack = aux3;

}




/*lcmp: */
void lcmp(OPERAND_STACK **op_stack){

    long long int *l1, *l2;
    OPERAND_STACK *aux1, *aux2, *aux3, *new_operand1;
    unsigned int *item;

    item = calloc(2,sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    l1 = malloc(sizeof(long long int));
    l2 = malloc(sizeof(long long int));

    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l1,item,8);

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);
    item[0] = aux2->type.u_int_number;
    item[1] = aux1->type.u_int_number;
    memcpy(l2,item,8);

    if((*l1) == (*l2)){
        new_operand1->type.int_number = 0;
        printf("0");
    }else{
        if((*l1) > (*l2)){
            new_operand1->type.int_number = -1;
            printf("-1");
        }else{
            new_operand1->type.int_number = 1;
            printf("1");
        }
    }

    new_operand1 = malloc(sizeof(OPERAND_STACK));
    new_operand1->prox = NULL;
    new_operand1->operand_type = TYPE_INT;
    PushOperandoPilha(&aux3, new_operand1);

    *op_stack = aux3;

}
/*--------------------------*/








/*If jump*/

void if_acmpeq(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    OPERAND_STACK *aux1, *aux2, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);


    if((aux1->type.object_ref) == (aux2->type.object_ref)){
        (*pc) += offset;
    }

	*op_stack = aux3;

    /*printf("%d", *pc);*/

}




void if_acmpne(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    OPERAND_STACK *aux1, *aux2, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);


    if((aux1->type.object_ref) != (aux2->type.object_ref)){
        (*pc) += offset;
    }

	*op_stack = aux3;

    /*printf("%d", *pc);*/

}



void if_icmpeq(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1, *i2;
    OPERAND_STACK *aux1, *aux2, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    i2 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    *item = aux2->type.int_number;
    memcpy(i2,item,4);

    if ((*i2) == (*i1)){
        (*pc) += offset;
    }

    *op_stack = aux3;

    /*printf("%d", *pc);*/

}



void if_icmpge(OPERAND_STACK **op_stack, short int offset, unsigned int *pc){

    int *i1, *i2;
    OPERAND_STACK *aux1, *aux2, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    i2 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    *item = aux2->type.int_number;
    memcpy(i2,item,4);

    if ((*i2) >= (*i1)){
        (*pc) += offset;
    }

    /*printf("%d", *pc);*/

    *op_stack = aux3;

}




void if_icmpgt(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1, *i2;
    OPERAND_STACK *aux1, *aux2, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    i2 = malloc(sizeof(int));

    *item = aux2->type.int_number;
    memcpy(i1,item,4);

    *item = aux1->type.int_number;
    memcpy(i2,item,4);

    /*printf("Valor de comparacao: %d, %d\n",*i1,*i2);*/
    if ((*i2) < (*i1)){
        (*pc) += (offset - 2);
    }

    *op_stack = aux3;

    /*printf("PC: %d\n", *pc);*/
    /*getchar()*/

}




void if_icmple(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1, *i2;
    OPERAND_STACK *aux1, *aux2, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    i2 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    *item = aux2->type.int_number;
    memcpy(i2,item,4);

    if ((*i2) <= (*i1)){
        (*pc) += offset;
    }

    *op_stack = aux3;

    /*printf("%d", *pc);*/

}




void if_icmplt(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1, *i2;
    OPERAND_STACK *aux1, *aux2, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    i2 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    *item = aux2->type.int_number;
    memcpy(i2,item,4);

    if ((*i2) < (*i1)){
        (*pc) += offset;
    }

    *op_stack = aux3;

    /*printf("%d", *pc);*/

}




void if_icmpne(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1, *i2;
    OPERAND_STACK *aux1, *aux2, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);
    aux2 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));
    i2 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    *item = aux2->type.int_number;
    memcpy(i2,item,4);

    if ((*i2) != (*i1)){
        (*pc) += offset;
    }

    *op_stack = aux3;

    /*printf("%d", *pc);*/

}




void if_eq(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1;
    OPERAND_STACK *aux1, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    if ((*i1) == 0){
        (*pc) += offset;
    }

    *op_stack = aux3;

    /*printf("%d", *pc);*/

}




void if_ge(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1;
    OPERAND_STACK *aux1, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    if ((*i1) >= 0){
        (*pc) += offset;
    }

    *op_stack = aux3;

    /*printf("%d", *pc);*/

}




void if_gt(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1;
    OPERAND_STACK *aux1, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    if ((*i1) > 0){
        (*pc) += offset;
    }

    *op_stack = aux3;

    /*printf("%d", *pc);*/

}




void if_le(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1;
    OPERAND_STACK *aux1, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    if ((*i1) <= 0){
        (*pc) += offset;
    }

    *op_stack = aux3;

    /*printf("%d", *pc);*/

}




void if_lt(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1;
    OPERAND_STACK *aux1, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    if ((*i1) < 0){
        (*pc) += offset;
    }

    *op_stack = aux3;

    /*printf("%d", *pc);*/

}




/*if_ne: */
void if_ne(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    int *i1;
    OPERAND_STACK *aux1, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    i1 = malloc(sizeof(int));

    *item = aux1->type.int_number;
    memcpy(i1,item,4);

    if ((*i1) != 0){
        (*pc) += offset;
    }

    *op_stack = aux3;

    /*printf("%d", *pc);*/

}
/*--------------------------*/




/*if_nonull: */
void if_nonnull(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    OPERAND_STACK *aux1, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    if((aux1->type.object_ref) != NULL){
        (*pc) += offset;
    }

    /*printf("%d", *pc);*/

}
/*--------------------------*/




/*if_null: */
void if_null(OPERAND_STACK **op_stack,short int offset, unsigned int *pc){

    OPERAND_STACK *aux1, *aux3;
    unsigned int *item;

    item = malloc(sizeof(unsigned int));
    *item = 0;

    aux3 = *op_stack;

    aux1 = PopOperandoPilha(&aux3);

    if((aux1->type.object_ref) == NULL){
        (*pc) += offset;
    }

    /*printf("%d", *pc);*/

}
/*--------------------------*/

