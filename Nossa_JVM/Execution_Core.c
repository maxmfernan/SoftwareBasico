//
//  Execution_Core.c
//  
//
//  Created by Luiz Henrique Campos Barboza on 09/12/15.
//
//

#include "Execution_Core.h"

u4 Execute (Frame *pFrame) {
    u4 *local_iterator = pFrame->local;
    u1 *code_iterator;
    i4 error=0;
    
    code_iterator = pFrame->code + pFrame->pc;
    
    while (pFrame->pc < pFrame->code_lenght) {
        
        switch (code_iterator[pFrame->pc]) {
            case nop:
                pFrame->pc++;
                break;
                
                ///////////////// Stack Operations ////////////////
                //Instructions that push a constant onto the stack
            case iconst_m1:
            case iconst_0:
            case iconst_1:
            case iconst_2:
            case iconst_3:
            case iconst_4:
            case iconst_5:
                pFrame->sp++;
                pFrame->stack[pFrame->sp].intValue = (u1)code_iterator[pFrame->pc] - iconst_0;
                pFrame->pc++;
                break;
                
            case aconst_null:
                pFrame->sp++;
                pFrame->stack[pFrame->sp].object = NULL;
                pFrame->pc++;
                break;
                
            case lconst_0:// 9 /*(0x9)*/
            case lconst_1:// 10 /*(0xa)*/
                pFrame->sp++;
                pFrame->stack[pFrame->sp].intValue = 0;
                pFrame->sp++;
                pFrame->stack[pFrame->sp].intValue = (u1)code_iterator[pFrame->pc] - lconst_0;
                pFrame->pc++;
                break;
                
            case bipush:// 16 /*(0x10)*/
                pFrame->sp++;
                pFrame->stack[pFrame->sp].charValue = (u1)code_iterator[pFrame->pc+1];
                pFrame->pc += 2;
                break;
            case sipush:// 17 /*(0x11)*/
                pFrame->sp++;
                pFrame->stack[pFrame->sp].shortValue = getu2(&code_iterator[pFrame->pc+1]);
                pFrame->pc += 3;
                break;
                
            case ldc: //Push item from constant pool
                pFrame->stack[++pFrame->sp] = LoadConstant(pFrame->pClass, (u1)code_iterator[pFrame->pc + 1]);
                pFrame->pc += 2;
                break;
                
            case ldc2_w:// 20 /*(0x14)*/
                index = getu2(&bc[pFrame->pc+1]);
                pFrame->sp++;
                pFrame->stack[pFrame->sp].intValue = getu4(&((char *)pClass->constant_pool[index - 1])[1]);
                pFrame->sp++;
                pFrame->stack[pFrame->sp].intValue = getu4(&((char *)pClass->constant_pool[index - 1])[5]);
                pFrame->pc += 3;
                break;
                
                //Instructions that load a local variable onto the stack
            case aload:// 25 /*(0x19)*/
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc+1]];
                pFrame->pc += 2;
                break;
                
            case iload:// 21 /*(0x15)*/
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc+1]];
                pFrame->pc += 2;
                break;
            case iload_0: //26 Load int from local variable 0
            case iload_1: //27 Load int from local variable 1
            case iload_2: //28 Load int from local variable 2
            case iload_3: //29 Load int from local variable 3
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc] - iload_0];
                pFrame->pc++;
                break;
                
                
            case lload:// 22 /*(0x16)*/
                
                break;
            case lload_0:// 30 /*(0x1e) */
            case lload_1:// 31 /*(0x1f) */
            case lload_2:// 32 /*(0x20) */
            case lload_3:// 33 /*(0x21) */
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc] - lload_0];
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = pFrame->local[(u1)code_iterator[pFrame->pc] - lload_0 + 1];
                pFrame->pc++;
                break;
                
            case fload_0: // 34 /*(0x22)*/
            case fload_1: // 35 /*(0x23)*/
            case fload_2: // 36 /*(0x24)*/
            case fload_3: // 37 /*(0x25)*/
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc] - fload_0];
                pFrame->pc++;
                break;
                
            case aload_0:  //42 Load reference from local variable 0
            case aload_1:  //Load reference from local variable 1
            case aload_2:  //Load reference from local variable 2
            case aload_3:  //Load reference from local variable 3
                pFrame->sp++;
                pFrame->stack[pFrame->sp] = pFrame->local[(u1) code_iterator[pFrame->pc] - aload_0];
                pFrame->pc++;
                break;
                
            case iaload:// 46 /*(0x2e)*/Load int from array
                //..., arrayref, index  => ..., value
                pFrame->stack[pFrame->sp - 1] = getArrayVariable(pFrame->stack[pFrame->sp - 1]->arrayList, pFrame->stack[pFrame->sp].intValue, 2);
                pFrame->sp--;
                pFrame->pc++;
                break;
            case aaload://50
                //..., arrayref, index  ..., value
                pFrame->stack[pFrame->sp - 1] = pFrame->stack[pFrame->sp - 1]->arrayList[pFrame->stack[pFrame->sp].intValue];
                pFrame->sp--;
                pFrame->pc++;
                break;
                //Instructions that store a value from the stack into a local variable
            case astore:// 58 (0x3a)
                pFrame->local[(u1) code_iterator[pFrame->pc+1]] = pFrame->stack[pFrame->sp];
                pFrame->sp--;
                pFrame->pc+=2;
                break;
                
            case istore:// 54 /*(0x36)*/
                pFrame->local[(u1) code_iterator[pFrame->pc+1]] = pFrame->stack[pFrame->sp];
                pFrame->sp--;
                pFrame->pc+=2;
                break;
            case istore_0: // 59 /*(0x3b)*/
            case istore_1: // 60 /*(0x3c) */
            case istore_2: // 61 /*(0x3d) */
            case istore_3: // 62 /*(0x3e)*/
                pFrame->local[(u1) code_iterator[pFrame->pc] - istore_0] = pFrame->stack[pFrame->sp];
                pFrame->sp--;
                pFrame->pc++;
                break;
                
            case lstore_0: // 63 /*(0x3f) */
            case lstore_1: // 64 /*(0x40) */
            case lstore_2: // 65 /*(0x41) */
            case lstore_3: // 66 /*(0x42) */
                pFrame->local[(u1) code_iterator[pFrame->pc] - lstore_0 + 1] = pFrame->stack[pFrame->sp];
                pFrame->sp--;
                pFrame->local[(u1) code_iterator[pFrame->pc] - lstore_0] = pFrame->stack[pFrame->sp];
                pFrame->sp--;
                pFrame->pc++;
                break;
                
            case fstore_0:
            case fstore_1:
            case fstore_2:
            case fstore_3:
                pFrame->local[(u1)code_iterator[pFrame->pc] - fstore_0] = pFrame->stack[pFrame->sp];
                pFrame->sp--;
                pFrame->pc++;
                break;
                
            case astore_0:// 75 /*(0x4b) Store reference into local variable 0*/
            case astore_1:// 76 /*(0x4c) */
            case astore_2:// 77 /*(0x4d) */
            case astore_3:// 78 /*(0x4e)*/
                pFrame->local[(u1) code_iterator[pFrame->pc] - astore_0] = pFrame->stack[pFrame->sp];
                pFrame->sp--;
                pFrame->pc++;
                break;
                
            case iastore:// 79 /*(0x4f)*/
            case aastore: // 83 - both seems same (TODO: Check it)
                pFrame->stack[pFrame->sp-2]->arrrayList[pFrame->stack[pFrame->sp-1].intValue] = pFrame->stack[pFrame->sp];
                pFrame->sp-=3;
                pFrame->pc++;
                break;
                
                //Generic (typeless) stack operations
                
            case dup:// 89 /*(0x59)*/
                pFrame->stack[pFrame->sp+1] = pFrame->stack[pFrame->sp];
                pFrame->sp++;
                pFrame->pc++;
                break;
                
                //Type Conversion
                
                //Integer Arithmetic
                
            case iadd: //96
                pFrame->stack[pFrame->sp-1].intValue = pFrame->stack[pFrame->sp-1].intValue + pFrame->stack[pFrame->sp].intValue;
                pFrame->sp--;
                pFrame->pc++;
                break;
            case ladd:// 97 /*(0x61)*/
                longVal = (i8)(((i8)pFrame->stack[pFrame->sp-3].intValue<<32) | (i8)pFrame->stack[pFrame->sp-2].intValue)+(i8)(((i8)pFrame->stack[pFrame->sp-1].intValue<<32) | (i8)pFrame->stack[pFrame->sp].intValue);
                pFrame->stack[pFrame->sp-3].intValue=HIINT64(longVal);
                pFrame->stack[pFrame->sp-2].intValue=LOINT64(longVal);
                pFrame->sp -= 2;
                pFrame->pc++;
                break;
            case isub: //100
                pFrame->stack[pFrame->sp-1].intValue = pFrame->stack[pFrame->sp-1].intValue - pFrame->stack[pFrame->sp].intValue;
                pFrame->sp--;
                pFrame->pc++;
                break;
            case imul://104
                pFrame->stack[pFrame->sp-1].intValue=pFrame->stack[pFrame->sp-1].intValue * pFrame->stack[pFrame->sp].intValue;
                pFrame->sp--;
                pFrame->pc++;
                break;
            case idiv://108
                pFrame->stack[pFrame->sp-1].intValue=pFrame->stack[pFrame->sp-1].intValue / pFrame->stack[pFrame->sp].intValue;
                pFrame->sp--;
                pFrame->pc++;
                break;
            case iinc:// 132 /*(0x84)*/ Increment local variable by constant
                pFrame->stack[(u1)bc[pFrame->pc+1]].intValue += (char)bc[pFrame->pc+2];
                pFrame->pc+=3;
                break;
                ////////////////////// Logic ///////////////////
                
                //Shift operations
                
                //Bitwise boolean operations
                
                //Floating Point Arithmetic
                
                
                
                /////////////// Objects and Arrays  ////////////
                
                //Instructions that deal with objects
                
            case _new:// 187 (0xbb)
                ExecuteNew(pFrame);
                pFrame->pc+=3;
                break;
            case putfield: //181 (0xb5): Set field in object
                PutField(pFrame);
                pFrame->sp-=2;
                pFrame->pc+=3;
                break;
                
            case getfield: //180 (0xb4) Fetch field from object
                GetField(pFrame);
                pFrame->pc+=3;
                break;
                
                //Instructions that deal with arrays
                
            case newarray:// 188 /*(0xbc)*/
                ExecuteNewArray(pFrame);
                pFrame->pc+=2;
                break;
                
            case anewarray: //189
                ExecuteANewArray(pFrame);
                pFrame->pc+=3;
                break;
                ////////////// Control Flow /////////////////////
                
                //Conditional branch instructions
                
            case if_icmpeq: // 159 /*(0x9f) */
                if(pFrame->stack[pFrame->sp -1].intValue == pFrame->stack[pFrame->sp].intValue) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp-=2;
                break;
            case if_icmpne: //160 /*(0xa0) */
                if(pFrame->stack[pFrame->sp -1].intValue != pFrame->stack[pFrame->sp].intValue) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp-=2;
                break;
            case if_icmplt: // 161 /*(0xa1) */
                if(pFrame->stack[pFrame->sp -1].intValue < pFrame->stack[pFrame->sp].intValue) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp-=2;
                break;
            case if_icmpge: // 162 /*(0xa2) */
                if(pFrame->stack[pFrame->sp -1].intValue >= pFrame->stack[pFrame->sp].intValue) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp-=2;
                break;
            case if_icmpgt: // 163 /*(0xa3) */
                if(pFrame->stack[pFrame->sp -1].intValue > pFrame->stack[pFrame->sp].intValue) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp-=2;
                break;
            case if_icmple: // 164 /*(0xa4)*/
                if(pFrame->stack[pFrame->sp -1].intValue <= pFrame->stack[pFrame->sp].intValue) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp-=2;
                break;
                
            case ifeq:// 153 /*(0x99) */
                if(pFrame->stack[pFrame->sp].intValue == 0) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp--;
                break;
            case ifne:// 154 /*(0x9a) */
                if(pFrame->stack[pFrame->sp].intValue != 0) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp--;
                break;
            case iflt:// 155 /*(0x9b) */
                if(pFrame->stack[pFrame->sp].intValue < 0) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp--;
                break;
            case ifge:// 156 /*(0x9c) */
                if(pFrame->stack[pFrame->sp].intValue >= 0) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp--;
                break;
            case ifgt:// 157 /*(0x9d) */
                if(pFrame->stack[pFrame->sp].intValue > 0) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp--;
                break;
            case ifle:// 158 /*(0x9e)*/
                if(pFrame->stack[pFrame->sp].intValue <= 0) {
                    pFrame->pc+= geti2(&bc[pFrame->pc+1]);
                }
                else {
                    pFrame->pc+=3;
                }
                pFrame->sp--;
                break;
                //Comparison instructions
                
                //Unconditional branch instructions
            case  _goto: // 167 /*(0xa7)*/
                pFrame->pc += geti2(&code_iterator[pFrame->pc+1]);
                break;
                //Table jumping instructions
                
                ////////////// Exceptions ///////////////////////
            case athrow:
                error = 1;
                break;
                
                //////////////////////// Method Invocation and Return ////////
                
                //Method invocation instructions
            case invokespecial:
                ExecuteInvokeSpecial(pFrame);			
                pFrame->pc+=3;
                break;
                
            case invokevirtual: //182
                ExecuteInvokeVirtual(pFrame, invokevirtual);
                pFrame->pc+=3;
                break;
                
            case invokestatic:// 184 
                ExecuteInvokeVirtual(pFrame, invokestatic);
                pFrame->pc+=3;
                break;
                //Method return instructions
            case ireturn: //172 (0xac)			
                DbgPrint(_T("----IRETURN------\n"));
                pFrame->stack[0].intValue=pFrame->stack[pFrame->sp].intValue;			
                return ireturn;
                break;
                
            case _return: //177 (0xb1): Return (void) from method			
                DbgPrint(_T("----RETURN------\n"));
                return 0;//METHOD_RETURN;
                break;
                //////////////// Thread Synchronization ////////////////////
                
            case monitorenter:// Enter and acquire object monitor 
            case monitorexit:// Release and exit object monitor
                error = 1;
                break;
                
            default:
                error=1;
                break;
            
        }
        
    }
    
    
}

