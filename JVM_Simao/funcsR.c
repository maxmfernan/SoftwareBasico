#include "funcsR.h"

/*Funcoes de criacaoes de stacks de pilha: */
void cria_itemOperandoPilha(OPERAND_STACK **epilha,char tipo,void *termo)
{
    (*epilha) = malloc(sizeof(OPERAND_STACK));
    (*epilha)->operand_type = tipo;
    if(tipo==TYPE_INT){
        (*epilha)->type.int_number = *((int*)termo);
    }else if(tipo==TYPE_FLOAT){
        (*epilha)->type.float_number = *((float*)termo);
    }else if(tipo==TYPE_OBJ_REF){
        (*epilha)->type.object_ref = ((CLASS*)termo);
    }else if(tipo==TYPE_ARRAY){
        (*epilha)->type.vector_ref = ((unsigned int*)termo);
    }else if(tipo==TYPE_RETURNADRESS){
        (*epilha)->type.int_number = *((int*)termo);
    }else if(tipo==TYPE_LONG){
        (*epilha)->type.u_int_number = *((unsigned int*)termo);
    }else if(tipo==TYPE_DOUBLE){
        (*epilha)->type.u_int_number = *((unsigned int*)termo);
    }
    (*epilha)->prox = NULL;
}

void cria_itemUIntOperandoPilha(OPERAND_STACK **epilha,char tipo,unsigned int termo)
{
    (*epilha) = malloc(sizeof(OPERAND_STACK));
    (*epilha)->operand_type = tipo;
    (*epilha)->type.u_int_number = termo;
    (*epilha)->prox = NULL;
}
/*--------------------------------------------------------------------*/

/*Operacoes com inteiros: */
/*iadd: */
void iadd(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2,*result;

    value1 = PopOperandoPilha(pilha);
    value2 = PopOperandoPilha(pilha);

    int valor =0;
    valor = value1->type.int_number + value2->type.int_number;
    cria_itemOperandoPilha(&result,value1->operand_type,&valor);

    PushOperandoPilha(pilha, result);
    free(value1);
    free(value2);
}
/*--------------------------*/

/*iand: */
void iand(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2,*result;

    value1 = PopOperandoPilha(pilha);
    value2 = PopOperandoPilha(pilha);

    int valor =0;
    valor = value1->type.int_number & value2->type.int_number;

    cria_itemOperandoPilha( &result, value1->operand_type, &valor);

    PushOperandoPilha(pilha, result);
    free(value1);
    free(value2);
}
/*------------------------------*/

/*idiv: */
void idiv(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2,*result;

    value2 = PopOperandoPilha(pilha);
    value1 = PopOperandoPilha(pilha);

    int valor =0;
    valor =  value1->type.int_number / value2->type.int_number;

    cria_itemOperandoPilha( &result, value1->operand_type,&valor);

    PushOperandoPilha(pilha, result);
    free(value1);
    free(value2);
}
/*------------------------------*/

/*imul: */
void imul(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2,*result;

    value2 = PopOperandoPilha(pilha);
    value1 = PopOperandoPilha(pilha);

    int valor =0;
    valor =  value1->type.int_number * value2->type.int_number;

    cria_itemOperandoPilha( &result, value1->operand_type, &valor);

    PushOperandoPilha(pilha, result);
    free(value1);
    free(value2);
}
/*------------------------------*/

/*ior: */
void ior(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2,*result;

    value1 = PopOperandoPilha(pilha);
    value2 = PopOperandoPilha(pilha);

    int valor =0;
    valor =  value1->type.int_number | value2->type.int_number;

    cria_itemOperandoPilha( &result, value1->operand_type,&valor);

    PushOperandoPilha(pilha, result);
    free(value1);
    free(value2);
}
/*------------------------------*/

