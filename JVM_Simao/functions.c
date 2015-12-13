#include "functions.h"

/*PUSH null na pilha de operandos */
void aconst_null(OPERAND_STACK **pilha){

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_NULL;
	(newItem->type).object_ref = NULL;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);
}

/*empurra a constante 0.0 ou 1.0 na pilha - ocupa 2 espacos*/
void dconst_n(double number,OPERAND_STACK **pilha){

	double *dAux = malloc(sizeof(double));
	*dAux = number;

	unsigned int *iAux = calloc(2,sizeof(unsigned int));
	memcpy(iAux,dAux,8);

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_DOUBLE;
	(newItem->type).u_int_number = iAux[0];
	newItem->prox = NULL;

	OPERAND_STACK *newItem2 = malloc(sizeof(OPERAND_STACK));
	newItem2->operand_type = TYPE_DOUBLE;
	(newItem2->type).u_int_number = iAux[1];
	newItem2->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);
	PushOperandoPilha(&(*pilha), newItem2);

}

/*empurra a constante 0.0, 1.0, 2.0 ou 3.0 na pilha*/
void fconst_n(float number,OPERAND_STACK **pilha){

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_INT;
	(newItem->type).float_number = number;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);
}

/*empurra a constante 0,1,2,3,4 ou 5 na pilha*/
void iconst_n(int number,OPERAND_STACK **pilha){
	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_INT;
	(newItem->type).int_number = number;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);
	printStack((*pilha));
}

/*empurra a constante -1 na pilha*/
void iconst_m1(OPERAND_STACK **pilha){
	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_INT;
	(newItem->type).int_number = -1;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);
}

/*empurra a constante 0 ou 1 na pilha - ocupa 2 espacos*/
void lconst_n(long int number, OPERAND_STACK **pilha){

	long int *lAux = malloc(sizeof(long int));
	*lAux = number;

	int *iAux = calloc(2,sizeof(unsigned int));
	memcpy(iAux,lAux,8);
	/*A[0] = bits LSB e A[1] = bits MSB*/

	OPERAND_STACK *newItem1 = malloc(sizeof(OPERAND_STACK));
	newItem1->operand_type = TYPE_LONG;
	(newItem1->type).u_int_number = iAux[0];
	newItem1->prox = NULL;

	OPERAND_STACK *newItem2 = malloc(sizeof(OPERAND_STACK));
	newItem2->operand_type = TYPE_LONG;
	(newItem2->type).u_int_number = iAux[1];
	newItem2->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem1);
	PushOperandoPilha(&(*pilha), newItem2);

}

/*soma os dois floats do topo da pilha e joga o resultado na pilha*/
int fadd(OPERAND_STACK **pilha)
{
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));
	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));

	if ((operando1->operand_type != TYPE_FLOAT)){
		if((operando1->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}

	if ((operando2->operand_type != TYPE_FLOAT)){
		if((operando2->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}

	float faux1 = (operando1->type).float_number;
	float faux2 = (operando2->type).float_number;

	faux1 = faux1 + faux2;

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_FLOAT;
	(newItem->type).float_number = faux1;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);

	return 0;
}

/*divide os dois floats do topo da pilha e joga o resultado na pilha*/
int fdiv(OPERAND_STACK **pilha){
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));
	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));


	if ((operando1->operand_type != TYPE_FLOAT)){
		if((operando1->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}


	if ((operando2->operand_type != TYPE_FLOAT)){
		if((operando2->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}

	float faux1 = (operando1->type).float_number;
	float faux2 = (operando2->type).float_number;

	faux1 = faux2 / faux1;

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_FLOAT;
	(newItem->type).float_number = faux1;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);

	return 0;
}

/*multiplica os dois floats do topo da pilha e joga o resultado na pilha*/
int fmul(OPERAND_STACK **pilha){
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));
	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));

	if ((operando1->operand_type != TYPE_FLOAT)){
		if((operando1->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}


	if ((operando2->operand_type != TYPE_FLOAT)){
		if((operando2->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}


	float faux1 = (operando1->type).float_number;
	float faux2 = (operando2->type).float_number;

	faux1 = faux1 * faux2;

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_FLOAT;
	(newItem->type).float_number = faux1;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);
	return 0;
}

/*nega o valor do topo da pilha e coloca na pilha*/
int fneg(OPERAND_STACK **pilha){
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if ((operando1->operand_type != TYPE_FLOAT)){
		if((operando1->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}


	float faux1 = (operando1->type).float_number;
	faux1 = faux1 * -(1.0);

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_FLOAT;
	(newItem->type).float_number = faux1;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);

	return 0;
}

/*divde os dois floats do topo da pilha e joga o resto na pilha*/
int frem(OPERAND_STACK **pilha){
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));
	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));

	if ((operando1->operand_type != TYPE_FLOAT)){
		if((operando1->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}


	if ((operando2->operand_type != TYPE_FLOAT)){
		if((operando2->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}


	float faux1 = (operando1->type).float_number;
	float faux2 = (operando2->type).float_number;

	float div = faux1/faux2;
	int intAux = round(div);
	faux1 = faux1 - ((float)intAux * faux2);

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_FLOAT;
	(newItem->type).float_number = faux1;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);

	return 0;
}

/*subtrai os dois floats do topo da pilha e joga o resultado na pilha*/
int fsub(OPERAND_STACK **pilha){
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));
	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));

	if ((operando1->operand_type != TYPE_FLOAT)){
		if((operando1->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}


	if ((operando2->operand_type != TYPE_FLOAT)){
		if((operando2->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}


	float faux1 = (operando1->type).float_number;
	float faux2 = (operando2->type).float_number;

	faux2 -=faux1;

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_FLOAT;
	(newItem->type).float_number = faux2;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);

	return 0;
}

int astore(OPERAND_STACK **pilha, ITEM_VECTOR **vetor, int index_vector){

	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if (operando1->operand_type != TYPE_OBJ_REF) {
		return 1;
	}

	ITEM_VECTOR *vetAux = (*vetor);
	if (vetAux == NULL) {
		ITEM_VECTOR *newItem = malloc(sizeof(ITEM_VECTOR));
		newItem->type_union = TYPE_OBJ_REF;
		(newItem->type).object_ref = (operando1->type).object_ref;
		newItem->index_item = index_vector;
		newItem->prox = NULL;
		(*vetor) = newItem;
		return 0;
	}

	ITEM_VECTOR *newItem = malloc(sizeof(ITEM_VECTOR));
	newItem->type_union = TYPE_OBJ_REF;
	(newItem->type).object_ref = (operando1->type).object_ref;
	newItem->index_item = index_vector;
	newItem->prox = NULL;

	insereItemVetor(&(*vetor), newItem);

	return 0;
}

int fstore(OPERAND_STACK **pilha, ITEM_VECTOR **vetor, int index_vector){

	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if ((operando1->operand_type != TYPE_FLOAT)){
		if((operando1->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}


	ITEM_VECTOR *vetAux = (*vetor);
	if (vetAux == NULL) {

		ITEM_VECTOR *newItem = malloc(sizeof(ITEM_VECTOR));
		newItem->type_union = TYPE_FLOAT;
		(newItem->type).float_number = (operando1->type).float_number;
		newItem->index_item = index_vector;
		newItem->prox = NULL;
		(*vetor) = newItem;
		/*printVetor(*vetor);*/
		return 0;
	}

	ITEM_VECTOR *newItem = malloc(sizeof(ITEM_VECTOR));
	newItem->type_union = TYPE_FLOAT;
	(newItem->type).float_number = (operando1->type).float_number;
	newItem->index_item = index_vector;
	newItem->prox = NULL;

	insereItemVetor(&(*vetor), newItem);
	/*printVetor(*vetor);*/

	return 0;
}


int dstore(OPERAND_STACK **pilha, ITEM_VECTOR **vetor, int index_vector){

	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if (operando1->operand_type != TYPE_DOUBLE) {
		return 1;
	}

	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));
	if (operando2->operand_type != TYPE_DOUBLE) {
		return 1;
	}

	unsigned int *iAux = calloc(2,sizeof(unsigned int));
	ITEM_VECTOR *newItem;
	ITEM_VECTOR *newItem2;

	iAux[0] = (operando2->type).u_int_number;
	iAux[1] = (operando1->type).u_int_number;

	ITEM_VECTOR *vetAux = (*vetor);
	if (vetAux == NULL) {
		newItem = malloc(sizeof(ITEM_VECTOR));
		newItem->type_union = TYPE_DOUBLE;
		(newItem->type).u_int_number = (operando2->type).u_int_number;
		newItem->index_item = index_vector + 1;
		newItem->prox = NULL;

		newItem2 = malloc(sizeof(ITEM_VECTOR));
		newItem2->type_union = TYPE_DOUBLE;
		(newItem2->type).u_int_number = (operando1->type).u_int_number;
		newItem2->index_item = index_vector;
		newItem2->prox = NULL;
		(*vetor) = newItem2;
		(*vetor)->prox = newItem;

	/*printf("\nParte 1: %u\n",(newItem->type).u_int_number);
    printf("Parte 2: %u\n",(newItem2->type).u_int_number);*/

		/*printVetor(*vetor);*/
		return 0;
	}
	else
	{
		newItem = malloc(sizeof(ITEM_VECTOR));
		newItem->type_union = TYPE_DOUBLE;
		(newItem->type).u_int_number = iAux[0];
		newItem->index_item = index_vector + 1;
		newItem->prox = NULL;

		newItem2 = malloc(sizeof(ITEM_VECTOR));
		newItem2->type_union = TYPE_DOUBLE;
		(newItem2->type).u_int_number = iAux[1];
		newItem2->index_item = index_vector;
		newItem2->prox = NULL;

    insereItemVetor(&(*vetor), newItem2);
 	insereItemVetor(&(*vetor), newItem);

   /*printVetor(*vetor);*/
   }

	return 0;
}

int istore(OPERAND_STACK **pilha, ITEM_VECTOR **vetor, int index_vector){
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if ((operando1->operand_type != TYPE_INT)){
		if((operando1->operand_type != TYPE_INT_U)) {
			return 1;
		}
	}

	ITEM_VECTOR *vetAux = (*vetor);
	if (vetAux == NULL) {
		ITEM_VECTOR *newItem = malloc(sizeof(ITEM_VECTOR));
		newItem->type_union = TYPE_INT;
		(newItem->type).int_number = (operando1->type).int_number;
		newItem->index_item = index_vector;
		newItem->prox = NULL;
		(*vetor) = newItem;
        /*printVetor((*vetor));*/
		return 0;
	}

	ITEM_VECTOR *newItem = malloc(sizeof(ITEM_VECTOR));
	newItem->type_union = TYPE_INT;
	(newItem->type).int_number = (operando1->type).int_number;
	newItem->index_item = index_vector;
	newItem->prox = NULL;

	insereItemVetor(&(*vetor), newItem);
	/*printVetor(*vetor);*/

	 /*printVetor((*vetor));*/

	return 0;
}

int lstore(OPERAND_STACK **pilha, ITEM_VECTOR **vetor, int index_vector){

	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if (operando1->operand_type != TYPE_LONG) {
         printf("Erro - lstore1");
		return 1;
	}

	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));
	if (operando2->operand_type != TYPE_LONG) {
         printf("Erro - lstore2");
		return 1;
	}
	/*printf("\nParte 1: %u\n",(operando1->type).u_int_number);
    printf("Parte 2: %u\n",(operando2->type).u_int_number);*/

	ITEM_VECTOR *vetAux = (*vetor);
	if (vetAux == NULL) {
		ITEM_VECTOR *newItem = malloc(sizeof(ITEM_VECTOR));
		newItem->type_union = TYPE_LONG;
		(newItem->type).int_number = (operando1->type).int_number;
		newItem->index_item = index_vector + 1;
		newItem->prox = NULL;

		ITEM_VECTOR *newItem2 = malloc(sizeof(ITEM_VECTOR));
		newItem2->type_union = TYPE_LONG;
		(newItem2->type).int_number = (operando2->type).int_number;
		newItem2->index_item = index_vector;
		newItem2->prox = NULL;
		(*vetor) = newItem2;
		(*vetor)->prox = newItem;

        /*printVetor(*vetor);*/
		return 0;
	}

	ITEM_VECTOR *newItem = malloc(sizeof(ITEM_VECTOR));
	newItem->type_union = TYPE_LONG;
	(newItem->type).int_number = (operando1->type).int_number;
	newItem->index_item = index_vector + 1;
	newItem->prox = NULL;

	ITEM_VECTOR *newItem2 = malloc(sizeof(ITEM_VECTOR));
	newItem2->type_union = TYPE_LONG;
	(newItem2->type).int_number = (operando2->type).int_number;
	newItem2->index_item = index_vector;
	newItem2->prox = NULL;

	insereItemVetor(&(*vetor), newItem2);
	insereItemVetor(&(*vetor), newItem);
	/*printVetor(*vetor);*/

	return 0;
}

