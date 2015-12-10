#include "LoadClass_core.h"
#include "LoadClass_ui.h"
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constant Pool
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Função par imprimir o conteúdo da constante
void printContent (cp_info pool) {
	switch (pool.tag) {
		case 1: // Utf8
			printf("\t%s", pool.info.CONSTANT_Utf8_info.bytes);
			break;
		case 3: // Integer
		case 4: // Float
			printf("\t%"PRId32, pool.info.CONSTANT_IntegerFloat_info.bytes);
			break;
		case 5: // Long
		case 6: // Double
			printf("\tHigh: 0x%04"PRIx32" / Low: 0x%04"PRIx32, \
			pool.info.CONSTANT_LongDouble_info.high_bytes, pool.info.\
			CONSTANT_LongDouble_info.low_bytes);
			break;
		case 7: // Class
			printf("\t#%"PRId16, pool.info.CONSTANT_Class_info.name_index);
			break;
		case 8: // String
            printf("\t#%"PRId16, pool.info.CONSTANT_String_info.string_index);
            break;
        case 9: // Fieldref
		case 10: // Methodref
		case 11: // Interfaceref
			printf("#%"PRId16", #%"PRId16, pool.info.\
			CONSTANT_FieldMethodIMethod_info.class_index, pool.info\
			.CONSTANT_FieldMethodIMethod_info.name_and_type_index);
			break;
		case 12: // Name and type
			printf("#%"PRId16", #%"PRId16, pool.info.CONSTANT_NameAndType_info.\
			name_index, pool.info.CONSTANT_NameAndType_info.\
			descriptor_index);
			break;
		default: 
			printf("Erro de consistência identificado na Pool de constantes!\n");
			break;
    }
}

