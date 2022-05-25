#include<stdio.h>    
#include<stdlib.h>
    
void copy_file(char** arguments) {
    int arg_number = 2;
    char* argument;
    argument = arguments[arg_number];
    char* source_file = malloc(sizeof(char) * 25);

    strcpy(source_file, arguments[1]);
    while (argument) {
        strcat(source_file, " ");
        strcat(source_file, argument);
        arg_number++;
        argument = arguments[arg_number];
    }
    
    source_file[strlen(source_file)-1] = '\0';



    char ch, target_file[25];
    
    FILE *source, *target; 
    
    source = fopen(source_file, "r");
    
    if (source == NULL) {        
        printf("[ERROR] Invalid source file specified. Please make sure that the file exists.\n");
    } else {
        printf("Enter name of target file\n");
        gets(target_file);
        
        target = fopen(target_file, "w");
        
        if (target == NULL) {
            fclose(source);        
            printf("[ERROR] Invalid target file  name.\n");
        } else {
            while( ( ch = fgetc(source) ) != EOF ) {
                fputc(ch, target);
            }
            printf("[SUCCESS] File copied successfully.\n");        
            fclose(source);        
            fclose(target);
                
        }
    }
}