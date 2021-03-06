#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "macros.h"




int findClass(ClassFile *classHeap_ptr, dataMSize_t dmSize, char* ClassName){

	u2 clsHeapSize = dmSize.stkHeap_size;
	u2 index;

	for(int i=0; i < clsHeapSize; i++) {
		index = classHeap_ptr[i].this_class;
		if(strcmp(classHeap_ptr[i].constant_pool[index-1].info.CONSTANT_Utf8_info.bytes, ClassName) == 0) {
			return i;
		}
	}
	return -1;	
}

u2 findCode(ClassFile *Class) {

	u2 i = 0;

	while(Class->methods->attribute[i].tag != 1){
		i++;
	}
	return i;
}

//Lembrar de enviar o dataMSize->stkHeap_size para o numFrames
void createFrame(method_info *method, ClassFile *Class, Frame *frame_ptr, u2 *numFrames) {
    
	u2 i = *numFrames;
	u2 codeIndex = 0;
	findCode(Class);

	if (i < STKFRAME_MAX - 1) {
	    frame_ptr[i].pClass = Class;
	    frame_ptr[i].pMethod = method;
	    frame_ptr[i].code_length = Class->methods->attribute[codeIndex].info.Code_attribute.code_length;
	    frame_ptr[i].code = malloc(frame_ptr[i].code_length * sizeof(u1));

	    frame_ptr[i].pc = 0;
	    frame_ptr[i].sp = 0;

	    frame_ptr[i].stack_size = Class->methods->attribute[codeIndex].info.Code_attribute.max_stack;
	    frame_ptr[i].local_size = Class->methods->attribute[codeIndex].info.Code_attribute.max_locals;
	    frame_ptr[i].stack = malloc(frame_ptr[i].stack_size * sizeof(u4));
	    frame_ptr[i].local = malloc(frame_ptr[i].local_size * sizeof(u4));

	    *numFrames++;
	} else {
		printf("Frame não pode ser alocado, tamanho máximo atingido");
		exit(1);
	}
}

//Lembrar de enviar o dataMSize->stkHeap_size para o numFrames
void destructFrame(Frame *frame_ptr, u2 *numFrames) {

	free(frame_ptr);
	*numFrames--;

}

int main () {
	int x = 0;
	return x;
}
