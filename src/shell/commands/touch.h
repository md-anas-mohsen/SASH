#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void touch(char** arguments)
{
  struct stat st = {0};

  int arg_number = 2;
  char* argument;
  argument = arguments[arg_number];
  char* file_path = malloc(sizeof(char) * PATH_SIZE);

  strcpy(file_path, arguments[1]);
  while (argument) {
    strcat(file_path, " ");
    strcat(file_path, argument);
    arg_number++;
    argument = arguments[arg_number];
  }
  
  file_path[strlen(file_path)-1] = '\0';

  if (stat(file_path, &st) == -1) {
    FILE *fd;
    fd=fopen(file_path,"w");
    fclose(fd);
  } else {
    printf("\n[ERROR] File already exists.\n");
  }
}
