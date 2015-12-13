/* Universidade de Brasília
 * Instituto de Ciencias Exatas
 * Departamento de Ciencia da Computacao
 * Trabalho JVM
 *
 * Grupo:
 * 07/45006 - Carolina S. R. de Oliveira
 * 09/0114388 - Gabriel Heleno Goncalves da Silva
 * 09/0128818 - Pedro Vitor Falcetti Sozin
 * 09/0012704 - Rafael Simao da Costa
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "mnemonics.h"


opcodeT verifica_opcode(u1 opcode){
        int i = opcode;
        i = i & 0xFF;
    	static const opcodeT opcodes[] = {

/*  00 (0x00) */ {"noop\0",			0},
/*  01 (0x01) */ {"aconst_null\0",	0},
/*  02 (0x02) */ {"aconst_m1\0",		0},
/*  03 (0x03) */ {"iconst_0\0",		0},
/*  04 (0x04) */ {"iconst_1\0",		0},
/*  05 (0x05) */ {"iconst_2\0",		0},
/*  06 (0x06) */ {"iconst_3\0",		0},
/*  07 (0x07) */ {"iconst_4\0",		0},
/*  08 (0x08) */ {"iconst_5\0",		0},
/*  09 (0x09) */ {"lconst_0\0",		0},
/*  10 (0x0a) */ {"lconst_1\0",		0},
/*  11 (0x0b) */ {"fconst_0\0",		0},
/*  12 (0x0c) */ {"fconst_1\0",		0},
/*  13 (0x0d) */ {"fconst_2\0",		0},
/*  14 (0x0e) */ {"dconst_0\0",		0},
/*  15 (0x0f) */ {"dconst_1\0",		0},
/*  16 (0x10) */ {"bipush\0",         1},
/*  17 (0x11) */ {"sipush\0",         2},
/*  18 (0x12) */ {"ldc\0",            1},
/*  19 (0x13) */ {"ldc_w\0",          2},
/*  20 (0x14) */ {"ldc2_w\0",         2},
/*  21 (0x15) */ {"iload\0",          1},
/*  22 (0x16) */ {"lload\0",          1},
/*  23 (0x17) */ {"fload\0",          1},
/*  24 (0x18) */ {"dload\0",          1},
/*  25 (0x19) */ {"aload\0",          1},
/*  26 (0x1a) */ {"iload_0\0",        0},
/*  27 (0x1b) */ {"iload_1\0",        0},
/*  28 (0x1c) */ {"iload_2\0",        0},
/*  29 (0x1d) */ {"iload_3\0",        0},
/*  30 (0x1e) */ {"lload_0\0",        0},
/*  31 (0x1f) */ {"lload_1\0",        0},
/*  32 (0x20) */ {"lload_2\0",        0},
/*  33 (0x21) */ {"lload_3\0",        0},
/*  34 (0x22) */ {"fload_0\0",        0},
/*  35 (0x23) */ {"fload_1\0",        0},
/*  36 (0x24) */ {"fload_2\0",        0},
/*  37 (0x25) */ {"fload_3\0",        0},
/*  38 (0x26) */ {"dload_0\0",        0},
/*  39 (0x27) */ {"dload_1\0",        0},
/*  40 (0x28) */ {"dload_2\0",        0},
/*  41 (0x29) */ {"dload_3\0",        0},
/*  42 (0x2a) */ {"aload_0\0",        0},
/*  43 (0x2b) */ {"aload_1\0",        0},
/*  44 (0x2c) */ {"aload_2\0",        0},
/*  45 (0x2d) */ {"aload_3\0",        0},
/*  46 (0x2e) */ {"iaload\0",			0},
/*  47 (0x2f) */ {"laload\0",			0},
/*  48 (0x30) */ {"faload\0",			0},
/*  49 (0x31) */ {"daload\0",			0},
/*  50 (0x32) */ {"aaload\0",			0},
/*  51 (0x33) */ {"baload\0",			0},
/*  52 (0x34) */ {"caload\0",			0},
/*  53 (0x35) */ {"saload\0",			0},
/*  54 (0x36) */ {"istore\0",	        1},
/*  55 (0x37) */ {"lstore\0",	        1},
/*  56 (0x38) */ {"fstore\0",	        1},
/*  57 (0x39) */ {"dstore\0",	        1},
/*  58 (0x3a) */ {"astore\0",	        1},
/*  59 (0x3b) */ {"istore_0\0",	    0},
/*  60 (0x3c) */ {"istore_1\0",	    0},
/*  61 (0x3d) */ {"istore_2\0",	    0},
/*  62 (0x3e) */ {"istore_3\0",	    0},
/*  63 (0x3f) */ {"lstore_0\0",	    0},
/*  64 (0x40) */ {"lstore_1\0",	    0},
/*  65 (0x41) */ {"lstore_2\0",	    0},
/*  66 (0x42) */ {"lstore_3\0",	    0},
/*  67 (0x43) */ {"fstore_0\0",	    0},
/*  68 (0x44) */ {"fstore_1\0",	    0},
/*  69 (0x45) */ {"fstore_2\0",	    0},
/*  70 (0x46) */ {"fstore_3\0",	    0},
/*  71 (0x47) */ {"dstore_0\0",	    0},
/*  72 (0x48) */ {"dstore_1\0",	    0},
/*  73 (0x49) */ {"dstore_2\0",	    0},
/*  74 (0x4a) */ {"dstore_3\0",	    0},
/*  75 (0x4b) */ {"astore_0\0",	    0},
/*  76 (0x4c) */ {"astore_1\0",	    0},
/*  77 (0x4d) */ {"astore_2\0",	    0},
/*  78 (0x4e) */ {"astore_3\0",	    0},
/*  79 (0x4f) */ {"iastore\0",		0},
/*  80 (0x50) */ {"lastore\0",		0},
/*  81 (0x51) */ {"fastore\0",		0},
/*  82 (0x52) */ {"dastore\0",		0},
/*  83 (0x53) */ {"aastore\0",		0},
/*  84 (0x54) */ {"bastore\0",		0},
/*  85 (0x55) */ {"castore\0",		0},
/*  86 (0x56) */ {"sastore\0",		0},
/*  87 (0x57) */ {"pop\0",			0},
/*  88 (0x58) */ {"pop2\0",			0},
/*  89 (0x59) */ {"dup\0",			0},
/*  90 (0x5a) */ {"dup_x1\0",			0},
/*  91 (0x5b) */ {"dup_x2\0",			0},
/*  92 (0x5c) */ {"dup2\0",			0},
/*  93 (0x5d) */ {"dup2_x1\0",		0},
/*  94 (0x5e) */ {"dup2_x2\0",		0},
/*  95 (0x5f) */ {"swap\0",			0},
/*  96 (0x60) */ {"iadd\0",			0},
/*  97 (0x61) */ {"ladd\0",			0},
/*  98 (0x62) */ {"fadd\0",			0},
/*  99 (0x63) */ {"dadd\0",			0},
/* 100 (0x64) */ {"isub\0",			0},
/* 101 (0x65) */ {"lsub\0",			0},
/* 102 (0x66) */ {"fsub\0",			0},
/* 103 (0x67) */ {"dsub\0",			0},
/* 104 (0x68) */ {"imul\0",			0},
/* 105 (0x69) */ {"lmul\0",			0},
/* 106 (0x6a) */ {"fmul\0",			0},
/* 107 (0x6b) */ {"dmul\0",			0},
/* 108 (0x6c) */ {"idiv\0",			0},
/* 109 (0x6d) */ {"ldiv\0",			0},
/* 110 (0x6e) */ {"fdiv\0",			0},
/* 111 (0x6f) */ {"ddiv\0",			0},
/* 112 (0x70) */ {"irem\0",			0},
/* 113 (0x71) */ {"lrem\0",			0},
/* 114 (0x72) */ {"frem\0",			0},
/* 115 (0x73) */ {"drem\0",			0},
/* 116 (0x74) */ {"ineg\0",			0},
/* 117 (0x75) */ {"lneg\0",			0},
/* 118 (0x76) */ {"fneg\0",			0},
/* 119 (0x77) */ {"dneg\0",			0},
/* 120 (0x78) */ {"ishl\0",			0},
/* 121 (0x79) */ {"lshl\0",			0},
/* 122 (0x7a) */ {"ishr\0",			0},
/* 123 (0x7b) */ {"lshr\0",			0},
/* 124 (0x7c) */ {"iushr\0",			0},
/* 125 (0x7d) */ {"lushr\0",			0},
/* 126 (0x7e) */ {"iand\0",			0},
/* 127 (0x7f) */ {"land\0",			0},
/* 128 (0x80) */ {"ior\0",			0},
/* 129 (0x81) */ {"lor\0",			0},
/* 130 (0x82) */ {"ixor\0",			0},
/* 131 (0x83) */ {"lxor\0",			0},
/* 132 (0x84) */ {"iinc\0",           1},
/* 133 (0x85) */ {"i2l\0",			0},
/* 134 (0x86) */ {"i2f\0",			0},
/* 135 (0x87) */ {"i2d\0",			0},
/* 136 (0x88) */ {"l2i\0",			0},
/* 137 (0x89) */ {"l2f\0",			0},
/* 138 (0x8a) */ {"l2d\0",			0},
/* 139 (0x8b) */ {"f2i\0",			0},
/* 140 (0x8c) */ {"f2l\0",			0},
/* 141 (0x8d) */ {"f2d\0",			0},
/* 142 (0x8e) */ {"d2i\0",			0},
/* 143 (0x8f) */ {"d2l\0",			0},
/* 144 (0x90) */ {"d2f\0",			0},
/* 145 (0x91) */ {"i2b\0",			0},
/* 146 (0x92) */ {"i2c\0",			0},
/* 147 (0x93) */ {"i2s\0",			0},
/* 148 (0x94) */ {"lcmp\0",			0},
/* 149 (0x95) */ {"fcmpl\0",			0},
/* 150 (0x96) */ {"fcmpg\0",			0},
/* 151 (0x97) */ {"dcmpl\0",			0},
/* 152 (0x98) */ {"dcmpg\0",			0},
/* 153 (0x99) */ {"ifeq\0",           2},
/* 154 (0x9a) */ {"ifne\0",           2},
/* 155 (0x9b) */ {"iflt\0",           2},
/* 156 (0x9c) */ {"ifge\0",           2},
/* 157 (0x9d) */ {"ifgt\0",           2},
/* 158 (0x9e) */ {"ifle\0",           2},
/* 159 (0x9f) */ {"if_icmpeq\0",      2},
/* 160 (0xa0) */ {"if_icmpne\0",      2},
/* 161 (0xa1) */ {"if_icmplt\0",      2},
/* 162 (0xa2) */ {"if_icmpge\0",      2},
/* 163 (0xa3) */ {"if_icmpgt\0",      2},
/* 164 (0xa4) */ {"if_icmple\0",      2},
/* 165 (0xa5) */ {"if_acmpeq\0",      2},
/* 166 (0xa6) */ {"if_acmpne\0",      2},
/* 167 (0xa7) */ {"goto \0",          2},
/* 168 (0xa8) */ {"jsr\0",            2},
/* 169 (0xa9) */ {"ret\0",            1},
/* 170 (0xaa) */ {"tableswitch\0",    6},
/* 171 (0xab) */ {"lookupswitch\0",   6},
/* 172 (0xac) */ {"ireturn\0",        0},
/* 173 (0xad) */ {"lreturn\0",        0},
/* 174 (0xae) */ {"freturn\0",		0},
/* 175 (0xaf) */ {"dreturn\0",		0},
/* 176 (0xb0) */ {"areturn\0",		0},
/* 177 (0xb1) */ {"return\0",			0},
/* 178 (0xb2) */ {"getstatic\0",      2},
/* 179 (0xb3) */ {"putstatic\0",      2},
/* 180 (0xb4) */ {"getfield\0",		2},
/* 181 (0xb5) */ {"putfield\0",		  2},
/* 182 (0xb6) */ {"invokevirtual\0",	  2},
/* 183 (0xb7) */ {"invokespecial\0",	  2},
/* 184 (0xb8) */ {"invokestatic\0",	  2},
/* 185 (0xb9) */ {"invokeinterface\0",  4},
/* 186 (0xba) */ {"invokedynamic\0",    4},
/* 187 (0xbb) */ {"new\0",			  2},
/* 188 (0xbc) */ {"newarray\0",		  1},
/* 189 (0xbd) */ {"anewarray\0",		  2},
/* 190 (0xbe) */ {"arraylength\0",      0},
/* 191 (0xbf) */ {"athrow\0",			  0},
/* 192 (0xc0) */ {"checkcast\0",		  2},
/* 193 (0xc1) */ {"instanceof\0",		  2},
/* 194 (0xc2) */ {"monitorenter\0",     0},
/* 195 (0xc3) */ {"monitorexit\0",	  0},
/* 196 (0xc4) */ {"wide\0",			  5},
/* 197 (0xc5) */ {"multianewarray\0",	  3},
/* 198 (0xc6) */ {"ifnull\0",         2},
/* 199 (0xc7) */ {"ifnonnull\0",      2},
/* 200 (0xc8) */ {"goto_w\0",	        4},
/* 201 (0xc9) */ {"jsr_w\0",          4},
/* 202 (0xca) */ {"breakpoint\0",     0},	/* Reserved opcodes start here */
/* 203 (0xcb) */ {"?203?\0",          0},
/* 204 (0xcc) */ {"?204?\0",	        0},
/* 205 (0xcd) */ {"?205?\0",          0},
/* 206 (0xce) */ {"?206?\0",          0},
/* 207 (0xcf) */ {"?207?\0",          0},
/* 208 (0xd0) */ {"?208?\0",          0},
/* 209 (0xd1) */ {"ret_w\0",          2},
/* 210 (0xd2) */ {"?210?\0",       0},
/* 211 (0xd3) */ {"?211?\0",       0},
/* 212 (0xd4) */ {"?212?\0",       0},
/* 213 (0xd5) */ {"?213?\0",       0},
/* 214 (0xd6) */ {"?214?\0",       0},
/* 215 (0xd7) */ {"?215?\0",       0},
/* 216 (0xd8) */ {"?216?\0",       0},
/* 217 (0xd9) */ {"?217?\0",       0},
/* 218 (0xda) */ {"?218?\0",       0},
/* 219 (0xdb) */ {"?219?\0",       0},
/* 220 (0xdc) */ {"?220?\0",       0},
/* 221 (0xdd) */ {"?221?\0",       0},
/* 222 (0xde) */ {"?222?\0",       0},
/* 223 (0xdf) */ {"?223?\0",       0},
/* 224 (0xe0) */ {"?224?\0",       0},
/* 225 (0xe1) */ {"?225?\0",       0},
/* 226 (0xe2) */ {"?226?\0",       0},
/* 227 (0xe3) */ {"?227?\0",       0},
/* 228 (0xe4) */ {"?228?\0",       0},
/* 229 (0xe5) */ {"?229?\0",       0},
/* 230 (0xe6) */ {"?230?\0",       0},
/* 231 (0xe7) */ {"?231?\0",       0},
/* 232 (0xe8) */ {"?232?\0",       0},
/* 233 (0xe9) */ {"?233?\0",       0},
/* 234 (0xea) */ {"?234?\0",       0},
/* 235 (0xeb) */ {"?235?\0",       0},
/* 236 (0xec) */ {"?236?\0",       0},
/* 237 (0xed) */ {"?237?\0",       0},
/* 238 (0xee) */ {"?238?\0",       0},
/* 239 (0xef) */ {"?239?\0",       0},
/* 240 (0xf0) */ {"?240?\0",       0},
/* 241 (0xf1) */ {"?241?\0",       0},
/* 242 (0xf2) */ {"?242?\0",       0},
/* 243 (0xf3) */ {"?243?\0",       0},
/* 244 (0xf4) */ {"?244?\0",       0},
/* 245 (0xf5) */ {"?245?\0",       0},
/* 246 (0xf6) */ {"?246?\0",       0},
/* 247 (0xf7) */ {"?247?\0",       0},
/* 248 (0xf8) */ {"?248?\0",       0},
/* 249 (0xf9) */ {"?249?\0",       0},
/* 250 (0xfa) */ {"?250?\0",       0},
/* 251 (0xfb) */ {"?251?\0",       0},
/* 252 (0xfc) */ {"?252?\0",       0},
/* 253 (0xfd) */ {"?253?\0",       0},
/* 254 (0xfe) */ {"impdep1\0",     0},
/* 255 (0xff) */ {"impdep2\0",     0}
	};
    return opcodes[i];
}

