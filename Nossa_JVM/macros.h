/**
 *       @file  macros.h
 *      @brief  coleção de definições
 *
 * Detailed description starts here.
 *
 *     @author  Maxwell M. Fernandes (mmf), maxmfernan@gmail.com
 *
 *   @internal
 *     Created  07/11/2015
 *    Revision  $Id: doxygen.templates,v 1.3 2010/07/06 09:20:12 mehner Exp $
 *    Compiler  gcc/g++
 *     Company  none
 *   Copyright  Copyright (c) 2015, Maxwell M. Fernandes
 *
 * This source code is released for free distribution under the terms of the
 * GNU General Public License as published by the Free Software Foundation.
 * =====================================================================================
 */

#ifndef HEADER_MACROS
#define HEADER_MACROS
#include <stdint.h>

/** Definição dos tipo com formato u#, onde # é um número */
typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef int32_t i4;
typedef float f4;

#define getu2(p) (u2)((p)[0]<< 8 & 0x0000FF00 |(p)[1])
#define getu4(p) (u4)( (u4)((p)[0])<<24 & 0xFF000000 | (u4)((p)[1])<<16 & 0x00FF0000 | (u4)((p)[2])<<8 & 0x0000FF00| (u4)((p)[3]) & 0x000000FF)

//getf4 depents on geti4 : carefull when changing...
#define geti4(p) (i4)( (u4)((p)[0])<<24 | (u4)((p)[1])<<16 | (u4)((p)[2])<<8 | (u4)((p)[3]) )
#define geti2(p) (i2)(((p)[0]<<8)|(p)[1])

f4 getf4(char *p);


/** Definição valores máximos */
#define CLSHEAP_MAX 50
#define OBJHEAP_MAX 50
#define STKFRAME_MAX 50

/** Definição dos nomes dos atributos */
#define CONSTANTVALUE_STR "ConstantValue"
#define SYNTHETIC_STR "Synthetic"
#define DEPRECATED_STR "Deprecates"

/** Definição das versões suportadas */
#define SUPPORTED_VERSION12 46 


/** Definição de flags de acesso da estrutura .class */
#define ACC_PUBLIC 0x0001
#define ACC_FINAL 0x0010
#define ACC_SUPER 0x0020
#define ACC_INTERFACE 0x0200
#define ACC_ABSTRACT 0x0400
/** Definição de flags de cacesso da estrutura field */
#define ACC_PRIVATE 0x0002
#define ACC_PROTECTED 0x0004
#define ACC_STATIC 0x0008
#define ACC_VOLATILE 0x0040
#define ACC_TRANSIENT 0x0080
/** Definição de flags de acesso da estrutura method */
#define ACC_SYNCHRONIZED 0x0020
#define ACC_NATIVE 0x0100
#define ACC_STRICT 0x0800
/** Definição de flags de acesso da estrutura inner class */


