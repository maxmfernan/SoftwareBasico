#include "constant_pool.h"

void printUtf8(CONSTANT_Utf8 *itemInfo) {
	printf("Tag: 1 - constante tipo Utf8\n");
	printf("Tamanho: %d\n",itemInfo->tamanho);
	printf("Conteudo: %s\n", itemInfo->conteudo);
}

void printInteger(CONSTANT_Integer itemInfo) {
	printf("Tag: 3 - constante tipo Integer\n");
	printf("Valor: %d\n",itemInfo.valor);
}

void printFloat(CONSTANT_Float itemInfo) {
	printf("Tag: 4 - constante tipo Float\n");
	printf("Valor: %f\n",itemInfo.valor);
}

void printLong(CONSTANT_Long itemInfo) {
	printf("Tag: 5 - constante tipo Long\n");
	printf("Valor: %lld\n",itemInfo.valor);
}

void printDouble(CONSTANT_Double itemInfo) {
	printf("Tag: 6 - constante tipo Double\n");
	printf("Valor: %f\n",itemInfo.valor);
}

void printClass(CONSTANT_Class itemInfo) {
	printf("Tag: 7 - constante tipo Class\n");
	printf("Name Index: %hu\n",itemInfo.name_index);
}

void printString(CONSTANT_String itemInfo) {
	printf("Tag: 8 - constante tipo String\n");
	printf("String Index: %hu\n",itemInfo.string_index);
}

void printRef(CONST_Ref itemInfo, int tag) {
	if(tag == 9)
		printf("Tag: 9 - constante tipo Field Reference\n");
	if(tag == 10)
		printf("Tag: 10 - constante tipo Method Reference\n");
	if(tag == 11)
		printf("Tag: 10 - constante tipo Interface andMethod Reference\n");

	printf("Class Index: %hu\n",itemInfo.class_index);
	printf("Name and Type Index: %hu\n",itemInfo.name_and_type_index);
}

void printNameAndType(CONSTANT_NameAndType itemInfo) {
	printf("Tag: 12 - constante tipo Name and Type \n");
	printf("Class Index: %hu\n",itemInfo.class_index);
	printf("Descriptor Index: %hu\n",itemInfo.descriptor_index);
}

void printfConstPoolItems(ConstantPoolItem *constPool)
{
	ConstantPoolItem *itemAux;
    itemAux = constPool;
	int constCount = 0;

	while(itemAux != NULL)
	{
		constCount++;
		printf("Item %d\n",constCount);
		unsigned int tag = 0;
		tag = (int)itemAux->tag;
		printf("TAG: %d\n",tag);
		switch(tag){
		case 1 :
		{
			printUtf8(itemAux->info.utf8Info);
			break;
		}
		case 3 :
		{
			printInteger(itemAux->info.integerInfo);
			break;
		}
		case 4 :
		{
			printFloat(itemAux->info.floatInfo);
			break;
		}
		case 5 :
		{
			printLong(itemAux->info.longInfo);
			break;
		}
		case 6 :
		{
			printDouble(itemAux->info.doubleInfo);
			break;
		}
		case 7 :
		{
			printClass(itemAux->info.classInfo);
			break;
		}
		case 8 :
		{
			printString(itemAux->info.stringInfo);
			break;
		}
		case 9 :
		{
			printRef(itemAux->info.refInfo,9);
			break;
		}
		case 10 :
		{
			printRef(itemAux->info.refInfo,10);
			break;
		}
		case 11 :
		{
			printRef(itemAux->info.refInfo,11);
			break;
		}
		case 12 :
		{
			printNameAndType(itemAux->info.nameandtypeInfo);
			break;
		}
		default:
			{
			break;
			}
		}
		printf("\n");
		itemAux = itemAux->proxItem;
	}

}