int aastore(OPERAND_STACK **pilha)
{
	OPERAND_STACK *item1_obj = PopOperandoPilha(&(*pilha));
	OPERAND_STACK *item2_int = PopOperandoPilha(&(*pilha));
	OPERAND_STACK *item3_arr = PopOperandoPilha(&(*pilha));

	CLASS *value = (item1_obj->type).object_ref;
	int index = (item2_int->type).int_number;
	CLASS *array_ref = (CLASS*)(item3_arr->type).vector_ref;
	CLASS **array = (CLASS**)&array_ref[0];

	array[index] = value;

	return 0;
}

/*funcao que inicia uma nova classe. É necessário passar um ponteiro para a nova classe e o nome do arquivo (ou caminho para o arquivo)*/
int new(ConstantPoolItem *vConstPool, CLASS **newClass, int index_class, CLASS *vClasse){

	CLASS *classe = *newClass;
	FILE *arquivo;
    u4 magicNumber;
    u4 result;
    u4 magicTest;
    u4 i;
    u2 minor;
    u2 major;
    u4 constPoolCount;
    u2 acessFlag;
    u2 thisClass;
    u2 superClass;
    
    ConstantPoolItem *constPool;
	ConstantPoolItem *outroConstPool = vConstPool;
    
    int index = 0;
	index = index_class;
	ConstantPoolItem *constItem = searchConstPoolItem(outroConstPool,index, vClasse->constPoolCount);

	if (constItem->tag != 10) {
		return 1;
	}
	int index_caminho_arquivo = ((constItem->info).refInfo).class_index;


	ConstantPoolItem *constItem2 = searchConstPoolItem(outroConstPool,index_caminho_arquivo,vClasse->constPoolCount);
	if (constItem2->tag != 7) {
		return 1;
	}
	int index_string_arquivo = ((constItem2->info).classInfo).name_index;


	ConstantPoolItem *constItem3 = searchConstPoolItem(outroConstPool,index_string_arquivo, vClasse->constPoolCount);
	if (constItem3->tag != 1) {
		return 1;
	}

	int tamanho = ((constItem3->info).utf8Info)->tamanho + 8;
	char *nomeArquivo = malloc(tamanho);
	char *nome = ((constItem3->info).utf8Info)->conteudo;
	char *pontoClass = ".class\0";

	strcpy(nomeArquivo,nome);
	strcat(nomeArquivo,pontoClass);

	/*printf("Arquivo: %s\n", nomeArquivo);*/
	arquivo=fopen(nomeArquivo,"rb");
	if (!arquivo)
	{
		printf("Não foi possível abrir o arquivo!\n");
		return 1;
	}
    
    classe = malloc(sizeof(CLASS));
    
	classe->minor =0;
	classe->major =0;
	classe->constPoolCount =0;
	classe->acessFlag =0;
	classe->thisClassRef =0;
	classe->superClassRef =0;
	classe->interfaceCount =0;
	classe->fieldsCount =0;
	classe->methodsCount =0;
	classe->attributeCount =0;
    
	classe->listaMetodos = NULL;
	classe->listaAtributos = NULL;
	classe->listaField = NULL;
	classe->listaInterface = NULL;
	classe->constPool = NULL;
	
	
    magicTest = 0xCAFEBABE;
    magicNumber = 0;
    result = fread(&magicNumber, sizeof(int), 1, arquivo);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        return 1;
    }
    
    magicNumber =inverteIntBits(magicNumber);
    if(magicNumber != magicTest)
    {
        printf("Magic Number errado.\n");
        return 1;      
    }
    printf("Magic Number %#x\n",magicNumber);
    
    minor = 0;
    result = fread(&minor, sizeof(short), 1, arquivo);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        return 1;
    }
    minor = inverteShortBits(minor);
    classe->minor = minor;
    printf("Minor %d\n",classe->minor);
    
    major = 0;
    result = fread(&major, sizeof(short), 1, arquivo);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        return 1;
    }
    major = inverteShortBits(major);
    classe->major = major;
    printf("Major %d\n",classe->major);
    
    constPoolCount = 0;
    result = fread(&constPoolCount, sizeof(short), 1, arquivo);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        return 1;
    }
    constPoolCount = inverteShortBits(constPoolCount);
    classe->constPoolCount = constPoolCount;
    
    constPool = NULL;
    readConstPool(arquivo, &classe, &constPool);
    printfConstPoolItems(constPool); 
    
	fread(&acessFlag, sizeof(short), 1, arquivo);
	fread(&thisClass, sizeof(short), 1, arquivo);
	fread(&superClass, sizeof(short), 1, arquivo);
	classe->acessFlag = acessFlag = inverteShortBits(acessFlag);
	classe->thisClassRef = thisClass = inverteShortBits(thisClass);
	classe->superClassRef = superClass = inverteShortBits(superClass);

	/*printf("Acess Flag: %hu\n", classe->acessFlag);
	printf("This Class Ref: %hu\n", classe->thisClassRef);
	printf("Super class Ref: %hu\n", classe->superClassRef);*/
	
	ConstantPoolItem *constPoolItemAux2;
	constPoolItemAux2 = searchConstPoolItem(constPool, classe->thisClassRef, constPoolCount);
	CONSTANT_Class constClassAux1;
    constClassAux1 = constPoolItemAux2->info.classInfo;
    
	ConstantPoolItem *constPoolItemAux3;
	constPoolItemAux3 = searchConstPoolItem(constPool, constClassAux1.name_index, constPoolCount);
	
	CONSTANT_Utf8 *constClassName;
	constClassName = malloc(sizeof(CONSTANT_Utf8));
	if(constPoolItemAux3->tag == TAG_CONSTANT_Utf8){
		constClassName = (constPoolItemAux3->info).utf8Info;
		classe->thisClass = constClassName->conteudo;
	}
	/*printf("This Class Name: %s\n", classe->thisClass);*/
	