/** Definição das tags para os elementos na constant poll */
#define CONSTANT_CLASS 7
#define CONSTANT_FIELDREF 9
#define CONSTANT_METHODREF 10
#define CONSTANT_INTERFACEMETHODREF 11
#define CONSTANT_STRING 8
#define CONSTANT_INTEGER 3
#define CONSTANT_FLOAT 4
#define CONSTANT_LONG 5
#define CONSTANT_DOUBLE 6
#define CONSTANT_NAMEANDTYPE 12
#define CONSTANT_UTF8 1
/** Definição das tags para os tipo de atributos. Não esixte na especificação */
#define SOURCEFILE 1
#define CONSTANTVALUE 2
#define CODE 3
#define EXCEPTIONS 4
#define INNERCLASSES 5
#define SYNTHETIC 6
#define LINENUMBERTABLE 7
#define LOCALVARIABLETABLE 8
#define DEPRECATED 9
/** Definição dos OPCODES */
#define nop  0
#define aconst_null 1 
#define iconst_m1  2
#define iconst_0  3
#define iconst_1  4
#define iconst_2  5
#define iconst_3  6
#define iconst_4  7
#define iconst_5  8
#define lconst_0  9
#define lconst_1  10
#define fconst_0  11
#define fconst_1  12
#define fconst_2  13
#define dconst_0  14
#define dconst_1  15
#define bipush  16
#define sipush  17
#define ldc  18
#define ldc_w  19
#define ldc2_w  20
#define iload  21
#define lload  22
#define fload  23
#define dload  24
#define aload  25
#define iload_0  26
#define iload_1  27
#define iload_2  28
#define iload_3  29
#define lload_0  30
#define lload_1  31
#define lload_2  32
#define lload_3  33
#define fload_0  34
#define fload_1  35
#define fload_2  36
#define fload_3  37
#define dload_0  38
#define dload_1  39
#define dload_2  40
#define dload_3  41
#define aload_0  42
#define aload_1  43
#define aload_2  44
#define aload_3  45
#define iaload  46
#define laload  47
#define faload  48
#define daload  49
#define aaload  50
#define baload  51
#define caload  52
#define saload  53
#define istore  54
#define lstore  55
#define fstore  56
#define dstore  57
#define astore  58
#define istore_0  59
#define istore_1  60
#define istore_2  61
#define istore_3  62
#define lstore_0  63
#define lstore_1  64
#define lstore_2  65
#define lstore_3  66
#define fstore_0  67
#define fstore_1  68
#define fstore_2  69
#define fstore_3  70
#define dstore_0  71
#define dstore_1  72
#define dstore_2  73
#define dstore_3  74
#define astore_0  75
#define astore_1  76
#define astore_2  77
#define astore_3  78
#define iastore  79
#define lastore  80
#define fastore  81
#define dastore  82
#define aastore  83
#define bastore  84
#define castore  85
#define sastore  86
#define pop  87
#define pop2  88
#define dup  89
#define dup_x1  90
#define dup_x2  91
#define dup2  92
#define dup2_x1  93
#define dup2_x2  94
#define swap  95
#define iadd  96
#define ladd  97
#define fadd  98
#define dadd  99
#define isub  100
#define lsub  101
#define fsub  102
#define dsub  103
#define imul  104
#define lmul  105
#define fmul  106
#define dmul  107
#define idiv  108
#define ldiv  109
#define fdiv  110
#define ddiv  111
#define irem  112
#define lrem  113
#define frem  114
#define drem  115
#define ineg  116
#define lneg  117
#define fneg  118
#define dneg  119
#define ishl  120
#define lshl  121
#define ishr  122
#define lshr  123
#define iushr  124
#define lushr  125
#define iand  126
#define land  127
#define ior  128
#define lor  129
#define ixor  130
#define lxor  131
#define iinc  132
#define i2l  133
#define i2f  134
#define i2d  135
#define l2i  136
#define l2f  137
#define l2d  138
#define f2i  139
#define f2l  140
#define f2d  141
#define d2i  142
#define d2l  143
#define d2f  144
#define i2b  145
#define i2c  146
#define i2s  147
#define lcmp  148
#define fcmpl  149
#define fcmpg  150
#define dcmpl  151
#define dcmpg  152
#define ifeq  153
#define ifne  154
#define iflt  155
#define ifge  156
#define ifgt  157
#define ifle  158
#define if_icmpeq  159
#define if_icmpne  160
#define if_icmplt  161
#define if_icmpge  162
#define if_icmpgt  163
#define if_icmple  164
#define if_acmpeq  165
#define if_acmpne  166
#define goto  167
#define jsr  168
#define ret  169
#define tableswitch  170
#define lookupswitch  171
#define ireturn  172
#define lreturn  173
#define freturn  174
#define dreturn  175
#define areturn  176
#define return  177
#define getstatic  178
#define putstatic  179
#define getfield  180
#define putfield  181
#define invokevirtual  182
#define invokespecial  183
#define invokestatic  184
#define invokeinterface  185
#define new  187
#define newarray  188
#define anewarray  189
#define arraylength  190
#define athrow  191
#define checkcast  192
#define instanceof  193
#define monitorenter  194
#define monitorexit  195
#define wide  196
#define multianewarray  197
#define ifnull  198
#define ifnonnull  199
#define goto_w  200
#define jsr_w  201
#define breakpoint  202
/** Definição dos códigos numéricos para os atributos */
//#define SOURCEFILE 0x436
//#define CONSTANTVALUE
//#define CODE
//#define EXCEPTIONS
//#define INNERCLASSES
//#define SYNTHETIC
//#define LINENUMBERTABLE
//#define LOCALVARIABLETABLE
//#define DEPRECATED


