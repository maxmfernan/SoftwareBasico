#ifndef SIMULATION_H
#define SIMULATION_H

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

#include "funcsG.h"
#include "funcsR.h"
#include "loads.h"
#include "functions.h"

int executa_funcao(FUNCTION , OPERAND_STACK **, ITEM_VECTOR **, ConstantPoolItem *, FRAME **, CLASS **, CLASS*);

int traduz_funcao(FUNCTION* , u1 *, u4 );

void traduz_codigo(u1 *, u4 , OPERAND_STACK **, ITEM_VECTOR **, ConstantPoolItem *, FRAME **);

METHOD *searchMethod(METHOD *, char*, char*);

int executaMain(FRAME **);

int contaArgumentos(char *);

int printStack(OPERAND_STACK *pilha);

int printVetor(ITEM_VECTOR *vetor);

#endif
