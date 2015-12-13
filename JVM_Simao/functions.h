/*
 *  functions.h
 *  
 *
 *  Created by Carolina Oliveira on 7/16/12.
 *  Copyright 2012 UnB. All rights reserved.
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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
#include "operacoesFrame.h"
#include "simulation.h"
#include "mnemonics.h"

/*PUSH null na pilha de operandos */
void aconst_null(OPERAND_STACK **);

/*empurra a constante 0.0 ou 1.0 na pilha - ocupa 2 espacos*/
void dconst_n(double,OPERAND_STACK **);

/*empurra a constante 0.0, 1.0, 2.0 ou 3.0 na pilha*/
void fconst_n(float,OPERAND_STACK **);

/*empurra a constante 0,1,2,3,4 ou 5 na pilha*/
void iconst_n(int, OPERAND_STACK **);

/*empurra a constante -1 na pilha*/
void iconst_m1(OPERAND_STACK **);

/*empurra a constante 0 ou 1 na pilha - ocupa 2 espacos*/
void lconst_n(long int, OPERAND_STACK **);

/*soma os dois floats do topo da pilha e joga o resultado na pilha*/
int fadd(OPERAND_STACK **);

/*divide os dois floats do topo da pilha e joga o resultado na pilha*/
int fdiv(OPERAND_STACK **);

/*multiplica os dois floats do topo da pilha e joga o resultado na pilha*/
int fmul(OPERAND_STACK **);

/*nega o valor do topo da pilha e coloca na pilha*/
int fneg(OPERAND_STACK **);

/*divde os dois floats do topo da pilha e joga o resto na pilha*/
int frem(OPERAND_STACK **);

/*subtrai os dois floats do topo da pilha e joga o resultado na pilha*/
int fsub(OPERAND_STACK **);

/*transfere da pilha para o vetor de variaveis locais uma referencia a um objeto*/
int astore(OPERAND_STACK **, ITEM_VECTOR **, int);

/*transfere da pilha para o vetor de variaveis locais um valor float*/
int fstore(OPERAND_STACK **, ITEM_VECTOR **, int);

/*transfere da pilha para o vetor de variaveis locais um valor float*/
int dstore(OPERAND_STACK **, ITEM_VECTOR **, int);

/*transfere da pilha para o vetor de variaveis locais um valor inteiro*/
int istore(OPERAND_STACK **, ITEM_VECTOR **, int);

/*transfere da pilha para o vetor de variaveis locais um valor long int*/
int lstore(OPERAND_STACK **, ITEM_VECTOR **, int);

/*coloca uma referencia a um objeto do topo da pilha no index i,que e o segundo elemento da pilha , do vetor, terceiro elemento*/
int aastore(OPERAND_STACK **);

/*funcao que inicia uma nova classe. É necessário passar um ponteiro para a nova classe e o nome do arquivo (ou caminho para o arquivo)*/
int new(ConstantPoolItem *, CLASS **, int, CLASS *);

/*funcao que converte o double armazenado no topo da pilha para um float, e armazena no topo da pilha*/
int d2f(OPERAND_STACK **);

/*funcao que converte o double armazenado no topo da pilha para um inteiro, e armazena no topo da pilha*/
int d2i(OPERAND_STACK **);

/*funcao que converte o double armazenado no topo da pilha para um long, e armazena no topo da pilha*/
int d2l(OPERAND_STACK **);

/*funcao que converte o long armazenado no topo da pilha para um inteiro, e armazena no topo da pilha*/
int l2i(OPERAND_STACK **);

/*funcao que converte o long armazenado no topo da pilha para um float, e armazena no topo da pilha*/
int l2f(OPERAND_STACK **);

/*funcao que converte o long armazenado no topo da pilha para um double, e armazena no topo da pilha*/
int l2d(OPERAND_STACK **);

/*funcao que incrementa o elemento x do vetor de variaveis locais em y*/
int iinc(OPERAND_STACK **, ITEM_VECTOR **, unsigned int, int);

/*funcao que empurra na pilha uma single-word*/
int ldc(OPERAND_STACK **, short , ConstantPoolItem *);

/*funcao que empurra na pilha uma single-word*/
int ldc_w(OPERAND_STACK **, int , ConstantPoolItem *);

/*funcao que empurra na pilha um double ou um long do constant pool*/
int ldc2_w(OPERAND_STACK **, int , ConstantPoolItem *);

/*retira o tamanho da pilha cria um novo vetor e coloca a referencia na pilha */
int anewarray(OPERAND_STACK **, int , ConstantPoolItem *);

int invokespecial(OPERAND_STACK **, short int , FRAME **);

int invokevirtual(OPERAND_STACK **epilha, int vIndex, FRAME **fr);

char achaTipo(char *descritor);

int getstatic(OPERAND_STACK **pilha, int cp_index, FRAME **fr);

int putfield(OPERAND_STACK **pilha, int cp_index, FRAME **fr);

int getfield (OPERAND_STACK **pilha, int cp_index, FRAME **fr);

int putstatic(OPERAND_STACK **pilha, int cp_index, FRAME **fr);

#endif
