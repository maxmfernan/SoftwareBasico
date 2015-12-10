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
	loadClass(classPathF_ptr, classHeap_ptr, dmSize_ptr); 

	//Checa a consistência da classe

	//Inicializa a classe inicial, roda clinit
	initializeClass(classF);
}
