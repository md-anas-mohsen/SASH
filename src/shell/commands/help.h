#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void show_help() {
	printf("help - shows help\n");
	printf("cd 'path' - change directory to the path specified.\n");
	printf("mkdir 'folder_name' - create a new folder with specified name.\n");
	printf("rmdir 'folder_name' - deletes the folder, the folder must be empty\n");
	printf("echo 'any text'- prints to console.\n");
	printf("ls - shows the directory contents\n");
	printf("pwd - shows the current directory that we are on.\n");
	printf("touch 'file_name' - creates the file with specified name\n");
	printf("writeto 'file_name' - a prompt opens asking for text to be input. File is overwritten.\n");
	printf("copy 'file_name' - a prompt opens asking the name of the duplicate file.\n");
	printf("cat 'file_name' - show file contents\n");
	printf("rm 'file_name' - deletes the file.\n");
}