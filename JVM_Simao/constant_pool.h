#ifndef CONSTANT_POOL_H
#define CONSTANT_POOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "operacaoListas.h"
#include "operacaoBits.h"

void printUtf8(CONSTANT_Utf8 *);

void printInteger(CONSTANT_Integer );

void printFloat(CONSTANT_Float );

void printLong(CONSTANT_Long );

void printDouble(CONSTANT_Double );

void printClass(CONSTANT_Class );

void printString(CONSTANT_String );

void printRef(CONST_Ref , int );

void printNameAndType(CONSTANT_NameAndType );

void printfConstPoolItems(ConstantPoolItem * );

void readConst_Utf8(FILE *arq, CONSTANT_Utf8 **, char **);

void readConst_Integer(FILE *arq, CONSTANT_Integer *constAux);

void readConst_Float(FILE *arq, CONSTANT_Float *constAux);

void readConst_Long(FILE *arq, CONSTANT_Long *constAux);

void readConst_Double(FILE *arq, CONSTANT_Double *constAux);

void readConst_Class(FILE *arq, CONSTANT_Class *constAux);

void readConst_String(FILE *arq, CONSTANT_String *constAux);

void readConst_Ref(FILE *arq, CONST_Ref *constAux);

void readConst_NameAndType(FILE *arq, CONSTANT_NameAndType  *constAux);

void readConst_Empty();

void valorNaoExiste();

void readConstPool(FILE *arquivo, CLASS **classe, ConstantPoolItem **inicioConstPool );

ConstantPoolItem *searchConstPoolItem(ConstantPoolItem *, u4, u4 );

char *searchPoolTableUTF8(u2 , ConstantPoolItem *);

METHOD *searchMethod(METHOD *, char*, char*);

#endif
