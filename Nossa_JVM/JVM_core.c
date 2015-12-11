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
    //OK! 
    loadClass(classPathF_ptr, classHeap_ptr, dmSize_ptr);
   	printf("\nstatic_values_size %d", classHeap_ptr->static_values_size); 
	for(int i = 0; i < classHeap_ptr->static_values_size; i++)
		printf("\nname %s", classHeap_ptr->static_values[i].field_name);
    //Checa a consistência da classe
    printf("\n\nConteudo do .class");
    printf("\n--------------------------------");
    print_ClassFile(classHeap_ptr);
    //Inicializa a classe inicial, roda clinit
	//OK!
    initializeClass(classHeap_ptr, stackFrame_ptr, dmSize_ptr, classHeap_ptr);
    //initializeClass(classHeap_ptr, stackFrame_ptr, &dmSize_ptr->stkHeap_size); //Sei que o primeiro elemento da classHeap é a classe inicial
}

/**
 * @brief
 *
 * @param class_ptr
 * @param stkFrame_ptr
 * @param stkFrameTop_ptr
 */
void initializeClass(ClassFile *class_ptr, Frame *stkFrame_ptr, dataMSize_t *dmSize_ptr, ClassFile *classHeap_ptr){
    u2 method_idx = seekMethodInClass( class_ptr, "<clinit>", "()V" );
    printf("\nIDX %d", method_idx);
    method_info *method_ptr = &class_ptr->methods[method_idx];
    printf("\nOlhe %d", method_ptr->name_index);
    //Quem cria deleta.
    
    createFrame(method_ptr, class_ptr, stkFrame_ptr, &dmSize_ptr->stkHeap_size);//Cria o frame para o método <clinit> da classe.
    
    u2 aux_idx = dmSize_ptr->stkHeap_size - 1; // o stkFrameTop_ptr na verdade é o stack frame size, que indica a qtd de frames na stkframe.
    
    //Teste
    Execute(&stkFrame_ptr[aux_idx], classHeap_ptr, dmSize_ptr);
    
    //Deleta o frame.
    printf("\n%d\t%d\n", dmSize_ptr->stkHeap_size, aux_idx);
    deleteFrame(&stkFrame_ptr[aux_idx], &dmSize_ptr->stkHeap_size);
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

u2 findCode(method_info *method) {
    
    u2 i = 0;
    
    printf("\nEntrou findCode");
    while(method->attribute[i].tag != 1){
        i++;
        
    }
    printf("\n%d", method->attribute[i].tag );
    printf("\n%d", i);
    return i;
}

//Lembrar de enviar o dataMSize->stkHeap_size para o numFrames
void createFrame(method_info *method, ClassFile *Class, Frame *frame_ptr, u2 *numFrames) {
    
    u2 i = *numFrames;
    u2 codeIndex = 0;
    codeIndex = findCode(method);
    
    if (i < STKFRAME_MAX - 1) {
        frame_ptr[i].pClass = Class;
        frame_ptr[i].pMethod = method;
        frame_ptr[i].code_length = method->attribute[codeIndex].info.Code_attribute.code_length;
        frame_ptr[i].code = method->attribute[codeIndex].info.Code_attribute.code;
        
        frame_ptr[i].pc = 0;
        frame_ptr[i].sp = 0;
        
        frame_ptr[i].stack_size = method->attribute[codeIndex].info.Code_attribute.max_stack;
        frame_ptr[i].local_size = method->attribute[codeIndex].info.Code_attribute.max_locals;
        frame_ptr[i].stack = malloc(frame_ptr[i].stack_size * sizeof(u4));
        frame_ptr[i].local = malloc(frame_ptr[i].local_size * sizeof(u4));
        
        /*TESTE*/
        //      frame_ptr[i - 1].pClass = Class;
        //          frame_ptr[i -1].pMethod = method;
        //          frame_ptr[i -1].code_length = Class->methods->attribute[codeIndex].info.Code_attribute.code_length;
        //          frame_ptr[i - 1].code = malloc(frame_ptr[i].code_length * sizeof(u1));
        //
        //          frame_ptr[i - 1].pc = 0;
        //          frame_ptr[i - 1].sp = 0;
        //
        //          frame_ptr[i - 1].stack_size = Class->methods->attribute[codeIndex].info.Code_attribute.max_stack;
        //          frame_ptr[i - 1].local_size = Class->methods->attribute[codeIndex].info.Code_attribute.max_locals;
        //          frame_ptr[i - 1].stack = malloc(frame_ptr[i].stack_size * sizeof(u4));
        //          frame_ptr[i - 1].local = malloc(frame_ptr[i].local_size * sizeof(u4));
        //
        
        
        (*numFrames)++;
        printf("\n##%d", frame_ptr[i].pMethod->attribute[0].info.Code_attribute.max_stack);
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