/*--------------------------*/
    ConstantPoolItem *constPoolItemAux4;
	constPoolItemAux4 = searchConstPoolItem(constPool, classe->superClassRef, constPoolCount);
	CONSTANT_Class constClassAux2;
    constClassAux2 = constPoolItemAux4->info.classInfo;
    
	ConstantPoolItem *constPoolItemAux5;
	constPoolItemAux5 = searchConstPoolItem(constPool, constClassAux2.name_index, constPoolCount);
	
	CONSTANT_Utf8 *constClassName2;
	constClassName2 = malloc(sizeof(CONSTANT_Utf8));
	if(constPoolItemAux5->tag == TAG_CONSTANT_Utf8){
		constClassName2 = (constPoolItemAux5->info).utf8Info;
		classe->superClass = constClassName2->conteudo;
	}
	/*printf("Super Class Name: %s\n", classe->superClass);*/
	
	classe->listaMetodos = NULL;
	classe->listaAtributos = NULL;
	classe->listaField = NULL;
	classe->listaInterface = NULL;
	
/* --------------- INTERFACES -------------------*/
    /*printf(" ----------------- Interfaces --------------------\n");*/
	fread(&(classe->interfaceCount), sizeof(short), 1, arquivo);
	classe->interfaceCount = inverteShortBits(classe->interfaceCount);
	/*printf("Nro interfaces: %hu\n\n", classe->interfaceCount);*/
	readInterfaces(&classe, arquivo, 'N');
	
/* --------------- CAMPOS -------------------*/
	/*printf(" ----------------- CAMPOS --------------------\n");*/
	fread(&(classe->fieldsCount), sizeof(short), 1, arquivo);
	classe->fieldsCount = inverteShortBits(classe->fieldsCount);
	/*printf("Nro Campos: %hu\n\n", classe->fieldsCount);*/
	readFields(&classe, arquivo,constPool,'N');
	
/* --------------- METODOS -------------------*/
	/*printf(" ----------------- METODOS --------------------\n");*/
	fread(&(classe->methodsCount), sizeof(short), 1, arquivo);
	classe->methodsCount = inverteShortBits(classe->methodsCount);
    /*printf("Nro Metodos: %hu\n\n", classe->methodsCount);*/
    char *charAux = malloc(sizeof(METHOD));
	readMethods(&classe, arquivo, constPool,'N');
	
/* --------------- ATRIBUTOS -------------------*/
	/*printf(" ----------------- ATRIBUTOS --------------------\n");*/
	fread(&(classe->attributeCount), sizeof(short), 1, arquivo);
	classe->attributeCount = inverteShortBits(classe->attributeCount);
	/*printf("Attribute count: %hu\n\n", classe->attributeCount);*/
	readAttributes(&classe, arquivo,constPool,'N');
	
	insereClasse(classe, classe->thisClass);
	
	fclose(arquivo);
	
	return 0;
}

/*operacao que converte um double para um float*/
int d2f(OPERAND_STACK **pilha)
{
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if (operando1->operand_type != TYPE_DOUBLE) {
		return 1;
	}

	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));
	if (operando2->operand_type != TYPE_DOUBLE) {
		return 1;
	}

	unsigned int *iAux = calloc(2,sizeof(unsigned int));

	iAux[0] = (operando2->type).u_int_number;
	iAux[1] = (operando1->type).u_int_number;

	double *dAux = malloc(sizeof(double));
	memcpy(dAux,iAux,8);

	float fAux = (float)(*dAux);

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_FLOAT;
	(newItem->type).float_number = fAux;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);

	return 0;
}

/*operacao que converte um double para um inteiro*/
int d2i(OPERAND_STACK **pilha)
{
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if (operando1->operand_type != TYPE_DOUBLE) {
		return 1;
	}

	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));
	if (operando2->operand_type != TYPE_DOUBLE) {
		return 1;
	}

	unsigned int *i_u_Aux = calloc(2,sizeof(unsigned int));

	i_u_Aux[0] = (operando2->type).u_int_number;
	i_u_Aux[1] = (operando1->type).u_int_number;

	double *dAux = malloc(sizeof(double));
	memcpy(dAux,i_u_Aux,8);

	int iAux = (int)(*dAux);

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_INT;
	(newItem->type).int_number = iAux;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);

	return 0;
}

/*operacao que converte um double para um long int*/
int d2l(OPERAND_STACK **pilha)
{
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if (operando1->operand_type != TYPE_DOUBLE) {
		return 1;
	}

	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));
	if (operando2->operand_type != TYPE_DOUBLE) {
		return 1;
	}

	unsigned int *i_u_Aux = calloc(2,sizeof(unsigned int));

	i_u_Aux[0] = (operando2->type).u_int_number;
	i_u_Aux[1] = (operando1->type).u_int_number;

	double *dAux = malloc(sizeof(double));
	memcpy(dAux,i_u_Aux,8);

	long int *lAux = malloc(sizeof(long));;
	*lAux= (long int)(*dAux);

	memcpy(i_u_Aux,lAux,8);

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_LONG;
	(newItem->type).u_int_number = i_u_Aux[0];
	newItem->prox = NULL;

	OPERAND_STACK *newItem2 = malloc(sizeof(OPERAND_STACK));
	newItem2->operand_type = TYPE_LONG;
	(newItem2->type).u_int_number = i_u_Aux[1];
	newItem2->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);
	PushOperandoPilha(&(*pilha), newItem2);

	return 0;
}

/*operacao que pega os ultimos 32bits de um long e armazena em um inteiro*/
int l2i(OPERAND_STACK **pilha)
{
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if (operando1->operand_type != TYPE_LONG) {
		return 1;
	}

	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));
	if (operando2->operand_type != TYPE_LONG) {
		return 1;
	}


	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_INT;
	(newItem->type).int_number = (operando2->type).u_int_number;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);

	return 0;
}

/*operacao que converte um long em um float*/
int l2f(OPERAND_STACK **pilha)
{
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if (operando1->operand_type != TYPE_LONG) {
		return 1;
	}

	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));
	if (operando2->operand_type != TYPE_LONG) {
		return 1;
	}

	unsigned int *i_u_Aux = calloc(2,sizeof(unsigned int));

	i_u_Aux[1] = (operando1->type).u_int_number;
	i_u_Aux[0] = (operando2->type).u_int_number;

	long int *lAux = malloc(sizeof(long int));;
	memcpy(lAux,i_u_Aux,8);

	float fAux = (float)(*lAux);

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_FLOAT;
	(newItem->type).float_number = fAux;
	newItem->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);

	return 0;
}

/*operacao que converte um long em um double*/
int l2d(OPERAND_STACK **pilha){
	OPERAND_STACK *operando1 = PopOperandoPilha(&(*pilha));

	if (operando1->operand_type != TYPE_LONG) {
		return 1;
	}

	OPERAND_STACK *operando2 = PopOperandoPilha(&(*pilha));
	if (operando2->operand_type != TYPE_LONG) {
		return 1;
	}

	unsigned int *i_u_Aux = calloc(2,sizeof(unsigned int));

	i_u_Aux[0] = (operando2->type).u_int_number;
	i_u_Aux[1] = (operando1->type).u_int_number;

	long int *lAux = malloc(sizeof(long));
	memcpy(lAux,i_u_Aux,8);

	double *dAux = malloc(sizeof(double));
	*dAux= (double)(*lAux);

	memcpy(i_u_Aux,dAux,8);

	OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
	newItem->operand_type = TYPE_DOUBLE;
	(newItem->type).u_int_number = i_u_Aux[0];
	newItem->prox = NULL;

	OPERAND_STACK *newItem2 = malloc(sizeof(OPERAND_STACK));
	newItem2->operand_type = TYPE_DOUBLE;
	(newItem2->type).u_int_number = i_u_Aux[1];
	newItem2->prox = NULL;

	PushOperandoPilha(&(*pilha), newItem);
	PushOperandoPilha(&(*pilha), newItem2);

	return 0;
}