int ExecuteNew(Frame *pFrame) {
    pFrame->sp++;
    u1 *code_iterator = pFrame->pMethod->pCode_attr->code;
    u2 index = getu2(&code_iterator[pFrame->pc+1]);
    
    //if(!pFrame->pClass->CreateObject(index, this->pObjectHeap, pFrame->stack[pFrame->sp].object))
    //    return -1;
    
    
    return 0;
}

Variable *CreateNewArray(u1 type, i4 count) {
    Variable *pVar= new Variable[count+1];
    
    if(pVar) {
        memset(pVar, 0, sizeof(Variable)*(count+1));
        pVar[0].intValue = type;
    }
    
    return pVar;
}

Variable getArrayVariable(Array_t *array, int index, int type) {
    Variable v;
    
    switch (type) {
        case 0: //char
            v.charValue = array[index];
            break;
        case 1: //short
            v.shortValue = array[index];
            break;
        case 2: //int
            v.intValue = array[index];
            break;
        case 3: //float
            v.floatValue = array[index];
            break;
        case 4: //string
            v.string = array[index];
            break;
        case 5: //object
            v.object = NULL;
            break;
    }
    return v;
}

BOOL GetStringFromConstPool(int nIndex, u1 *strValue, cp_info *pool) {
    
    if(pool[nIndex - 1]->tag != CONSTANT_UTF8)
        return FALSE;
    
    u1 *p =(u1 *) pool[nIndex -1];
    
    short length = getu2(&p[1]);
    char *buffer = new char[length+1];
    buffer[length] = 0;
    memcpy(buffer, &p[3], length);
    strValue += buffer;
    delete buffer;
    return TRUE;
}

