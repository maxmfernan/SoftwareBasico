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
                //opcodes
                for(int i = 0; i < attributes[counter].info.Code_attribute.code_length; i++){
                    switch( attributes[counter].info.Code_attribute.code[i] ){
                        case op_nop: 
                        	printf("%s\n", opcodes_str_names[op_nop]);
                        	break;
                        case op_aconst_null: 
                        	printf("%s\n", opcodes_str_names[op_aconst_null]);
                        	break;
                        case op_iconst_m1: 
                        	printf("%s\n", opcodes_str_names[op_iconst_m1]);
                        	break;
                        case op_iconst_0: 
                        	printf("%s\n", opcodes_str_names[op_iconst_0]);
                        	break;
                        case op_iconst_1: 
                        	printf("%s\n", opcodes_str_names[op_iconst_1]);
                        	break;
                        case op_iconst_2: 
                        	printf("%s\n", opcodes_str_names[op_iconst_2]);
                        	break;
                        case op_iconst_3: 
                        	printf("%s\n", opcodes_str_names[op_iconst_3]);
                        	break;
                        case op_iconst_4: 
                        	printf("%s\n", opcodes_str_names[op_iconst_4]);
                        	break;
                        case op_iconst_5: 
                        	printf("%s\n", opcodes_str_names[op_iconst_5]);
                        	break;
                        case op_lconst_0: 
                        	printf("%s\n", opcodes_str_names[op_lconst_0]);
                        	break;
                        case op_lconst_1: 
                        	printf("%s\n", opcodes_str_names[op_lconst_1]);
                        	break;
                        case op_fconst_0: 
                        	printf("%s\n", opcodes_str_names[op_fconst_0]);
                        	break;
                        case op_fconst_1: 
                        	printf("%s\n", opcodes_str_names[op_fconst_1]);
                        	break;
                        case op_fconst_2: 
                        	printf("%s\n", opcodes_str_names[op_fconst_2]);
                        	break;
                        case op_dconst_0: 
                        	printf("%s\n", opcodes_str_names[op_dconst_0]);
                        	break;
                        case op_dconst_1: 
                        	printf("%s\n", opcodes_str_names[op_dconst_1]);
                        	break;
                        case op_bipush: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_bipush]);
                        	break;
                        case op_sipush: 
                            i+= 2;
                        	printf("%s\n", opcodes_str_names[op_sipush]);
                        	break;
                        case op_ldc: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_ldc]);
                        	break;
                        case op_ldc_w: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_ldc_w]);
                        	break;
                        case op_ldc2_w: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_ldc2_w]);
                        	break;
                        case op_iload: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_iload]);
                        	break;
                        case op_lload: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_lload]);
                        	break;
                        case op_fload: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_fload]);
                        	break;
                        case op_dload: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_dload]);
                        	break;
                        case op_aload: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_aload]);
                        	break;
                        case op_iload_0: 
                        	printf("%s\n", opcodes_str_names[op_iload_0]);
                        	break;
                        case op_iload_1: 
                        	printf("%s\n", opcodes_str_names[op_iload_1]);
                        	break;
                        case op_iload_2: 
                        	printf("%s\n", opcodes_str_names[op_iload_2]);
                        	break;
                        case op_iload_3: 
                        	printf("%s\n", opcodes_str_names[op_iload_3]);
                        	break;
                        case op_lload_0: 
                        	printf("%s\n", opcodes_str_names[op_lload_0]);
                        	break;
                        case op_lload_1: 
                        	printf("%s\n", opcodes_str_names[op_lload_1]);
                        	break;
                        case op_lload_2: 
                        	printf("%s\n", opcodes_str_names[op_lload_2]);
                        	break;
                        case op_lload_3: 
                        	printf("%s\n", opcodes_str_names[op_lload_3]);
                        	break;
                        case op_fload_0: 
                        	printf("%s\n", opcodes_str_names[op_fload_0]);
                        	break;
                        case op_fload_1: 
                        	printf("%s\n", opcodes_str_names[op_fload_1]);
                        	break;
                        case op_fload_2: 
                        	printf("%s\n", opcodes_str_names[op_fload_2]);
                        	break;
                        case op_fload_3: 
                        	printf("%s\n", opcodes_str_names[op_fload_3]);
                        	break;
                        case op_dload_0: 
                        	printf("%s\n", opcodes_str_names[op_dload_0]);
                        	break;
                        case op_dload_1: 
                        	printf("%s\n", opcodes_str_names[op_dload_1]);
                        	break;
                        case op_dload_2: 
                        	printf("%s\n", opcodes_str_names[op_dload_2]);
                        	break;
                        case op_dload_3: 
                        	printf("%s\n", opcodes_str_names[op_dload_3]);
                        	break;
                        case op_aload_0: 
                        	printf("%s\n", opcodes_str_names[op_aload_0]);
                        	break;
                        case op_aload_1: 
                        	printf("%s\n", opcodes_str_names[op_aload_1]);
                        	break;
                        case op_aload_2: 
                        	printf("%s\n", opcodes_str_names[op_aload_2]);
                        	break;
                        case op_aload_3: 
                        	printf("%s\n", opcodes_str_names[op_aload_3]);
                        	break;
                        case op_iaload: 
                        	printf("%s\n", opcodes_str_names[op_iaload]);
                        	break;
                        case op_laload: 
                        	printf("%s\n", opcodes_str_names[op_laload]);
                        	break;
                        case op_faload: 
                        	printf("%s\n", opcodes_str_names[op_faload]);
                        	break;
                        case op_daload: 
                        	printf("%s\n", opcodes_str_names[op_daload]);
                        	break;
                        case op_aaload: 
                        	printf("%s\n", opcodes_str_names[op_aaload]);
                        	break;
                        case op_baload: 
                        	printf("%s\n", opcodes_str_names[op_baload]);
                        	break;
                        case op_caload: 
                        	printf("%s\n", opcodes_str_names[op_caload]);
                        	break;
                        case op_saload: 
                        	printf("%s\n", opcodes_str_names[op_saload]);
                        	break;
                        case op_istore: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_istore]);
                        	break;
                        case op_lstore: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_lstore]);
                        	break;
                        case op_fstore: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_fstore]);
                        	break;
                        case op_dstore: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_dstore]);
                        	break;
                        case op_astore: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_astore]);
                        	break;
                        case op_istore_0: 
                        	printf("%s\n", opcodes_str_names[op_istore_0]);
                        	break;
                        case op_istore_1: 
                        	printf("%s\n", opcodes_str_names[op_istore_1]);
                        	break;
                        case op_istore_2: 
                        	printf("%s\n", opcodes_str_names[op_istore_2]);
                        	break;
                        case op_istore_3: 
                        	printf("%s\n", opcodes_str_names[op_istore_3]);
                        	break;
                        case op_lstore_0: 
                        	printf("%s\n", opcodes_str_names[op_lstore_0]);
                        	break;
                        case op_lstore_1: 
                        	printf("%s\n", opcodes_str_names[op_lstore_1]);
                        	break;
                        case op_lstore_2: 
                        	printf("%s\n", opcodes_str_names[op_lstore_2]);
                        	break;
                        case op_lstore_3: 
                        	printf("%s\n", opcodes_str_names[op_lstore_3]);
                        	break;
                        case op_fstore_0: 
                        	printf("%s\n", opcodes_str_names[op_fstore_0]);
                        	break;
                        case op_fstore_1: 
                        	printf("%s\n", opcodes_str_names[op_fstore_1]);
                        	break;
                        case op_fstore_2: 
                        	printf("%s\n", opcodes_str_names[op_fstore_2]);
                        	break;
                        case op_fstore_3: 
                        	printf("%s\n", opcodes_str_names[op_fstore_3]);
                        	break;
                        case op_dstore_0: 
                        	printf("%s\n", opcodes_str_names[op_dstore_0]);
                        	break;
                        case op_dstore_1: 
                        	printf("%s\n", opcodes_str_names[op_dstore_1]);
                        	break;
                        case op_dstore_2: 
                        	printf("%s\n", opcodes_str_names[op_dstore_2]);
                        	break;
                        case op_dstore_3: 
                        	printf("%s\n", opcodes_str_names[op_dstore_3]);
                        	break;
                        case op_astore_0: 
                        	printf("%s\n", opcodes_str_names[op_astore_0]);
                        	break;
                        case op_astore_1: 
                        	printf("%s\n", opcodes_str_names[op_astore_1]);
                        	break;
                        case op_astore_2: 
                        	printf("%s\n", opcodes_str_names[op_astore_2]);
                        	break;
                        case op_astore_3: 
                        	printf("%s\n", opcodes_str_names[op_astore_3]);
                        	break;
                        case op_iastore: 
                        	printf("%s\n", opcodes_str_names[op_iastore]);
                        	break;
                        case op_lastore: 
                        	printf("%s\n", opcodes_str_names[op_lastore]);
                        	break;
                        case op_fastore: 
                        	printf("%s\n", opcodes_str_names[op_fastore]);
                        	break;
                        case op_dastore: 
                        	printf("%s\n", opcodes_str_names[op_dastore]);
                        	break;
                        case op_aastore: 
                        	printf("%s\n", opcodes_str_names[op_aastore]);
                        	break;
                        case op_bastore: 
                        	printf("%s\n", opcodes_str_names[op_bastore]);
                        	break;
                        case op_castore: 
                        	printf("%s\n", opcodes_str_names[op_castore]);
                        	break;
                        case op_sastore: 
                        	printf("%s\n", opcodes_str_names[op_sastore]);
                        	break;
                        case op_pop: 
                        	printf("%s\n", opcodes_str_names[op_pop]);
                        	break;
                        case op_pop2: 
                        	printf("%s\n", opcodes_str_names[op_pop2]);
                        	break;
                        case op_dup: 
                        	printf("%s\n", opcodes_str_names[op_dup]);
                        	break;
                        case op_dup_x1: 
                        	printf("%s\n", opcodes_str_names[op_dup_x1]);
                        	break;
                        case op_dup_x2: 
                        	printf("%s\n", opcodes_str_names[op_dup_x2]);
                        	break;
                        case op_dup2: 
                        	printf("%s\n", opcodes_str_names[op_dup2]);
                        	break;
                        case op_dup2_x1: 
                        	printf("%s\n", opcodes_str_names[op_dup2_x1]);
                        	break;
                        case op_dup2_x2: 
                        	printf("%s\n", opcodes_str_names[op_dup2_x2]);
                        	break;
                        case op_swap: 
                        	printf("%s\n", opcodes_str_names[op_swap]);
                        	break;
                        case op_iadd: 
                        	printf("%s\n", opcodes_str_names[op_iadd]);
                        	break;
                        case op_ladd: 
                        	printf("%s\n", opcodes_str_names[op_ladd]);
                        	break;
                        case op_fadd: 
                        	printf("%s\n", opcodes_str_names[op_fadd]);
                        	break;
                        case op_dadd: 
                        	printf("%s\n", opcodes_str_names[op_dadd]);
                        	break;
                        case op_isub: 
                        	printf("%s\n", opcodes_str_names[op_isub]);
                        	break;
                        case op_lsub: 
                        	printf("%s\n", opcodes_str_names[op_lsub]);
                        	break;
                        case op_fsub: 
                        	printf("%s\n", opcodes_str_names[op_fsub]);
                        	break;
                        case op_dsub: 
                        	printf("%s\n", opcodes_str_names[op_dsub]);
                        	break;
                        case op_imul: 
                        	printf("%s\n", opcodes_str_names[op_imul]);
                        	break;
                        case op_lmul: 
                        	printf("%s\n", opcodes_str_names[op_lmul]);
                        	break;
                        case op_fmul: 
                        	printf("%s\n", opcodes_str_names[op_fmul]);
                        	break;
                        case op_dmul: 
                        	printf("%s\n", opcodes_str_names[op_dmul]);
                        	break;
                        case op_idiv: 
                        	printf("%s\n", opcodes_str_names[op_idiv]);
                        	break;
                        case op_ldiv: 
                        	printf("%s\n", opcodes_str_names[op_ldiv]);
                        	break;
                        case op_fdiv: 
                        	printf("%s\n", opcodes_str_names[op_fdiv]);
                        	break;
                        case op_ddiv: 
                        	printf("%s\n", opcodes_str_names[op_ddiv]);
                        	break;
                        case op_irem: 
                        	printf("%s\n", opcodes_str_names[op_irem]);
                        	break;
                        case op_lrem: 
                        	printf("%s\n", opcodes_str_names[op_lrem]);
                        	break;
                        case op_frem: 
                        	printf("%s\n", opcodes_str_names[op_frem]);
                        	break;
                        case op_drem: 
                        	printf("%s\n", opcodes_str_names[op_drem]);
                        	break;
                        case op_ineg: 
                        	printf("%s\n", opcodes_str_names[op_ineg]);
                        	break;
                        case op_lneg: 
                        	printf("%s\n", opcodes_str_names[op_lneg]);
                        	break;
                        case op_fneg: 
                        	printf("%s\n", opcodes_str_names[op_fneg]);
                        	break;
                        case op_dneg: 
                        	printf("%s\n", opcodes_str_names[op_dneg]);
                        	break;
                        case op_ishl: 
                        	printf("%s\n", opcodes_str_names[op_ishl]);
                        	break;
                        case op_lshl: 
                        	printf("%s\n", opcodes_str_names[op_lshl]);
                        	break;
                        case op_ishr: 
                        	printf("%s\n", opcodes_str_names[op_ishr]);
                        	break;
                        case op_lshr: 
                        	printf("%s\n", opcodes_str_names[op_lshr]);
                        	break;
                        case op_iushr: 
                        	printf("%s\n", opcodes_str_names[op_iushr]);
                        	break;
                        case op_lushr: 
                        	printf("%s\n", opcodes_str_names[op_lushr]);
                        	break;
                        case op_iand: 
                        	printf("%s\n", opcodes_str_names[op_iand]);
                        	break;
                        case op_land: 
                        	printf("%s\n", opcodes_str_names[op_land]);
                        	break;
                        case op_ior: 
                        	printf("%s\n", opcodes_str_names[op_ior]);
                        	break;
                        case op_lor: 
                        	printf("%s\n", opcodes_str_names[op_lor]);
                        	break;
                        case op_ixor: 
                        	printf("%s\n", opcodes_str_names[op_ixor]);
                        	break;
                        case op_lxor: 
                        	printf("%s\n", opcodes_str_names[op_lxor]);
                        	break;
                        case op_iinc: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_iinc]);
                        	break;
                        case op_i2l: 
                        	printf("%s\n", opcodes_str_names[op_i2l]);
                        	break;
                        case op_i2f: 
                        	printf("%s\n", opcodes_str_names[op_i2f]);
                        	break;
                        case op_i2d: 
                        	printf("%s\n", opcodes_str_names[op_i2d]);
                        	break;
                        case op_l2i: 
                        	printf("%s\n", opcodes_str_names[op_l2i]);
                        	break;
                        case op_l2f: 
                        	printf("%s\n", opcodes_str_names[op_l2f]);
                        	break;
                        case op_l2d: 
                        	printf("%s\n", opcodes_str_names[op_l2d]);
                        	break;
                        case op_f2i: 
                        	printf("%s\n", opcodes_str_names[op_f2i]);
                        	break;
                        case op_f2l: 
                        	printf("%s\n", opcodes_str_names[op_f2l]);
                        	break;
                        case op_f2d: 
                        	printf("%s\n", opcodes_str_names[op_f2d]);
                        	break;
                        case op_d2i: 
                        	printf("%s\n", opcodes_str_names[op_d2i]);
                        	break;
                        case op_d2l: 
                        	printf("%s\n", opcodes_str_names[op_d2l]);
                        	break;
                        case op_d2f: 
                        	printf("%s\n", opcodes_str_names[op_d2f]);
                        	break;
                        case op_i2b: 
                        	printf("%s\n", opcodes_str_names[op_i2b]);
                        	break;
                        case op_i2c: 
                        	printf("%s\n", opcodes_str_names[op_i2c]);
                        	break;
                        case op_i2s: 
                        	printf("%s\n", opcodes_str_names[op_i2s]);
                        	break;
                        case op_lcmp: 
                        	printf("%s\n", opcodes_str_names[op_lcmp]);
                        	break;
                        case op_fcmpl: 
                        	printf("%s\n", opcodes_str_names[op_fcmpl]);
                        	break;
                        case op_fcmpg: 
                        	printf("%s\n", opcodes_str_names[op_fcmpg]);
                        	break;
                        case op_dcmpl: 
                        	printf("%s\n", opcodes_str_names[op_dcmpl]);
                        	break;
                        case op_dcmpg: 
                        	printf("%s\n", opcodes_str_names[op_dcmpg]);
                        	break;
                        case op_ifeq: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_ifeq]);
                        	break;
                        case op_ifne: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_ifne]);
                        	break;
                        case op_iflt: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_iflt]);
                        	break;
                        case op_ifge: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_ifge]);
                        	break;
                        case op_ifgt: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_ifgt]);
                        	break;
                        case op_ifle: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_ifle]);
                        	break;
                        case op_if_icmpeq: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_if_icmpeq]);
                        	break;
                        case op_if_icmpne: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_if_icmpne]);
                        	break;
                        case op_if_icmplt: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_if_icmplt]);
                        	break;
                        case op_if_icmpge: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_if_icmpge]);
                        	break;
                        case op_if_icmpgt: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_if_icmpgt]);
                        	break;
                        case op_if_icmple: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_if_icmple]);
                        	break;
                        case op_if_acmpeq: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_if_acmpeq]);
                        	break;
                        case op_if_acmpne: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_if_acmpne]);
                        	break;
                        case op_goto: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_goto]);
                        	break;
                        case op_jsr: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_jsr]);
                        	break;
                        case op_ret: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_ret]);
                        	break;
                        case op_tableswitch: 
                        	printf("%s\n", opcodes_str_names[op_tableswitch]);
                        	break;
                        case op_lookupswitch: 
                        	printf("%s\n", opcodes_str_names[op_lookupswitch]);
                        	break;
                        case op_ireturn: 
                        	printf("%s\n", opcodes_str_names[op_ireturn]);
                        	break;
                        case op_lreturn: 
                        	printf("%s\n", opcodes_str_names[op_lreturn]);
                        	break;
                        case op_freturn: 
                        	printf("%s\n", opcodes_str_names[op_freturn]);
                        	break;
                        case op_dreturn: 
                        	printf("%s\n", opcodes_str_names[op_dreturn]);
                        	break;
                        case op_areturn: 
                        	printf("%s\n", opcodes_str_names[op_areturn]);
                        	break;
                        case op_return: 
                        	printf("%s\n", opcodes_str_names[op_return]);
                        	break;
                        case op_getstatic: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_getstatic]);
                        	break;
                        case op_putstatic: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_putstatic]);
                        	break;
                        case op_getfield: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_getfield]);
                        	break;
                        case op_putfield: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_putfield]);
                        	break;
                        case op_invokevirtual: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_invokevirtual]);
                        	break;
                        case op_invokespecial: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_invokespecial]);
                        	break;
                        case op_invokestatic: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_invokestatic]);
                        	break;
                        case op_invokeinterface: 
                            i+=4;
                        	printf("%s\n", opcodes_str_names[op_invokeinterface]);
                        	break;
                        case op_new: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_new]);
                        	break;
                        case op_newarray: 
                            i++;
                        	printf("%s\n", opcodes_str_names[op_newarray]);
                        	break;
                        case op_anewarray: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_anewarray]);
                        	break;
                        case op_arraylength: 
                        	printf("%s\n", opcodes_str_names[op_arraylength]);
                        	break;
                        case op_athrow: 
                        	printf("%s\n", opcodes_str_names[op_athrow]);
                        	break;
                        case op_checkcast: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_checkcast]);
                        	break;
                        case op_instanceof: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_instanceof]);
                        	break;
                        case op_monitorenter: 
                        	printf("%s\n", opcodes_str_names[op_monitorenter]);
                        	break;
                        case op_monitorexit: 
                        	printf("%s\n", opcodes_str_names[op_monitorexit]);
                        	break;
                        case op_wide: 
                        	printf("%s\n", opcodes_str_names[op_wide]);
                        	break;
                        case op_multianewarray: 
                            i+=3;
                        	printf("%s\n", opcodes_str_names[op_multianewarray]);
                        	break;
                        case op_ifnull: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_ifnull]);
                        	break;
                        case op_ifnonnull: 
                            i+=2;
                        	printf("%s\n", opcodes_str_names[op_ifnonnull]);
                        	break;
                        case op_goto_w: 
                            i+=4;
                        	printf("%s\n", opcodes_str_names[op_goto_w]);
                        	break;
                        case op_jsr_w: 
                            i+=4;
                        	printf("%s\n", opcodes_str_names[op_jsr_w]);
                        	break;
                        case op_breakpoint: 
                        	printf("%s\n", opcodes_str_names[op_breakpoint]);
                        	break;
                        default:
                            printf("opcode desconhecido\n");
                    }
                } 
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