/*irem: */
void irem(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2,*result;

    value2 = PopOperandoPilha(pilha);
    value1 = PopOperandoPilha(pilha);

    int valor =0;
    valor =  value1->type.int_number -(value1->type.int_number /
            value2->type.int_number)*value2->type.int_number;

    cria_itemOperandoPilha( &result, value1->operand_type, &valor);

    PushOperandoPilha(pilha, result);
    free(value1);
    free(value2);
}
/*------------------------------*/

/*ixor: */
void ixor(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2,*result;

    value1 = PopOperandoPilha(pilha);
    value2 = PopOperandoPilha(pilha);

    int valor =0;
    valor =  value1->type.int_number ^ value2->type.int_number;

    cria_itemOperandoPilha( &result, value1->operand_type, &valor);

    PushOperandoPilha(pilha, result);
    free(value1);
    free(value2);
}
/*------------------------------*/

/*Movimentacoes na pilha: */
/*bipush: */
void bipush(OPERAND_STACK **pilha, u1 byte)
{
    OPERAND_STACK *value;

    value = malloc(sizeof(OPERAND_STACK));
    value->operand_type = TYPE_INT;
    if((0x80&byte)!=0)
        value->type.int_number = (0xffffff00|byte);
    else
        value->type.int_number = byte;
    value->prox = NULL;

    PushOperandoPilha(pilha,value);
}
/*--------------------------*/

/*sipush: */
void sipush(OPERAND_STACK **pilha, int numero)
{
    OPERAND_STACK *value;

    value = malloc(sizeof(OPERAND_STACK));
    value->operand_type = TYPE_INT;
    value->type.int_number = numero;
    value->prox = NULL;

    PushOperandoPilha(pilha,value);
}
/*---------------------------*/

/*swap: */
void swap(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2,*result;

    value1 = PopOperandoPilha(pilha);
    value2 = PopOperandoPilha(pilha);

    PushOperandoPilha(pilha, value1);
    PushOperandoPilha(pilha, value2);
}
/*---------------------------*/

/*dup: */
void dup(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2;

    value1 = PopOperandoPilha(pilha);
    if(value1 == NULL)
    {
        printf("Valor da pilha retonou vazio.\n");
    }
    if((value1->operand_type!=TYPE_LONG)&&(value1->operand_type!=TYPE_DOUBLE))
    {
        /*printf("type != long ou double\n");*/
        void *valor = &value1->type;
        cria_itemOperandoPilha( &value2, value1->operand_type,valor);

        PushOperandoPilha(pilha, value1);
        PushOperandoPilha(pilha, value2);
    }else
    {
         /*printf("else\n");*/
        PushOperandoPilha(pilha, value1);
    }
}
/*--------------------------*/

/*dup-x1: */
void dup_x1(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value1_2,*value2;

    value1 = PopOperandoPilha(pilha);
    value2 = PopOperandoPilha(pilha);
    if((value1->operand_type!=TYPE_LONG)&&(value1->operand_type!=TYPE_DOUBLE)&&
        (value2->operand_type!=TYPE_LONG)&&(value2->operand_type!=TYPE_DOUBLE))
    {
        void *valor = &value1->type;
        cria_itemOperandoPilha( &value1_2, value1->operand_type, valor);

        PushOperandoPilha(pilha, value1_2);
        PushOperandoPilha(pilha, value2);
        PushOperandoPilha(pilha, value1);
    }else
    {
        PushOperandoPilha(pilha, value2);
        PushOperandoPilha(pilha, value1);
    }
}
/*--------------------------*/

/*dup-x2: */
void dup_x2(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value1_2,*value2,*value3;

    value1 = PopOperandoPilha(pilha);
    if((value1->operand_type!=TYPE_LONG)&&(value1->operand_type!=TYPE_DOUBLE))
    {
        value2 = PopOperandoPilha(pilha);
        value3 = PopOperandoPilha(pilha);
        void *valor = &value1->type;
        cria_itemOperandoPilha( &value1_2, value1->operand_type,valor);

        PushOperandoPilha(pilha, value1_2);
        PushOperandoPilha(pilha, value3);
        PushOperandoPilha(pilha, value2);
        PushOperandoPilha(pilha, value1);
    }else
    {
        PushOperandoPilha(pilha, value1);
    }
}
/*--------------------------*/

