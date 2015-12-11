/**
 *       @file  JVM.c
 *      @brief  Função principal da JVM. Chama todas as outras
 *
 * Detailed description starts here.
 *
 *     @author  Maxwell M. Fernandes (mmf), maxmfernan@gmail.com
 *
 *   @internal
 *     Created  05/12/2015
 *    Revision  $Id: doxygen.templates,v 1.3 2010/07/06 09:20:12 mehner Exp $
 *    Compiler  gcc/g++
 *     Company  none
 *   Copyright  Copyright (c) 2015, Maxwell M. Fernandes
 *
 * This source code is released for free distribution under the terms of the
 * GNU General Public License as published by the Free Software Foundation.
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include "JVM_core.h"


int main(int argc, char **argv){
	ClassFile *classHeap_ptr;
	Object *objectHeap_ptr;
	Frame *stackFrame_ptr;
	FILE *classPathF_ptr;	
	char *classPathStr = malloc( sizeof(char)*100 );
	dataMSize_t dmSize;
	

	if( argc > 1){
		classPathStr = argv[1];	
	}
	else{
		printf("\nDigite o nome do arquivo: ");
		scanf("%s", classPathStr);
	}
	
	printf("\n%s", classPathStr);	
	classPathF_ptr = fopen(classPathStr, "rb");
	if( classPathF_ptr == NULL){
		printf("\nArquivo não encontrado");
		exit(1);
	}		
	printf("\nPassei1");
	/** Inicicializa a JVM.
		Cria espaço para os heaps e para o stackFrame.
		Carrega a class inicial. */
	jvmStartup(classHeap_ptr, objectHeap_ptr, stackFrame_ptr, classPathF_ptr, &dmSize);

	//Fecha o arquivo do primeiro class file aberto
	fclose(classPathF_ptr);

	return 0;
}
