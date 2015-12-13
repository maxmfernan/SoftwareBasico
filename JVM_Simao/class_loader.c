#include "class_loader.h"

void readInterfaces(CLASS **classe, FILE *arquivo, char classLoader)
{
	int k;
	for(k=1; k <= (*classe)->interfaceCount; k++)
	{
		INTERFACE *interfaceAux;
        interfaceAux = malloc(sizeof(INTERFACE));
		if (interfaceAux == NULL) {
			printf("Malloc return null class 1\n");
			getchar();
			exit (EXIT_FAILURE);
		}
		interfaceAux->proxInterface = NULL;
		fread(&(interfaceAux->interface_index), sizeof(short), 1, arquivo);
		interfaceAux->interface_index = inverteShortBits(interfaceAux->interface_index);
        if(classLoader == 'S')
		    printf("Interface index: %hu\n", interfaceAux->interface_index);

		if((*classe)->listaInterface == NULL)
			(*classe)->listaInterface = interfaceAux;
		else
		{
			INTERFACE *intAux = (*classe)->listaInterface;
			while (intAux->proxInterface != NULL)
				intAux = intAux->proxInterface;

			intAux->proxInterface = interfaceAux;
		}

	}
	if(classLoader == 'S')
	    printf("\n\n");

}

void readGenericInfo(GENERIC_ATTRIBUTE **attributesIni, FILE *arquivo, ConstantPoolItem *iniPool, char **stringAux){
	GENERIC_ATTRIBUTE *attAux = *attributesIni;
	(*stringAux) = malloc((*attributesIni)->attribute_length);
	if ((*stringAux) == NULL) {
		printf("Malloc return null class 2\n");
		getchar();
		exit (EXIT_FAILURE);
	}
	fread((*stringAux), attAux->attribute_length, 1, arquivo);
	((*attributesIni)->type).info_generic = (*stringAux);
}

void readFields(CLASS **classe, FILE *arquivo,ConstantPoolItem *iniConstaPool,char  classLoader)
{
	u4 k;
	for(k=1; k <= ((*classe)->fieldsCount); k++)
	{
		FIELD *fieldAux;
        fieldAux = malloc(sizeof(FIELD));
		if (fieldAux == NULL) {
			printf("Malloc return null clss 3\n");
			getchar();
			exit (EXIT_FAILURE);
		}

		fieldAux->listaAtributos = NULL;
		fieldAux->proxField = NULL;

		fread(&(fieldAux->acess_flag), sizeof(short),1,arquivo);
		fieldAux->acess_flag = inverteShortBits(fieldAux->acess_flag);
		fread(&(fieldAux->name_index), sizeof(short),1,arquivo);
		fieldAux->name_index = inverteShortBits(fieldAux->name_index);
		fread(&(fieldAux->descriptor_index), sizeof(short),1,arquivo);
		fieldAux->descriptor_index = inverteShortBits(fieldAux->descriptor_index);
		fread(&(fieldAux->attributes_count), sizeof(short),1,arquivo);
		fieldAux->attributes_count = inverteShortBits(fieldAux->attributes_count);

        if(classLoader == 'S')
        {
		printf("Campo acess_flag: %d\n",fieldAux->acess_flag);
		printf("Campo name_index: %d\n",fieldAux->name_index);
		printf("Campo descriptor_index: %d\n",fieldAux->descriptor_index);
		printf("Campo attributes_count: %d\n",fieldAux->attributes_count);
        }

		int j;
		for(j=1; j <= fieldAux->attributes_count; j++)
		{
			GENERIC_ATTRIBUTE *attAux;
			char *stringAux;
            attAux = malloc(sizeof(GENERIC_ATTRIBUTE));
			if (attAux == NULL) {
				printf("Malloc return null class 4\n");
				getchar();
				exit (EXIT_FAILURE);
			}
			attAux->proxItem = NULL;
			
			u4 name_index;
			fread(&name_index, sizeof(short), 1, arquivo);
			name_index = inverteShortBits(name_index);
			
			u4 tamanho;
			fread(&tamanho, sizeof(int), 1, arquivo);
			tamanho = inverteIntBits(tamanho);
			attAux->name_index = name_index;
			attAux->attribute_length = tamanho;

			readGenericInfo(&attAux,arquivo, iniConstaPool, &stringAux);

			if(fieldAux->listaAtributos == NULL)
				fieldAux->listaAtributos = attAux;
			else
			{
				GENERIC_ATTRIBUTE *attAux2;
                attAux2 = fieldAux->listaAtributos;
				while(attAux2->proxItem != NULL)
					attAux2 = attAux2->proxItem;

				attAux2->proxItem = attAux;
			}
		}

		if((*classe)->listaField == NULL)
			(*classe)->listaField = fieldAux;
		else{
			FIELD *fAux = (*classe)->listaField;
			while (fAux->proxField != NULL)
				fAux = fAux->proxField;

			fAux->proxField = fieldAux;
		}
		/*printf("\n");*/
	}
    if(classLoader == 'S')
     	printf("\n\n");

}