/*dup2: */
void dup2(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2,*value1_2,*value2_2;

    value1 = PopOperandoPilha(pilha);
    value2 = PopOperandoPilha(pilha);
    if((value1->operand_type==TYPE_LONG)||(value1->operand_type==TYPE_DOUBLE))
    {
        cria_itemUIntOperandoPilha( &value1_2, value1->operand_type,
            value1->type.u_int_number);
        cria_itemUIntOperandoPilha( &value2_2, value2->operand_type,
            value2->type.u_int_number);
    }else
    {
        void *valor = &value1->type;
        cria_itemOperandoPilha( &value1_2, value1->operand_type,valor);
        valor = &value2->type;
        cria_itemOperandoPilha( &value2_2, value2->operand_type,valor);
    }

    PushOperandoPilha(pilha, value2_2);
    PushOperandoPilha(pilha, value1_2);
    PushOperandoPilha(pilha, value2);
    PushOperandoPilha(pilha, value1);
}
/*--------------------------*/

/*dup2-x1: */
void dup2_x1(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value1_2,*value2,*value2_2,*value3;

    value1 = PopOperandoPilha(pilha);
    value2 = PopOperandoPilha(pilha);
    value3 = PopOperandoPilha(pilha);
    if((value3->operand_type!=TYPE_LONG)&&(value3->operand_type!=TYPE_DOUBLE))
    {
        if((value1->operand_type==TYPE_LONG)||(value1->operand_type==TYPE_DOUBLE))
        {
            cria_itemUIntOperandoPilha( &value1_2, value1->operand_type,
                value1->type.u_int_number);
            cria_itemUIntOperandoPilha( &value2_2, value2->operand_type,
                value2->type.u_int_number);
        }else
        {
            void *valor = &value1->type;
            cria_itemOperandoPilha( &value1_2, value1->operand_type, valor);
            valor = &value2->type;
            cria_itemOperandoPilha( &value2_2, value2->operand_type,valor);
        }

        PushOperandoPilha(pilha, value2_2);
        PushOperandoPilha(pilha, value1_2);

    }
    PushOperandoPilha(pilha, value3);
    PushOperandoPilha(pilha, value2);
    PushOperandoPilha(pilha, value1);
}
/*--------------------------*/

/*dup-x2: */
void dup2_x2(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value1_2,*value2,*value2_2,*value3,*value4;

    value1 = PopOperandoPilha(pilha);
    value2 = PopOperandoPilha(pilha);
    value3 = PopOperandoPilha(pilha);
    value4 = PopOperandoPilha(pilha);

    if((value1->operand_type==TYPE_LONG)||(value1->operand_type==TYPE_DOUBLE))
    {
        cria_itemUIntOperandoPilha( &value1_2, value1->operand_type,
            value1->type.u_int_number);
        cria_itemUIntOperandoPilha( &value2_2, value2->operand_type,
            value2->type.u_int_number);
    }else
    {
        void *valor = &value1->type;
        cria_itemOperandoPilha( &value1_2, value1->operand_type,valor);
        valor = &value2->type;
        cria_itemOperandoPilha( &value2_2, value2->operand_type,valor);
    }

    PushOperandoPilha(pilha, value2_2);
    PushOperandoPilha(pilha, value1_2);
    PushOperandoPilha(pilha, value4);
    PushOperandoPilha(pilha, value3);
    PushOperandoPilha(pilha, value2);
    PushOperandoPilha(pilha, value1);
}
/*--------------------------*/

/*pop: */
void pop(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value;
    value = PopOperandoPilha(pilha);
    if((value->operand_type!=TYPE_LONG)&&(value->operand_type!=TYPE_DOUBLE))
    {
        free(value);
    }else
    {
        PushOperandoPilha(pilha, value);
    }
}
/*--------------------------*/

