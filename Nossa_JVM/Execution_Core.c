//
//  Execution_Core.c
//  
//
//  Created by Luiz Henrique Campos Barboza on 09/12/15.
//
//
//

#include "LoadClass_core.h"
#include "macros.h"
#include "Execution_Core.h"

/**
 *  Description
 *  @brief Execução da JVM
 *  @param pFrame     <#pFrame description#>
 *  @param pClassHeap <#pClassHeap description#>
 *  @param dmSize_ptr <#dmSize_ptr description#>
 *
 *  @return <#return value description#>
 */
u4 Execute (Frame *pFrame, ClassFile *pClassHeap, dataMSize_t *dmSize_ptr) {
    u2 classHeapLength = dmSize_ptr->clsHeap_size;
    u4 *local_iterator = pFrame->local;
    u1 *code_iterator;
    i4 error = 0;
    i8 longVal;
    u2 i;
    
    code_iterator = pFrame->code + pFrame->pc;
    
    while (pFrame->pc < pFrame->code_length) {
        switch (code_iterator[pFrame->pc]) {
            case op_nop:
                pFrame->pc++;
                break;
                
                ///////////////// Stack Operations ////////////////
                //Instructions that push a constant onto the stack
//            case op_iconst_m1:
//            case op_iconst_0:
//            case op_iconst_1:
//            case op_iconst_2:
//            case op_iconst_3:
//            case op_iconst_4:
//            case op_iconst_5:
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = code_iterator[pFrame->pc] - op_iconst_0;
//                pFrame->pc++;
//                break;
//                
//            case op_aconst_null:
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = 0;
//                pFrame->pc++;
//                break;
//                
//            case op_lconst_0:// 9 /*(0x9)*/
//            case op_lconst_1:// 10 /*(0xa)*/
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = 0;
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = code_iterator[pFrame->pc] - op_lconst_0;
//                pFrame->pc++;
//                break;
                
            case op_bipush:// 16 /*(0x10)*/
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = code_iterator[pFrame->pc+1];
                pFrame->pc += 2;
                break;
//            case op_sipush:// 17 /*(0x11)*/
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = getu2(&code_iterator[pFrame->pc+1]);
//                pFrame->pc += 3;
//                break;
//                
            case op_ldc: //Push item from constant pool
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = LoadConstant(pFrame->pClass, code_iterator[pFrame->pc + 1]);
                pFrame->pc += 2;
                break;
                
            case op_ldc2_w:// 20 /*(0x14)*/
                i = getu2(&code_iterator[pFrame->pc + 1]);
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = pFrame->pClass->constant_pool[i - 1].info.CONSTANT_LongDouble_info.high_bytes;
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = pFrame->pClass->constant_pool[i - 1].info.CONSTANT_LongDouble_info.low_bytes;
                pFrame->pc += 3;
                break;
//                
//                //Instructions that load a local variable onto the stack
//            case op_aload:// 25 /*(0x19)*/
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc+1]];
//                pFrame->pc += 2;
//                break;
//                
//            case op_iload:// 21 /*(0x15)*/
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc+1]];
//                pFrame->pc += 2;
//                break;
//            case op_iload_0: //26 Load int from local variable 0
//            case op_iload_1: //27 Load int from local variable 1
//            case op_iload_2: //28 Load int from local variable 2
//            case op_iload_3: //29 Load int from local variable 3
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc] - op_iload_0];
//                pFrame->pc++;
//                break;
//                
//                
//            case op_lload:// 22 /*(0x16)*/
//                
//                break;
//            case op_lload_0:// 30 /*(0x1e) */
//            case op_lload_1:// 31 /*(0x1f) */
//            case op_lload_2:// 32 /*(0x20) */
//            case op_lload_3:// 33 /*(0x21) */
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc] - op_lload_0];
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = pFrame->local[(u1)code_iterator[pFrame->pc] - op_lload_0 + 1];
//                pFrame->pc++;
//                break;
//                
//            case op_fload_0: // 34 /*(0x22)*/
//            case op_fload_1: // 35 /*(0x23)*/
//            case op_fload_2: // 36 /*(0x24)*/
//            case op_fload_3: // 37 /*(0x25)*/
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc] - op_fload_0];
//                pFrame->pc++;
//                break;
//                
//            case op_aload_0:  //42 Load reference from local variable 0
//            case op_aload_1:  //Load reference from local variable 1
//            case op_aload_2:  //Load reference from local variable 2
//            case op_aload_3:  //Load reference from local variable 3
//                pFrame->sp++;
//                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc] - op_aload_0];
//                pFrame->pc++;
//                break;
//                
//            case op_iaload:// 46 /*(0x2e)*/Load int from array
//                //..., arrayref, index  => ..., value
//                pFrame->stack[pFrame->sp - 1] = getArrayVariable(pFrame->stack[pFrame->sp - 1], pFrame->stack[pFrame->sp], 2);
//                pFrame->sp--;
//                pFrame->pc++;
//                break;
////            case op_aaload://50
////                //..., arrayref, index  ..., value
////                pFrame->stack[pFrame->sp - 1] = pFrame->stack[pFrame->sp - 1]->arrayList[pFrame->stack[pFrame->sp]];
////                pFrame->sp--;
////                pFrame->pc++;
////                break;
//                //Instructions that store a value from the stack into a local variable
//            case op_astore:// 58 (0x3a)
//                pFrame->local[(u1) code_iterator[pFrame->pc+1]] = pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->pc+=2;
//                break;
//                
//            case op_istore:// 54 /*(0x36)*/
//                pFrame->local[(u1) code_iterator[pFrame->pc+1]] = pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->pc+=2;
//                break;
//            case op_istore_0: // 59 /*(0x3b)*/
//            case op_istore_1: // 60 /*(0x3c) */
//            case op_istore_2: // 61 /*(0x3d) */
//            case op_istore_3: // 62 /*(0x3e)*/
//                pFrame->local[(u1) code_iterator[pFrame->pc] - op_istore_0] = pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->pc++;
//                break;
//                
//            case op_lstore_0: // 63 /*(0x3f) */
//            case op_lstore_1: // 64 /*(0x40) */
//            case op_lstore_2: // 65 /*(0x41) */
//            case op_lstore_3: // 66 /*(0x42) */
//                pFrame->local[(u1) code_iterator[pFrame->pc] - op_lstore_0 + 1] = pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->local[(u1) code_iterator[pFrame->pc] - op_lstore_0] = pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->pc++;
//                break;
//                
//            case op_fstore_0:
//            case op_fstore_1:
//            case op_fstore_2:
//            case op_fstore_3:
//                pFrame->local[(u1)code_iterator[pFrame->pc] - op_fstore_0] = pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->pc++;
//                break;
//                
//            case op_astore_0:// 75 /*(0x4b) Store reference into local variable 0*/
//            case op_astore_1:// 76 /*(0x4c) */
//            case op_astore_2:// 77 /*(0x4d) */
//            case op_astore_3:// 78 /*(0x4e)*/
//                pFrame->local[(u1) code_iterator[pFrame->pc] - op_astore_0] = pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->pc++;
//                break;
//                
//            case op_iastore:// 79 /*(0x4f)*/
//            case op_aastore: // 83 - both seems same (TODO: Check it)
//                pFrame->stack[pFrame->sp-2]->arrrayList[pFrame->stack[pFrame->sp-1]] = pFrame->stack[pFrame->sp];
//                pFrame->sp-=3;
//                pFrame->pc++;
//                break;
                
                //Generic (typeless) stack operations
                
            case op_dup:// 89 /*(0x59)*/
                pFrame->stack[pFrame->sp+1] = pFrame->stack[pFrame->sp];
                pFrame->sp++;
                pFrame->pc++;
                break;
                