int GetMethodIndex(u1 *strMethodName, u1 *strMethodDesc, ClassFile * &pClass, ClassFile *thisClass) {
    
    ClassFile *pCurClass = thisClass;
    while(pCurClass) {
        for(int i=0; i<pCurClass->methods_count; i++) {
            u1* name, desc;
            
            //pCurClass->GetStringFromConstPool(pCurClass->methods[i].name_index, name);
            GetStringFromConstPool(pCurClass->methods[i].name_index, name, pCurClass.constant_pool);
            if(name.Compare(strMethodName)) continue;
            
            pCurClass->GetStringFromConstPool(pCurClass->methods[i].descriptor_index, desc);
            
            if(!desc.Compare(strMethodDesc)) {
                if(pClass)
                    pClass = pCurClass;
                
                return i;
            }
        }
        
        if(pClass != NULL) {
            pCurClass = pCurClass->GetSuperClass();
        }
        else {
            break;
        }
    }
    return -1;
}

Variable LoadConstant(ClasFile *pClass, u1 nIndex) {
    Variable v;
    u1 *bytes;
    u1 *cp = (u1 *) pClass->constant_pool[nIndex - 1];

    switch(cp[0])
    {
        case CONSTANT_INTEGER:
            v.intValue = getu4(&cp[1]);
            break;
            
        case CONSTANT_FLOAT:
            v.floatValue = getf4((char *)&cp[1]);
            break;
            
        case CONSTANT_STRING:
            bytes = pClass->constant_pool[pClass->constant_pool[nIndex - 1].info.CONSTANT_String_info.string_index - 1];
            v.string = bytes;
            break;
            
        case CONSTANT_DOUBLE:
            break;
            
        case CONSTANT_LONG:
            
            break;		
    }
    return v;
}


