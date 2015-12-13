#ifndef FUNCS_H_
#define FUNCS_H_

#include "types.h"
#include "operacaoListas.h"
#include "operacaoBits.h"
#include "operacoesPilhas.h"
#include "class_loader.h"
#include "constant_pool.h"
#include "operacaoListas.h"
#include "operacoesPilhas.h"


/**
** Funcoes:
    ** Operacoes Aritimeticas de inteiro;
    ** Conversoes de floats e inteiros;
    ** Operacoes de Pilha;
    ** Operacoes de store e load com arrays
***/

/*Funcao que cria um item de pilha:
    Argumento um ponteiro de ponteiro e tipó e valor do item,
    sempre atribui-se NULL ao prox.
    Retorno: void*/
void cria_itemOperandoPilha(OPERAND_STACK **epilha,char tipo,void *termo);
void cria_itemUIntOperandoPilha(OPERAND_STACK **epilha,char tipo,unsigned int termo);
/*----------------------------------------------------*/

/*Operacoes com inteiros: */
/*iadd:
    *Retira dois operandos da pilha e coloca na pilha a soma*/
void iadd(OPERAND_STACK **pilha);

/*iand:
    *Retira 2 operandos e cloca de volta o resultado de um and bitwise.*/
void iand(OPERAND_STACK **pilha);

/*idiv:
    *Divide o segundo operando pelo primeiro e coloca o resultado na lista.*/
void idiv(OPERAND_STACK **pilha);

/*imul:
    *Retira dois operandos da pilha e coloca a multiplicacao deles.*/
void imul(OPERAND_STACK **pilha);

/*ior:
    *Retira dois operandos da pilha e coloca o resultado do or bitwise.*/
void ior(OPERAND_STACK **pilha);

/*irem:
    *Divide o segundo pelo primeiro e retorna o resto.*/
void irem(OPERAND_STACK **pilha);

/*ixor:
    *Retira dois operandos da pilha e coloca o resultado do xor bitwise.*/
void ixor(OPERAND_STACK **pilha);
/*------------------------------*/

/*Movimentacoes na pilha: */
/*bipush:
    *Coloca o byte na pilha como int com sinal extendido.*/
void bipush(OPERAND_STACK **pilha, u1 byte);

/*sipush:
    *Coloca o short na pilha como int com sinal extendido.*/
void sipush(OPERAND_STACK **pilha, int variavel);

/*swap:
    *Troca os dois primeiros operandos.*/
void swap(OPERAND_STACK **pilha);

/*dup:
    *Duplica o elemento do topo*/
void dup(OPERAND_STACK **pilha);

/*dup-x1:
    *Duplica o elemento do topo e o coloca em baixo do segundo elemento.*/
void dup_x1(OPERAND_STACK **pilha);

/*dup-x2:
    **Duplica o elemento do topo e o coloca em baixo do terceiro elemento.*/
void dup_x2(OPERAND_STACK **pilha);

/*dup2:
    *Duplica os 2 primeiros elementos.*/
void dup2(OPERAND_STACK **pilha);

/*dup2-x1:
    *Duplica os 2 primeiros elementos e coloca depois do terceiro.*/
void dup2_x1(OPERAND_STACK **pilha);

/*dup-x2:
    *Duplica os 2 primeiros elementos e coloca depois do quarto.*/
void dup2_x2(OPERAND_STACK **pilha);

/*pop:
    *Retira o primeiro elemento da pilha.*/
void pop(OPERAND_STACK **pilha);

/*pop2:
    *Retira os dois primeiros elementos da pilha*/
void pop2(OPERAND_STACK **pilha);
/*--------------------------*/

/*Conversoes: */
/*i2b: */
void i2b(OPERAND_STACK **pilha);

/*i2c: */
void i2c(OPERAND_STACK **pilha);

/*i2d: */
void i2d(OPERAND_STACK **pilha);

/*i2f: */
void i2f(OPERAND_STACK **pilha);

/*i2l: */
void i2l(OPERAND_STACK **pilha);

/*i2s: */
void i2s(OPERAND_STACK **pilha);

/*Conversoes de float:*/
/*f2d: */
void f2d(OPERAND_STACK **pilha);

/*f2i: */
void f2i(OPERAND_STACK **pilha);

/*f2l: */
void f2l(OPERAND_STACK **pilha);
/*--------------------------*/

/*Operacoes de JUMP: */
/*goto:
    *Incrementa o pc com o branch*/
void go2(int numero,u4 *pc);

/*goto_w:
    *Incrementa o pc com o branch.*/
void goto_w(int numero,u4 *pc);
/*void goto_w(u1 branchbyte1,u1 branchbyte2,u1 branchbyte3,u1 branchbyte4,u4 *pc);*/

/*jsr:
    *Incrementa o pc com o branch e coloca o pc da instrucao seguinte na pilha*/
/*ATENCAO!!!!!!
    * o returnAddress foi considerado um inteiro,
    * e nada mais é do que o pc incrementado para a proxima instruçao*/
void jsr(OPERAND_STACK **pilha,int numero,u4 *pc);

/*jsr:
    *Incrementa o pc com o branch e coloca o pc da instrucao seguinte na pilha*/
/*ATENCAO!!!!!!
    * o returnAddress foi considerado um inteiro,
    * e nada mais é do que o pc incrementado para a proxima instruçao*/
void jsr_w(OPERAND_STACK **pilha,int numero,u4 *pc);
/*--------------------------*/


/*Stores e loads: */
/*castore:
    *Retira o valor, o indice e a referencia e coloca o char no arrayref.*/
void castore(OPERAND_STACK **pilha);

/*sastore:
    **Retira o valor, o indice e a referencia e coloca o short no arrayref.*/
void sastore(OPERAND_STACK **pilha);

/*daload:
    *Retira o valor, o indice e a referencia e coloca o double no arrayref.*/
void daload(OPERAND_STACK **pilha);

/*dastore:
    *Retira o indice e a referencia e coloca o valor double no arrayref na pilha.*/
void dastore(OPERAND_STACK **pilha);

/*fastore:
    *Retira o valor, o indice e a referencia e coloca o float no arrayref.*/
void fastore(OPERAND_STACK **pilha);

/*iastore:
    *Retira o valor, o indice e a referencia e coloca o int no arrayref.*/
void iastore(OPERAND_STACK **pilha);

/*bastore:
    *Retira o valor, o indice e a referencia e coloca o byte no arrayref.*/
void bastore(OPERAND_STACK **pilha);

/*baload:
    *Retira o indice e a referencia e coloca o valor byte no arrayref na pilha.*/
void baload(OPERAND_STACK **pilha);

/*lastore:
    **Retira o valor, o indice e a referencia e coloca o long no arrayref.*/
void lastore(OPERAND_STACK **pilha);
/*---------------------------*/

#endif
