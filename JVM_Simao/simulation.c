#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "simulation.h"

int executa_funcao(FUNCTION funcao, OPERAND_STACK **pilhaOperandos, ITEM_VECTOR **vetor, ConstantPoolItem *constPool, FRAME **pilhaFrame, CLASS **nova_Classe, CLASS *classe_corrente)
{
	u4 opCode = funcao.opCode;
	opCode = opCode & 0xFF;
	unsigned char *c;
	/*printf("Executa codigo - Opcode: %x\n",opCode);*/

	switch (opCode) {
		case 0x00:
            /*noop:*/
			break;
		case 0x01:
            /*aconst_null:*/
			aconst_null(&(*pilhaOperandos));
			break;
		case 0x02:
            /*aconst_m1*/
			/*aconst_m1()*/
			break;
		case 0x03:
            /*iconst_0*/
			iconst_n(0,&(*pilhaOperandos));
			break;
		case 0x04:
            /*iconst_1*/
			iconst_n(1,&(*pilhaOperandos));
		case 0x05:
            /*iconst_2*/
			iconst_n(2,&(*pilhaOperandos));
			break;
		case 0x06:
            /*iconst_3*/
			iconst_n(3,&(*pilhaOperandos));
			break;
		case 0x07:
            /*iconst_4*/
			iconst_n(4,&(*pilhaOperandos));
			break;
		case 0x08:
            /*iconst_5*/
			iconst_n(5,&(*pilhaOperandos));
			break;
		case 0x09:
            /*lconst_0*/
			lconst_n(0, &(*pilhaOperandos));
			break;
		case 0x0a:
            /*lconst_1*/
			lconst_n(1, &(*pilhaOperandos));
			break;
		case 0x0b:
            /*fconst_0*/
			/*fconst_n(0,&(*pilhaOperandos))*/
			break;
		case 0x0c:
            /*fconst_1*/
			/*fconst_n(1,&(*pilhaOperandos))*/
			break;
		case 0x0d:
            /*fconst_2*/
			/*fconst_n(2,&(*pilhaOperandos))*/
			break;
		case 0x0e:
            /*dconst_0*/
			/*dconst_n(0,&(*pilhaOperandos))*/
			break;
		case 0x0f:
            /*dconst_1*/
			/*dconst_n(1,&(*pilhaOperandos))*/
			break;
		case 0x10:
			/*bipush*/
			bipush(pilhaOperandos, funcao.index_atributo);
			break;
		case 0x11:
			/*sipush*/
			sipush(pilhaOperandos, funcao.index_atributo);
			break;
		case 0x12:
            /*ldc*/
			ldc(&(*pilhaOperandos), funcao.index_atributo, constPool);
			break;
		case 0x13:
            /*ldc_w*/
			ldc_w(&(*pilhaOperandos), funcao.index_atributo, constPool);
			break;
		case 0x14:
            /*ldc2_w*/
			ldc2_w(&(*pilhaOperandos), funcao.index_atributo, constPool);
			break;
		case 0x15:
			/*iload*/
			iload(&(*pilhaOperandos), &(*vetor), funcao.index_atributo);/*-*/
			break;
		case 0x16:
			/*lload*/
			lload(&(*pilhaOperandos), &(*vetor), funcao.index_atributo);/*-*/
			break;
		case 0x17:
			/*fload*/
			fload (&(*pilhaOperandos), &(*vetor), funcao.index_atributo);/*-*/
			break;
		case 0x18:
			/*dload*/
			dload(&(*pilhaOperandos), &(*vetor), funcao.index_atributo);/*-*/
			break;
		case 0x19:
			/*aload*/
			aload(&(*pilhaOperandos), &(*vetor), funcao.index_atributo);/*-*/
			break;
		case 0x1a:
			/*iload_0*/
			iload(&(*pilhaOperandos), &(*vetor), 0);
			break;
		case 0x1b:
			/*iload_1*/
			iload(&(*pilhaOperandos), &(*vetor), 1);
			break;
		case 0x1c:
			/*iload_2*/
			iload(&(*pilhaOperandos), &(*vetor), 2);
			break;
		case 0x1d:
			/*iload_3*/
			iload(&(*pilhaOperandos), &(*vetor), 3);
			break;
		case 0x1e:
			/*lload_0*/
			lload(&(*pilhaOperandos), &(*vetor), 0);/*-*/
			break;
		case 0x1f:
			/*lload_1*/
			lload(&(*pilhaOperandos), &(*vetor), 1);/*-*/
			break;
		case 0x20:
			/*lload_2*/
			lload(&(*pilhaOperandos), &(*vetor), 2);/*-*/
			break;
		case 0x21:
			/*lload_3*/
			lload(&(*pilhaOperandos), &(*vetor), 3);/*-*/
			break;
		case 0x22:
			/*fload_0*/
			fload (&(*pilhaOperandos), &(*vetor), 0);/*-*/
			break;
		case 0x23:
			/*fload_1*/
			fload (&(*pilhaOperandos), &(*vetor), 1);/*-*/
			break;
		case 0x24:
			/*fload_2*/
			fload (&(*pilhaOperandos), &(*vetor),2);/*-*/
			break;
		case 0x25:
			/*fload_3*/
			fload (&(*pilhaOperandos), &(*vetor), 3);/*-*/
			break;
		case 0x26:
			/*dload_0*/
			dload(&(*pilhaOperandos), &(*vetor), 0);/*-*/
			break;
		case 0x27:
			/*dload_1*/
			dload(&(*pilhaOperandos), &(*vetor), 1);/*-*/
			break;
		case 0x28:
			/*dload_2*/
			dload(&(*pilhaOperandos), &(*vetor), 2);/*-*/
			break;
		case 0x29:
			/*dload_3*/
			dload(&(*pilhaOperandos), &(*vetor), 3);/*-*/
			break;
		case 0x2a:
			/*aload_0*/
			aload(&(*pilhaOperandos), &(*vetor), 0);/*-*/
			break;
		case 0x2b:
			/*aload_1*/
			aload(&(*pilhaOperandos), &(*vetor), 1);/*-*/
			break;
		case 0x2c:
			/*aload_2*/
			aload(&(*pilhaOperandos), &(*vetor), 2);/*-*/
			break;
		case 0x2d:
			/*aload_3*/
			aload(&(*pilhaOperandos), &(*vetor), 3);/*-*/
			break;
		case 0x2e:
			/*iaload*/
			iaload (&(*pilhaOperandos));/*-*/
			break;
		case 0x2f:
			/*laload*/
			laload (&(*pilhaOperandos));/*-*/
			break;
		case 0x30:
			/*faload*/
			faload (&(*pilhaOperandos));/*-*/
			break;
		case 0x31:
			/*daload*/
			daload(pilhaOperandos);/*-*/
			break;
		case 0x32:
			/*aaload*/
			break;
		case 0x33:
			/*baload*/
			baload(pilhaOperandos);
			break;
		case 0x34:
			/*caload*/
			caload (&(*pilhaOperandos));/*-*/
			break;
		case 0x35:
			/*saload*/
			saload (&(*pilhaOperandos));/*-*/
			break;
		case 0x36:
			/*istore*/
			istore(pilhaOperandos, vetor, funcao.index_atributo);
			break;
		case 0x37:
			/*lstore*/
			lstore(pilhaOperandos, vetor, funcao.index_atributo);
			break;
		case 0x38:
			/*fstore*/
			fstore(pilhaOperandos, vetor, funcao.index_atributo);
			break;
		case 0x39:
			/*dstore*/
			dstore(pilhaOperandos, vetor, funcao.index_atributo);
			/*printf("sai dstore\n");*/
			/*getchar()*/
			break;
		case 0x3a:
			/*astore*/
			astore(pilhaOperandos, vetor, funcao.index_atributo);
			break;
		case 0x3b:
			/*istore_0*/
			istore(pilhaOperandos, vetor, 0);
			break;
		case 0x3c:
			/*istore_1*/
			istore(pilhaOperandos, vetor,1);
			break;
		case 0x3d:
			/*istore_2*/
			istore(pilhaOperandos, vetor, 2);
			break;
		case 0x3e:
			/*istore_3*/
			istore(pilhaOperandos, vetor, 3);
			break;
		case 0x3f:
			/*lstore_0*/
			lstore(pilhaOperandos, vetor, 0);
			break;
		case 0x40:
			/*lstore_1*/
			lstore(pilhaOperandos, vetor, 1);
			break;
		case 0x41:
			/*lstore_2*/
			lstore(pilhaOperandos, vetor, 2);
			break;
		case 0x42:
			/*lstore_3*/
			lstore(pilhaOperandos, vetor, 3);
			break;
		case 0x43:
			/*fstore_0*/
			fstore(pilhaOperandos, vetor, 0);
			break;
		case 0x44:
			/*fstore_1*/
			fstore(pilhaOperandos, vetor, 1);
			break;
		case 0x45:
			/*fstore_2*/
			fstore(pilhaOperandos, vetor, 2);
			break;
		case 0x46:
			/*fstore_3*/
			fstore(pilhaOperandos, vetor, 3);
			break;
		case 0x47:
			/*dstore_0*/
			dstore(pilhaOperandos, vetor, 0);
			break;
		case 0x48:
			/*dstore_1*/
			dstore(pilhaOperandos, vetor, 1);
			break;
		case 0x49:
			/*dstore_2*/
			dstore(pilhaOperandos, vetor, 2);
			break;
		case 0x4a:
			/*dstore_3*/
			dstore(pilhaOperandos, vetor, 3);
			break;
		case 0x4b:
			/*astore_0*/
			astore(pilhaOperandos, vetor, 0);
			break;
		case 0x4c:
			/*astore_1*/
			astore(pilhaOperandos, vetor, 1);
			break;
		case 0x4d:
			/*astore_2*/
			astore(pilhaOperandos, vetor, 2);
			break;
		case 0x4e:
			/*astore_3*/
			astore(pilhaOperandos, vetor, 3);
			break;
		case 0x4f:
			/*iastore*/
			iastore(pilhaOperandos);
			break;
		case 0x50:
			/*lastore*/
			lastore(pilhaOperandos);
			break;
		case 0x51:
			/*fastore*/
			fastore(pilhaOperandos);
			break;
		case 0x52:
			/*dastore*/
			dastore(pilhaOperandos);
			break;
		case 0x53:
			/*aastore*/
			aastore(pilhaOperandos);
			break;
		case 0x54:
			/*bastore*/
			bastore(pilhaOperandos);
			break;
		case 0x55:
			/*castore*/
			castore(pilhaOperandos);
			break;
		case 0x56:
			/*sastore*/
			sastore(pilhaOperandos);
			break;
		case 0x57:
			/*pop*/
			pop(pilhaOperandos);
			break;
		case 0x58:
			/*pop2*/
			pop2(pilhaOperandos);
			break;
		case 0x59:
			/*dup*/
			/*printf("dUPPPPP!\n");*/
			dup(pilhaOperandos);
			break;
		case 0x5a:
			/*dup_x1*/
			dup_x1(pilhaOperandos);
			break;
		case 0x5b:
			/*dup_x2*/
			dup_x2(pilhaOperandos);
			break;
		case 0x5c:
			/*dup2*/
			dup2(pilhaOperandos);
			break;
		case 0x5d:
			/*dup2_x1*/
			dup2_x1(pilhaOperandos);
			break;
		case 0x5e:
			/*dup2_x2*/
			dup2_x2(pilhaOperandos);
			break;
		case 0x5f:
			/*swap*/
			swap(pilhaOperandos);
			break;
		case 0x60:
			/*iadd*/
			iadd(pilhaOperandos);
			break;
		case 0x61:
			/*ladd*/
			ladd(pilhaOperandos);
			break;
		case 0x62:
            /*fadd*/
			fadd(&(*pilhaOperandos));
			break;
		case 0x63:
			/*dadd*/
			dadd(pilhaOperandos);
			break;
		case 0x64:
			/*isub*/
			isub(pilhaOperandos);
			break;
		case 0x65:
			/*lsub*/
			lsub(pilhaOperandos);
			break;
		case 0x66:
            /*fsub*/
			fsub(&(*pilhaOperandos));
			break;
		case 0x67:
			/*dsub*/
			dsub(pilhaOperandos);
			break;
		case 0x68:
			/*imul*/
			imul(pilhaOperandos);
			break;
		case 0x69:
			/*lmul*/
			lmul(pilhaOperandos);
			break;
		case 0x6a:
            /*fmul*/
			fmul(&*(pilhaOperandos));
			break;
		case 0x6b:
			/*dmul*/
			dmul(pilhaOperandos);
			break;
		case 0x6c:
			/*idiv*/
			idiv(pilhaOperandos);
			break;
		case 0x6d:
			/*ldiv*/
			ldivi(pilhaOperandos);
			break;
		case 0x6e:
            /*fdiv*/
			fdiv(&*(pilhaOperandos));
			break;
		case 0x6f:
			/*ddiv*/
			ddiv(pilhaOperandos);
			break;
		case 0x70:
			/*irem*/
			irem(pilhaOperandos);
			break;
		case 0x71:
			/*lrem*/
			lrem(pilhaOperandos);
			break;
		case 0x72:
            /*frem*/
			frem(&*(pilhaOperandos));
			break;
		case 0x73:
			/*drem*/
			drem_nova(pilhaOperandos);
			break;
		case 0x74:
			/*ineg*/
			ineg(pilhaOperandos);
			break;
		case 0x75:
			/*lneg*/
			lneg(pilhaOperandos);
			break;
		case 0x76:
            /*fneg*/
			fneg(&*(pilhaOperandos));
			break;
		case 0x77:
			/*dneg*/
			dneg(pilhaOperandos);
			break;
		case 0x78:
			/*ishl*/
			ishl(pilhaOperandos);
			break;
		case 0x79:
			/*lshl*/
			lshl(pilhaOperandos);
			break;
		case 0x7a:
			/*ishr*/
			ishr(pilhaOperandos);
			break;
		case 0x7b:
			/*lshr*/
			lshr(pilhaOperandos);
			break;
		case 0x7c:
			/*iushr*/
			break;
		case 0x7d:
			/*lushr*/
			lushr(pilhaOperandos);
			break;
		case 0x7e:
			/*iand*/
			iand(pilhaOperandos);
			break;
		case 0x7f:
			/*land*/
			land(pilhaOperandos);
			break;
		case 0x80:
			/*ior*/
			ior(pilhaOperandos);
			break;
		case 0x81:
			/*lor*/
			lor(pilhaOperandos);
			break;
		case 0x82:
			/*ixor*/
			ixor(pilhaOperandos);
			break;
		case 0x83:
			/*lxor*/
			lxor(pilhaOperandos);
			break;
		case 0x84:
            /*iinc*/
            c = calloc(2, sizeof(unsigned char));
            memcpy(c ,&funcao.index_atributo,2);
			iinc(&(*pilhaOperandos), &(*vetor), c[0], c[1]);
			break;
		case 0x85:
			/*i2l*/
			i2l(pilhaOperandos);
			break;
		case 0x86:
			/*i2f*/
			i2f(pilhaOperandos);
			break;
		case 0x87:
			/*i2d*/
			i2d(pilhaOperandos);
			break;
		case 0x88:
			/*l2i*/
			l2i(pilhaOperandos);
			break;
		case 0x89:
			/*l2f*/
			l2f(pilhaOperandos);
			break;
		case 0x8a:
			/*l2d*/
			l2d(pilhaOperandos);
			break;
		case 0x8b:
			/*f2i*/
			f2i(pilhaOperandos);
			break;
		case 0x8c:
			/*f2l*/
			f2l(pilhaOperandos);
			break;
		case 0x8d:
			/*f2d*/
			f2d(pilhaOperandos);
			break;
		case 0x8e:
			/*d2i*/
			d2i(pilhaOperandos);
			break;
		case 0x8f:
			/*d2l*/
			d2l(pilhaOperandos);
			break;
		case 0x90:
			/*d2f*/
			d2f(pilhaOperandos);
			break;
		case 0x91:
			/*i2b*/
			i2b(pilhaOperandos);
			break;
		case 0x92:
			/*i2c*/
			i2c(pilhaOperandos);
			break;
		case 0x93:
			/*i2s*/
			i2s(pilhaOperandos);
			break;
		case 0x94:
            /*lcmp*/
            lcmp(pilhaOperandos);
			break;
		case 0x95:
            /*fcmpl*/
            fcmpl(pilhaOperandos);
			break;
		case 0x96:
            /*fcmpg*/
            fcmpg(pilhaOperandos);
			break;
		case 0x97:
            /*dcmpl*/
            dcmpl(pilhaOperandos);
			break;
		case 0x98:
            /*dcmpg*/
            dcmpg(pilhaOperandos);
			break;
		case 0x99:
            /*ifeq*/
            if_eq(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0x9a:
            /*ifne*/
            if_ne(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0x9b:
            /*iflt*/
            if_lt(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0x9c:
            /*ifge*/
            if_ge(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0x9d:
            /*ifgt*/
            if_gt(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0x9e:
            /*ifle*/
            if_le(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0x9f:
            /*if_icmpeq*/
            if_icmpeq(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xa0:
            /*if_icmpne*/
            if_icmpne(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xa1:
            /*if_icmplt*/
            if_icmplt(pilhaOperandos,funcao.index_atributo,&((*pilhaFrame)->pc));
			break;
		case 0xa2:
            /*if_icmpge*/
            if_icmpge(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xa3:
            /*if_icmpgt*/
            if_icmpgt(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xa4:
            /*if_icmple*/
            if_icmple(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xa5:
            /*if_acmpeq*/
            if_acmpeq(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xa6:
            /*if_acmpne*/
            if_acmpne(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xa7:
            /*goto*/
            go2(funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xa8:
            /*jsr*/
            jsr(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xa9:
            /*ret*/
            /*ret(pilhaFrame);*/
			break;
		case 0xaa:
            /*tableswitch*/
			break;
		case 0xab:
            /*lookupswitch*/
			break;
		case 0xac:
            /*ireturn*/
            ireturn(pilhaFrame);
			break;
		case 0xad:
            /*lreturn*/
            lreturn(pilhaFrame);
			break;
		case 0xae:
            /*freturn*/
            freturn(pilhaFrame);
			break;
		case 0xaf:
            /*dreturn*/
            dreturn(pilhaFrame);
			break;
		case 0xb0:
            /*areturn*/
            areturn(pilhaFrame);
			break;
		case 0xb1:
            /*return*/
            returne(pilhaFrame);
			break;
		case 0xb2:
            /*getstatic*/
            /*printf("getsatic ini\n");*/
            getstatic(pilhaOperandos, funcao.index_atributo, pilhaFrame);
            /*printf("getsatic fim\n");*/
			break;
		case 0xb3:
            /*putstatic*/
            putstatic(pilhaOperandos, funcao.index_atributo, pilhaFrame);
			break;
		case 0xb4:
            /*getfield*/
            getfield(pilhaOperandos, funcao.index_atributo, pilhaFrame);
			break;
		case 0xb5:
            /*putfield*/
            putfield(pilhaOperandos, funcao.index_atributo, pilhaFrame);
			break;
		case 0xb6:
            /*invokevirtual*/
            invokevirtual(pilhaOperandos, funcao.index_atributo, pilhaFrame);
			break;
		case 0xb7:
            /*invokespecial*/
            invokespecial(pilhaOperandos, funcao.index_atributo, pilhaFrame);
			break;
		case 0xb8:
            /*invokestatic*/
			break;
		case 0xb9:
            /*invokeinterface*/
			break;
		case 0xba:
            /*invokedynamic*/
			break;
		case 0xbb:
            /*new*/
            new(constPool, nova_Classe, funcao.index_atributo, classe_corrente);
			break;
		case 0xbc:
            /*newarray*/
            newarray(pilhaOperandos, funcao.index_atributo );
			break;
		case 0xbd:
            /*anewarray*/
			break;
		case 0xbe:
            /*arraylength*/
            arraylength(pilhaOperandos);
			break;
		case 0xbf:
            /*athrow*/
			break;
		case 0xc0:
            /*checkcast*/
			break;
		case 0xc1:
            /*instanceof*/
			break;
		case 0xc2:
            /*monitorenter*/
			break;
		case 0xc3:
            /*monitorexit*/
			break;
		case 0xc4:
            /*wide*/
			break;
		case 0xc5:
            /*multianewarray*/
			break;
		case 0xc6:
            /*ifnull*/
            if_null(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xc7:
            /*ifnonnull*/
            if_nonnull(pilhaOperandos,funcao.index_atributo, &((*pilhaFrame)->pc));
			break;
		case 0xc8:
            /*goto_w*/
            goto_w(funcao.index_atributo,&((*pilhaFrame)->pc));
			break;
		case 0xc9:
            /*jsr_w*/
            jsr_w(pilhaOperandos,funcao.index_atributo,&((*pilhaFrame)->pc));
			break;
		case 0xca:
            /*breakpoint*/
			break;
		case 0xd1:
            /*ret_w*/
			break;
		case 0xfe:
            /*impdep1*/
			break;
		case 0xff:
            /*impdep2*/
			break;

		default:
			/*printf("default\n");*/
			break;
	}
	return 0;
}

int traduz_funcao(FUNCTION *function, u1 *code, u4 index){
	/*tamanho do atributo em bytes*/
    int tamanho_atributo = (function->dados_function).attributes_number;
	int j, retorno, offset;

    FUNCTION funcao_extra;
    u4 def, low, hi,valor, npair;
	u4 init = index;
	
	/*printf("Entra traduz\n");
	/*getchar()*/

	int *atributoFinal = malloc(sizeof(int));
	char *atributo = (char*)atributoFinal;

	retorno = 0;
    switch (tamanho_atributo){
		case 0:
			break;
		case 1:
            *atributoFinal = 0;
			*atributo = 0;
			atributo[0] = code[index + 0];

			function->index_atributo = *atributoFinal;

			retorno = tamanho_atributo;
			break;

		case 2:
             *atributoFinal = 0;
			*atributo = 0;
			atributo[1] = code[index + 0];
			atributo[0] = code[index + 1];

			function->index_atributo = *atributoFinal;
			retorno = tamanho_atributo;
			break;

		case 3:
            *atributoFinal = 0;
			*atributo = 0;

			atributo[2] = code[index + 0];
			atributo[1] = code[index + 1];
			atributo[0] = code[index + 2];

			function->index_atributo = *atributoFinal;
			retorno = tamanho_atributo;
			break;
		case 4:
             *atributoFinal = 0;
			*atributo = 0;

			atributo[3] = code[index + 0];
			atributo[2] = code[index + 1];
			atributo[1] = code[index + 2];
			atributo[0] = code[index + 3];

			function->index_atributo = *atributoFinal;
			retorno = tamanho_atributo;
			break;

		/*case de funcoes que falam para ler outra funcao em seguida*/
		case 5:
			funcao_extra.opCode = code[index];
			funcao_extra.dados_function = verifica_opcode(code[index]);
			/*printf("Funcao extra: %s", funcao_extra.dados_function.name);*/

			/*como na funcao wide, o tamanho é *2*/
			atributo = 0;
			j = funcao_extra.dados_function.attributes_number * 2;

			for (j = 0; j < tamanho_atributo; j++){
				atributo[j] = code[index + j + 1];
				/*printf("%#X ", code[index+j+1]);*/
			}

			function->index_atributo = *atributoFinal;
			retorno = j+1;
			break;

		default:
			if (strcmp ("tableswitch", function->dados_function.name) == 0){
				if (index % 4 != 0){
					index += 4 - (index % 4);
				}
				def = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] << 24)));
				index = index+4;
				low = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] << 24)));
				index = index+4;
				hi = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] << 24)));
				index = index+4;
				/*printf(" %#X %#X\n", low, hi);*/
				offset = hi - low +1;
				int i;
				for (i = 0; i < offset; i++){
					valor = (((code[index+3]) << 24) + (code[index+2] << 16) + (code[index+1] << 8) + ((code[index])));
					/*printf(" %#X", valor);*/
					index = index+4;
				}
				retorno = index - init;
			}
			else{
				if (index % 4 != 0){
					index += 4 - (index % 4);
				}
				def = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index]<< 24)));
				index = index+4;
				npair = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] <<24)));
				index = index+4;
				/*printf("%d\n",npair);*/
				int i;
				for (i = 0; i < npair; i++){
					valor = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] << 24)));
					index = index+4;
					offset = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] << 24)));
					index = index+4;
					/*printf("\t%d +%#X\n", valor, offset);*/
				}
				printf("\tdefault +%d\n",def);
			}
			retorno = index - init;
			break;
    }
    return retorno;

}