CODE *readCode(GENERIC_ATTRIBUTE **attributesIni, FILE *arquivo, ConstantPoolItem *iniPool, char classLoader)
{
    if(classLoader == 'S')
	    printf("\tCODE:\n");
	CODE *attributeCode;
	attributeCode = malloc(sizeof(CODE));
	if (attributeCode == NULL) {
		printf("Malloc return null - CODE class5\n");
		getchar();
		exit (EXIT_FAILURE);
	}

	attributeCode->exceptionTable = NULL;
	attributeCode->listaAtributos = NULL;
	attributeCode->proxItem = NULL;
	attributeCode->code = NULL;

	fread(&(attributeCode->max_stack), sizeof(short), 1, arquivo);
	attributeCode->max_stack = inverteShortBits(attributeCode->max_stack);
	fread(&(attributeCode->max_locals), sizeof(short), 1, arquivo);
	attributeCode->max_locals = inverteShortBits(attributeCode->max_locals);

	fread(&(attributeCode->code_length), sizeof(int), 1, arquivo);
	attributeCode->code_length = inverteIntBits(attributeCode->code_length);

    char *stringCode;
	stringCode = malloc(attributeCode->code_length +1);
	if (stringCode == NULL) {
		printf("Malloc return null - string code class6\n");
		getchar();
		exit (EXIT_FAILURE);
	}

	fread(stringCode, attributeCode->code_length, 1, arquivo);
	stringCode[attributeCode->code_length] = '\0';
	attributeCode->code = stringCode;


	fread(&(attributeCode->exception_table_length), sizeof(short), 1, arquivo);
	attributeCode->exception_table_length = inverteShortBits(attributeCode->exception_table_length);

    if(classLoader == 'S'){
	printf("\tMax_stack: %hu\n",attributeCode->max_stack);
	printf("\tmax_locals: %hu\n",attributeCode->max_locals);
	printf("\tcode_length: %hu\n",attributeCode->code_length);
	printf("\texception table: %hu\n",attributeCode->exception_table_length);}

	int k;
	for(k = 1; k <= attributeCode->exception_table_length; k++)
	{
		EXCEPTION_TABLE_ITEM *attributeExTable = malloc(sizeof(EXCEPTION_TABLE_ITEM));
		if (attributeExTable == NULL) {
			printf("Malloc return null class 7\n");
			getchar();
			exit (EXIT_FAILURE);
		}

		fread(&(attributeExTable->start_pc), sizeof(short), 1, arquivo);
		attributeExTable->start_pc = inverteShortBits(attributeExTable->start_pc);
		fread(&(attributeExTable->end_pc), sizeof(short), 1, arquivo);
		attributeExTable->end_pc = inverteIntBits(attributeExTable->end_pc);
		fread(&(attributeExTable->handler_pc), sizeof(short), 1, arquivo);
		attributeExTable->handler_pc = inverteShortBits(attributeExTable->handler_pc);
		fread(&(attributeExTable->catch_type), sizeof(short), 1, arquivo);
		attributeExTable->catch_type = inverteIntBits(attributeExTable->catch_type);
        if(classLoader == 'S'){
		printf("\t\t\tstart_pc: %u\n",attributeExTable->start_pc);
		printf("\t\t\tend_pc: %u\n",attributeExTable->end_pc);
		printf("\t\t\thandler_pc: %u\n",attributeExTable->handler_pc);
		printf("\t\t\tcatch_pc: %u\n",attributeExTable->catch_type);}

	}

 	fread(&(attributeCode->attributes_count), sizeof(short), 1, arquivo);
	attributeCode->attributes_count = inverteShortBits(attributeCode->attributes_count);
	if(classLoader == 'S')
	    printf("\tCODE attribute count: %hu \n\n",attributeCode->attributes_count);

	attributeCode->listaAtributos = NULL;
	for(k = 1; k <= attributeCode->attributes_count; k++)
	{
		GENERIC_ATTRIBUTE *attribute;
        attribute = malloc(sizeof(GENERIC_ATTRIBUTE));
		if (attribute == NULL) {
			printf("Malloc return null class8\n");
			getchar();
			exit (EXIT_FAILURE);
		}
		attribute->proxItem = NULL;

		fread(&(attribute->name_index), sizeof(short), 1, arquivo);
		attribute->name_index = inverteShortBits(attribute->name_index);
		fread(&(attribute->attribute_length), sizeof(int), 1, arquivo);
		attribute->attribute_length = inverteIntBits(attribute->attribute_length);

        char *stringAux;
        readGenericInfo(&attribute, arquivo, iniPool, &stringAux);
        (attribute->type).info_generic = stringAux;

		if(attributeCode->listaAtributos == NULL)
		{
			attributeCode->listaAtributos = attribute;

		}
		else{
			GENERIC_ATTRIBUTE *aux = attributeCode->listaAtributos;
			if(aux == NULL)
				aux = attribute;
			else{
				while (aux->proxItem != NULL)
					aux = aux->proxItem;

				aux->proxItem = attribute;
			}
		}
	}

	return attributeCode;
	/*printf("\n\n");*/
}

