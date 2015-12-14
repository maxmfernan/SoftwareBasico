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

char *opcodes_str_names[] = { "nop", "aconst_null", "iconst_m1", "iconst_0", "iconst_1", 
	"iconst_2", "iconst_3", "iconst_4", "iconst_5", "lconst_0", 
	"lconst_1", "fconst_0", "fconst_1", "fconst_2", "dconst_0", 
	"dconst_1", "bipush", "sipush", "ldc", "ldc_w", 
	"ldc2_w", "iload", "lload", "fload", "dload", 
	"aload", "iload_0", "iload_1", "iload_2", "iload_3", 
	"lload_0", "lload_1", "lload_2", "lload_3", "fload_0", 
	"fload_1", "fload_2", "fload_3", "dload_0", "dload_1", 
	"dload_2", "dload_3", "aload_0", "aload_1", "aload_2", 
	"aload_3", "iaload", "laload", "faload", "daload", 
	"aaload", "baload", "caload", "saload", "istore", 
	"lstore", "fstore", "dstore", "astore", "istore_0", 
	"istore_1", "istore_2", "istore_3", "lstore_0", "lstore_1", 
	"lstore_2", "lstore_3", "fstore_0", "fstore_1", "fstore_2", 
	"fstore_3", "dstore_0", "dstore_1", "dstore_2", "dstore_3", 
	"astore_0", "astore_1", "astore_2", "astore_3", "iastore", 
	"lastore", "fastore", "dastore", "aastore", "bastore", 
	"castore", "sastore", "pop", "pop2", "dup", 
	"dup_x1", "dup_x2", "dup2", "dup2_x1", "dup2_x2", 
	"swap", "iadd", "ladd", "fadd", "dadd", 
	"isub", "lsub", "fsub", "dsub", "imul", 
	"lmul", "fmul", "dmul", "idiv", "ldiv", 
	"fdiv", "ddiv", "irem", "lrem", "frem", 
	"drem", "ineg", "lneg", "fneg", "dneg", 
	"ishl", "lshl", "ishr", "lshr", "iushr", 
	"lushr", "iand", "land", "ior", "lor", 
	"ixor", "lxor", "iinc", "i2l", "i2f", 
	"i2d", "l2i", "l2f", "l2d", "f2i", 
	"f2l", "f2d", "d2i", "d2l", "d2f", 
	"i2b", "i2c", "i2s", "lcmp", "fcmpl", 
	"fcmpg", "dcmpl", "dcmpg", "ifeq", "ifne", 
	"iflt", "ifge", "ifgt", "ifle", "if_icmpeq", 
	"if_icmpne", "if_icmplt", "if_icmpge", "if_icmpgt", "if_icmple", 
	"if_acmpeq", "if_acmpne", "goto", "jsr", "ret", 
	"tableswitch", "lookupswitch", "ireturn", "lreturn", "freturn", 
	"dreturn", "areturn", "return", "getstatic", "putstatic", 
	"getfield", "putfield", "invokevirtual", "invokespecial", "invokestatic", 
	"xyzNotUsedxyz", "invokeinterface", "new", "newarray", "anewarray", "arraylength", 
	"athrow", "checkcast", "instanceof", "monitorenter", "monitorexit", 
	"wide", "multianewarray", "ifnull", "ifnonnull", "goto_w", 
	"jsr_w", "breakpoint" };
 


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
	/** Inicicializa a JVM.
		Cria espaço para os heaps e para o stackFrame.
		Carrega a class inicial. */
	jvmStartup(classHeap_ptr, objectHeap_ptr, stackFrame_ptr, classPathF_ptr, &dmSize);

	//Fecha o arquivo do primeiro class file aberto
	fclose(classPathF_ptr);

	return 0;
}
