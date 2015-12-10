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
#define OPCODE_nop  0
#define OPCODE_aconst_null 1 
#define OPCODE_iconst_m1  2
#define OPCODE_iconst_0  3
#define OPCODE_iconst_1  4
#define OPCODE_iconst_2  5
#define OPCODE_iconst_3  6
#define OPCODE_iconst_4  7
#define OPCODE_iconst_5  8
#define OPCODE_lconst_0  9
#define OPCODE_lconst_1  10
#define OPCODE_fconst_0  11
#define OPCODE_fconst_1  12
#define OPCODE_fconst_2  13
#define OPCODE_dconst_0  14
#define OPCODE_dconst_1  15
#define OPCODE_bipush  16
#define OPCODE_sipush  17
#define OPCODE_ldc  18
#define OPCODE_ldc_w  19
#define OPCODE_ldc2_w  20
#define OPCODE_iload  21
#define OPCODE_lload  22
#define OPCODE_fload  23
#define OPCODE_dload  24
#define OPCODE_aload  25
#define OPCODE_iload_0  26
#define OPCODE_iload_1  27
#define OPCODE_iload_2  28
#define OPCODE_iload_3  29
#define OPCODE_lload_0  30
#define OPCODE_lload_1  31
#define OPCODE_lload_2  32
#define OPCODE_lload_3  33
#define OPCODE_fload_0  34
#define OPCODE_fload_1  35
#define OPCODE_fload_2  36
#define OPCODE_fload_3  37
#define OPCODE_dload_0  38
#define OPCODE_dload_1  39
#define OPCODE_dload_2  40
#define OPCODE_dload_3  41
#define OPCODE_aload_0  42
#define OPCODE_aload_1  43
#define OPCODE_aload_2  44
#define OPCODE_aload_3  45
#define OPCODE_iaload  46
#define OPCODE_laload  47
#define OPCODE_faload  48
#define OPCODE_daload  49
#define OPCODE_aaload  50
#define OPCODE_baload  51
#define OPCODE_caload  52
#define OPCODE_saload  53
#define OPCODE_istore  54
#define OPCODE_lstore  55
#define OPCODE_fstore  56
#define OPCODE_dstore  57
#define OPCODE_astore  58
#define OPCODE_istore_0  59
#define OPCODE_istore_1  60
#define OPCODE_istore_2  61
#define OPCODE_istore_3  62
#define OPCODE_lstore_0  63
#define OPCODE_lstore_1  64
#define OPCODE_lstore_2  65
#define OPCODE_lstore_3  66
#define OPCODE_fstore_0  67
#define OPCODE_fstore_1  68
#define OPCODE_fstore_2  69
#define OPCODE_fstore_3  70
#define OPCODE_dstore_0  71
#define OPCODE_dstore_1  72
#define OPCODE_dstore_2  73
#define OPCODE_dstore_3  74
#define OPCODE_astore_0  75
#define OPCODE_astore_1  76
#define OPCODE_astore_2  77
#define OPCODE_astore_3  78
#define OPCODE_iastore  79
#define OPCODE_lastore  80
#define OPCODE_fastore  81
#define OPCODE_dastore  82
#define OPCODE_aastore  83
#define OPCODE_bastore  84
#define OPCODE_castore  85
#define OPCODE_sastore  86
#define OPCODE_pop  87
#define OPCODE_pop2  88
#define OPCODE_dup  89
#define OPCODE_dup_x1  90
#define OPCODE_dup_x2  91
#define OPCODE_dup2  92
#define OPCODE_dup2_x1  93
#define OPCODE_dup2_x2  94
#define OPCODE_swap  95
#define OPCODE_iadd  96
#define OPCODE_ladd  97
#define OPCODE_fadd  98
#define OPCODE_dadd  99
#define OPCODE_isub  100
#define OPCODE_lsub  101
#define OPCODE_fsub  102
#define OPCODE_dsub  103
#define OPCODE_imul  104
#define OPCODE_lmul  105
#define OPCODE_fmul  106
#define OPCODE_dmul  107
#define OPCODE_idiv  108
#define OPCODE_ldiv  109
#define OPCODE_fdiv  110
#define OPCODE_ddiv  111
#define OPCODE_irem  112
#define OPCODE_lrem  113
#define OPCODE_frem  114
#define OPCODE_drem  115
#define OPCODE_ineg  116
#define OPCODE_lneg  117
#define OPCODE_fneg  118
#define OPCODE_dneg  119
#define OPCODE_ishl  120
#define OPCODE_lshl  121
#define OPCODE_ishr  122
#define OPCODE_lshr  123
#define OPCODE_iushr  124
#define OPCODE_lushr  125
#define OPCODE_iand  126
#define OPCODE_land  127
#define OPCODE_ior  128
#define OPCODE_lor  129
#define OPCODE_ixor  130
#define OPCODE_lxor  131
#define OPCODE_iinc  132
#define OPCODE_i2l  133
#define OPCODE_i2f  134
#define OPCODE_i2d  135
#define OPCODE_l2i  136
#define OPCODE_l2f  137
#define OPCODE_l2d  138
#define OPCODE_f2i  139
#define OPCODE_f2l  140
#define OPCODE_f2d  141
#define OPCODE_d2i  142
#define OPCODE_d2l  143
#define OPCODE_d2f  144
#define OPCODE_i2b  145
#define OPCODE_i2c  146
#define OPCODE_i2s  147
#define OPCODE_lcmp  148
#define OPCODE_fcmpl  149
#define OPCODE_fcmpg  150
#define OPCODE_dcmpl  151
#define OPCODE_dcmpg  152
#define OPCODE_ifeq  153
#define OPCODE_ifne  154
#define OPCODE_iflt  155
#define OPCODE_ifge  156
#define OPCODE_ifgt  157
#define OPCODE_ifle  158
#define OPCODE_if_icmpeq  159
#define OPCODE_if_icmpne  160
#define OPCODE_if_icmplt  161
#define OPCODE_if_icmpge  162
#define OPCODE_if_icmpgt  163
#define OPCODE_if_icmple  164
#define OPCODE_if_acmpeq  165
#define OPCODE_if_acmpne  166
#define OPCODE_goto  167
#define OPCODE_jsr  168
#define OPCODE_ret  169
#define OPCODE_tableswitch  170
#define OPCODE_lookupswitch  171
#define OPCODE_ireturn  172
#define OPCODE_lreturn  173
#define OPCODE_freturn  174
#define OPCODE_dreturn  175
#define OPCODE_areturn  176
#define OPCODE_return  177
#define OPCODE_getstatic  178
#define OPCODE_putstatic  179
#define OPCODE_getfield  180
#define OPCODE_putfield  181
#define OPCODE_invokevirtual  182
#define OPCODE_invokespecial  183
#define OPCODE_invokestatic  184
#define OPCODE_invokeinterface  185
#define OPCODE_new  187
#define OPCODE_newarray  188
#define OPCODE_anewarray  189
#define OPCODE_arraylength  190
#define OPCODE_athrow  191
#define OPCODE_checkcast  192
#define OPCODE_instanceof  193
#define OPCODE_monitorenter  194
#define OPCODE_monitorexit  195
#define OPCODE_wide  196
#define OPCODE_multianewarray  197
#define OPCODE_ifnull  198
#define OPCODE_ifnonnull  199
#define OPCODE_goto_w  200
#define OPCODE_jsr_w  201
#define OPCODE_breakpoint  202
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

typedef struct{
    ClassFile * classRef; ///Referencia para a classe alocada na memoria
    field_info * fields; ///Espaco de memoria alocado para os fields do Objeto
    structArrayList *arrayList;
    Field_Value * field_value;
}ClassHandler; ///Objeto


typedef struct {
    ClassFile * classRef; ///Referencia para a classe alocada na memoria
    field_info * fields; ///Espaco de memoria alocado para os fields do Objeto
    structArrayList *arrayList;
    Field_Value * field_value;
    u2 field_size;
}Object; ///Objeto

union Variable
{
    u1 charValue;
    u2 shortValue;
    u4 intValue;
    f4 floatValue;
    LONG_PTR ptrValue;
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
