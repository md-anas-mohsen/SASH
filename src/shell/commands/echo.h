#include <stdio.h>
#include <string.h>

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