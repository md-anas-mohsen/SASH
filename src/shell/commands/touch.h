#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void touch(char** arguments)
{
  struct stat st = {0};
  char *file_name = arguments[1];

  if (stat(file_name, &st) == 0) {
    printf("\n[ERROR] File with that name already exists.");
  } else {
    FILE *fd;
    fd=fopen(file_name,"w");
    fclose(fd);
  }
}