/*count é o tamanho do codigo*/
void traduz_codigo(u1 *code, u4 code_size, OPERAND_STACK **pilhaOperandos, ITEM_VECTOR **vetor, ConstantPoolItem *constPool, FRAME **pilhaFrame){
    u4 i =0;

	/*controle dos bytes da string codigo*/
    int pc = 0;

	/*loop para ler todo o codigo*/
    for (i=0; i < code_size; i++){
        FUNCTION function;

		function.opCode = 0;
        function.opCode = code[i];
		function.index_atributo = 0;

        function.dados_function = verifica_opcode(code[i]);

        /*printf("Nome funcao %s\n", function.dados_function.name);
        printf("Opcode: %#x\n",function.opCode);*/
        /*getchar()*/
        int iAux = traduz_funcao(&function, code, i+1);
        pc = pc + iAux;
        i += iAux;
        (*pilhaFrame)->pc = i;

        int testeOpcode = (int)function.opCode;
        if(testeOpcode == 0xbb){
            CLASS *nova_Classe = NULL;
            nova_Classe = malloc(sizeof(CLASS));
            executa_funcao(function, pilhaOperandos,vetor, constPool, pilhaFrame, &nova_Classe, (*pilhaFrame)->this_class);
        }
        else
        {
             executa_funcao(function, pilhaOperandos,vetor, constPool, pilhaFrame, NULL, (*pilhaFrame)->this_class);
        }
       
    }
	/*printf("\n");*/
}