void readAttributesMethod(GENERIC_ATTRIBUTE **attributesIni, FILE *arquivo, ConstantPoolItem *iniPool, char classLoader)
{
	GENERIC_ATTRIBUTE *attribute;

	attribute = malloc(sizeof(GENERIC_ATTRIBUTE));
	if (attribute == NULL) {
		printf("Malloc return null class9\n");
		getchar();
		exit (EXIT_FAILURE);
	}
	attribute->proxItem = NULL;

	fread(&(attribute->name_index), sizeof(short), 1, arquivo);
	attribute->name_index = inverteShortBits(attribute->name_index);
	fread(&(attribute->attribute_length), sizeof(int), 1, arquivo);
	attribute->attribute_length = inverteIntBits(attribute->attribute_length);

	attribute->name_info = searchPoolTableUTF8(attribute->name_index, iniPool);

	if(!strcmp(attribute->name_info, "Code"))
		(attribute->type).code = readCode(&attribute,arquivo, iniPool, classLoader);
	else{
         char *stringAux;
		readGenericInfo(&attribute,arquivo, iniPool, &stringAux);
		(attribute->type).info_generic = stringAux;
	}

	if(*attributesIni == NULL)
		*attributesIni = attribute;
	else{
		GENERIC_ATTRIBUTE *aux;
        aux = *attributesIni;
		while(aux->proxItem != NULL)
			aux = aux->proxItem;

		aux->proxItem = attribute;
	}
}