//                //Type Conversion
//                
//                //Integer Arithmetic
//                
//            case op_iadd: //96
//                pFrame->stack[pFrame->sp-1] = pFrame->stack[pFrame->sp-1] + pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->pc++;
//                break;
//            case op_ladd:// 97 /*(0x61)*/
//                longVal = (i8)(((i8)pFrame->stack[pFrame->sp-3]<<32) | (i8)pFrame->stack[pFrame->sp-2])+(i8)(((i8)pFrame->stack[pFrame->sp-1]<<32) | (i8)pFrame->stack[pFrame->sp]);
//                pFrame->stack[pFrame->sp-3] = HIINT64(longVal);
//                pFrame->stack[pFrame->sp-2] = LOINT64(longVal);
//                pFrame->sp -= 2;
//                pFrame->pc++;
//                break;
//            case op_isub: //100
//                pFrame->stack[pFrame->sp-1] = pFrame->stack[pFrame->sp-1] - pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->pc++;
//                break;
//            case op_imul://104
//                pFrame->stack[pFrame->sp-1] = pFrame->stack[pFrame->sp-1] * pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->pc++;
//                break;
//            case op_idiv://108
//                pFrame->stack[pFrame->sp-1] = pFrame->stack[pFrame->sp-1] / pFrame->stack[pFrame->sp];
//                pFrame->sp--;
//                pFrame->pc++;
//                break;
//            case op_iinc:// 132 /*(0x84)*/ Increment local variable by constant
//                pFrame->stack[(u1)code_iterator[pFrame->pc+1]] += (char)code_iterator[pFrame->pc+2];
//                pFrame->pc+=3;
//                break;
                ////////////////////// Logic ///////////////////
                
                //Shift operations
                
                //Bitwise boolean operations
                
                //Floating Point Arithmetic
                
                
            case op_putstatic:
                i = getu2(&code_iterator[pFrame->pc+1]);
                u1 *field_name = getFieldName(i, pFrame->pClass->constant_pool);
                Field_Value *fv = getFieldValue(field_name, pFrame->pClass->static_values, pFrame->pClass->static_values_size);
                if (strcmp(fv->descriptor,"Ljava/lang/String;") == 0) {
                    fv->info.UTF8.bytes = pFrame->stack[pFrame->sp];
                    pFrame->sp--;
                }
                else {
                    if (strcmp(fv->descriptor,"I") == 0 || strcmp(fv->descriptor,"F") == 0) {
                        fv->info.I4.value = pFrame->stack[pFrame->sp];
                        pFrame->sp--;
                    }
                    else {
                        if (strcmp(fv->descriptor,"D") == 0 || strcmp(fv->descriptor,"J") == 0) {
                            fv->info.U8.low = pFrame->stack[pFrame->sp];
                            pFrame->sp--;
                            fv->info.U8.high = pFrame->stack[pFrame->sp];
                            pFrame->sp--;
                        }

                    }

                }
                pFrame->pc += 3;
                break;
                /////////////// Objects and Arrays  ////////////
                
                //Instructions that deal with objects