// Função para imprimir a tabela da pool de constantes
//Retirei o segundo argumento u2 poolLength
void printConstantPoolTable (u2 poolElementsNum,  cp_info pool[]) {
	u2 counter = 0;
	
	printf("*****cp_info*****\n");
    printf("------------------------------------------------\n");
	//printf("Number of bytes: %"PRId16"\n", poolLength);
	printf("Number of elements: %"PRId16"\n", poolElementsNum - 1);
	printf("Index |\tConstant Type\t|\tContent\n");
	while (counter < poolElementsNum - 1) {
        if (pool[counter].tag) {
            printf("#%"PRId16"\t", counter+1);
            printf("%s\t\t", searchConstantType(pool[counter].tag));
            printContent(pool[counter]);
            printf("\n");
        }
		counter++;
	}
    printf("------------------------------------------------\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fields
////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
* @brief imprime os fields do arquivo .class. Assume que o .class está correto
*
* @param pool_array contém dos os elementos presentes na pool de constantes
* @param fields_array contém todos os fields do arquivo .class
* @param fieldn a quantidade de fields, i.e, o número de elementos do vetor acima
*/
void printField(cp_info* pool_array, field_info* fields_array, unsigned int fieldn){
    printf("\n*****Fields*****\n");
    printf("------------------------------------------------\n");
	
    u2 acc_flag = 0;
	//u2 flags_count = 0;
	u2 index;
	u2 str_len;
	char* str;
	u2 count = 0;
	u4 att_len = 0;
	u1 tag = 0;
	u4 high = 0;
	u4 low = 0;
	//Imprime a quantidade de fields
	printf("\nQuantidades de fields: %d", fieldn);
	
	for(int i = 0; i < fieldn; i++){
		printf("\n#%d", i + 1);
		//access flags
		acc_flag = fields_array[i].access_flag;
		if( acc_flag & ACC_PUBLIC){
			printf("\nAccess flag: %s", "Public");	
		}	
		if( acc_flag & ACC_PRIVATE){
			printf("\nAccess flag: %s", "PRIVATE");	
		}
		if( acc_flag & ACC_PROTECTED){
			printf("\nAccess flag: %s", "Protect");	
		}
		if( acc_flag & ACC_STATIC){
			printf("\nAccess flag: %s", "Static");	
		}
		if( acc_flag & ACC_FINAL){
			printf("\nAccess flag: %s", "Final");	
		}
		if( acc_flag & ACC_VOLATILE){
			printf("\nAccess flag: %s", "Volatile");	
		}
		if( acc_flag & ACC_TRANSIENT){
			printf("\nAccess flag: %s", "Transient");	
		}

		//field name
		index = fields_array[i].name_index;
		str_len = pool_array[index - 1].info.CONSTANT_Utf8_info.length;
		str = malloc( (str_len + 1)*sizeof(char) );		
		str[str_len] = '\0';
		for(int j = 0; j < str_len; j++){
			str[j] = pool_array[index - 1].info.CONSTANT_Utf8_info.bytes[j];
		}
		printf("\nField name: %s", str);

		//field descriptor
		index = fields_array[i].descriptor_index;
		str_len = pool_array[index - 1].info.CONSTANT_Utf8_info.length;
		str = malloc( (str_len + 1)*sizeof(char) );		
		str[str_len] = '\0';
		for(int j = 0; j < str_len; j++){
			str[j] = pool_array[index - 1].info.CONSTANT_Utf8_info.bytes[j];
		}
		printf("\nField descriptor: %s", str);

		//attribute count
		count = fields_array[i].attributes_count;
		//tabela de atributos
		for(int j = 0; j < count; j++){
			index =	fields_array[i].attributes[j].attribute_name_index;
			//nome do atributo
			str_len = pool_array[index - 1].info.CONSTANT_Utf8_info.length;
			str = malloc( (str_len + 1)*sizeof(char) );		
			str[str_len] = '\0';
			for(int j = 0; j < str_len; j++){
				str[j] = pool_array[index - 1].info.CONSTANT_Utf8_info.bytes[j];
			}
			printf("\nAttribute name: %s", str);
			
			//tamanho do atributo
			att_len = fields_array[i].attributes[j].attribute_length;
			printf("\nAttribute length: %d", att_len);
			
			//ConstantValue ou outro?
			if( !strcmp(str, CONSTANTVALUE_STR) ){
				index = fields_array[i].attributes[j].info.ConstantValue_attribute.constantvalue_index;
				tag = pool_array[index - 1].tag;
				switch( tag ){
					case CONSTANT_INTEGER:
						high = pool_array[index - 1].info.CONSTANT_IntegerFloat_info.bytes;
						printf("\nValor inteiro: %d", high);
					case CONSTANT_FLOAT:
						high = pool_array[index - 1].info.CONSTANT_IntegerFloat_info.bytes;
						printf("\nValor inteiro: %f", high);
					case CONSTANT_LONG:
					case CONSTANT_DOUBLE:
						high = pool_array[index - 1].info.CONSTANT_LongDouble_info.high_bytes;
						low = pool_array[index - 1].info.CONSTANT_LongDouble_info.low_bytes;
						printf("\nVc sabia que ia esquecer, pq deixou pra depois?");
				}
			}
		}//for para percorrer os atributos de um field	
	}//for para percorrer o fields_array
	printf("\n\n");	
	return;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//Methods
////////////////////////////////////////////////////////////////////////////////////////////////////////

// Imprime os Metodos
void print_Methods(ClassFile *classFileVar, cp_info *pool) {
    
     printf("\n*****Methods*****\n\n");
    
    for (int i = 0; i < classFileVar->methods_count; i++) {
        char methodFlags[150] = "";
        printf("------------------------------------------------\n");
        printf("[%d] %s\n",i,pool[classFileVar->methods[i].name_index -1].info.CONSTANT_Utf8_info.bytes);
        printf("\tName:\t\t cp_info #%d\t <%s>\n",classFileVar->methods[i].name_index,pool[classFileVar->methods[i].name_index -1].info.CONSTANT_Utf8_info.bytes);
        
        
        if(classFileVar->methods[i].access_flags & ACC_PUBLIC) {
            //printf("public ");
            //strcat(methodFlags,"ACC_PUBLIC");
            strcat(methodFlags,"public");
        }
        if(classFileVar->methods[i].access_flags & ACC_PRIVATE) {
            //printf("private ");
            //if(methodFlags != "")
            if (!strcmp(methodFlags,"") == 0)
                strcat(methodFlags," ");
            //strcat(methodFlags,"ACC_PRIVATE");
            strcat(methodFlags,"private");
        }
        if(classFileVar->methods[i].access_flags & ACC_PROTECTED) {
            //printf("protected ");
            //if(methodFlags != "")
            if (!strcmp(methodFlags,"") == 0)
                strcat(methodFlags," ");
            //strcat(methodFlags,"ACC_PROTECTED");
            strcat(methodFlags,"protected");
        }
        if(classFileVar->methods[i].access_flags & ACC_STATIC) {
            //printf("static ");
            //if(methodFlags != "")
            if (!strcmp(methodFlags,"") == 0)
                strcat(methodFlags," ");
            //strcat(methodFlags,"ACC_STATIC");
            strcat(methodFlags,"static");
        }
        if(classFileVar->methods[i].access_flags & ACC_FINAL) {
            //printf("final ");
            //if(methodFlags != "")
            if (!strcmp(methodFlags,"") == 0)
                strcat(methodFlags," ");
            //strcat(methodFlags,"ACC_FINAL");
            strcat(methodFlags,"final");
        }
        if(classFileVar->methods[i].access_flags & ACC_SYNCHRONIZED) {
            //printf("synchronized ");
            //if(methodFlags != "")
            if (!strcmp(methodFlags,"") == 0)
                strcat(methodFlags," ");
            //strcat(methodFlags,"ACC_SYNCHRONIZED");
            strcat(methodFlags,"synchronized");
        }
        if(classFileVar->methods[i].access_flags & ACC_NATIVE) {
            //printf("native ");
            //if(methodFlags != "")
            if (!strcmp(methodFlags,"") == 0)
                strcat(methodFlags," ");
            //strcat(methodFlags,"ACC_NATIVE");
            strcat(methodFlags,"native");
        }
        if(classFileVar->methods[i].access_flags & ACC_ABSTRACT) {
            //printf("abstract ");
            //if(methodFlags != "")
            if (!strcmp(methodFlags,"") == 0)
                strcat(methodFlags," ");
            //strcat(methodFlags,"ACC_ABSTRACT");
            strcat(methodFlags,"abstract");
        }
        if(classFileVar->methods[i].access_flags & ACC_STRICT) {
            //printf("strict ");
            //if(methodFlags != "")
            if (!strcmp(methodFlags,"") == 0)
                strcat(methodFlags," ");
            //strcat(methodFlags,"ACC_STRICT");
            strcat(methodFlags,"strict");
        }
        /* TODO: fazer parse do descriptor para achar retorno e parametros
         B byte
         C char
         D double
         F float
         I int
         J long
         L<classname>; reference
         S short
         Z boolean
         [ reference
         */
        
        printf("\tDescriptor:\t cp_info #%d\t <%s>\n",classFileVar->methods[i].descriptor_index,pool[classFileVar->methods[i].descriptor_index -1].info.CONSTANT_Utf8_info.bytes);  //TODO: colocar funcao para recuperar valor da constant_pool
        printf("\tAccess flags:\t 0x%.4x\t\t [%s]\n",classFileVar->methods[i].access_flags,methodFlags);
        
        //printf("%d\n",classFileVar->methods[i].attribute[0].attribute_name_index);
        //getchar();
        //printf("%d\n",classFileVar->methods[i].attribute[0].info.Code_attribute.attribute[0].attribute_name_index);
        //getchar();
        print_attributes(classFileVar->methods[i].attribute, classFileVar->methods[i].attributes_count, pool);
        printf("------------------------------------------------\n");
    }
    printf("\n\n");
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//Atributos
////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_attributes (attribute_info *attributes, u2 attr_count, cp_info *pool) {
    u2 counter = 0;
    
    printf("\n*****Attributes*****\n\n");
    
    while (counter < attr_count) {
        switch (attributes[counter].tag) {
            case 0:
                printf("------------------------------------------------\n");
                printf("[%d] ConstantValue\n", counter);
                printf("\tAttribute name index: cp_info #%d\n",attributes[counter].attribute_name_index);
                printf("\tAttribute length: %d\n",attributes[counter].attribute_length);

                break;
            case 1:
                printf("------------------------------------------------\n");
                printf("[%d] Code\n", counter);
                printf("\tAttribute name index: cp_info #%d\n",attributes[counter].attribute_name_index);
                printf("\tAttribute length: %d\n",attributes[counter].attribute_length);
                printf("Info:\n");
                printf("\tMaximum stack depth:\t %d\n",attributes[counter].info.Code_attribute.max_stack);
                printf("\tMaximum local variable:\t %d\n",attributes[counter].info.Code_attribute.max_locals);
                printf("\tCode length:\t %d\n",attributes[counter].info.Code_attribute.code_length);
                print_attributes(attributes[counter].info.Code_attribute.attribute, attributes[counter].info.Code_attribute.attribute_count, pool);

                break;
            case 2:
                printf("------------------------------------------------\n");
                printf("[%d] Exceptions\n", counter);
                printf("\tAttribute name index: cp_info #%d\n",attributes[counter].attribute_name_index);
                printf("\tAttribute length: %d\n",attributes[counter].attribute_length);

                break;
            case 3:
                printf("------------------------------------------------\n");
                printf("[%d] InnerClasses\n", counter);
                printf("\tAttribute name index: cp_info #%d\n",attributes[counter].attribute_name_index);
                printf("\tAttribute length: %d\n",attributes[counter].attribute_length);

                break;
            case 4:
                printf("------------------------------------------------\n");
                printf("[%d] Synthetic\n", counter);
                printf("\tAttribute name index: cp_info #%d\n",attributes[counter].attribute_name_index);
                printf("\tAttribute length: %d\n",attributes[counter].attribute_length);
                break;
            case 5:
                printf("------------------------------------------------\n");
                printf("[%d] SourceFile\n",counter);
                printf("\tAttribute name index:\t cp_info #%d\n",attributes[counter].attribute_name_index);
                printf("\tAttribute length:\t %d\n",attributes[counter].attribute_length);
                printf("Info:\n");
                printf("\tSource File name index:\t cp_info #%d\t <%s>\n",attributes[counter].info.SourceFile_attribute.sourcefile_index, pool[attributes[counter].info.SourceFile_attribute.sourcefile_index -1].info.CONSTANT_Utf8_info.bytes);
                printf("------------------------------------------------\n");
                break;
            case 6:
                printf("------------------------------------------------\n");
                printf("[%d] LineNumberTable\n", counter);
                printf("\tAttribute name index: cp_info #%d\n",attributes[counter].attribute_name_index);
                printf("\tAttribute length: %d\n",attributes[counter].attribute_length);

                break;
            case 7:
                printf("------------------------------------------------\n");
                printf("[%d] LocalVariableTable\n", counter);
                printf("\tAttribute name index: cp_info #%d\n",attributes[counter].attribute_name_index);
                printf("\tAttribute length: %d\n",attributes[counter].attribute_length);

                break;
            case 8:
                printf("------------------------------------------------\n");
                printf("[%d] Deprecated\n", counter);
                printf("\tAttribute name index: cp_info #%d\n",attributes[counter].attribute_name_index);
                printf("\tAttribute length: %d\n",attributes[counter].attribute_length);

                
                break;
        }
        printf("\n\n");
        ++counter;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//Interface
////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_interface (u2 interface[], u2 inter_length, cp_info pool[]) {
	printf("\n\n*****Interface*****");
	printf("\nInterfaces Number: %d\n", inter_length);
	for (int i = 0; i < inter_length; i++) {
		printf("Ref.: #%d  -->  ", interface[i]);
		printContent(pool[interface[i]-1]);
		
		printf("\t//");
		printContent(pool[pool[interface[i]-1].info.CONSTANT_Class_info.name_index-1]);
		printf("\n\n");
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//ClassFile
////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_ClassFile(ClassFile* class_file_ptr){
    printf("\n\nMagic: %.8x\n\n", class_file_ptr->magic);
	printf("Minor Version: %.4x\n", class_file_ptr->minor_version);
	printf("Major Version: %.4x\n\n", class_file_ptr->major_version);
    
    printConstantPoolTable(class_file_ptr->constant_pool_count, class_file_ptr->constant_pool);

    print_interface(class_file_ptr->interfaces, class_file_ptr->interfaces_count, class_file_ptr->constant_pool);

    printField(class_file_ptr->constant_pool, class_file_ptr->fields, class_file_ptr->fields_count);

    print_Methods(class_file_ptr, class_file_ptr->constant_pool);

    print_attributes(class_file_ptr->attributes, class_file_ptr->attributes_count, class_file_ptr->constant_pool);

    
}