void readConst_Utf8(FILE *arq, CONSTANT_Utf8 **constAux, char **stringAux)
{
	fread(&((*constAux)->tamanho), sizeof(short), 1, arq);
	(*constAux)->tamanho = inverteShortBits((*constAux)->tamanho);
	
	u4 size = sizeof(char)*((*constAux)->tamanho);
	
	(*stringAux) = malloc(size + 1);
	if ((*stringAux) == NULL) {
		printf("Malloc return null\n");
		getchar();
		exit (EXIT_FAILURE);
	}
	fread((*stringAux), size, 1, arq);
	(*constAux)->conteudo = (*stringAux);
}

void readConst_Integer(FILE *arq, CONSTANT_Integer *constAux)
{
     u4 result;
     result = fread(&(constAux->valor), sizeof(int), 1, arq);
     if(result != 1)
     {
         printf("Leitura com erro.\n");
         getchar();
         exit (EXIT_FAILURE);

     }
     
     constAux->valor = inverteIntBits(constAux->valor);
}

void readConst_Float(FILE *arq, CONSTANT_Float *constAux)
{
     u4 result;
     u4 valorAux;
     result = fread(&valorAux, sizeof(u4), 1, arq);
     if(result != 1)
     {
         printf("Leitura com erro.\n");
         getchar();
         exit (EXIT_FAILURE);
     }
     
     valorAux = inverteIntBits(valorAux);
     float fAux;
     memcpy(&fAux, &valorAux,4);
     constAux->valor = fAux;
}

void readConst_Long(FILE *arq, CONSTANT_Long *constAux)
{
     u4 result;
     result = fread(&(constAux->valor), sizeof(u8), 1, arq);
     if(result != 1)
     {
         printf("Leitura com erro.\n");
         getchar();
         exit (EXIT_FAILURE);
     }
     constAux->valor = inverteLongBits(constAux->valor);
}

void readConst_Double(FILE *arq, CONSTANT_Double *constAux)
{
     u4 result;
     u8 valorAux;
     result = fread(&valorAux, sizeof(u8), 1, arq);
     if(result != 1)
     {
         printf("Leitura com erro.\n");
         getchar();
         exit (EXIT_FAILURE);
     }
     
     valorAux = inverteLongBits(valorAux);
     double dAux;
     memcpy(&dAux,&valorAux,8); 
     constAux->valor = dAux;
}

void readConst_Class(FILE *arq, CONSTANT_Class *constAux)
{
     u4 result;
     result = fread(&(constAux->name_index), sizeof(short), 1, arq);
     if(result != 1)
     {
         printf("Leitura com erro.\n");
         getchar();
         exit (EXIT_FAILURE);
     }
     
	constAux->name_index = inverteShortBits(constAux->name_index);
}

void readConst_String(FILE *arq, CONSTANT_String *constAux)
{
    u4 result;
	result = fread(&(constAux->string_index), sizeof(short), 1, arq);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        getchar();
        exit (EXIT_FAILURE);
    }
	constAux->string_index = inverteShortBits(constAux->string_index);
}

void readConst_Ref(FILE *arq, CONST_Ref *constAux)
{
     u4 result;
	result = fread(&(constAux->class_index), sizeof(short), 1, arq);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        getchar();
        exit (EXIT_FAILURE);
    }
	constAux->class_index = inverteShortBits(constAux->class_index);
	
	
	result = fread(&(constAux->name_and_type_index), sizeof(short), 1, arq);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        getchar();
        exit (EXIT_FAILURE);
    }
	constAux->name_and_type_index = inverteShortBits(constAux->name_and_type_index);

}

void readConst_NameAndType(FILE *arq, CONSTANT_NameAndType  *constAux)
{
     u4 result;
	result = fread(&(constAux->class_index), sizeof(short), 1, arq);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        getchar();
        exit (EXIT_FAILURE);
    }
	constAux->class_index = inverteShortBits(constAux->class_index);
	
	
	result = fread(&(constAux->descriptor_index), sizeof(short), 1, arq);
    if(result != 1)
    {
        printf("Leitura com erro.\n");
        getchar();
        exit (EXIT_FAILURE);
    }
	constAux->descriptor_index = inverteShortBits(constAux->descriptor_index);
}


