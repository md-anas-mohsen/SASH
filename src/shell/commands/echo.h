#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void echo(char** arguments) {
	int arg_number = 1;
	char* argument;
	argument = arguments[arg_number];

	printf("\n");
	while (argument) {
		int first_index = 0, last_index = strlen(argument)-1;
		if (argument[first_index] == '"') {
			argument = argument + 1;
		}
		if (argument[last_index-1] == '"') {
			argument[last_index-1] = '\0';
		}
		printf("%s ", argument);
		arg_number++;
		argument = arguments[arg_number];
	}
	printf("\n");
}

// int echo(char** arguments) {
// 	int arg_number = 2;
// 	char* argument;
// 	argument = arguments[arg_number];
// 	// char* text_to_write = malloc(sizeof(char) * 200);
// 	char text_to_write[200];
// 	char* file_path = malloc(sizeof(char) * 200);
// 	int WRITE_TO_SCREEN = 1;

// 	strcpy(text_to_write, arguments[1]);
// 	while (argument) {
// 		if (strcmp(argument, ">") == 0) {
// 			arg_number++;
// 			WRITE_TO_SCREEN = 0;
// 			break;
// 		}

// 		strcat(&text_to_write, " ");
// 		strcat(&text_to_write, argument);
// 		arg_number++;
// 		argument = arguments[arg_number];
// 	}
	
// 	// text_to_write[strlen(text_to_write)-1] = '\0';
// 	if (WRITE_TO_SCREEN > 0) {
// 		printf("\n%s\n", text_to_write);
// 		return 0;
// 	} else {
// 		if (argument) {
// 			strcpy(file_path, arguments[arg_number]);
// 			arg_number++;
// 			argument = arguments[arg_number];
// 			while (argument) {
// 				strcat(file_path, " ");
// 				strcat(file_path, argument);
// 				arg_number++;
// 				argument = arguments[arg_number];
// 			}

// 			file_path[strlen(file_path)-1] = '\0';
// 			FILE *fd;
// 		    fd=fopen(file_path,"w");
// 		    if (fd) {
// 		    	printf("text written to file: %s\n", text_to_write);
// 		    	fprintf(fd, "%s\n", text_to_write);
// 		    	fflush(fd);
// 		    	fclose(fd);
// 		    	return 0;
// 		    }	
// 		} else {
// 			printf("[ERROR] Invalid file path.");
// 		}
		
// 	}
// }