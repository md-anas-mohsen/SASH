#include <stdio.h>
#include <string.h>

#include "commands/echo.h"
#include "commands/pwd.h"
#include "commands/ls.h"
#include "commands/chdir.h"
#include "commands/mkdir.h"
#include "commands/rmdir.h"
#include "commands/touch.h"
#include "commands/cat.h"
#include "commands/rm.h"
#include "commands/copy.h"
#include "commands/write.h"
#include "commands/help.h"



#define ARG_CAPACITY 16

int strings_equal(char* input, char* command) {
	return strcmp(input, command) == 0; 
}

void execute_args(char** arguments, char* line) {
	char* command = arguments[0];

	//TODO: ADD MORE CASES FOR OTHER COMMANDS HERE
	if (strings_equal(command, "echo")) {
		echo(arguments);
	} else if(strings_equal(command, "cd")) {
		change_dir(arguments);
		get_pwd();
	} else if (strings_equal(command, "mkdir")) {
		create_directory(arguments);
	} else if (strings_equal(command, "rmdir")) {
		remove_directory(arguments);
	} else if (strings_equal(command, "touch")) {
		touch(arguments);
	}
	else if (strings_equal(command, "cat")) {
		cat(arguments);
	} else if (strings_equal(command, "rm")) {
		rm(arguments);
	} else if(strings_equal(command, "copy")) {
		copy_file(arguments);
	} else if(strings_equal(command, "writeto")) {
		write_to_file(arguments);
	} else {
		command = line;
		line[strlen(line)-1] = '\0';
		if(strings_equal(command, "pwd")) {
			get_pwd();
		} else if (strings_equal(command, "ls")) {
			list_dir();
		} else if(strings_equal(command, "exit")) {
			exit(0);
		} else if (strings_equal(command, "help")) {
			show_help();
		} else {
			printf("[ERROR] Command does not exist.\n");
		}
	}

}

int loop() {
	printf("|----- S A S H (Shahreyar and Anas Shell) ------|\n");
	printf("|Welcome to SASH! the best shell on the planet! |\n");
	printf("|----Coded by Anas Mohsen and Shahreyar Raza----|\n\n");
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

		execute_args(arguments, line);

		// int i;
		// for (i = 0; i < (arg_number+1); ++i) {
		// 	printf("arg[%d]: %s\n", i, arguments[i]);
		// }

		free(arguments);
		free(line);
	}
}
