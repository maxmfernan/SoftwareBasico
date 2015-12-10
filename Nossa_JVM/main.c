//
//  main.c
//  
//
//  Created by Luiz Henrique Campos Barboza on 09/12/15.
//
//
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>

void loadClass( FILE *classPathF_ptr, ClassFile* clsHeap, dataMSize_t *dmSize ); 
u2 seekMethodInClass(ClassFile *class_ptr, char *methName_str, char *methDescriptor_str);

int main(){
    ClassFile* classHeap_ptr = malloc( sizeof( ClassFile ) );
	dataMSize_t *dmsize;
	dmsize->clsHeap_size = 0;
	dmsize->objHeap_size = 0;
	dmsize->stkHeap_size = 0;

	FILE *classPathF_ptr = fopen("HelloWorld.class", "rb");
	if( classPathF_ptr == NULL ){
		printf("\nErro ao abrir");
		exit(1);
	}

    loadClass( classPathF_ptr, classHeap_ptr, dmsize );

    printf("\n\nConteudo do .class");
    printf("\n--------------------------------");
    print_ClassFile(classHeap_ptr);
 	
	method_idx = seekMethodInClass(challHeap_ptr, "<clinit>", "()V"); 
   	if( method_idx == -1 ){
		printf("\nDeu pau");
	}
	else{
		printf("\n%d", (int*) method_idx);	
	}   
    printf("%s\n",classHeap_ptr->className);
    
    return 0;
}

/**
* @brief Busca no classFile por um métodos específico e retorna o indice para a tabela de métodos
*
* @param class_ptr ponteiro para um classFile
* @param methName_str nome do método que se deseja buscar
* @param methDescriptor_str descritor do método, ()V por exemplo
*
* @return retorna o índice na tabela de métodos do classFile
*/
u2 seekMethodInClass(ClassFile *class_ptr, char *methName_str, char *methDescriptor_str){
	char *methodN;
	char *methodD;
	//char *bytes;
	//u2 str_size;
	for(int i = 0; i < class_ptr->methods_count; i++){
		//str_size = class_ptr->constant_pool[class_ptr->methods[i].name_inex - 1].info.CONSTANT_Utf8_info.length;	
		//methodN = malloc( (str_size + 1)*sizeof(char) );
		//bytes = class_ptr->constant_pool[class_ptr->methods[i].name_index - 1].info.CONSTANT_Utf8_info_bytes;
		
		methodN = class_ptr->constant_pool[class_ptr->methods[i].name_index - 1].info.CONSTANT_Utf8_info.bytes;
		methodD = class_ptr->constant_pool[class_ptr->methods[i].descriptor_index - 1].info.CONSTANT_Utf8_info.bytes;
		if( !strcmp(methodN, methName_str) && !strcmp(methodD, methDescriptor_str) ){
			return i;
		}
		
		/*for(int j = 0; j < str_size; j++){
			methodN[j] = bytes[j]; 
		} 
		methodN[str_size
		*/
	}
	return SEEK_NOTFOUND;
