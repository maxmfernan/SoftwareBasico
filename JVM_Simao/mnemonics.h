#ifndef MNEMONICS_H
#define MNEMONICS_H

#include <stdlib.h>
#include <stdio.h>

#include "types.h"

opcodeT verifica_opcode(u1 );

int print_mnemonic(opcodeT , u1 *, u4 );

void print_code(u1 *, u4 );

#endif