/** Definição das estruturas relacionadas as áreas de memória da JVM (Heap, stack) */
typedef struct{
	u2 clsHeap_size;
	u2 objHeap_size;
	u2 stkHeap_size;
}dataMSize_t;

/** Definição das estruturas de todos os componentes da constant poll */
/** Nessas estruturas não foram inseridos os campos de tag. Eles já existem no cp_info */

//
/** Definição da estrutura que representa elementos na constant poll */
typedef struct{
	u1 tag;

	union{
		struct{
			u2 name_index;
		}CONSTANT_Class_info;
		struct{ //cobre 3 tipos de estruturas
			u2 class_index;
			u2 name_and_type_index;
		}CONSTANT_FieldMethodIMethod_info; //serve para field, method ou interface method
        struct{
            u2 string_index;
        }CONSTANT_String_info;
		struct{ //cobre 2 tipos de estrutura
			u4 bytes;
		}CONSTANT_IntegerFloat_info; //serve para integer e float
		struct{ //cobre 2 tipoe de estutura
			u4 high_bytes;
			u4 low_bytes;
		}CONSTANT_LongDouble_info; //serve para long e double
		struct{
			u2 name_index;
			u2 descriptor_index;
		}CONSTANT_NameAndType_info;	
		struct{
			u2 length;
			u1 *bytes; //Tamanho especificado por length
		}CONSTANT_Utf8_info;
	}info; //Anonymous unions isn't part of c99	
}cp_info;
	
/**Definição das estrutura das interfaces na tabela de interface*/
typedef struct {
	u2 name_index;
} CONSTANT_Class_info;


/** Definição das estruturas de todos os possíveis atributos */
/** Estrutura para as execeções dentro do atributo code */
typedef struct{
		u2 start_pc;
		u2 end_pc;
		u2 handler_pc;
		u2 catch_type;
	}ExceptionForCode;
//
/** Estrutura para classes dentro do atributo InnerClasses */
typedef struct{
	u2 inner_class_info_index;
	u2 outer_class_info_index;
	u2 inner_name_index;
	u2 inner_class_access_flags;
}ClassesForIClasses;
//
/** Estrutura para número de linha dentro do atributo line number */
typedef struct{
	u2 start_pc;
	u2 line_number; //Número de linha no arquivo fonte
}LineNumberForLNumber;
//
/** Estrutura para variáveis locais dentro do atributo Local Variable */
typedef struct{
	u2 start_pc;
	u2 length;
	u2 name_index;
	u2 descriptor_index;
	u2 index;
}LocalVariableForVariable;
//
/** Definição da estrutura attribute */
typedef struct attribute_info_e attribute_info; //foward declaration
typedef struct attribute_info_e{
	u2 attribute_name_index;
	u4 attribute_length; //Número em bytes da informação seguinte
	u1 tag; //Pra saber o tipo de atributo aqui
	union{
		struct{
		//	u2 attribute_name_index;
		//	u4 attribute_length;
			u2 constantvalue_index;
		}ConstantValue_attribute;
		struct{ //Possivelmente contem componentes flexíveis
		//	u2 attribute_name_index;
		//	u4 attribute_length;
			u2 max_stack;
			u2 max_locals;
			u4 code_length; //Número de bytes do array abaixo
			u1 *code; //Vetor com a qtd de byte indicada acima
			u2 exception_table_length; //Número de entradas e não de bytes da exception_table
			ExceptionForCode *exception_table; //A qtd de elementos é indicada pela variável acima.
			u2 attribute_count; //Número de atributos dentro desse atributo
			attribute_info* attribute; //Vetor de atributos
		}Code_attribute;
		struct{
		//	u2 attribute_name_index;
		//	u4 attribute_lenght; //Indica a qtd de byte do atributo excluindo os 6bytes inici.
			u2 number_of_exceptions; //Número de entradas para o vetor abaixo.
			u2 *exception_index_table; //Vetor imcompleto
		}Exception_attribute;
		struct{
		//	u2 attribute_name_index;
		//	u4 attribute_length; //Tamanho em byte do atributo excluindo os 6 bytes iniciais
			u2 number_of_classes; //Número das estruturas abaixo.
			ClassesForIClasses *classes;
		}InnerClasses_attribute;
		struct{
		//	u2 attribute_name_index;
		//	u4 attribute_length; //Segundo as especificações da JVM esse valor é 0
		}Synthetic_attribute;
		struct{
		//	u2 attribute_name_index;
		//	u4 attribute_length; //Segundo as especificações da JVM esse valor deve ser 2
			u2 sourcefile_index;
		}SourceFile_attribute;
		struct{
		//	u2 attribute_name_index;
		//	u4 attribute_length; //Valor em bytes do atributo excluindo os 6bytes inic.
			u2 line_number_table_length; 
			LineNumberForLNumber *line_number_table;
		}LineNumberTable_attribute;
		struct{
		//	u2 attribute_name_index;
		//	u4 attribute_length;
			u2 local_variable_length;
			LocalVariableForVariable *local_variable_table; //Tabela de variáveis locais
		}LocalVariableTable_attribute; 
		struct{
		//	u2 attribute_name_index;
		//	u4 attribute_length;
		}Deprecated_attribute;
	}info; //Um tipo específico de atributo
}attribute_info;
	