/*funcao que incrementa o increment a variavel index_vector do vetor de variaveis locais*/
int iinc(OPERAND_STACK **pilha, ITEM_VECTOR **vector, unsigned int index_vector, int increment){

	ITEM_VECTOR *itemAux;

	itemAux = procuraItemVetor(&(*vector),index_vector);
	if (itemAux == NULL) {
		printf("Item não existente no vetor de variaveis locais.\n");
		return 1;
	}

	if (itemAux->type_union != TYPE_INT) {
		printf("Item não é inteiro.\n");
		return 1;
	}

	(itemAux->type).int_number += increment;
	/*printVetor(*vector);*/

	return 0;
}

/*funcao que empurra na pilha uma single-word*/
int ldc(OPERAND_STACK **pilha, short index_constPool, ConstantPoolItem *constPool)
{
	ConstantPoolItem *itemConstPool1 = searchConstPoolItem(constPool, index_constPool, constPool->count);
	/*printf("Tag: %d\n",itemConstPool1->tag);
	printf("index: %d\n",index_constPool);*/

	if (itemConstPool1->tag == TAG_CONSTANT_String) {
		CONSTANT_String constAuxString = (itemConstPool1->info).stringInfo;
		ConstantPoolItem *itemConstPool2 = searchConstPoolItem(constPool, constAuxString.string_index, constPool->count);
		if(itemConstPool2->tag == TAG_CONSTANT_Utf8)
		{
			CONSTANT_Utf8 *constAux = (itemConstPool2->info).utf8Info;
			OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
			newItem->operand_type = TYPE_STRING;
			(newItem->type).string = constAux->conteudo;
			newItem->prox = NULL;
			PushOperandoPilha(&(*pilha), newItem);
			return 0;
		}

	}
	else{
		if (itemConstPool1->tag == TAG_CONSTANT_Float) {
			CONSTANT_Float constAux = (itemConstPool1->info).floatInfo;
			OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
			newItem->operand_type = TYPE_FLOAT;
			(newItem->type).float_number = constAux.valor;
			newItem->prox = NULL;
			PushOperandoPilha(&(*pilha), newItem);
		}
		else {
             if (itemConstPool1->tag == TAG_CONSTANT_Integer) {
    			CONSTANT_Integer constAux = (itemConstPool1->info).integerInfo;
    			OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
    			newItem->operand_type = TYPE_INT;
    			(newItem->type).int_number = constAux.valor;
    			newItem->prox = NULL;
    			PushOperandoPilha(&(*pilha), newItem);
              }
		}

	}

	return 0;
}

/*funcao que empurra na pilha uma single-word*/
int ldc_w(OPERAND_STACK **pilha, int index_constPool, ConstantPoolItem *constPool)
{
	ConstantPoolItem *itemConstPool1 = searchConstPoolItem(constPool, index_constPool, constPool->count);

	if (itemConstPool1->tag == TAG_CONSTANT_String) {
		CONSTANT_String constAuxString = (itemConstPool1->info).stringInfo;
		ConstantPoolItem *itemConstPool2 = searchConstPoolItem(constPool, constAuxString.string_index, constPool->count);
		if(itemConstPool2->tag == TAG_CONSTANT_Utf8)
		{
			CONSTANT_Utf8 *constAux = (itemConstPool2->info).utf8Info;
			OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
			newItem->operand_type = TYPE_STRING;
			(newItem->type).string = malloc(sizeof(constAux->tamanho));
			(newItem->type).string = constAux->conteudo;
			newItem->prox = NULL;
			PushOperandoPilha(&(*pilha), newItem);
			return 0;
		}

	}
	else{
		if (itemConstPool1->tag == TAG_CONSTANT_Float) {
			CONSTANT_Float constAux = (itemConstPool1->info).floatInfo;
			OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
			newItem->operand_type = TYPE_FLOAT;
			(newItem->type).float_number = constAux.valor;
			newItem->prox = NULL;
			PushOperandoPilha(&(*pilha), newItem);
		}
		else {
			CONSTANT_Integer constAux = (itemConstPool1->info).integerInfo;
			OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
			newItem->operand_type = TYPE_INT;
			(newItem->type).int_number = constAux.valor;
			newItem->prox = NULL;
			PushOperandoPilha(&(*pilha), newItem);
		}

	}

	return 0;
}

/*funcao que empurra na pilha um double ou um long do constant pool*/
int ldc2_w(OPERAND_STACK **pilha, int index_constPool, ConstantPoolItem *constPool)
{
	ConstantPoolItem *itemConstPool1;
    itemConstPool1 = searchConstPoolItem(constPool, index_constPool, constPool->count);
	CONSTANT_Double constAux;
	unsigned int *iAux;

	if (itemConstPool1->tag == TAG_CONSTANT_Double) {
		constAux = (itemConstPool1->info).doubleInfo;

		iAux = calloc(2,sizeof(int)); /*variavel auxiliar para quebrar o double*/
		memcpy(iAux,&constAux.valor,8); /*copia todos os bits para um unsigned int*/

		/*coloca a parte LSB dos bits*/
		OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
		newItem->operand_type = TYPE_DOUBLE;
		(newItem->type).u_int_number = iAux[0];
		newItem->prox = NULL;

		/*coloca a parte MSB dos bits*/
		OPERAND_STACK *newItem2 = malloc(sizeof(OPERAND_STACK));
		newItem2->operand_type = TYPE_DOUBLE;
		(newItem2->type).u_int_number = iAux[1];
		newItem2->prox = NULL;

		PushOperandoPilha(&(*pilha), newItem);
		PushOperandoPilha(&(*pilha), newItem2);
	}
	else {
		CONSTANT_Long constAux = (itemConstPool1->info).longInfo;

		long long int *lAux = malloc(sizeof(long int));
		*lAux = constAux.valor; /*valor do double*/

		unsigned int *iAux = calloc(2,sizeof(int)); /*variavel auxiliar para quebrar o double*/
		memcpy(iAux,lAux,8); /*copia todos os bits para um unsigned int*/

		/*coloca a parte LSB dos bits*/
		OPERAND_STACK *newItem = malloc(sizeof(OPERAND_STACK));
		newItem->operand_type = TYPE_LONG;
		(newItem->type).u_int_number = iAux[0];
		newItem->prox = NULL;

		/*coloca a parte MSB dos bits*/
		OPERAND_STACK *newItem2 = malloc(sizeof(OPERAND_STACK));
		newItem2->operand_type = TYPE_LONG;
		(newItem2->type).u_int_number = iAux[1];
		newItem2->prox = NULL;

		PushOperandoPilha(&(*pilha), newItem);
		PushOperandoPilha(&(*pilha), newItem2);
	}

	return 0;
}

/*retira o tamanho da pilha cria um novo vetor e coloca a referencia na pilha */
int anewarray(OPERAND_STACK **pilha, int index_constPool, ConstantPoolItem *constPool)
{
	ConstantPoolItem *itemConstPool1 = searchConstPoolItem(constPool, index_constPool, constPool->count);

	if (itemConstPool1->tag == TAG_CONSTANT_Class) {
		CONSTANT_Class constAuxClass = (itemConstPool1->info).classInfo;
		ConstantPoolItem *itemConstPool2 = searchConstPoolItem(constPool, constAuxClass.name_index, constPool->count);

		if(itemConstPool2->tag == TAG_CONSTANT_Utf8)
		{
			CONSTANT_Utf8 *constAux = (itemConstPool2->info).utf8Info;
			/*printf("tipo do vetor: %s\n",constAux->conteudo);*/
			return 0;
		}
	}

	return 0;
}