void ExecutionEngine::ExecuteInvokeSpecial(Frame *pFrameStack) {
    ExecuteInvokeVirtual(pFrameStack, invokespecial);
}

void ExecuteInvokeVirtual(Frame *pFrameStack, u2 type) {
    u2 mi = getu2(&pFrameStack[0]->code[pFrameStack[0].pc+1]);
    Variable objectRef = pFrameStack[0].stack[pFrameStack[0].sp];
    char *pConstPool = (char *)pFrameStack[0].pClass->constant_pool[mi - 1];
    
    u2 classIndex = getu2(&pConstPool[1]);
    u2 nameAndTypeIndex = getu2(&pConstPool[3]);
    
    //get class at pool index
    pConstPool = (char *)pFrameStack[0].pClass->constant_pool[classIndex - 1];
    
    u2 ni = getu2(&pConstPool[1]);
    
    u1 *strClassName;
    GetStringFromConstPool(ni, srtClassName, pFrameStack[0].pClass.constant_pool);
    
    pFrameStack[0].pClass->GetStringFromConstPool(ni, strClassName);
    
    
    ClassFile *pClass = pClassHeap->fetchClass(pClassHeap, strClassName, classHeapLength);
    
    pConstPool = (char *) pFrameStack[0].pClass->constant_pool[nameAndTypeIndex -1];
    
    method_info method;
    
    
    method.name_index = getu2(&pConstPool[1]);
    method.descriptor_index = getu2(&pConstPool[3]);
    
    method.access_flags = 0; // Nao sei
    
    u1 *strName, *strDesc;
    GetStringFromConstPool(method.name_index, strName, pFrameStack[0].pClass.constant_pool);
    GetStringFromConstPool(method.descriptor_index, strDesc, pFrameStack[0].pClass.constant_pool);
    
    JavaClass *pVirtualClass=pClass;
    int nIndex=pClass->GetMethodIndex(strName, strDesc, pVirtualClass);
    
    memset(&pFrameStack[1],0,sizeof(pFrameStack[1]));
    pFrameStack[1].pMethod = &pClass->methods[nIndex];
    
    method.access_flags = getu2((char *)pFrameStack[1].pMethod);
    if( ACC_SUPER & method.access_flags) {
        pFrameStack[1].pClass = pVirtualClass->GetSuperClass();
        //ShowClassInfo(pFrameStack[1].pClass);
    }
    else {
        pFrameStack[1].pClass=pVirtualClass;
    }
    
    //pFrameStack[1].pOpStack[++pFrameStack[1].sp]=pFrameStack[0].pOpStack[pFrameStack[0].sp--];
    int params=GetMethodParametersStackCount(strDesc)+1;
    
    //static
    if(type==invokestatic) params--;
    
    int nDiscardStack =params;
    if(pFrameStack[1].pMethod->access_flags & ACC_NATIVE) {
    }
    else {
        nDiscardStack+=pFrameStack[1].pMethod->pCode_attr->max_locals;
    }
    
    pFrameStack[1].stack = &Frame::pOpStack[pFrameStack->stack-Frame::pOpStack+pFrameStack[0].sp-params+1];
    pFrameStack[1].sp=nDiscardStack-1;
    DbgPrint(_T("Invoking method %s%s, \n"), strName, strDesc);
    DbgPrint(_T("Last Frame Stack %d Params %d Stack start at %d\n"),pFrameStack[0].stack-Frame::pOpStack+pFrameStack[0].sp,pFrameStack[1].sp,pFrameStack[1].stack-Frame::pOpStack );
    
    this->Execute(&pFrameStack[1]);
    
    //if returns then get on stack	
    if(strDesc.Find(_T(")V")) < 0) {
        nDiscardStack--;		
    }
    
    pFrameStack[0].sp-=nDiscardStack;
}