//                
//            case op_new:// 187 (0xbb)
//                //ExecuteNew(pFrame);
//                pFrame->pc+=3;
//                break;
//            case op_putfield: //181 (0xb5): Set field in object
//                PutField(pFrame);
//                pFrame->sp-=2;
//                pFrame->pc+=3;
//                break;
//                
//            case op_getfield: //180 (0xb4) Fetch field from object
//                GetField(pFrame);
//                pFrame->pc+=3;
//                break;
//                
//                //Instructions that deal with arrays
//                
//            case op_newarray:// 188 /*(0xbc)*/
//                ExecuteNewArray(pFrame);
//                pFrame->pc+=2;
//                break;
//                
//            case op_anewarray: //189
//                ExecuteANewArray(pFrame);
//                pFrame->pc+=3;
//                break;
//                ////////////// Control Flow /////////////////////
//                
//                //Conditional branch instructions
//                
//            case op_if_icmpeq: // 159 /*(0x9f) */
//                if(pFrame->stack[pFrame->sp -1] == pFrame->stack[pFrame->sp]) {
//                    pFrame->pc += geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp-=2;
//                break;
//            case op_if_icmpne: //160 /*(0xa0) */
//                if(pFrame->stack[pFrame->sp -1] != pFrame->stack[pFrame->sp]) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp-=2;
//                break;
//            case op_if_icmplt: // 161 /*(0xa1) */
//                if(pFrame->stack[pFrame->sp -1] < pFrame->stack[pFrame->sp]) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp-=2;
//                break;
//            case op_if_icmpge: // 162 /*(0xa2) */
//                if(pFrame->stack[pFrame->sp -1] >= pFrame->stack[pFrame->sp]) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp-=2;
//                break;
//            case op_if_icmpgt: // 163 /*(0xa3) */
//                if(pFrame->stack[pFrame->sp -1] > pFrame->stack[pFrame->sp]) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp-=2;
//                break;
//            case op_if_icmple: // 164 /*(0xa4)*/
//                if(pFrame->stack[pFrame->sp -1] <= pFrame->stack[pFrame->sp]) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp-=2;
//                break;
//                
//            case op_ifeq:// 153 /*(0x99) */
//                if(pFrame->stack[pFrame->sp] == 0) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp--;
//                break;
//            case op_ifne:// 154 /*(0x9a) */
//                if(pFrame->stack[pFrame->sp] != 0) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp--;
//                break;
//            case op_iflt:// 155 /*(0x9b) */
//                if(pFrame->stack[pFrame->sp] < 0) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp--;
//                break;
//            case op_ifge:// 156 /*(0x9c) */
//                if(pFrame->stack[pFrame->sp] >= 0) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp--;
//                break;
//            case op_ifgt:// 157 /*(0x9d) */
//                if(pFrame->stack[pFrame->sp] > 0) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp--;
//                break;
//            case op_ifle:// 158 /*(0x9e)*/
//                if(pFrame->stack[pFrame->sp] <= 0) {
//                    pFrame->pc+= geti2(&code_iterator[pFrame->pc+1]);
//                }
//                else {
//                    pFrame->pc+=3;
//                }
//                pFrame->sp--;
//                break;
//                //Comparison instructions
//                
//                //Unconditional branch instructions
//            case op_goto: // 167 /*(0xa7)*/
//                pFrame->pc += geti2(&code_iterator[pFrame->pc+1]);
//                break;
//                //Table jumping instructions
//                
//                ////////////// Exceptions ///////////////////////
//            case op_athrow:
//                error = 1;
//                break;
//                
//                //////////////////////// Method Invocation and Return ////////
//                
//                //Method invocation instructions
//            case op_invokespecial:
//                //ExecuteInvokeSpecial(pFrame);
//                pFrame->pc+=3;
//                break;
//                
//            case op_invokevirtual: //182
//                //ExecuteInvokeVirtual(pFrame, invokevirtual);
//                pFrame->pc+=3;
//                break;
//                
//            case op_invokestatic:// 184
//                //ExecuteInvokeVirtual(pFrame, invokestatic);
//                pFrame->pc+=3;
//                break;
//                //Method return instructions
//            case op_ireturn: //172 (0xac)
//                pFrame->stack[0]=pFrame->stack[pFrame->sp];			
//                return ireturn;
//                break;
                
            case op_return: //177 (0xb1): Return (void) from method
                printf("return\n");
                pFrame->sp = -1;
                pFrame->pc = 0;
                return 0;//METHOD_RETURN;
                
                break;
                //////////////// Thread Synchronization ////////////////////
                
            case op_monitorenter:// Enter and acquire object monitor
            case op_monitorexit:// Release and exit object monitor
                error = 1;
                break;
                
            default:
                error=1;
                break;
            
        }
        
    }
    
    
}

