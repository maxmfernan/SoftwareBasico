#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "operacaoBits.h"
#include "constant_pool.h"
#include "class_loader.h"
#include "operacoesFrame.h"
#include "simulation.h"



int main(int argc, char *argv[]) {
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
    
    CLASS *classe;
    ConstantPoolItem *constPool;
    
    printf("Nome arquivo: %s\n",argv[1]);
    arquivo = fopen(argv[1],"rb");
    if(arquivo == NULL)
    {
        printf("Arquivo nao pode ser aberto.\n");
        getchar();
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
	
	ListaClasses = NULL; 
	
	
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
    
    minor = 0;
    result = fread(&minor, sizeof(short), 1, arquivo);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        return 1;
    }
    minor = inverteShortBits(minor);
    classe->minor = minor;
    
    major = 0;
    result = fread(&major, sizeof(short), 1, arquivo);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        return 1;
    }
    major = inverteShortBits(major);
    classe->major = major;
    
    constPoolCount = 0;
    result = fread(&constPoolCount, sizeof(short), 1, arquivo);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        return 1;
    }
    constPoolCount = inverteShortBits(constPoolCount);
    classe->constPoolCount = constPoolCount;
    printf("Constant Pool Count %d\n",classe->constPoolCount);
    
    constPool = NULL;
    readConstPool(arquivo, &classe, &constPool);
    constPool->count = constPoolCount;
    
    printf("Deseja ver a estrutura do .class?? S - sim, N- nao\n");
    char c = getchar();
    
    if(c == 'S'|| c == 's')
    {
         printf("Magic Number %#x\n",magicNumber);
         printf("Minor %d\n",classe->minor);
         printf("Major %d\n",classe->major);
         printfConstPoolItems(constPool); 
         }
    
    classe->constPool = constPool;
    
	fread(&acessFlag, sizeof(short), 1, arquivo);
	fread(&thisClass, sizeof(short), 1, arquivo);
	fread(&superClass, sizeof(short), 1, arquivo);
	classe->acessFlag = acessFlag = inverteShortBits(acessFlag);
	classe->thisClassRef = thisClass = inverteShortBits(thisClass);
	classe->superClassRef = superClass = inverteShortBits(superClass);

	
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

	
	classe->listaMetodos = NULL;
	classe->listaAtributos = NULL;
	classe->listaField = NULL;
	classe->listaInterface = NULL;

     if(c == 'S'|| c == 's')
    {
	printf("Acess Flag: %hu\n", classe->acessFlag);
	printf("This Class Ref: %hu\n", classe->thisClassRef);
	printf("Super class Ref: %hu\n", classe->superClassRef);
	printf("This Class Name: %s\n", classe->thisClass);
	printf("Super Class Name: %s\n", classe->superClass);
    }
    
    char classLoader;
    printf("\nDeseja ver a estrutura montada pelo class loader? S- sim, N - nao\n");
    getchar();
    scanf("%c", &classLoader);
	
/* --------------- INTERFACES -------------------*/
    if(classLoader == 'S')
        printf(" ----------------- Interfaces --------------------\n");
	fread(&(classe->interfaceCount), sizeof(short), 1, arquivo);
	classe->interfaceCount = inverteShortBits(classe->interfaceCount);
    if(classLoader == 'S')
	    printf("Nro interfaces: %hu\n\n", classe->interfaceCount);
	readInterfaces(&classe, arquivo,classLoader );
	
/* --------------- CAMPOS -------------------*/
    if(classLoader == 'S')
	    printf(" ----------------- CAMPOS --------------------\n");
	fread(&(classe->fieldsCount), sizeof(short), 1, arquivo);
	classe->fieldsCount = inverteShortBits(classe->fieldsCount);
     if(classLoader == 'S')
	    printf("Nro Campos: %hu\n\n", classe->fieldsCount);
	readFields(&classe, arquivo,constPool,classLoader );
	
/* --------------- METODOS -------------------*/
	if(classLoader == 'S')
       printf(" ----------------- METODOS --------------------\n");
	fread(&(classe->methodsCount), sizeof(short), 1, arquivo);
	classe->methodsCount = inverteShortBits(classe->methodsCount);
	if(classLoader == 'S')
        printf("Nro Metodos: %hu\n\n", classe->methodsCount);
    char *charAux = malloc(sizeof(METHOD));
	readMethods(&classe, arquivo, constPool, classLoader);
	
/* --------------- ATRIBUTOS -------------------*/
     if(classLoader == 'S')
	    printf(" ----------------- ATRIBUTOS --------------------\n");
	fread(&(classe->attributeCount), sizeof(short), 1, arquivo);
	classe->attributeCount = inverteShortBits(classe->attributeCount);
	if(classLoader == 'S')
	    printf("Attribute count: %hu\n\n", classe->attributeCount);
	readAttributes(&classe, arquivo,constPool, classLoader);
	
	char *descriptorMain = "([Ljava/lang/String;)V";
	METHOD *methodMain;
    methodMain = searchMethod(classe->listaMetodos, "main",descriptorMain);
	if( methodMain != NULL)
	{
		/*printf("\nNome do metodo: %s\n",methodMain->name);
		printf("Metodo descriptor: %s\n",methodMain->descriptor);*/
		int i = 1;
	}
	else {
		printf("ERRO: Metodo MAIN nao encontrado.\n");
	}
	
	insereClasse(classe, classe->thisClass);
	
	FRAME *pilhaFrames = NULL;
	FRAME *mainFrame = NULL;
	cria_Frame(&mainFrame, methodMain,classe,classe->constPool);
	getchar();
	/*printf("Executar o codigo do main.");*/
	executaMain(&mainFrame);
	/*printf("terminei\n");*/
	
	fclose(arquivo);
	getchar();
    return 0;
    
}
