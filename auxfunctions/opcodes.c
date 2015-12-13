#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char *line = malloc( 256*sizeof(char) );
    FILE *filep = fopen(argv[1], "rt");
    char *output_line = malloc( 256*sizeof(char) ); 
    char *output_linecp = malloc( 256*sizeof(char) );
    FILE *ofilep = fopen("opcodes_array.txt", "wt");
    int counter = 0;
    while( fgets(line, 256, filep) != NULL ){
        counter++;
        printf("\n0 : %s", line);
        output_line = strtok(line, " ");
        strcpy(output_linecp, output_line);
        printf("\n A: %s", output_linecp);
        strcat(output_linecp, ",");
        printf("\n B: %s", output_linecp);
        
        fputs(output_linecp, ofilep);
        if( counter % 5 == 0 )
            fputs("\n\t", ofilep);
        //output_line = strtok(output_linecp, "op_");
        //strcpy(output_linecp, output_line); //retorna um ponteiro para a string copiada, mas já recebo no parâmetro.
        //printf("\n\n B: %s", output_linecp);


    }
         
    
    return 0;
}