/**
 *  <#Description#>
 *
 *  @param pFrame <#pFrame description#>
 *
 *  @return <#return value description#>
 */
//int ExecuteNew(Frame *pFrame) {
//    pFrame->sp++;
//    u1 *code_iterator = pFrame->pMethod->pCode_attr->code;
//    u2 index = getu2(&code_iterator[pFrame->pc+1]);
//    
//    //if(!pFrame->pClass->CreateObject(index, this->pObjectHeap, pFrame->stack[pFrame->sp].object))
//    //    return -1;
//    
//    
//    return 0;
//}



/**
 *  <#Description#>
 *
 *  @param name               <#name description#>
 *  @param pField             <#pField description#>
 *  @param static_values_size <#static_values_size description#>
 *
 *  @return <#return value description#>
 */
Field_Value *getFieldValue(u1 *name, Field_Value *pField, u2 static_values_size) {
    u2 count = 0;
    u2 found = 0;
    
    while (count < static_values_size && found == 0) {
        if (strcmp(pField[count].field_name, name) == 0) {
            found = 1;
        }
        else {
            ++count;
        }
    }
    return &pField[count];
}

/**
 *  <#Description#>
 *
 *  @param array <#array description#>
 *  @param index <#index description#>
 *  @param type  <#type description#>
 *
 *  @return <#return value description#>
 */
//Variable getArrayVariable(Array_t *array, int index, int type) {
//    Variable v;
//    
//    switch (type) {
//        case 0: //char
//            v.charValue = array[index];
//            break;
//        case 1: //short
//            v.shortValue = array[index];
//            break;
//        case 2: //int
//            v.intValue = array[index];
//            break;
//        case 3: //float
//            v.floatValue = array[index];
//            break;
//        case 4: //string
//            v.string = array[index];
//            break;
//        case 5: //object
//            v.object = NULL;
//            break;
//    }
//    return v;
//}

/**
 *  <#Description#>
 *
 *  @param pClass <#pClass description#>
 *
 *  @return <#return value description#>
 */
