#include "macros.h"
#include "JVM_core.h"
#include "LoadClass_core.h"
/**
* @brief Inicializa a JVM; Aloca memória para as estruturas principais; 
	Chama o carregador para a primeira classe; inicializa a primeira classe
*
* @param classHeap 
* @param objectHeap
* @param stackFrame
* @param classPathF_ptr
*/
void jvmStartup(ClassFile *classHeap_ptr, Object *objectHeap_ptr, Frame *stackFrame_ptr, FILE *classPathF_ptr, dataMSize_t *dmSize_ptr){
	classHeap_ptr = malloc( CLSHEAP_MAX*sizeof( ClassFile ) );
	objectHeap_ptr = malloc( OBJHEAP_MAX*sizeof( Object_t ) );
	stackFrame_ptr = malloc( STKFRAME_MAX*sizeof( Frame ) );

	dmSize_ptr->clsHeap_size = 0;
	dmSize_ptr->objHeap_size = 0;
	dmSize_ptr->stkHeap_size = 0;

	//Carrega a classe inicial
	//OK! +-
	loadClass(classPathF_ptr, classHeap_ptr, dmSize_ptr); 

	//Checa a consistência da classe

	//Inicializa a classe inicial, roda clinit
	initializeClass(classHeap_ptr, stackFrame_ptr, &dmSize_ptr->stkHeap_size); //Sei que o primeiro elemento da classHeap é a classe inicial
}

/**
* @brief 
*
* @param class_ptr
* @param stkFrame_ptr
* @param stkFrameTop_ptr
*/
void initializeClass(ClassFile *class_ptr, Frame *stkFrame_ptr, u2 *stkFrameTop_ptr){
	u2 method_idx = seekMethodInClass( class_ptr, "<clinit>", "()V" );
	method_info *method_ptr = &class_ptr->methods[method_idx];
	
	//Quem cria deleta.	
	createFrame(method_ptr, class_ptr, stkFrame_ptr, stkFrameTop_ptr);//Cria o frame para o método <clinit> da classe.
	
	u2 aux_idx = *stkFrameTop_ptr - 1; // o stkFrameTop_ptr na verdade é o stack frame size, que indica a qtd de frames na stkframe.

	//Teste
	//execute(stkFrame_ptr[aux_idx]);

	//Deleta o frame.
	printf("\n%d\t%d\n", *stkFrameTop_ptr, aux_idx);
	deleteFrame(&stkFrame_ptr[aux_idx], stkFrameTop_ptr);
}

/** OK!
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
		
		printf("\n%hu", i);
			
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
}

/*SAMUEL - início*/
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

	printf("\nEntrou findCode");
	while(Class->methods->attribute[i].tag != 1){
		i++;
		
	}
	printf("\n%d", Class->methods->attribute[i].tag );
	return i;
}

//Lembrar de enviar o dataMSize->stkHeap_size para o numFrames
void createFrame(method_info *method, ClassFile *Class, Frame *frame_ptr, u2 *numFrames) {
    
	u2 i = *numFrames;
	u2 codeIndex = 0;
	codeIndex = findCode(Class);

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

	/*TESTE*/
//	frame_ptr[i - 1].pClass = Class;
//	    frame_ptr[i -1].pMethod = method;
//	    frame_ptr[i -1].code_length = Class->methods->attribute[codeIndex].info.Code_attribute.code_length;
//	    frame_ptr[i - 1].code = malloc(frame_ptr[i].code_length * sizeof(u1));
//
//	    frame_ptr[i - 1].pc = 0;
//	    frame_ptr[i - 1].sp = 0;
//
//	    frame_ptr[i - 1].stack_size = Class->methods->attribute[codeIndex].info.Code_attribute.max_stack;
//	    frame_ptr[i - 1].local_size = Class->methods->attribute[codeIndex].info.Code_attribute.max_locals;
//	    frame_ptr[i - 1].stack = malloc(frame_ptr[i].stack_size * sizeof(u4));
//	    frame_ptr[i - 1].local = malloc(frame_ptr[i].local_size * sizeof(u4));
//


	    (*numFrames)++;
			printf("\n##%d", frame_ptr[i].pMethod->name_index);
			printf("\nLength %d", frame_ptr[i].code_length);
	} else {
		printf("Frame não pode ser alocado, tamanho máximo atingido");
		exit(1);
	}
}

//Lembrar de enviar o dataMSize->stkHeap_size para o numFrames
void deleteFrame(Frame *frame_ptr, u2 *numFrames) {

	free(frame_ptr);
	(*numFrames)--;

}

/*SAMUEL - FIM*/
