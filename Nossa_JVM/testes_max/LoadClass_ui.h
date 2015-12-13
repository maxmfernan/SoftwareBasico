#ifndef HEADER_LOADCLASS_UI
#define HEADER_LOADCLASS_UI

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constant Pool
////////////////////////////////////////////////////////////////////////////////////////////////////////
void printContent (cp_info pool);

void printConstantPoolTable (u2 poolElementsNum, cp_info pool[]);

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fields
////////////////////////////////////////////////////////////////////////////////////////////////////////
void printField(cp_info* pool_array, field_info* fields_array, unsigned int fieldn);

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Methods
////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_Methods(ClassFile *classFileVar, cp_info *pool);

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Atributos
////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_attributes (attribute_info *attributes, u2 attr_count, cp_info *pool);

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Interface
////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_interface (u2 interface[], u2 inter_length, cp_info pool[]);

////////////////////////////////////////////////////////////////////////////////////////////////////////
//ClassFile
////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_ClassFile(ClassFile* class_file_ptr);

#endif