void readMethods(CLASS **classe, FILE *arquivo, ConstantPoolItem *iniPool, char classLoader)
{
	u4 k;
	for(k=1; k <= (*classe)->methodsCount; k++)
	{
		METHOD *method;
		method = malloc(sizeof(METHOD));
		if (method == NULL) {
			printf("Malloc return null class 10\n");
			getchar();
			exit (EXIT_FAILURE);
		}
		
		method->proxMethod = NULL;
		method->attributes = NULL;
		
		fread(&(method->acessFlag), sizeof(short),1,arquivo);
		method->acessFlag = inverteShortBits(method->acessFlag);
		fread(&(method->nameRef), sizeof(short),1,arquivo);
		method->nameRef = inverteShortBits(method->nameRef);
		

		ConstantPoolItem *itemAux;
        itemAux = searchConstPoolItem(iniPool,method->nameRef, (*classe)->constPoolCount);
        char *stringAux;
		if (itemAux->tag == 1 && itemAux != NULL) {
			CONSTANT_Utf8 *constAux = (itemAux->info).utf8Info;
			stringAux = malloc(sizeof(constAux->conteudo));
			stringAux = constAux->conteudo;
			method->name = stringAux;
		}

		fread(&(method->descriptorRef), sizeof(short),1,arquivo);
		method->descriptorRef = inverteShortBits(method->descriptorRef);

		itemAux = searchConstPoolItem(iniPool,method->descriptorRef, (*classe)->constPoolCount);
		char *stringAux2;
		if (itemAux->tag == 1 && itemAux != NULL) {
			CONSTANT_Utf8 *constAux = (itemAux->info).utf8Info;
			stringAux2 = malloc(sizeof(constAux->conteudo));
			stringAux2 = constAux->conteudo;
			method->descriptor = stringAux2;
		}

		fread(&(method->attributeMethodCount), sizeof(short),1,arquivo);
		method->attributeMethodCount = inverteShortBits(method->attributeMethodCount);
		method->attributes = NULL;
	    if(classLoader == 'S'){
		printf("Metodo acess flag: %hu\n", method->acessFlag);
		printf("Metodo name ref: %hu\n", method->nameRef);
		printf("Metodo descriptor ref: %hu\n", method->descriptorRef);
		printf("Metodo attribute count: %hu\n", method->attributeMethodCount);
		printf("\n");}

		u4 k;
		for(k=1; k <= method->attributeMethodCount; k++)
			readAttributesMethod(&(method->attributes), arquivo, iniPool, classLoader);

		if((*classe)->listaMetodos == NULL)
			(*classe)->listaMetodos = method;
		else{
			METHOD *mAux = (*classe)->listaMetodos;
			while (mAux->proxMethod != NULL)
				mAux = mAux->proxMethod;

			mAux->proxMethod = method;
		}
	}
}

void readAttributes(CLASS **classe, FILE *arquivo, ConstantPoolItem *iniPool, char classLoader)
{
	u4 k;
	(*classe)->listaAtributos = NULL;
	for(k = 1; k <= (*classe)->attributeCount; k++)
	{
		ATTRIBUTE_CLASS *attributeAux;
		attributeAux = malloc(sizeof(ATTRIBUTE_CLASS));

		if (attributeAux == NULL) {
			printf("Malloc return null class 11\n");
			getchar();
			exit (EXIT_FAILURE);
		}

		attributeAux->proxAttribute = NULL;

		fread(&(attributeAux->name_index), sizeof(short), 1, arquivo);
		attributeAux->name_index = inverteShortBits(attributeAux->name_index);
		fread(&(attributeAux->attribute_length), sizeof(int), 1, arquivo);
		attributeAux->attribute_length = inverteIntBits(attributeAux->attribute_length);
        if(classLoader == 'S'){
		printf("Attribute_name_index: %hu\n", attributeAux->name_index);
		printf("attribute_length: %hu\n", attributeAux->attribute_length);}

		size_t size = sizeof(char)*attributeAux->attribute_length;
		char *stringAtt;
		stringAtt = malloc(size);
		if (stringAtt == NULL) {
			printf("Malloc return null class 12\n");
			getchar();
			exit (EXIT_FAILURE);
		}

		fread(stringAtt, size, 1, arquivo);
		attributeAux->info = stringAtt;
		/*printf("attributeAux info: %s\n\n",attributeAux->info);*/

		if((*classe)->listaAtributos == NULL)
		{
			(*classe)->listaAtributos = attributeAux;
		}
		else{
			ATTRIBUTE_CLASS *attAux;
            attAux = (*classe)->listaAtributos;
			if(attAux == NULL)
				attAux = attributeAux;
			else{
				while (attAux->proxAttribute != NULL)
					attAux = attAux->proxAttribute;

				attAux->proxAttribute = attributeAux;
			}
		}
	}
	if(classLoader == 'S')
	    printf("\n\n");
}