//u1 *GetSuperClassName(ClassFile *pClass) {
//    u1 *retVal = _T("");
//    if(pClass->super_class < 1) return retVal;
//    
//    if(pClass->constant_pool[super_class-1].tag != CONSTANT_CLASS)
//        return retVal;
//    
//    char *bc = (char*)constant_pool[super_class-1];
//    u2 name_index = getu2(&bc[1]);
//    GetStringFromConstPool(name_index, retVal, pClass->constant_pool);
//    return retVal;
//}

/**
 *  <#Description#>
 *
 *  @param pClass <#pClass description#>
 *
 *  @return <#return value description#>
 */
//ClassFile *GetSuperClass(ClassFile *pClass) {
//    u1  *superClass = GetSuperClassName(pClass);
//    
//    ClassFile *pSuperClass = fetchClass(pClassHeap, superClass, classHeapLength);
//    
//    return pSuperClass;
//}

/**
 *  <#Description#>
 *
 *  @param nIndex   <#nIndex description#>
 *  @param strValue <#strValue description#>
 *  @param pool     <#pool description#>
 *
 *  @return <#return value description#>
 */



/**
 *  <#Description#>
 *
 *  @param strMethodName <#strMethodName description#>
 *  @param strMethodDesc <#strMethodDesc description#>
 *  @param pClass        <#pClass description#>
 *  @param thisClass     <#thisClass description#>
 *
 *  @return <#return value description#>
 */
//int GetMethodIndex(u1 *strMethodName, u1 *strMethodDesc, ClassFile * &pClass, ClassFile *thisClass) {
//    
//    ClassFile *pCurClass = thisClass;
//    while(pCurClass) {
//        for(int i=0; i<pCurClass->methods_count; i++) {
//            u1* name, desc;
//            
//            //pCurClass->GetStringFromConstPool(pCurClass->methods[i].name_index, name);
//            GetStringFromConstPool(pCurClass->methods[i].name_index, name, pCurClass.constant_pool);
//            if(name.Compare(strMethodName)) continue;
//            
//            GetStringFromConstPool(pCurClass->methods[i].descriptor_index, desc, pCurClass.constant_pool);
//            
//            if(strcmp(desc,strMethodDesc) != 0) {
//                if(pClass)
//                    pClass = pCurClass;
//                
//                return i;
//            }
//        }
//        
//        if(pClass != NULL) {
//            pCurClass = GetSuperClass(pCurClass);
//        }
//        else {
//            break;
//        }
//    }
//    return -1;
//}
//
///**
// *  <#Description#>
// *
// *  @param pClass <#pClass description#>
// *  @param nIndex <#nIndex description#>
// *
// *  @return <#return value description#>
// */


u4 LoadConstant(ClassFile *pClass, u2 nIndex) {
    u4 v = 0;
    u1 *bytes;

    switch(pClass->constant_pool[nIndex - 1].tag)
    {
        case CONSTANT_INTEGER:
        case CONSTANT_FLOAT:
            v = pClass->constant_pool[nIndex -1].info.CONSTANT_IntegerFloat_info.bytes;
            break;
            
        case CONSTANT_STRING:
            bytes = pClass->constant_pool[pClass->constant_pool[nIndex - 1].info.CONSTANT_String_info.string_index - 1].info.CONSTANT_Utf8_info.bytes;
            v = bytes;

            break;
            
        case CONSTANT_DOUBLE:
            break;
            
        case CONSTANT_LONG:
            
            break;		
    }
    return v;
}

u1 *GetStringFromConstPool(u2 nIndex, cp_info *pool) {
    u1 *string;
    
    string = pool[nIndex - 1].info.CONSTANT_Utf8_info.bytes;
    return string;

}

/**
 *  <#Description#>
 *
 *  @param index <#index description#>
 *  @param pool  <#pool description#>
 *
 *  @return <#return value description#>
 */
u1 *getFieldName(u2 index, cp_info *pool) { //3
    u2 nameAndType_index = 0;
    u2 name_index;
    u1 *string;
    
    nameAndType_index = pool[index -1].info.CONSTANT_FieldMethodIMethod_info.name_and_type_index; //24
    name_index = pool[nameAndType_index -1].info.CONSTANT_NameAndType_info.name_index;
    string = GetStringFromConstPool(name_index, pool);
    
    return string;
}

/**
 *  <#Description#>
 *
 *  @param strMethodDesc <#strMethodDesc description#>
 *
 *  @return <#return value description#>
 */