void readConst_Empty()
{
	printf("Entrada reservada para o sistema. \n");
}


void valorNaoExiste()
{
	printf("Valor de tab não existe.\n");
}

void readConstPool(FILE *arquivo, CLASS **classe, ConstantPoolItem **inicioConstPool ){

    u4 constPoolCount = (*classe)->constPoolCount;

	u4 i;
	u1 tag = 0;
	for(i = 1; i <= constPoolCount - 1; i++)
	{
        CONSTANT_Utf8 *constAux_Utf8;
        CONSTANT_Integer constAux_Integer;
        CONSTANT_Float constAux_Float;
        CONSTANT_Long constAux_Long;
        CONSTANT_Double constAux_Doule;
        CONSTANT_Class constAux_Class;
        CONSTANT_String constAux_String;
        CONSTANT_Fieldref constAux_FiledRef;
        CONSTANT_Methodref constAux_MethodRef;
        CONSTANT_InterfaceMethodref constAux_InterRef;
        CONSTANT_NameAndType constAux_NameAndType;
        ConstantPoolItem *novoItem;
        ConstantPoolItem *novoItem2;
        u4 sizeAux;
        char *stringAux;
        
		tag = 0;
		fread(&tag, sizeof(char), 1, arquivo);
		switch(tag){
		case 0 :
			{
			readConst_Empty();
			break;
			}
		case 1:
			{
            sizeAux = sizeof(CONSTANT_Utf8);
            constAux_Utf8 = malloc(sizeAux);
            if(constAux_Utf8 == NULL)
            {
                printf("Malloc retornou NULL.");
                getchar();
                exit (EXIT_FAILURE);
            }
            readConst_Utf8(arquivo, &constAux_Utf8, &stringAux);
            stringAux[constAux_Utf8->tamanho] = '\0';
            novoItem = malloc(sizeof(ConstantPoolItem));
            novoItem->count = constPoolCount;
			novoItem->index_item = i;
			novoItem->tag = 1;
			novoItem->info.utf8Info = constAux_Utf8;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			break;
			}
		case 3:
			{
            readConst_Integer(arquivo, &constAux_Integer);
            novoItem = malloc(sizeof(ConstantPoolItem));
			novoItem->count = constPoolCount;
            novoItem->index_item = i;
			novoItem->tag = 3;
			novoItem->info.integerInfo = constAux_Integer;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			break;
			}
		case 4:
			{
			readConst_Float(arquivo, &constAux_Float);
			novoItem = malloc(sizeof(ConstantPoolItem));
			novoItem->count = constPoolCount;
			novoItem->index_item = i;
			novoItem->tag = 4;
			novoItem->info.floatInfo = constAux_Float;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			break;
			}
		case 5:
			{
			readConst_Long(arquivo, &constAux_Long);
			novoItem = malloc(sizeof(ConstantPoolItem));
			novoItem->count = constPoolCount;
			novoItem->index_item = i;
			novoItem->tag = 5;
			novoItem->info.longInfo = constAux_Long;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			i = i + 1;
			novoItem2 = malloc(sizeof(ConstantPoolItem));
			novoItem2->count = constPoolCount;
			novoItem2->index_item = i;
			novoItem2->tag = 5;
			novoItem2->info.longInfo = constAux_Long;
			novoItem2->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem2);
			break;
			}
		case 6:
			{
			readConst_Double(arquivo, &constAux_Doule);
			novoItem = malloc(sizeof(ConstantPoolItem));
			novoItem->count = constPoolCount;
			novoItem->index_item = i;
			novoItem->tag = 6;
			novoItem->info.doubleInfo = constAux_Doule;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			i = i+1;
			novoItem2 = malloc(sizeof(ConstantPoolItem));
			novoItem2->count = constPoolCount;
			novoItem2->index_item = i;
			novoItem2->tag = 6;
			novoItem2->info.doubleInfo = constAux_Doule;
			novoItem2->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem2);
			break;
			}
		case 7:
			{
			readConst_Class(arquivo, &constAux_Class);
			novoItem = malloc(sizeof(ConstantPoolItem));
			novoItem->count = constPoolCount;
			novoItem->index_item = i;
			novoItem->tag = 7;
			novoItem->info.classInfo = constAux_Class;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			break;
			}
		case 8 :
			{
			readConst_String(arquivo, &constAux_String);
			novoItem = malloc(sizeof(ConstantPoolItem));
			novoItem->count = constPoolCount;
			novoItem->index_item = i;
			novoItem->tag = 8;
			novoItem->info.stringInfo = constAux_String;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			break;
			}
		case 9:
			{
			readConst_Ref(arquivo, &constAux_FiledRef);
			novoItem = malloc(sizeof(ConstantPoolItem));
			novoItem->count = constPoolCount;
			novoItem->index_item = i;
			novoItem->tag = 9;
			novoItem->info.refInfo = constAux_FiledRef;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			break;
			}
		case 10:
			{
			readConst_Ref(arquivo, &constAux_MethodRef);
			novoItem = malloc(sizeof(ConstantPoolItem));
			novoItem->count = constPoolCount;
			novoItem->index_item = i;
			novoItem->tag = 10;
			novoItem->info.refInfo = constAux_MethodRef;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			break;
			}
		case 11:
			{
			readConst_Ref(arquivo, &constAux_InterRef);
			novoItem = malloc(sizeof(ConstantPoolItem));
			novoItem->count = constPoolCount;
			novoItem->index_item = i;
			novoItem->tag = 11;
			novoItem->info.refInfo = constAux_InterRef;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			break;
			}
		case 12:
			{
			readConst_NameAndType(arquivo, &constAux_NameAndType);
			novoItem = malloc(sizeof(ConstantPoolItem));
			novoItem->count = constPoolCount;
			novoItem->index_item = i;
			novoItem->tag = 12;
			novoItem->info.nameandtypeInfo = constAux_NameAndType;
			novoItem->proxItem = NULL;
			adicionaItemConstPool(inicioConstPool, novoItem);
			break;
			}
		default:
			{
				valorNaoExiste();
				break;
			}
		}
	}
}

