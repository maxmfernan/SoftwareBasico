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
         
        //output_line = memset(output_line, 0, 256);
        //strcat(output_line, "\"");
        //strcat(output_line, output_linecp);
        //strcat(output_line, "\"");
        //strcat(output_line, ", ");
        //printf("\n B: %s", output_line);
        fputs("case ", ofilep);
        fputs(output_line, ofilep);
        fputs(": ", ofilep);
        //if( counter % 5 == 0 )
        //    fputs("\n\t", ofilep);
        fputs("\n", ofilep);

        memset(output_line, 0, 256);
        printf("\nB: %s", output_line);

        strcpy( output_line, "opcodes_str_names[" );
        printf("\nB: %s", output_line);

        //strcat(output_line,"op_");
        //printf("\nB: %s", output_line);

        strcat(output_line, output_linecp);
        strcat(output_line, "]");
        printf("\nB: %s", output_line);

        memset(output_linecp, 0, 256);
        strcpy( output_linecp, "printf(\"%s\\n\", " ); 
        strcat( output_linecp, output_line);
        strcat( output_linecp, ");\n");
        fputs("\t", ofilep); 
        fputs(output_linecp, ofilep);
        fputs("\tbreak;\n", ofilep);
        


        //strcat(output_linecp,    
        
        //output_line = strtok(output_linecp, "op_");
        //strcpy(output_linecp, output_line); //retorna um ponteiro para a string copiada, mas já recebo no parâmetro.
        //printf("\n\n B: %s", output_linecp);

    FILE *fp = fopen("ocases.txt", "wt");
    char *str_0 = malloc( 256*sizeof(char) );
    str_0 = "case ";
    for(int i = 0; i < 203; i++){
       
    }  

    }
         
    
    return 0;
}
