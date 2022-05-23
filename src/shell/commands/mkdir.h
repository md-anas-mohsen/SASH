#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void create_directory(char** arguments) {
	struct stat st = {0};

	int arg_number = 2;
	char* argument;
	argument = arguments[arg_number];
	char* new_directory = malloc(sizeof(char) * PATH_SIZE);

	strcpy(new_directory, arguments[1]);
	while (argument) {
		strcat(new_directory, " ");
		strcat(new_directory, argument);
		arg_number++;
		argument = arguments[arg_number];
	}
	
	new_directory[strlen(new_directory)-1] = '\0';

	if (stat(new_directory, &st) == -1) {
		mkdir(new_directory, 0700);
	} else {
		printf("\n[ERROR] Directory already exists.\n");
	}
}