//u2 GetMethodParametersStackCount(u1 *strMethodDesc) {
//    u2 count=0;
//    
//    int i, len = strlen(strMethodDesc);
//    
//    for(i = 1; i < len; i++) {
//        if(strMethodDesc[i] =='L') {
//            while(strMethodDesc[i] !=';') {
//                i++;
//            }
//        }
//        if(strMethodDesc[i] ==')') break;
//        if(strMethodDesc[i] =='J' || strMethodDesc[i] =='D')
//            count++;
//        count++;
//    }
//    
//    return count;
//}
//
///**
// *  <#Description#>
// *
// *  @param pFrameStack <#pFrameStack description#>
// */
//void ExecuteInvokeSpecial(Frame *pFrameStack) {
//    ExecuteInvokeVirtual(pFrameStack, invokespecial);
//}
//
///**
// *  <#Description#>
// *
// *  @param pFrameStack <#pFrameStack description#>
// *  @param type        <#type description#>
// */
//void ExecuteInvokeVirtual(Frame *pFrameStack, u2 type) {
//    u2 mi = getu2(&pFrameStack[0]->code[pFrameStack[0].pc+1]);
//    Variable objectRef = pFrameStack[0].stack[pFrameStack[0].sp];
//    char *pConstPool = (char *)pFrameStack[0].pClass->constant_pool[mi - 1];
//    
//    u2 classIndex = getu2(&pConstPool[1]);
//    u2 nameAndTypeIndex = getu2(&pConstPool[3]);
//    
//    //get class at pool index
//    pConstPool = (char *)pFrameStack[0].pClass->constant_pool[classIndex - 1];
//    
//    u2 ni = getu2(&pConstPool[1]);
//    
//    u1 *strClassName;
//    GetStringFromConstPool(ni, srtClassName, pFrameStack[0].pClass.constant_pool);
//    
//    pFrameStack[0].pClass->GetStringFromConstPool(ni, strClassName);
//    
//    
//    ClassFile *pClass = fetchClass(pClassHeap, strClassName, classHeapLength);
//    
//    pConstPool = (char *) pFrameStack[0].pClass->constant_pool[nameAndTypeIndex -1];
//    
//    method_info method;
//    
//    
//    method.name_index = getu2(&pConstPool[1]);
//    method.descriptor_index = getu2(&pConstPool[3]);
//    
//    method.access_flags = 0; // Nao sei
//    
//    u1 *strName, *strDesc;
//    GetStringFromConstPool(method.name_index, strName, pFrameStack[0].pClass.constant_pool);
//    GetStringFromConstPool(method.descriptor_index, strDesc, pFrameStack[0].pClass.constant_pool);
//    
//    ClassFile *pVirtualClass = pClass;
//    int nIndex = GetMethodIndex(strName, strDesc, pVirtualClass, pClass);
//    
//    //memset(&pFrameStack[1],0,sizeof(pFrameStack[1]));
//    &pFrameStack[1] = calloc(1, sizeof(pFrameStack[1]);
//    
//    pFrameStack[1].pMethod = &pClass->methods[nIndex];
//    
//    method.access_flags = getu2((char *)pFrameStack[1].pMethod);
//    if( ACC_SUPER & method.access_flags) {
//        pFrameStack[1].pClass = GetSuperClass(pVirtualClass);
//        //ShowClassInfo(pFrameStack[1].pClass);
//    }
//    else {
//        pFrameStack[1].pClass = pVirtualClass;
//    }
//    
//    //pFrameStack[1].pOpStack[++pFrameStack[1].sp]=pFrameStack[0].pOpStack[pFrameStack[0].sp--];
//    int params = GetMethodParametersStackCount(strDesc)+1;
//    
//    //static
//    if(type==invokestatic)
//        params--;
//    
//    int nDiscardStack = params;
//    if(pFrameStack[1].pMethod->access_flags & ACC_NATIVE) {
//    }
//    else {
//        nDiscardStack += pFrameStack[1]code->max_locals;
//    }
//    
//    //pFrameStack[1].stack = &Frame::pOpStack[pFrameStack->stack-Frame::pOpStack+pFrameStack[0].sp-params+1];
//    pFrameStack[1].sp = nDiscardStack-1;
//    
//    Execute(pFrameStack[1]);
//    
//    //if returns then get on stack	
//    if(strDesc.Find(_T(")V")) < 0) {
//        nDiscardStack--;		
//    }
//    
//    pFrameStack[0].sp -= nDiscardStack;
//}