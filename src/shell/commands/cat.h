#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void cat(char** arguments)
{
  char *file_name = arguments[1];
  struct stat st = {0};
  FILE * fd;

  if (stat(file_name, &st) == 0) {
    fd=fopen(file_name,"r");

    if (fd != NULL) {
      char ch;
      while ((ch=fgetc(fd))!=EOF) {
        printf("%c",ch);
      }  

      fclose(fd);
    }
  } else {
    printf("\n[ERROR] File does not exist or is empty.\n");
  }
}