int print_mnemonic(opcodeT opcode, u1 *code, u4 index){
    int i = opcode.attributes_number,j, retorno, offset;
    opcodeT trash2;
    u4 def, low, hi, init = index, valor, npair;

	retorno = 0;
    printf("\n%s ", opcode.name);
    switch (i){

    case 0:

        break;


    case 1:
        for (j = 0; j < i; j++){
            printf("%#X ", code[index+j]);
        }
        retorno = i;
        printf("\n");
        break;

    case 2:
        for (j = 0; j < i; j++){
            printf("%#X ", code[index+j]);
        }
        retorno = i;
        printf("\n");
        break;

    case 3:
        for (j = 0; j < i; j++){
            printf("%#X ", code[index+j]);
        }
        retorno = i;
        printf("\n");
        break;
    case 4:
        for (j = 0; j < i; j++){
            printf("%#X ", code[index+j]);
        }
        retorno = i;
        printf("\n");
        break;

    case 5:
        trash2 = verifica_opcode(code[index]);
        printf(" %s", trash2.name);
        j = trash2.attributes_number * 2;
        for (j = 0; j < i; j++){
            printf("%#X ", code[index+j+1]);
        }
        retorno = j+1;
        printf("\n");
        break;

    default:
        if (strcmp ("tableswitch", opcode.name) == 0){
            if (index % 4 != 0){
                index += 4 - (index % 4);
            }
            def = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] << 24)));
            index = index+4;
            low = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] << 24)));
            index = index+4;
            hi = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] << 24)));
            index = index+4;
            printf(" %#X %#X\n", low, hi);
            offset = hi - low +1;
            for (i = 0; i < offset; i++){
                valor = (((code[index+3]) << 24) + (code[index+2] << 16) + (code[index+1] << 8) + ((code[index])));
                printf(" %#X", valor);
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
            printf("%d\n",npair);
            for (i = 0; i < npair; i++){
                valor = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] << 24)));
                index = index+4;
                offset = (((code[index+3])) + (code[index+2] << 8) + (code[index+1] << 16) + ((code[index] << 24)));
                index = index+4;
                printf("\t%d +%#X\n", valor, offset);
            }
            printf("\tdefault +%d\n",def);
        }
        retorno = index - init;
        break;
    }
    return retorno;

}

void print_code(u1 *code, u4 count){
    u4 i =0;
    opcodeT opcode;
    int num_bytes = 0;

    for (i=0; i< count; i++){

        opcode = verifica_opcode(code[i]);
        num_bytes =  print_mnemonic(opcode, code, i+1);
        i += num_bytes;
    }
	printf("\n");
}
