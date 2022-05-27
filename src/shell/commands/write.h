#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>


int write_to_file(char** arguments) {
	int arg_number = 2;
	char* argument;
	argument = arguments[arg_number];
	char* file_path = malloc(sizeof(char) * 200);
	struct stat st = {0};

	strcpy(file_path, arguments[1]);
	while (argument) {
		strcat(file_path, " ");
		strcat(file_path, argument);
		arg_number++;
		argument = arguments[arg_number];
	}

	
	file_path[strlen(file_path)-1] = '\0';
	if (stat(file_path, &st) != 0) {
		printf("\n[ERROR] No such file exists. Create it first.\n");
		return 1;
	}

	FILE *fp;
	char ch;

	fp = fopen(file_path, "w");

	if (fp != NULL) {
		printf("Write Some text:\n ");

		while (1) {
			scanf("%c", &ch);
			if (ch == '\n') {
				break;
			} else {
				fprintf(fp, "%c", ch);		
			}
		}
		fclose(fp);
	} else {
		printf("[ERROR] Could not write to file.");
	}

	return 0;
}