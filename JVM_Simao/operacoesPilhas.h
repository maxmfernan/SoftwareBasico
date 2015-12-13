/*
 *  stack_operatios.h
 *  
 *
 *  Created by Carolina Oliveira on 7/15/12.
 *  Copyright 2012 UnB. All rights reserved.
 *
 */
#ifndef OPERACOES_PILHAS_H
#define OPERACOES_PILHAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"


/* Inicializadores: funcoes para inicializar uma pilha*/
void InicializaOperand (OPERAND_STACK **);
void InicializaFrame (FRAME **);
void InicializaPilha (void **);


/* Pilha Vazia: funcoes para verificar se uma pilha esta vazia*/
int PilhaFrameVazia (FRAME *);
int PilhaOperandVazia (OPERAND_STACK *);
int PilhaVazia (void*);


/* Topo: funcoes para buscar o valor do topo da pilha*/
u4 TopoFramePilha(FRAME *);
u1 TopoOperandPilha(OPERAND_STACK *);

/* Push: Funcoes para colocar um valor no topo da pilha */
void PushOperandoPilha(OPERAND_STACK **, OPERAND_STACK *);
void PushFramePilha(FRAME **, FRAME *);



/* Pop: Funcoes para retirar o valor no topo da pilha*/
OPERAND_STACK* PopOperandoPilha(OPERAND_STACK **);
FRAME* PopFramePilha(FRAME **);


OPERAND_STACK *coloca(void *, int );
OPERAND_STACK *divide(void *, int );

#endif
