#include <stdio.h>
#include <string.h>

#define PATH_SIZE 200

void change_dir(char** arguments) {
	int arg_number = 2;
	char* argument;
	argument = arguments[arg_number];
	char* new_path = malloc(sizeof(char) * PATH_SIZE);

	strcpy(new_path, arguments[1]);
	while (argument) {
		strcat(new_path, " ");
		strcat(new_path, argument);
		arg_number++;
		argument = arguments[arg_number];
	}
	
	new_path[strlen(new_path)-1] = '\0';
	chdir(new_path);
}