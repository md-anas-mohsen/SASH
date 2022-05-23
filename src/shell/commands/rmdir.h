#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void remove_directory(char** arguments) {
	struct stat st = {0};

	int arg_number = 2;
	char* argument;
	argument = arguments[arg_number];
	char* directory = malloc(sizeof(char) * PATH_SIZE);

	strcpy(directory, arguments[1]);
	while (argument) {
		strcat(directory, " ");
		strcat(directory, argument);
		arg_number++;
		argument = arguments[arg_number];
	}
	
	directory[strlen(directory)-1] = '\0';

	if (stat(directory, &st) == 0) {
		if (rmdir(directory) == -1) {
			printf("\n[ERROR] Cannot delete this directory. Directory must be empty.\n");
		}
	} else {
		printf("\n[ERROR] No such directory exists.\n");
	}
}