ConstantPoolItem *searchConstPoolItem(ConstantPoolItem *constPool, u4 index_item, u4 constPoolCount)
{
	ConstantPoolItem *itemAux;
    itemAux = constPool;
	if (itemAux == NULL) {
		return NULL;
	}

	u4 limit;
    limit = constPoolCount - 2;
	u4 k = 0;

	for(k=1;k <= limit; k++)
	{
		if (itemAux == NULL) {
			break;
		}

		if(index_item == k)
		{
			break;
		}
		itemAux = itemAux->proxItem;
	}

	return itemAux;

}

char *searchPoolTableUTF8(u2 name_index, ConstantPoolItem *iniConstaPool){
	ConstantPoolItem *poolAux = iniConstaPool;
	int k;
	for(k = 2; k <= name_index; k++)
		poolAux = poolAux->proxItem;

	CONSTANT_Utf8 *aux = (poolAux->info).utf8Info;
	return aux->conteudo;
}

METHOD *searchMethod(METHOD *listMethods, char* methodName, char*descriptor){

	METHOD *methodAux = listMethods;
	while (methodAux != NULL) {
		char *charAux = methodAux->name;
		if (!strcmp(methodName,charAux)) {
			char *charAux2 = methodAux->descriptor;
			if (!strcmp(descriptor,charAux2)) {
				return	methodAux;
			}
		}
		methodAux = methodAux->proxMethod;
	}
	return NULL;
}
