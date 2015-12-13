#ifndef LOADS_H_
#define LOAD_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "types.h"
#include "operacaoListas.h"
#include "operacaoBits.h"
#include "operacoesPilhas.h"
#include "class_loader.h"
#include "constant_pool.h"
#include "operacaoListas.h"
#include "operacoesPilhas.h"

/*Carrega um float do vetor de variaveis locais no indice index_vector e o coloca na pilha*/
void fload (OPERAND_STACK **, ITEM_VECTOR **, int);

/*Carrega um int do vetor de variaveis locais no indice index_vector e o coloca na pilha*/
void iload (OPERAND_STACK **, ITEM_VECTOR **, int);

/*Carrega um long do vetor de variaveis locais no indice index_vector e o coloca na pilha*/
void lload (OPERAND_STACK **, ITEM_VECTOR **, int);

/*Carrega um double do vetor de variaveis locais no indice index_vector e o coloca na pilha*/
void dload (OPERAND_STACK **, ITEM_VECTOR **, int);

/*Carrega um int presente no indice e na referencia para o vetor retirado da pilha*/
void iaload (OPERAND_STACK **);

/*Carrega um float presente no indice e na referencia para o vetor retirado da pilha*/
void faload (OPERAND_STACK **);

/*Carrega um long presente no indice e na referencia para o vetor retirado da pilha*/
void laload (OPERAND_STACK **);

/*Carrega um char presente no indice e na referencia para o vetor retirado da pilha*/
void caload (OPERAND_STACK **);

/*Carrega um short presente no indice e na referencia para o vetor retirado da pilha*/
void saload (OPERAND_STACK **);

/*Carrega uma refetencia presente no indice e na referencia para o vetor retirado da pilha*/
void aload (OPERAND_STACK **, ITEM_VECTOR **, int);

/*Cria um novo vetor*/
void newarray(OPERAND_STACK **, u1 );

/*Tamanho do vetor*/
void arraylength(OPERAND_STACK **);

void aaload (OPERAND_STACK **epilha);

#endif