/*int invokespecial(OPERAND_STACK **epilha, u1 indexbyte1, u1 indexbyte2, FRAME **fr){*/
int invokespecial(OPERAND_STACK **epilha, short int index_cp, FRAME **fr){
    ConstantPoolItem *cp;
    ConstantPoolItem *caux, *caux2, *caux3, *caux4, *caux5, *caux6;
    CLASS *classe_metodo;
    CONSTANT_Class classInfo;
    CONSTANT_Methodref cm;
    METHOD *metodo;
    CONSTANT_NameAndType cnt;
    CONSTANT_Utf8 *utfName,*utfDescriptor, *utfClass, *utf4;
    short int index;
    int args= 0, i =0;

	/*concatena o indexdyte */
    /*index =  (indexbyte1 << 8)|indexbyte2;index*/
    index =  index_cp;/*index*/

	/*referencia ao pool de constantes*/
    cp = (*fr)->ref_Const_Pool;

	/*referencia a classe do metodo corrente*/
	classe_metodo = (*fr)->this_class;

	/*procura o metodo na constante pool da classe do metodo corrente - constant_method_ref*/
    caux = searchConstPoolItem(cp, index, cp->count);

	/*verificar se o item encontrado eh do tipo method info*/
    if ( caux->tag != 10){
		printf("Item não é do tipo method info.\n");
        return 1;
    }
    cm = (caux->info).refInfo;

	/*procura o constante_class_info que tem as informacoes do caminho, descrito e o nome do meteodo*/
    caux2 = searchConstPoolItem(cp, cm.class_index, cp->count);
    if ( caux2->tag != 7){
		printf("Item não é do tipo class info.\n");
        return 1;
    }
    classInfo =(caux2->info).classInfo;

	/*procura a constante utf8 que contem os dados do metodo a ser chamado*/
    caux6 = searchConstPoolItem(cp, classInfo.name_index, cp->count);
    if ( caux6->tag != 1){
		printf("Item não é do tipo utf8 info.\n");
        return 1;
    }

	/*Caminho da Classe do metodo*/
    utfClass = caux6->info.utf8Info;

    /*args = contaArgumentos();*/

	/*procura uma constante do tipo name and type que contem o  nome e descritor do metodo*/
    caux3 = searchConstPoolItem(cp, cm.name_and_type_index, cp->count);
    if ( caux3->tag != 12){
		printf("Item não é do tipo name and type info.\n");
        return 1;
    }

    cnt = (caux3->info).nameandtypeInfo;

	/*procura a utf8 com o nome do metodo*/
    caux4 = searchConstPoolItem(cp, cnt.class_index, cp->count);
    if ( caux4->tag != 1){
		printf("Item não é do tipo utf8 info.\n");
        return 1;
    }

	/*procura a utf8 que tem o descritor do metodo*/
    caux5 = searchConstPoolItem(cp, cnt.descriptor_index, cp->count );
    if ( caux5->tag != 1){
		printf("Item não é do tipo utf8 info.\n");
        return 1;
    }
    utfName = caux4->info.utf8Info;
    utfDescriptor = caux5->info.utf8Info;

	/*printf("nome metodo: %s\n",utfName->conteudo);
	printf("descritor metodo: %s\n",utfDescriptor->conteudo);*/

    args =  contaArgumentos(utfDescriptor->conteudo);

    OPERAND_STACK *pilhaArgs,*opAux, *opAux2;

	ITEM_VECTOR *inicioVetor = NULL;
	/*printf("numero de argumentos: %d\n",args);*/
	for (i = 0; i < args; i++) {
		OPERAND_STACK *operandAux = PopOperandoPilha(&(*epilha));
		ITEM_VECTOR *itemAux = malloc(sizeof(ITEM_VECTOR));
		itemAux->index_item = args-(i+1);
		itemAux->type_union = operandAux->operand_type;
		char tipo = operandAux->operand_type;
		switch(tipo){
			case TYPE_INT :
				(itemAux->type).u_int_number = (operandAux->type).u_int_number;
				break;
			case TYPE_CHAR :
				(itemAux->type).int_number = (operandAux->type).int_number;
				break;
			case TYPE_SHORT :
				(itemAux->type).int_number = (operandAux->type).int_number;
				break;
			case TYPE_DOUBLE :
				(itemAux->type).u_int_number = (operandAux->type).u_int_number;
				break;
			case TYPE_LONG :
				(itemAux->type).u_int_number = (operandAux->type).u_int_number;
				break;
			case TYPE_STRING :
				(itemAux->type).string = malloc(strlen((operandAux->type).string));
				(itemAux->type).string = (operandAux->type).string;
				break;
			case TYPE_BOOLEAN :
				(itemAux->type).u_int_number = (operandAux->type).u_int_number;
				break;
			case TYPE_BYTE :
				(itemAux->type).u_int_number = (operandAux->type).u_int_number;
				break;
			case TYPE_NULL :
				(itemAux->type).object_ref = (operandAux->type).object_ref;
				break;
			case TYPE_INT_U :
				(itemAux->type).u_int_number = (operandAux->type).u_int_number;
				break;
			case TYPE_FLOAT :
				(itemAux->type).float_number = (operandAux->type).float_number;
				break;
			case TYPE_ARRAY :
				(itemAux->type).vector_ref = (operandAux->type).vector_ref;
				break;
			default:
				break;
			}

			itemAux->prox = NULL;
			insereItemVetor(&inicioVetor, itemAux);
	}
	if (*epilha == NULL) {
		printf("Erro! Pilha vazia.\n");
		return 1;
	}

    OPERAND_STACK *refObjetoMetodo = PopOperandoPilha(epilha);
	if (refObjetoMetodo == NULL) {
		printf("Objeto retorno vazio\n");
	}

	/*Objeto de referencia*/
	if (refObjetoMetodo->operand_type != TYPE_OBJ_REF) {
		printf("Item não é uma referência a um objeto. Tipo: %d\n",refObjetoMetodo->operand_type);
		return 1;
	}
    classe_metodo = refObjetoMetodo->type.object_ref;
	/*procura o metodo a ser executado dentro da classe referenciada*/
    metodo = searchMethod(classe_metodo->listaMetodos, utfName->conteudo, utfDescriptor->conteudo);
	/*printf("Metodo: \n\tacess flag: %d\n\tnameRef: %d\n\tdescriptor: %d\n", metodo->acessFlag, metodo->nameRef, metodo->descriptorRef);*/

    CODE *codigo = (metodo->attributes->type).code;
	if (codigo == NULL) {
		printf("Codigo retornou vazio.\n");
		return 1;
	}

    /*IDEALIZADOS!!!!!!!!!!!!!!*/
    FRAME *frame = malloc(sizeof(FRAME));
	cria_Frame(&frame,metodo, classe_metodo, classe_metodo->constPool);
	frame->local_vector->vector_ini = inicioVetor;
    PushFramePilha((&(*fr)), frame);
    traduz_codigo(codigo->code , codigo->code_length, &(frame->operand_stack), &(frame->local_vector->vector_ini),(refObjetoMetodo->type.object_ref)->constPool, &frame);
    /*executaCodigo(metodo,classe_metodo,rame);*/
}

