#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>


void rm(char**arguments)
{

  
 //  if(remove(arguments[1]) != 0)
 //  {
	// fprintf(stderr, "Errno: %d\n", errno);
	// perror("[ERROR]");
 //  }
 //  else printf("%s deleted \n",arguments[1]);
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

  if (stat(file_path, &st) == 0) {
    // FILE *fd;
    // fd=fopen(file_path,"r");
    // if (fd != NULL) {
    //   char ch;
    //   while ((ch=fgetc(fd))!=EOF) {
    //     printf("%c",ch);
    //   }  

    //   fclose(fd);
    //   printf("\n");
    // }
    // fclose(fd);
    if(remove(file_path) != 0) {
      fprintf(stderr, "Errno: %d\n", errno);
      perror("[ERROR]");
    }
    else printf("[DELETED] %s \n",arguments[1]);
  } else {
    printf("\n[ERROR] File does not exist.\n");
  }
	
}
