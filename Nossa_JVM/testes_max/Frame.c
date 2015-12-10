//
//  Frame.c
//  
//
//  Created by Luiz Henrique Campos Barboza on 09/12/15.
//
//

#include <stdio.h>

void alocaFrame(Frame **frame, int N) {
    *frame = (*Frame) malloc (N * sizeof(Frame));
    
}


void initFrame(Frame **frame) {
    *frame->pClass = NULL;
    *frame->pc=0;
    *frame->stack = NULL;
    *frame->local = NULL;
}

void setSP(Frame **frame, u2 sp) {
    *frame->sp=sp;
    *frame->pClass = NULL;
    *frame->pc=0;
    *frame->stack = NULL;
}