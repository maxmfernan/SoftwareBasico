#define SEEK_NOTFOUND -1
/**
* @brief Inicializa a JVM; Aloca memória para as estruturas principais; 
	Chama o carregador para a primeira classe; inicializa a primeira classe
*
* @param classHeap 
* @param objectHeap
* @param stackFrame
* @param classPathF_ptr
*/
void jvmStartup(ClassFile *classHeap_ptr, Object *objectHeap_ptr, Frame *stackFrame_ptr, FILE *classPathF_ptr, dataMSize *dmSize_ptr){
	classHeap_ptr = malloc( CLSHEAP_MAX*sizeof( ClassFile ) );
	objectHeap_ptr = malloc( OBJHEAP_MAX*sizeof( Object ) );
	stackFrame_ptr = malloc( STKFRAME_MAX*sizeof( Frame ) );

	//Carrega a classe inicial
	//ok +-
	loadClass(classPathF_ptr, classHeap_ptr, dmSize_ptr); 

	//Checa a consistência da classe

	//Inicializa a classe inicial, roda clinit
	initializeClass(classHeap_ptr); //Sei que o primeiro elemento da classHeap é a classe inicial
}

void initializeClass(ClassFile *class_ptr){

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
	for(int i = 0: i < class_ptr->methods_count){
		//str_size = class_ptr->constant_pool[class_ptr->methods[i].name_inex - 1].info.CONSTANT_Utf8_info.length;	
		//methodN = malloc( (str_size + 1)*sizeof(char) );
		//bytes = class_ptr->constant_pool[class_ptr->methods[i].name_index - 1].info.CONSTANT_Utf8_info_bytes;
		
		methodN = class_ptr->constant_pool[class_ptr->methods[i].name_index - 1].info.CONSTANT_Utf8_info.bytes;
		methodD = class_ptr->constant_pool[class_ptr->methods[i].descriptor_index - 1].info.CONSTANT_Utf8_infor.bytes;
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
