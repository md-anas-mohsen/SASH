#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_LEN 1024

int file_stats(char** arguments) {
  /*Read the file.*/
  struct stat st = {0};

  int arg_number = 2;
  char* argument;
  argument = arguments[arg_number];
  char* file_path = malloc(sizeof(char) * 200);

  char ch;
  int char_count = 0, word_count = 0, line_count = 0;

  strcpy(file_path, arguments[1]);
  while (argument) {
    strcat(file_path, " ");
    strcat(file_path, argument);
    arg_number++;
    argument = arguments[arg_number];
  }
  
  file_path[strlen(file_path)-1] = '\0';

  if (stat(file_path, &st) == 0) {
    FILE *fp;

    fp = fopen(file_path, "r");

    if(fp == NULL) {
      printf("[ERROR] Failed to open the file\n");
      return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
      if (ch != '\n') {
        char_count++;  
      }
      

      if(ch == ' ' || ch == '\n') {
        word_count++;
        if(ch = '\0' || ch == '\n') {
          line_count++;
        }
      } 
    }

    printf("stats for file '%s':\n", file_path);
    printf("Number of characters (including spaces): %d\n", char_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);

    return 0;
    
  } else {
    printf("\n[ERROR] File does not exist or is empty.\n");
  }
  
}