/*pop2: */
void pop2(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*value2;
    value1 = PopOperandoPilha(pilha);
    value2 = PopOperandoPilha(pilha);
    free(value1);
    free(value2);
}
/*--------------------------*/


/*Conversoes: */
/*i2b: */
void i2b(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*result;
    u1 byte;
    value1 = PopOperandoPilha(pilha);
    byte = value1->type.int_number;
    if((0x80&byte)!=0){
        int valor = 0xffffff00|byte;
        cria_itemOperandoPilha(&result, TYPE_INT, &valor);
    }else{
        int valor = (int)byte;
        cria_itemOperandoPilha(&result, TYPE_INT, &valor);
    }
    PushOperandoPilha(pilha, result);
    free(value1);
}
/*--------------------------*/

/*i2c: */
void i2c(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*result;
    u1 byte;
    value1 = PopOperandoPilha(pilha);
    byte = value1->type.int_number;
    int valor = (int)byte;
    cria_itemOperandoPilha(&result, TYPE_INT, &valor);
    PushOperandoPilha(pilha, result);
    free(value1);
}
/*--------------------------*/

/*i2d: */
void i2d(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*result1,*result2;
    value1 = PopOperandoPilha(pilha);
    double dAux = 0.0;
    dAux =(double)value1->type.int_number;
    unsigned int *iAux = calloc(2,sizeof(unsigned int));
	memcpy(iAux,&dAux,8);
    cria_itemOperandoPilha(&result1, TYPE_DOUBLE, &iAux[0]);
    cria_itemOperandoPilha(&result2, TYPE_DOUBLE, &iAux[1]);
    PushOperandoPilha(pilha, result1);
    PushOperandoPilha(pilha, result2);
    free(value1);
}
/*--------------------------*/

/*i2f: */
void i2f(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*result;
    value1 = PopOperandoPilha(pilha);
    float valor = (float)value1->type.int_number;
    cria_itemOperandoPilha(&result, TYPE_FLOAT, &valor);
    PushOperandoPilha(pilha, result);
    free(value1);
}
/*--------------------------*/

/*i2l: */
void i2l(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*result1,*result2;
    value1 = PopOperandoPilha(pilha);
    long long int dAux = 0;
    dAux =(long long int)value1->type.int_number;
    unsigned int *iAux = calloc(2,sizeof(unsigned int));
	memcpy(iAux,&dAux,8);
    cria_itemOperandoPilha(&result1, TYPE_LONG, &iAux[0]);
    cria_itemOperandoPilha(&result2, TYPE_LONG, &iAux[1]);

    PushOperandoPilha(pilha, result1);
    PushOperandoPilha(pilha, result2);
    free(value1);
}
/*--------------------------*/

/*i2s: */
void i2s(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*result;
    u2 shortInt;
    value1 = PopOperandoPilha(pilha);
    shortInt = value1->type.int_number;
    if((0x8000&shortInt)!=0){
        int valor = 0xffff0000|shortInt;
        cria_itemOperandoPilha(&result, TYPE_INT, &valor);
    }else{
        int valor = (int)shortInt;
        cria_itemOperandoPilha(&result, TYPE_INT, &valor);
    }
    PushOperandoPilha(pilha, result);
    free(value1);
}
/*--------------------------*/

/*Conversoes de float:*/
/*f2d: */
void f2d(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*result1,*result2;
    value1 = PopOperandoPilha(pilha);
    double dAux = 0.0;
    dAux =(double)value1->type.float_number;
    unsigned int *iAux = calloc(2,sizeof(unsigned int));
	memcpy(iAux,&dAux,8);
    cria_itemOperandoPilha(&result1, TYPE_DOUBLE, &iAux[0]);
    cria_itemOperandoPilha(&result2, TYPE_DOUBLE, &iAux[1]);
    PushOperandoPilha(pilha, result1);
    PushOperandoPilha(pilha, result2);
    free(value1);
}
/*--------------------------*/

