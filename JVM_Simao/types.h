#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE_INT 'I'
#define TYPE_CHAR 'C'
#define TYPE_SHORT 'S'
#define TYPE_DOUBLE 'D'
#define TYPE_LONG 'L'
#define TYPE_FLOAT 'F'
#define TYPE_ARRAY 'R'
#define TYPE_STRING 'T'
#define TYPE_BOOLEAN 'O'
#define TYPE_BYTE 'B'
#define TYPE_NULL 'N'
#define TYPE_INT_U 'U'
#define TYPE_OBJ_REF 'J'

#define TAG_CONSTANT_Utf8 1
#define TAG_CONSTANT_Integer 3
#define TAG_CONSTANT_Float 4
#define TAG_CONSTANT_Long 5
#define TAG_CONSTANT_Double 6
#define TAG_CONSTANT_Class 7
#define TAG_CONSTANT_String 8
#define TAG_CONSTANT_Fieldref 9
#define TAG_CONSTANT_Methodref 10
#define TAG_CONSTANT_InterfaceMethodref 11
#define TAG_CONSTANT_NameAndType 12
#define TYPE_RETURNADRESS 'R'

typedef char            u1;
typedef short int       u2;
typedef unsigned int    u4;
typedef signed int      s4;
typedef long long int   u8;
typedef float           f4;
typedef double          d8;


typedef struct {
	const char	*name;
	u1			attributes_number;
} opcodeT;

typedef struct struc_funcao{
	u1			opCode;
	unsigned int index_atributo;
	unsigned int *itens_table;
	opcodeT dados_function;
} FUNCTION;


/*constante de valor*/
typedef struct const_utf8{
	u2 tamanho;
	char *conteudo;
} CONSTANT_Utf8;

typedef struct const_integer{
	u4 valor;
} CONSTANT_Integer;

typedef struct const_float{
	f4 valor;
} CONSTANT_Float;

typedef struct const_long{
	u8 valor;
} CONSTANT_Long;

typedef struct const_double{
	d8 valor;
} CONSTANT_Double;

/*constantes de referencias */
typedef struct const_class{
	u2 name_index;
} CONSTANT_Class;

typedef struct const_string{
	u2 string_index;
} CONSTANT_String;

typedef struct const_Ref {
	u2 class_index;
	u2 name_and_type_index;
} CONST_Ref, CONSTANT_Fieldref, CONSTANT_Methodref, CONSTANT_InterfaceMethodref;

typedef struct const_nameAndType{
	u2 class_index;
	u2 descriptor_index;
} CONSTANT_NameAndType;

/*item da pool de constantes */
typedef struct  constpool_item{
		u1 tag;
		u4 index_item;
		u4 count;
		union {
			CONSTANT_Utf8 *utf8Info;
			CONSTANT_Long longInfo;
			CONSTANT_Double doubleInfo;
			CONSTANT_NameAndType nameandtypeInfo;
			CONSTANT_Integer integerInfo;
			CONSTANT_Float floatInfo;
			CONST_Ref refInfo;
			CONSTANT_String stringInfo;
			CONSTANT_Class classInfo;
		}info;
		struct constpool_item *proxItem;
} ConstantPoolItem;

/*estrutura de atributos*/
typedef struct line_number_table_struct{
    u2 start_pc;
    u2 line_number;
    struct line_number_table_struct *proxItem;
} LINE_NUMBER_TABLE_ITEM;

typedef struct local_variables_table_struct{
    u2 start_pc;
    u2 length;
    u2 name_index;
    u2 descriptor_index;
    u2 index;
    struct local_variables_table_struct *proxItem;
} LOCAL_VARIABLE_TABLE_ITEM;

typedef struct exception_table_struct {
	u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type; 
 } EXCEPTION_TABLE_ITEM;
 
 struct generic_attribute_struct;
 
 typedef struct code_struct{

    u2 max_stack;
    u2 max_locals;

    u4 code_length;
    u1 *code;

	u2 exception_table_length;
	struct generic_attribute_struct *exceptionTable;

    u2 attributes_count;
    struct generic_attribute_struct *listaAtributos;
    struct code_struct *proxItem;
} CODE;


typedef struct generic_attribute_struct {
	u2 name_index;
	u1 *name_info;
	u4 attribute_length;
	union {
		LOCAL_VARIABLE_TABLE_ITEM *local_table;
		LINE_NUMBER_TABLE_ITEM *line_number;
		CODE *code;
		u1 *info_generic;
	} type;
	struct generic_attribute_struct *proxItem;
} GENERIC_ATTRIBUTE;

/*estruturas principais */
typedef struct method_struct{
	u2 acessFlag;
	u2 nameRef;
	u1 *name;
	u2 descriptorRef;
	u1 *descriptor;
	u2 attributeMethodCount;
	GENERIC_ATTRIBUTE *attributes;
	
	struct method_struct *proxMethod;
	
}METHOD;

typedef struct attribute_struct{
	u2 name_index;
	u4 attribute_length;
	u1 *info;
	
	struct attribute_struct *proxAttribute;
} ATTRIBUTE_CLASS;

typedef struct field_struct {
	u2 acess_flag;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	union{
		u1 bool_data;
		u1 byte_data;
		u1 char_data;
		u2 short_data;
		u4 int_data;
		f4 float_data;
		void *ref_data;
		u1 *returnAdress_data;
		u8 long_data;
		d8 double_data;
	} data;
	
	GENERIC_ATTRIBUTE *listaAtributos;
	struct field_struct *proxField;
}FIELD;

typedef struct interface_struct{
	u4 interface_index;
	struct interface_struct *proxInterface;
} INTERFACE;

typedef struct this_class{
	u2 minor;
	u2 major;
	u2 constPoolCount;
	u2 acessFlag;
	u2 thisClassRef;
	u1 *thisClass;
	u2 superClassRef;
	u1 *superClass;
	u2 interfaceCount;
	u2 fieldsCount;
	u2 methodsCount;
	u2 attributeCount;
	
	METHOD *listaMetodos;
	ATTRIBUTE_CLASS *listaAtributos;
	FIELD *listaField;
	INTERFACE *listaInterface;
	ConstantPoolItem *constPool;
} CLASS;

typedef struct struct_item_vector {

	char type_union;

	union {
		int int_number;
		unsigned int u_int_number;
		long int long_number;

		float float_number;
		double double_number;
		char *string;
		unsigned int *vector_ref;
		CLASS *object_ref;
	}type;
	

	unsigned int index_item;
	
	struct struct_item_vector *prox;
	
} ITEM_VECTOR;


typedef struct struct_vector {
	int max_vector_size;

	ITEM_VECTOR *vector_ini;
}LOCAL_VECTOR;


typedef struct struc_op_stack {

	char operand_type;
	
	union {
		int int_number;
		unsigned int u_int_number;
		float float_number;
		CLASS *object_ref;
		unsigned int *vector_ref;
		char vector_type;
		char *string;
	}type;
	
	struct struc_op_stack *prox;
}OPERAND_STACK;

typedef struct struct_frame{
	u4 code_Size;
	u1 *code;
	u4 max_stack_depth;
	u4 max_local_variables;
	u4 pc;

	OPERAND_STACK *operand_stack;
	LOCAL_VECTOR *local_vector;
	
	METHOD *this_method;
	CLASS *this_class;
	ConstantPoolItem *ref_Const_Pool;

	struct struct_frame *prox;
}FRAME;

typedef struct ClassFileList{
    char *classPath;
    CLASS *classFile;
    struct ClassFileList *prox;
}ClassFileList;

ClassFileList *ListaClasses;

#endif
