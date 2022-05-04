#include <stdio.h>
#include <string.h>

#include "commands/echo.h"

#define ARG_CAPACITY 16

int strings_equal(char* input, char* command) {
	return strcmp(input, command) == 0; 
}

void execute_args(char** arguments) {
	char* command = arguments[0];

	//TODO: ADD MORE CASES FOR OTHER COMMANDS HERE
	if (strings_equal(command, "echo")) {
		echo(arguments);
	} else {
		printf("[ERROR] Command does not exist.\n");
	}

}

int loop() {
	printf("Welcome to SASH! the best shell on the planet! \n");
	while(1){
		printf("$ ");
		char *line = NULL;
		size_t len = 0;
		ssize_t lineSize = 0;
		char **arguments = malloc(ARG_CAPACITY * sizeof(char*));

		lineSize = getline(&line, &len, stdin);
		line[lineSize] = '\0';
		char *token = strtok(line, " ");
		int arg_number = 0;
		int buf_size = ARG_CAPACITY;

		while (token) {
			arguments[arg_number] = token;
			arg_number++;

			if (arg_number >= ARG_CAPACITY) {
				buf_size += ARG_CAPACITY;
				arguments = realloc(arguments, buf_size * sizeof(char*));
				if (arguments == NULL) {
					perror("[ERROR] Failed to parse arguments: Memory allocation error.");
					exit(1);
				}
			}

			token = strtok(NULL, " ");
		}

		arguments[arg_number] = NULL;

		execute_args(arguments);

		// int i;
		// for (i = 0; i < (arg_number+1); ++i) {
		// 	printf("arg[%d]: %s\n", i, arguments[i]);
		// }

		free(arguments);
		free(line);
	}
}