#ifndef CLASS_LOADER_H
#define CLASS_LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "operacaoListas.h"
#include "operacaoBits.h"
#include "constant_pool.h"

void readInterfaces(CLASS **, FILE *, char );

void readGenericInfo(GENERIC_ATTRIBUTE **, FILE *, ConstantPoolItem *, char **);

void readFields(CLASS **, FILE *,ConstantPoolItem *, char);

CODE *readCode(GENERIC_ATTRIBUTE **, FILE *, ConstantPoolItem *, char);

void readAttributesMethod(GENERIC_ATTRIBUTE **, FILE *, ConstantPoolItem *, char);

void readMethods(CLASS **, FILE *, ConstantPoolItem *, char);

void readAttributes(CLASS **, FILE *, ConstantPoolItem *, char);

#endif