/*f2i: */
void f2i(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*result;
    value1 = PopOperandoPilha(pilha);
    int valor = (int)value1->type.float_number;
    cria_itemOperandoPilha(&result, TYPE_INT, &valor);
    PushOperandoPilha(pilha, result);
    free(value1);
}
/*--------------------------*/

/*f2l: */
void f2l(OPERAND_STACK **pilha)
{
    OPERAND_STACK *value1,*result1,*result2;
    value1 = PopOperandoPilha(pilha);
    long long int lAux = 0;
    lAux =(long long int)value1->type.float_number;
    unsigned int *iAux = calloc(2,sizeof(unsigned int));
	memcpy(iAux,&lAux,8);
    cria_itemOperandoPilha(&result1, TYPE_LONG, &iAux[0]);
    cria_itemOperandoPilha(&result2, TYPE_LONG, &iAux[1]);

    PushOperandoPilha(pilha, result1);
    PushOperandoPilha(pilha, result2);
    free(value1);
}
/*--------------------------*/

/*Operacoes de JUMP: */
/*goto: */
void go2(int numero,u4 *pc)
{
    *pc += numero;
}
/*--------------------------*/

/*goto_w: */
/*void goto_w(u1 branchbyte1,u1 branchbyte2,u1 branchbyte3,u1 branchbyte4,u4 *pc)*/
void goto_w(int numero,u4 *pc)
{
    *pc += numero;
}
/*--------------------------*/

/*jsr: */
/*ATENCAO!!!!!!
    * o returnAddress foi considerado um inteiro,
    * e nada mais é do que o pc incrementado para a proxima instruçao*/
void jsr(OPERAND_STACK **pilha,int numero,u4 *pc)
{
    OPERAND_STACK *result;
    u4 fakepc = *(pc)+3;
    cria_itemOperandoPilha(&result, TYPE_RETURNADRESS, &fakepc);
    PushOperandoPilha(pilha, result);
    *pc += numero;
}
/*--------------------------*/

/*jsr: */
/*ATENCAO!!!!!!
    * o returnAddress foi considerado um inteiro,
    * e nada mais é do que o pc incrementado para a proxima instruçao*/
void jsr_w(OPERAND_STACK **pilha,int numero,u4 *pc)
{
    OPERAND_STACK *result;
    u4 fakepc = *(pc)+5;
    cria_itemOperandoPilha(&result, TYPE_RETURNADRESS, &fakepc);
    PushOperandoPilha(pilha, result);
    *pc += numero;
}
/*--------------------------*/


/*Stores e um load: */
/*castore: */
void castore(OPERAND_STACK **pilha)
{
    OPERAND_STACK *arrayref,*index,*value;
    char *array;
    char caracter;

    value = PopOperandoPilha(pilha);
    index = PopOperandoPilha(pilha);
    arrayref = PopOperandoPilha(pilha);

    array = (char*)arrayref->type.vector_ref;
    caracter = (char)value->type.int_number;

    array[index->type.int_number] = caracter;
}
/*---------------------------*/

/*sastore: */
void sastore(OPERAND_STACK **pilha)
{
    OPERAND_STACK *arrayref,*index,*value;
    short int *array;
    short int valor;

    value = PopOperandoPilha(pilha);
    index = PopOperandoPilha(pilha);
    arrayref = PopOperandoPilha(pilha);

    array = (short int *)arrayref->type.vector_ref;
    valor = (short int)value->type.int_number;

    array[index->type.int_number] = valor;
}
/*---------------------------*/