int invokevirtual(OPERAND_STACK **epilha, int vIndex, FRAME **fr){
    ConstantPoolItem *cp;
    ConstantPoolItem *caux, *caux2, *caux3, *caux4, *caux5, *caux6;
    CLASS *classe_metodo;
    CONSTANT_Class classInfo;
    CONSTANT_Methodref cm;
    METHOD *metodo;
    CONSTANT_NameAndType cnt;
    CONSTANT_Utf8 *utfName,*utfDescriptor, *utfClass;
    char type, *string1, *string2, *string_to_append, *string_appended, *string_append;
    short int index;
    int args= 0, i =0;
    int result_strcmp;

	/*concatena o indexdyte */
    index = vIndex;/*index*/

	/*referencia ao pool de constantes*/
    cp = (*fr)->ref_Const_Pool;

	/*referencia a classe do metodo corrente*/
	classe_metodo = (*fr)->this_class;

	/*procura o metodo na constante pool da classe do metodo corrente - constant_method_ref*/
    caux = searchConstPoolItem(cp, index, cp->count);

	/*verificar se o item encontrado eh do tipo method info*/
    if ( caux->tag != 10){
		printf("Item não é do tipo method info.\n");
        return 1;
    }
    cm = (caux->info).refInfo;

	/*procura o constante_class_info que tem as informacoes do caminho, descrito e o nome do meteodo*/
    caux2 = searchConstPoolItem(cp, cm.class_index, cp->count);
    if ( caux2->tag != 7){
		printf("Item não é do tipo class info.\n");
        return 1;
    }
    classInfo =(caux2->info).classInfo;

	/*procura a constante utf8 que contem os dados do metodo a ser chamado*/
    caux6 = searchConstPoolItem(cp, classInfo.name_index, cp->count);
    if ( caux6->tag != 1){
		printf("Item não é do tipo utf8 info.\n");
        return 1;
    }

	/*Caminho da Classe do metodo*/
    utfClass = caux6->info.utf8Info;

    /*args = contaArgumentos();*/

	/*procura uma constante do tipo name and type que contem o  nome e descritor do metodo*/
    caux3 = searchConstPoolItem(cp, cm.name_and_type_index, cp->count);
    if ( caux3->tag != 12){
		printf("Item não é do tipo name and type info.\n");
        return 1;
    }

    cnt = (caux3->info).nameandtypeInfo;

	/*procura a utf8 com o nome do metodo*/
    caux4 = searchConstPoolItem(cp, cnt.class_index, cp->count);
    if ( caux4->tag != 1){
		printf("Item não é do tipo utf8 info.\n");
        return 1;
    }

	/*procura a utf8 que tem o descritor do metodo*/
    caux5 = searchConstPoolItem(cp, cnt.descriptor_index,cp->count );
    if ( caux5->tag != 1){
		printf("Item não é do tipo utf8 info.\n");
        return 1;
    }
    utfName = caux4->info.utf8Info;
    utfDescriptor = caux5->info.utf8Info;

	/*printf("nome metodo: %s\n",utfName->conteudo);
	printf("descritor metodo: %s\n",utfDescriptor->conteudo);*/

	OPERAND_STACK *newItem;
	/*printf("no invoke: %s\n",caux6->info.utf8Info->conteudo);*/
	if(strcmp(caux6->info.utf8Info->conteudo, "java/io/PrintStream") == 0 &&
	   (strcmp(utfName->conteudo, "println") == 0 ||
		strcmp(utfName->conteudo, "print") == 0)) {
		/* realiza o println */
        newItem = PopOperandoPilha(&(*epilha));
        type = newItem->operand_type;

        if(type == 'B') {
            printf("%d", (newItem->type).int_number);
        } else if(type == 'C') {
            printf("%c", (unsigned char)(newItem->type).int_number);
        } else if(type == 'D') {
            OPERAND_STACK *newItem1 = PopOperandoPilha(&(*epilha));
            double *pdouble;
            unsigned int *p;
            pdouble = malloc(sizeof(double));
            p = calloc(2, sizeof(unsigned int));
            p[0] = (newItem1->type).u_int_number;
            p[1] = (newItem->type).u_int_number;
            memcpy(pdouble, p, 8);
            printf("%f", *pdouble);
        } else if(type == 'F') {
            printf("%f",(newItem->type).float_number);
        } else if(type == 'I') {
            printf("%d", (newItem->type).int_number);
        } else if(type == 'L') {
            OPERAND_STACK *newItem1 = PopOperandoPilha(&(*epilha));
            long long int *plong;
            unsigned int *p;
            plong = malloc(sizeof(long long));
            p = calloc(2, sizeof(unsigned int));
            p[0] = (newItem1->type).u_int_number;
            p[1] = (newItem->type).u_int_number;
            memcpy(plong, p, 8);
            printf("%lld", *plong);
        } else if(type == 'J') {
            printf("Não implementado! Impressao de um objeto?! ");
        } else if(type == 'S') {
            printf("%d", (newItem->type).int_number);
        } else if(type == 'Z') {
            printf("%d", (newItem->type).int_number);
        } else if(type == 'T') {
            printf("%s", (char*)(newItem->type).string);
        }

		PopOperandoPilha(&(*epilha));

		if((strcmp(utfName->conteudo, "println") == 0)){
			printf("\n");
		}
	} else if(strcmp(caux6->info.utf8Info->conteudo, "java/lang/String") == 0 &&
			  strcmp(utfName->conteudo, "equals") == 0) {
		string1 = (char*)PopOperandoPilha(&((*epilha)))->type.vector_ref;
		string2 = (char*)PopOperandoPilha(&((*epilha)))->type.vector_ref;

		if(strcmp(string1, string2) == 0) {
			result_strcmp = 1;
			OPERAND_STACK *equals = malloc(sizeof(OPERAND_STACK));
			equals->operand_type = TYPE_INT;
			equals->type.int_number = result_strcmp;
			equals->prox = NULL;
			PushOperandoPilha(&(*epilha), equals);
			return 0;
		} else {
			result_strcmp = 0;
			OPERAND_STACK *equals = malloc(sizeof(OPERAND_STACK));
			equals->operand_type = TYPE_INT;
			equals->type.int_number = result_strcmp;
			equals->prox = NULL;
			PushOperandoPilha(&(*epilha), equals);
			return 0;
		}
	} else if((strcmp(caux6->info.utf8Info->conteudo, "java/lang/StringBuffer") == 0 || strcmp(caux6->info.utf8Info->conteudo, "java/lang/StringBuilder") == 0) &&
			  strcmp(utfName->conteudo, "append") == 0) {
		string_append = calloc(50, sizeof(char));
		newItem = PopOperandoPilha(&(*epilha));
		type = newItem->operand_type;
		string_to_append = (char*)PopOperandoPilha(&(*epilha))->type.vector_ref;
		if(type == 'B') {
            sprintf(string_append,"%d", (newItem->type).int_number);
        } else if(type == 'C') {
            sprintf(string_append,"%c", (unsigned char)(newItem->type).int_number);
        } else if(type == 'D') {
            OPERAND_STACK *newItem1 = PopOperandoPilha(&(*epilha));
            double *pdouble;
            unsigned int *p;
            pdouble = malloc(sizeof(double));
            p = calloc(2, sizeof(unsigned int));
            p[0] = (newItem1->type).u_int_number;
            p[1] = (newItem->type).u_int_number;
            memcpy(pdouble, p, 8);
            sprintf(string_append,"%f", *pdouble);
        } else if(type == 'F') {
            sprintf(string_append,"%f",(newItem->type).float_number);
        } else if(type == 'I') {
            sprintf(string_append,"%d", (newItem->type).int_number);
        } else if(type == 'L') {
            OPERAND_STACK *newItem1 = PopOperandoPilha(&(*epilha));
            long long *plong;
            unsigned int *p;
            plong = malloc(sizeof(long long));
            p = calloc(2, sizeof(unsigned int));
            p[0] = (newItem1->type).u_int_number;
            p[1] = (newItem->type).u_int_number;
            memcpy(plong, p, 8);
            sprintf(string_append,"%lld", *(plong));
        } else if(type == 'J') {
            printf("Não implementado! Impressao de um objeto?! ");
        } else if(type == 'S') {
            sprintf(string_append,"%d", (newItem->type).int_number);
        } else if(type == 'Z') {
            sprintf(string_append,"%d", (newItem->type).int_number);
        } else if(type == 'T') {
            sprintf(string_append,"%s", (char*)(newItem->type).string);
        }


		string_appended = calloc(strlen(string_append) + strlen(string_to_append) + 1, sizeof(char));
		*string_appended = '\0';
		strcat(string_appended, string_to_append);
		strcat(string_appended, string_append);

        OPERAND_STACK *append = malloc(sizeof(OPERAND_STACK));
        append->operand_type = TYPE_ARRAY;
        append->type.vector_ref = (unsigned int *)string_appended;
        append->prox = NULL;
        PushOperandoPilha(&(*epilha), append);
		return 0;

	} else if((strcmp(caux6->info.utf8Info->conteudo, "java/lang/StringBuffer") == 0 || strcmp(caux6->info.utf8Info->conteudo, "java/lang/StringBuilder") == 0) &&
			  strcmp(utfName->conteudo, "toString") == 0) {
		return 0;
	} else if(strcmp((caux6->info.utf8Info->conteudo), "java/lang/String") == 0 &&
				  strcmp(utfName->conteudo, "length") == 0) {
		int len;
		string1 = (char*)PopOperandoPilha(&(*epilha))->type.vector_ref;

		len = strlen(string1);

        OPERAND_STACK *length = malloc(sizeof(OPERAND_STACK));
        length->operand_type = TYPE_INT;
        length->type.int_number = len;
        length->prox = NULL;
        PushOperandoPilha(&(*epilha), length);

		return 0;
	} else if(strcmp(caux6->info.utf8Info->conteudo, "java/lang/String") == 0 &&
					  strcmp(utfName->conteudo, "compareTo") == 0) {
		int strcm;
		string1 = (char*)PopOperandoPilha(&(*epilha))->type.vector_ref;
		string2 = (char*)PopOperandoPilha(&(*epilha))->type.vector_ref;
		strcm = strcmp(string1, string2);

        OPERAND_STACK *compareTo = malloc(sizeof(OPERAND_STACK));
        compareTo->operand_type = TYPE_INT;
        compareTo->type.int_number = strcm;
        compareTo->prox = NULL;
        PushOperandoPilha(&(*epilha), compareTo);

		return 0;
	} else if(strcmp(caux6->info.utf8Info->conteudo, "java/lang/String") == 0 &&
						  strcmp(utfName->conteudo, "indexOf") == 0 ) {
		int strstr_value;
		char *strstr_char;
		string1 = (char*)PopOperandoPilha(&(*epilha))->type.vector_ref;
		string2 = (char*)PopOperandoPilha(&(*epilha))->type.vector_ref;

		strstr_char = strstr(string1, string2);
		strstr_value = strstr_char - string1;

        OPERAND_STACK *indexOf = malloc(sizeof(OPERAND_STACK));
        indexOf->operand_type = TYPE_INT;
        indexOf->type.int_number = strstr_value;
        indexOf->prox = NULL;
        PushOperandoPilha(&(*epilha), indexOf);

		return 0;
	} else if(strcmp(caux6->info.utf8Info->conteudo, "java/lang/String") == 0 &&
							  strcmp(utfName->conteudo, "startsWith") == 0 ) {
		char bool_return;
		char *strstr_char;
		string1 = (char*)PopOperandoPilha(&(*epilha))->type.vector_ref;
		string2 = (char*)PopOperandoPilha(&(*epilha))->type.vector_ref;

		strstr_char = strstr(string1, string2);
		bool_return = (strstr_char - string1 == 0) ? 1:0;

		OPERAND_STACK *startsWith = malloc(sizeof(OPERAND_STACK));
        startsWith->operand_type = TYPE_INT;
        startsWith->type.int_number = bool_return;
        startsWith->prox = NULL;
        PushOperandoPilha(&(*epilha), startsWith);

		return 0;

	} else 	{
            /* POG veio para k*/
     args =  contaArgumentos(utfDescriptor->conteudo);

    OPERAND_STACK *operandAux = NULL;

	ITEM_VECTOR *inicioVetor = NULL;

    /*printf("argumentos: %d\n",args);*/
	for (i = 0; i < args; i++) {
		operandAux = PopOperandoPilha(&(*epilha));
	}
	if (*epilha == NULL) {
		printf("Erro! Pilha vazia 1. \n");
		return 1;
	}

    OPERAND_STACK *refObjetoMetodo = PopOperandoPilha(epilha);
	if (refObjetoMetodo == NULL) {
		printf("Objeto retorno vazio\n");
	}

    /*Objeto de referencia*/
	if (refObjetoMetodo->operand_type != TYPE_OBJ_REF) {
		printf("Item não é uma referência a um objeto. Tipo: %d\n",refObjetoMetodo->operand_type);
		return 1;
	}
    classe_metodo = refObjetoMetodo->type.object_ref;
	/*procura o metodo a ser executado dentro da classe referenciada*/
    metodo = searchMethod(classe_metodo->listaMetodos, utfName->conteudo, utfDescriptor->conteudo);
	printf("Metodo: \n\tacess flag: %d\n\tnameRef: %d\n\tdescriptor: %d\n", metodo->acessFlag, metodo->nameRef, metodo->descriptorRef);

	/*recupera o codigo a ser executado*/
    CODE *codigo = (metodo->attributes->type).code;
	if (codigo == NULL) {
		printf("Codigo retornou vazio.\n");
		return 1;
	}
	/*------*/


        FRAME *frame = malloc(sizeof(FRAME));
        cria_Frame(&frame,metodo, classe_metodo, classe_metodo->constPool);
        frame->local_vector->vector_ini = inicioVetor;
        PushFramePilha((&(*fr)), frame);
        print_code(codigo->code , codigo->code_length);

	}
    return 0;
}
char achaTipo(char *descritor){
    int i=0;
    char c;
    while(descritor[i] != '>') i++;
    c = descritor[i-1];
    switch (c){
        case 'I':
            return TYPE_INT;
        case 'C':
            return TYPE_CHAR;
        case 'S':
            return TYPE_SHORT;
        case 'D':
            return TYPE_DOUBLE;
        case 'L':
            return 'J';
        case 'F':
            return TYPE_FLOAT;
        case '[':
            return TYPE_ARRAY;
        case 'T':
            return TYPE_STRING;
        case 'Z':
            return TYPE_BOOLEAN;
        case 'B':
            return TYPE_BYTE;
        case 'N':
            return TYPE_NULL;
        case 'U':
            return TYPE_INT_U;
        case 'J':
            return 'L';
    }
    return 'z';
}



