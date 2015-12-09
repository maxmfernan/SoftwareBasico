//
//  main.c
//  
//
//  Created by Luiz Henrique Campos Barboza on 09/12/15.
//
//
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>


int main(){
    ClassFile* classHeap_ptr = malloc( sizeof( ClassFile ) );
    loadClass( classHeap_ptr );
    printf("\n\nConteudo do .class");
    printf("\n--------------------------------");
    print_ClassFile(classHeap_ptr);
    
    printf("%s\n",classHeap_ptr->className);
    
    return 0;
}