/** Definição da estrutura method */
typedef struct{
	u2 access_flags;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	attribute_info *attribute; //A quantidade é indicada por attributes_count
}method_info;

/** Definição da estutura field */
typedef struct{
	u2 access_flag;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count; //Indica o número de atributos 
	attribute_info *attributes; //Tabela de attributos
}field_info;

/*
union {
    u4 type;
    u1 charValue;
    u2 shortValue;
    u4 intValue;
    u1 *variable_name;
    //f4 floatValue;
    
    //LONG_PTR ptrValue;
    Object object;
} Variable;
*/
/** Estrutura do arquivo .class */
typedef struct {
	u4 magic;
   	u2 minor_version;
   	u2 major_version;
   	u2 constant_pool_count;
   	cp_info *constant_pool; //Tem o tamanho constant_pool_count -1
   	u2 access_flags;
   	u2 this_class;
   	u2 super_class;
   	u2 interfaces_count;
   	u2 *interfaces;
   	u2 fields_count;
   	field_info *fields;
   	u2 methods_count;
   	method_info *methods;
   	u2 attributes_count;
   	attribute_info *attributes;
    
    //Variable *variable;
    u1 *className;
    
    
}ClassFile;


typedef struct {
    Variable *data;
}Array_t;

typedef struct{
    u2 field_index;
    union {
        struct {
            u4 value;
        } U4;
        struct {
            u4 high;
            u4 low;
        } U8;
    }
}Field_Value;

typedef struct {
    ClassFile *classRef ; ///Referencia para a classe alocada na memoria
    field_info *fields; ///Espaco de memoria alocado para os fields do Objeto
    Array_t *arrayList;
    u2 array_lenght;
    Field_Value *field_value;
    u2 field_length;
}Object; ///Objeto

union Variable
{
    u1 charValue;
    u2 shortValue;
    u4 intValue;
    f4 floatValue;
    u1 *sring;
    //LONG_PTR ptrValue;
    Object object;
};

typedef struct {
    //Variable *pOpStack;
    ClassFile *pClass;
    method_info *pMethod;
    u4 code_length; //Número de bytes do array abaixo
    u1 *code; //Vetor com a qtd de byte indicada acima
    u4 pc;
    i4 sp;
    u2 stack_size;
    u2 local_size;
    u4 *stack;
    u4 *local;
}Frame;

#endif
