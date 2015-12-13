#ifndef OPERACAOLISTAS_H
#define OPERACAOLISTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

int adicionaItemConstPool(ConstantPoolItem **inicio, ConstantPoolItem *novoItem);

void insereItemVetor(ITEM_VECTOR **inicio, ITEM_VECTOR *newItem);

ITEM_VECTOR* procuraItemVetor(ITEM_VECTOR **vector, unsigned int index_item);

void insereClasse(CLASS *novaclasse, char *novaclassepath);

#endif