int executaMain(FRAME **mainFrame){

	METHOD *mainMethod = ((*mainFrame)->this_method);
	GENERIC_ATTRIBUTE *genericAux = mainMethod->attributes;
	if(genericAux == NULL)
	{
      printf("Metodo nao possui codigo!\n");
      return 1;
    }

	if (strcmp(genericAux->name_info, "Code") != 0) {
		printf("\nNao e um codigo executavel.\n");
		return 1;
	}

	CODE *codeMain = (genericAux->type).code;
	OPERAND_STACK *pilhaOperandos = (*mainFrame)->operand_stack;
	LOCAL_VECTOR *vetor_local = (*mainFrame)->local_vector;
	ITEM_VECTOR *vetor;
	if (vetor_local == NULL){
         vetor = NULL;
	}
	else {
        vetor = vetor_local->vector_ini;
	}
	ConstantPoolItem *constPool =  (*mainFrame)->ref_Const_Pool;
	traduz_codigo(codeMain->code, codeMain->code_length, &pilhaOperandos,&vetor,constPool, mainFrame);

	return 0;
}

/*Conta argumentos:*/
int contaArgumentos(char *descriptor){
    char *c;
    int contador;
    int testa;

    contador = 0;
    testa = 0;

    c = descriptor;
    while(*c != '\0') {
        switch(*c){
			case 'B' :
				if(testa)
					contador++;
				break;
			case 'C':
				if(testa)
					contador++;
				break;
			case 'D':
				if(testa)
					contador+=2;
				break;
			case 'F':
				if(testa)
					contador++;
				break;
			case 'I':
				if(testa)
					contador++;
				break;
			case 'J':
				if(testa)
					contador++;
				break;
			case 'L':
				if(testa){
					contador+=2;
					testa = 0;
				}
				break;
			case 'S':
				if(testa)
					contador++;
				break;
			case 'Z':
				if(testa)
					contador++;
				break;
			case '[':
				break;
			case '(':
				testa = 1;
				break;
			case ')':
				testa = 0;
				break;
			case ';':
				testa = 1;
				break;
			default:
				break;
        }
        c++;
    }
    return contador;/*Retorna o numero de argumentos*/
}

int printStack(OPERAND_STACK *pilha)
{
    OPERAND_STACK *opAux = pilha;
    if(opAux == NULL)
        printf("Pilha vazia");

    return 0;
}

int printVetor(ITEM_VECTOR *iniVetor)
{
    ITEM_VECTOR *inicio = iniVetor;

    printf("\nVETOR\n");
    while(inicio != NULL)
    {

       if(inicio->type_union == TYPE_INT)
       {
           printf("\tItem: %d\n",(inicio->type).int_number);
       }
       else if(inicio->type_union == TYPE_FLOAT)
       {
            printf("\tItem: %f\n",(inicio->type).float_number);
       }
       else if(inicio->type_union == TYPE_LONG || (inicio->type_union== TYPE_INT_U) || (inicio->type_union== TYPE_DOUBLE))
       {
            printf("\tItem: %u\n\n",(inicio->type).u_int_number);
       }

       inicio = inicio->prox;
    }

    return 0;
}