/*daload: */
void daload(OPERAND_STACK **pilha)
{
    OPERAND_STACK *arrayref,*index,*value1,*value2;
    double *array;
    double valor;
    unsigned int *iAux = calloc(2,sizeof(unsigned int));

    index = PopOperandoPilha(pilha);
    arrayref = PopOperandoPilha(pilha);

    array = (double *)arrayref->type.vector_ref;
    valor = array[index->type.int_number];
    memcpy(iAux,&valor,8);

    cria_itemOperandoPilha(&value1, TYPE_DOUBLE, &iAux[0]);
    PushOperandoPilha(pilha, value1);
    cria_itemOperandoPilha(&value2, TYPE_DOUBLE, &iAux[1]);
    PushOperandoPilha(pilha, value2);
}
/*---------------------------*/

/*dastore: */
void dastore(OPERAND_STACK **pilha)
{
    OPERAND_STACK *arrayref,*index,*value1,*value2;
    double *array;
    double valor;
    unsigned int *iAux = calloc(2,sizeof(unsigned int));

    value2 = PopOperandoPilha(pilha);
    value1 = PopOperandoPilha(pilha);
    index = PopOperandoPilha(pilha);
    arrayref = PopOperandoPilha(pilha);

    array = (double *)arrayref->type.vector_ref;
    iAux[0] = value1->type.u_int_number;
    iAux[1] = value2->type.u_int_number;
    memcpy(&valor,iAux,8);

    array[index->type.int_number] = valor;
}
/*---------------------------*/

/*fastore: */
void fastore(OPERAND_STACK **pilha)
{
    OPERAND_STACK *arrayref,*index,*value;
    float *array;
    float valor;

    value = PopOperandoPilha(pilha);
    index = PopOperandoPilha(pilha);
    arrayref = PopOperandoPilha(pilha);

    array = (float *)arrayref->type.vector_ref;
    valor = value->type.float_number;

    array[index->type.int_number] = valor;
}
/*---------------------------*/

/*iastore: */
void iastore(OPERAND_STACK **pilha)
{
    OPERAND_STACK *arrayref,*index,*value;
    int *array;
    int valor;

    value = PopOperandoPilha(pilha);
    index = PopOperandoPilha(pilha);
    arrayref = PopOperandoPilha(pilha);

    array = (int *)arrayref->type.vector_ref;
    valor = value->type.int_number;

    array[index->type.int_number] = valor;
}
/*---------------------------*/

/*bastore: */
void bastore(OPERAND_STACK **pilha)
{
    OPERAND_STACK *arrayref,*index,*value;
    u1 *array;
    u1 valor;

    value = PopOperandoPilha(pilha);
    index = PopOperandoPilha(pilha);
    arrayref = PopOperandoPilha(pilha);

    array = (u1 *)arrayref->type.vector_ref;
    valor = (u1)value->type.int_number;

    array[index->type.int_number] = valor;
}
/*---------------------------*/

/*baload: */
void baload(OPERAND_STACK **pilha)
{
    OPERAND_STACK *arrayref,*index,*value;
    u1 *array;
    u1 byte;
    int valor;

    index = PopOperandoPilha(pilha);
    arrayref = PopOperandoPilha(pilha);

    array = (u1 *)arrayref->type.vector_ref;
    byte = array[index->type.int_number];

    if((0x80&byte)!=0)
        valor = (0xffffff00|byte);
    else
        valor = byte;

    cria_itemOperandoPilha(&value, TYPE_INT, &valor);
    PushOperandoPilha(pilha, value);
}
/*---------------------------*/

/*lastore: */
void lastore(OPERAND_STACK **pilha)
{
    OPERAND_STACK *arrayref,*index,*value1,*value2;
    long long int *array;
    long long int valor;
    unsigned int *iAux = calloc(2,sizeof(unsigned int));

    value2 = PopOperandoPilha(pilha);
    value1 = PopOperandoPilha(pilha);
    index = PopOperandoPilha(pilha);
    arrayref = PopOperandoPilha(pilha);

    array = (long long int *)arrayref->type.vector_ref;
    iAux[0] = (unsigned int)value1->type.u_int_number;
    iAux[1] = (unsigned int)value2->type.u_int_number;
    memcpy(&valor,iAux,8);

    array[(index->type).int_number] = valor;
}
/*---------------------------*/