int getstatic(OPERAND_STACK **pilha, int cp_index, FRAME **fr) {

	CONSTANT_Fieldref t_field_about;
	int i;
	FIELD *field_got, *faux;
	ConstantPoolItem *cp;
    ConstantPoolItem *caux, *caux2, *caux3, *caux4;
	CONSTANT_Class classInfo;
	CONSTANT_NameAndType cnt;
	CONSTANT_Utf8 *utfname, *utfdescritor, *utfclass;
	ClassFileList *p1;
    field_got = NULL;
    /*pegando o field*/
	cp =(*fr)->ref_Const_Pool;
	caux = searchConstPoolItem(cp, cp_index, cp->count);

	if(caux->tag != 9){
        printf("Nao e do tipo field_ref\n");
        return 1;
	}
	t_field_about = (caux->info).refInfo;
    /*pegando a classe*/
    caux2 = searchConstPoolItem(cp, t_field_about.class_index, cp->count);

	if(caux2->tag != 7){
        printf("Nao e do tipo class_info\n");
        return 1;
	}
	classInfo = (caux2->info).classInfo;

    /*pegando o nome da classe*/
    caux3 = searchConstPoolItem(cp, classInfo.name_index, cp->count);

	if(caux3->tag != 1){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfclass = (caux3->info).utf8Info;

    /*pegando o field*/
    caux = searchConstPoolItem(cp, t_field_about.name_and_type_index, cp->count);

	if(caux->tag != 12){
        printf("Nao e do tipo nameandtype_info\n");
        return 1;
	}
	cnt = (caux->info).nameandtypeInfo;
	/*pegando o nome*/
	caux2 = searchConstPoolItem(cp, cnt.class_index, cp->count);

	if(caux2->tag != 1){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfname = (caux2->info).utf8Info;

	/*pegando o descritor*/
	caux2 = searchConstPoolItem(cp, cnt.descriptor_index, cp->count);

	if(caux2->tag != 1){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfdescritor = (caux2->info).utf8Info;

	if(strcmp(utfclass->conteudo, "java/lang/System") == 0 &&
			strcmp(utfname->conteudo, "out") == 0 ){
		/* se for a printstream, adiciona uma referencia nula. sera usada depois */
		OPERAND_STACK *newItem = malloc (sizeof(OPERAND_STACK));
		newItem->operand_type =TYPE_ARRAY;
		(newItem->type).vector_ref = NULL;
		newItem->prox = NULL;
		PushOperandoPilha(&(*pilha), newItem);

	} else {
		p1 = ListaClasses;
		while(p1 != NULL) {
			if(strcmp(p1->classPath, utfclass->conteudo) == 0) {
			    /*procurar pelo field*/
				faux = p1->classFile->listaField;

				for(i=0; i < (p1->classFile->fieldsCount); i++){
				    caux4 = searchConstPoolItem(cp, faux->name_index, cp->count);
                    if(caux4->tag != 1){
                        printf("Nao e do tipo Utf8_info\n");
                        return 1;
                    }
                    if(strcmp((caux4->info).utf8Info->conteudo, utfname->conteudo)){
                        field_got =  faux;
                    }
                    faux = faux->proxField;
				}
                /*FIM*/
				if(field_got != NULL) {
                    char tipochar = achaTipo(utfdescritor->conteudo);
                    if(( TYPE_LONG == tipochar) || (TYPE_DOUBLE == tipochar)){
                        OPERAND_STACK *pstack = divide(&(field_got->data), tipochar);
                        PushOperandoPilha(&(*pilha), pstack->prox);
                        PushOperandoPilha(&(*pilha), pstack);
                    }
                    else{
                        OPERAND_STACK *pcoloca = coloca(&(field_got->data), tipochar);
                        PushOperandoPilha(&(*pilha), pcoloca);
                    }
					return 0;
				}
			}
			p1 = p1->prox;
		}

	}
	return 0;
}

int putfield(OPERAND_STACK **pilha, int cp_index, FRAME **fr){
    CONSTANT_Fieldref t_field_about;
	int i;
	FIELD *field_got, *faux;
	ConstantPoolItem *cp;
    ConstantPoolItem *caux, *caux2, *caux3, *caux4;
	CONSTANT_Class classInfo;
	CONSTANT_NameAndType cnt;
	CONSTANT_Utf8 *utfname, *utfdescritor, *utfclass;
	CLASS *classe;
    field_got = NULL;
    /*pegando o field*/
	cp =(*fr)->ref_Const_Pool;
	caux = searchConstPoolItem(cp, cp_index, cp->count);

	if(caux->tag != 9){
        printf("Nao e do tipo field_ref\n");
        return 1;
	}
	t_field_about = (caux->info).refInfo;
    /*pegando a classe*/
    caux2 = searchConstPoolItem(cp, t_field_about.class_index, cp->count);

	if(caux2->tag != 7){
        printf("Nao e do tipo class_info\n");
        return 1;
	}
	classInfo = (caux2->info).classInfo;

    /*pegando o nome da classe*/
    caux3 = searchConstPoolItem(cp, classInfo.name_index, cp->count);

	if(caux3->tag != 8){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfclass = (caux3->info).utf8Info;

    /*pegando o field*/
    caux = searchConstPoolItem(cp, t_field_about.name_and_type_index, cp->count);

	if(caux->tag != 12){
        printf("Nao e do tipo nameandtype_info\n");
        return 1;
	}
	cnt = (caux->info).nameandtypeInfo;
	/*pegando o nome*/
	caux2 = searchConstPoolItem(cp, cnt.class_index, cp->count);

	if(caux2->tag != 1){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfname = (caux2->info).utf8Info;

	/*pegando o descritor*/
	caux2 = searchConstPoolItem(cp, cnt.descriptor_index, cp->count);

	if(caux2->tag != 1){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfdescritor = (caux2->info).utf8Info;
    OPERAND_STACK *value2 = NULL;
    char tipochar = achaTipo(utfdescritor->conteudo);

    if(( TYPE_LONG == tipochar) || (TYPE_DOUBLE == tipochar)){
        value2 = PopOperandoPilha(&(*pilha));
    }
    OPERAND_STACK *value1 = PopOperandoPilha(&(*pilha));
    OPERAND_STACK *obj = PopOperandoPilha(&(*pilha));


    classe = (obj->type).object_ref;
    faux = classe->listaField;
    for(i=0; i < (classe->fieldsCount); i++){
        caux4 = searchConstPoolItem(cp, faux->name_index, cp->count);
            if(caux4->tag != 1){
                printf("Nao e do tipo Utf8_info\n");
                return 1;
            }
            if(strcmp((caux4->info).utf8Info->conteudo, utfname->conteudo)){
                field_got =  faux;
            }
        faux = faux->proxField;
    }
    if(field_got != NULL){
        char type = tipochar;
        if(type == 'B') {
            (field_got->data).byte_data = (value1->type).int_number;
        } else if(type == 'C') {
            (field_got->data).char_data = (value1->type).int_number;
        } else if(type == 'D') {
            double *pdouble;
            unsigned int *p;
            pdouble = malloc(sizeof(double));
            p = calloc(2, sizeof(unsigned int));
            p[0] = (value1->type).u_int_number;
            p[1] = (value2->type).u_int_number;
            memcpy(pdouble, p, 8);
            (field_got->data).double_data = *pdouble;
        } else if(type == 'F') {
            (field_got->data).float_data = (value1->type).float_number;
        } else if(type == 'I') {
            (field_got->data).int_data = (value1->type).int_number;
        } else if(type == 'L') {
            long long int *plong;
            unsigned int *p;
            plong = malloc(sizeof(long long));
            p = calloc(2, sizeof(unsigned int));
            p[0] = (value1->type).u_int_number;
            p[1] = (value2->type).u_int_number;
            memcpy(plong, p, 8);
            (field_got->data).double_data = *plong;
        } else if(type == 'J') {
            (field_got->data).ref_data = (value1->type).object_ref;
        } else if(type == 'S') {
            (field_got->data).short_data = (value1->type).int_number;
        } else if(type == 'Z') {
            (field_got->data).bool_data = (value1->type).int_number;
        } else if(type == 'R') {
            (field_got->data).ref_data = (value1->type).vector_ref;
        }
    }
    return 0;
}

int getfield (OPERAND_STACK **pilha, int cp_index, FRAME **fr){
    CONSTANT_Fieldref t_field_about;
	int i;
	FIELD *field_got, *faux;
	ConstantPoolItem *cp;
    ConstantPoolItem *caux, *caux2, *caux3, *caux4;
	CONSTANT_Class classInfo;
	CONSTANT_NameAndType cnt;
	CONSTANT_Utf8 *utfname, *utfdescritor, *utfclass;
	CLASS *classe;
    field_got = NULL;
    /*pegando o field*/
	cp =(*fr)->ref_Const_Pool;
	caux = searchConstPoolItem(cp, cp_index, cp->count);

	if(caux->tag != 9){
        printf("Nao e do tipo field_ref\n");
        return 1;
	}
	t_field_about = (caux->info).refInfo;
    /*pegando a classe*/
    caux2 = searchConstPoolItem(cp, t_field_about.class_index, cp->count);

	if(caux2->tag != 7){
        printf("Nao e do tipo class_info\n");
        return 1;
	}
	classInfo = (caux2->info).classInfo;

    /*pegando o nome da classe*/
    caux3 = searchConstPoolItem(cp, classInfo.name_index, cp->count);

	if(caux3->tag != 8){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfclass = (caux3->info).utf8Info;

    /*pegando o field*/
    caux = searchConstPoolItem(cp, t_field_about.name_and_type_index, cp->count);

	if(caux->tag != 12){
        printf("Nao e do tipo nameandtype_info\n");
        return 1;
	}
	cnt = (caux->info).nameandtypeInfo;
	/*pegando o nome*/
	caux2 = searchConstPoolItem(cp, cnt.class_index, cp->count);

	if(caux2->tag != 1){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfname = (caux2->info).utf8Info;

	/*pegando o descritor*/
	caux2 = searchConstPoolItem(cp, cnt.descriptor_index, cp->count);

	if(caux2->tag != 1){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfdescritor = (caux2->info).utf8Info;

    OPERAND_STACK *obj = PopOperandoPilha(&(*pilha));

    char tipochar = achaTipo(utfdescritor->conteudo);

    classe = (obj->type).object_ref;
    faux = classe->listaField;
    for(i=0; i < (classe->fieldsCount); i++){
        caux4 = searchConstPoolItem(cp, faux->name_index,cp->count);
            if(caux4->tag != 1){
                printf("Nao e do tipo Utf8_info\n");
                return 1;
            }
            if(strcmp((caux4->info).utf8Info->conteudo, utfname->conteudo)){
                field_got =  faux;
            }
        faux = faux->proxField;
    }
    if(field_got != NULL){
        char type = tipochar;

        if(( TYPE_LONG == type) || (TYPE_DOUBLE == type)){
            OPERAND_STACK *pstack = divide(&(field_got->data), type);
            PushOperandoPilha(&(*pilha), pstack->prox);
            PushOperandoPilha(&(*pilha), pstack);
        }
        else{
            OPERAND_STACK *pcoloca = coloca(&(field_got->data), type);
            PushOperandoPilha(&(*pilha), pcoloca);
        }
        return 0;
    }
    return 0;
}

int putstatic(OPERAND_STACK **pilha, int cp_index, FRAME **fr){
    CONSTANT_Fieldref t_field_about;
	int i;
	FIELD *field_got, *faux;
	ConstantPoolItem *cp;
    ConstantPoolItem *caux, *caux2, *caux3, *caux4;
	CONSTANT_Class classInfo;
	CONSTANT_NameAndType cnt;
	CONSTANT_Utf8 *utfname, *utfdescritor, *utfclass;

    field_got = NULL;

    ClassFileList *p1;
    /*pegando o field*/
	cp =(*fr)->ref_Const_Pool;
	caux = searchConstPoolItem(cp, cp_index,cp->count);

	if(caux->tag != 9){
        printf("Nao e do tipo field_ref\n");
        return 1;
	}
	t_field_about = (caux->info).refInfo;
    /*pegando a classe*/
    caux2 = searchConstPoolItem(cp, t_field_about.class_index, cp->count);

	if(caux2->tag != 7){
        printf("Nao e do tipo class_info\n");
        return 1;
	}
	classInfo = (caux2->info).classInfo;

    /*pegando o nome da classe*/
    caux3 = searchConstPoolItem(cp, classInfo.name_index,cp->count);

	if(caux3->tag != 8){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfclass = (caux3->info).utf8Info;

    /*pegando o field*/
    caux = searchConstPoolItem(cp, t_field_about.name_and_type_index,cp->count);

	if(caux->tag != 12){
        printf("Nao e do tipo nameandtype_info\n");
        return 1;
	}
	cnt = (caux->info).nameandtypeInfo;
	/*pegando o nome*/
	caux2 = searchConstPoolItem(cp, cnt.class_index,cp->count);

	if(caux2->tag != 1){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfname = (caux2->info).utf8Info;

	/*pegando o descritor*/
	caux2 = searchConstPoolItem(cp, cnt.descriptor_index, cp->count);

	if(caux2->tag != 1){
        printf("Nao e do tipo Utf8_info\n");
        return 1;
	}
	utfdescritor = (caux2->info).utf8Info;

    OPERAND_STACK *value2 = NULL;

    char tipochar = achaTipo(utfdescritor->conteudo);

    if(( TYPE_LONG == tipochar) || (TYPE_DOUBLE == tipochar)){
        value2 = PopOperandoPilha(&(*pilha));
    }
    OPERAND_STACK *value1 = PopOperandoPilha(&(*pilha));

    p1 = ListaClasses;
    while(p1 != NULL) {
        if(strcmp(p1->classPath, utfclass->conteudo) == 0) {
            /*procurar pelo field*/
            faux = p1->classFile->listaField;

            for(i=0; i < (p1->classFile->fieldsCount); i++){
                caux4 = searchConstPoolItem(cp, faux->name_index,cp->count);
                if(caux4->tag != 1){
                    printf("Nao e do tipo Utf8_info\n");
                    return 1;
                }
                if(strcmp((caux4->info).utf8Info->conteudo, utfname->conteudo)){
                    field_got =  faux;
                }
                faux = faux->proxField;
            }
        }
        p1 = p1->prox;
    }
    if(field_got != NULL) {
        char type = tipochar;
        if(type == 'B') {
            (field_got->data).byte_data = (value1->type).int_number;
        } else if(type == 'C') {
            (field_got->data).char_data = (value1->type).int_number;
        } else if(type == 'D') {
            double *pdouble;
            unsigned int *p;
            pdouble = malloc(sizeof(double));
            p = calloc(2, sizeof(unsigned int));
            p[0] = (value1->type).u_int_number;
            p[1] = (value2->type).u_int_number;
            memcpy(pdouble, p, 8);
            (field_got->data).double_data = *pdouble;
        } else if(type == 'F') {
            (field_got->data).float_data = (value1->type).float_number;
        } else if(type == 'I') {
            (field_got->data).int_data = (value1->type).int_number;
        } else if(type == 'L') {
            long long int *plong;
            unsigned int *p;
            plong = malloc(sizeof(long long));
            p = calloc(2, sizeof(unsigned int));
            p[0] = (value1->type).u_int_number;
            p[1] = (value2->type).u_int_number;
            memcpy(plong, p, 8);
            (field_got->data).double_data = *plong;
        } else if(type == 'J') {
            (field_got->data).ref_data = (value1->type).object_ref;
        } else if(type == 'S') {
            (field_got->data).short_data = (value1->type).int_number;
        } else if(type == 'Z') {
            (field_got->data).bool_data = (value1->type).int_number;
        } else if(type == 'R') {
            (field_got->data).ref_data = (value1->type).vector_ref;
        }
    }
    return 0;
}


