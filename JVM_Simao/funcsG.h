/*
 *  funcsG.h
 *
 *
 *  Created by Carolina Oliveira on 7/21/12.
 *  Copyright 2012 UnB. All rights reserved.
 *
 */

#ifndef FUNCSG_H
#define FUNCSG_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "types.h"
#include "operacaoListas.h"
#include "operacaoBits.h"
#include "operacoesPilhas.h"
#include "class_loader.h"
#include "constant_pool.h"
#include "operacaoListas.h"
#include "operacoesPilhas.h"
#include "operacoesFrame.h"


/*Returns*/

/*Retorna referencia de obejto*/
void areturn(FRAME **);

/*Retorna double*/
void dreturn(FRAME **);

/*Retorna float*/
void freturn(FRAME **);

/*ireturn: Retorna inteiro*/
void ireturn(FRAME **);

/*lreturn: Retorna long*/
void lreturn(FRAME **);

/*returne: Retorna void*/
void returne(FRAME **);

/*returne: Retorna void*/
void ret(FRAME **);



/*Operacoes aritmeticas*/


/*doubles_arith*/

/*Efetua operacao de adicao entre doubles*/
void dadd(OPERAND_STACK **);

/*Efetua operacao de divisao entre doubles*/
void ddiv(OPERAND_STACK **);

/*Efetua operacao de multiplicacao entre doubles*/
void dmul(OPERAND_STACK **);

/*Efetua operacao de inversao de sinal de double*/
void dneg(OPERAND_STACK **);

/*Efetua operacao de modulo entre doubles*/
void drem_nova(OPERAND_STACK **);

/*Efetua operacao de subtracao entre doubles*/
void dsub(OPERAND_STACK **);




/*int_arith*/

/*ineg: Efetua operacao de inversao de sinal de inteiro*/
void ineg(OPERAND_STACK **);

/*ishl: Efetua operacao de shift left de inteiro*/
void ishl(OPERAND_STACK **);

/*ishr: Efetua operacao de shift right de inteiro*/
void ishr(OPERAND_STACK **);

/*isub: Efetua operacao de subtracao inteiro*/
void isub(OPERAND_STACK **);



/*long_arith*/

/*ladd: Efetua operacao de adicao entre longs*/
void ladd(OPERAND_STACK **);

/*land: Efetua operacao de and bitwise entre longs*/
void land(OPERAND_STACK **);

/*ldiv: Efetua operacao de divisao entre longs*/
void ldivi(OPERAND_STACK **);

/*lmul: Efetua operacao de multiplicacao entre longs*/
void lmul(OPERAND_STACK **);

/*lneg: Efetua operacao de inversao de sinal de long*/
void lneg(OPERAND_STACK **);

/*lor: Efetua operacao de or biteise entre longs*/
void lor(OPERAND_STACK **);

/*lrem: Efetua operacao de modulo entre longs*/
void lrem(OPERAND_STACK **);

/*lshl: Efetua operacao de shift left entre longs*/
void lshl(OPERAND_STACK **);

/*lshr: Efetua operacao de shift right entre longs*/
void lshr(OPERAND_STACK **);

/*lsub: Efetua operacao de subtracao entre longs*/
void lsub(OPERAND_STACK **);

/*lushr: Efetua operacao de logical shift right entre longs*/
void lushr(OPERAND_STACK **);

/*lxor: Efetua operacao de xor bitwise entre longs*/
void lxor(OPERAND_STACK **);



/*comparacoes*/

/*Compara dois valores do tipo double com 1 caso NaN*/
void dcmpg(OPERAND_STACK **);

/*Compara dois valores do tipo double com -1 caso NaN*/
void dcmpl(OPERAND_STACK **);

/*Compara dois valores do tipo float com 1 caso NaN*/
void fcmpg(OPERAND_STACK **);

/*Compara dois valores do tipo float com -1 caso NaN*/
void fcmpl(OPERAND_STACK **);

/*lcmp: Compara dois valores do tipo long*/
void lcmp(OPERAND_STACK **);



/*If jumps*/

/*Compara referencias de objetos e se forem iguais executa o jump*/
void if_acmpeq(OPERAND_STACK **,short int , unsigned int *);

/*Compara referencias de objetos e se forem diferentes executa o jump*/
void if_acmpne(OPERAND_STACK **,short int , unsigned int *);

/*Compara se dois inteiros sao iguais para executar o jump*/
void if_icmpeq(OPERAND_STACK **,short int , unsigned int *);

/*Compara se dois inteiros sao diferentes para executar o jump*/
void if_icmpne(OPERAND_STACK **,short int , unsigned int *);

/*Compara se o segundo argumento eh maior ou igual ao primeiro para executar o jump*/
void if_icmpge(OPERAND_STACK **, short int , unsigned int *);

/*Compara se o segundo argumento eh maior que o primeiro para executar o jump*/
void if_icmpgt(OPERAND_STACK **, short int , unsigned int *);

/*Compara se o segundo argumento eh menor ou igual ao primeiro para executar o jump*/
void if_icmple(OPERAND_STACK **, short int , unsigned int *);

/*Compara se o segundo argumento eh menor que o primeiro para executar o jump*/
void if_icmplt(OPERAND_STACK **, short int , unsigned int *);

/*Compara se o topo da pilha de operandos eh igual a zero para executar o jump*/
void if_eq(OPERAND_STACK **,short int , unsigned int *);

/*Compara se o topo da pilha de operandos eh deferente de zero para executar o jump*/
void if_ne(OPERAND_STACK **,short int , unsigned int *);

/*Compara se o topo da pilha de operandos eh maior ou igual a zero para executar o jump*/
void if_ge(OPERAND_STACK **,short int , unsigned int *);

/*Compara se o topo da pilha de operandos eh maior que zero para executar o jump*/
void if_gt(OPERAND_STACK **,short int , unsigned int *);

/*Compara se o topo da pilha de operandos eh menor ou igual a zero para executar o jump*/
void if_le(OPERAND_STACK **,short int , unsigned int *);

/*Compara se o topo da pilha de operandos eh menor que zero para executar o jump*/
void if_lt(OPERAND_STACK **,short int , unsigned int *);

/*if_nonull: Compara se o topo da pilha eh um objeto nao nulo*/
void if_nonnull(OPERAND_STACK **,short int , unsigned int *);

/*if_null: Compara se o topo da pilha eh um objeto nulo*/
void if_null(OPERAND_STACK **,short int , unsigned int *);

#endif
