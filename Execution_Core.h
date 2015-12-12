//
//  Execution_Core.h
//  
//
//  Created by Luiz Henrique Campos Barboza on 09/12/15.
//
//

#ifndef Execution_Core_h
#define Execution_Core_h

#include <stdio.h>

u1 * getFieldName(u2 index, cp_info *pool);
u4 LoadConstant(ClassFile *pClass, u2 nIndex);
Field_Value *getFieldValue(u1 *name, Field_Value *pField, u2 static_values_size);
u1 *GetStringFromConstPool(u2 nIndex, cp_info *pool);
u4 Execute (Frame *pFrame, ClassFile *pClassHeap, dataMSize_t *dmSize_ptr); 

#endif /* Execution_Core_h */

