#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>


void rm(char**arguments)
{

  
  if(remove(arguments[1]) != 0)
  {
	fprintf(stderr, "Errno: %d\n", errno);
	perror("[ERROR]");
  }
  else printf("%s deleted \n",arguments[1]);
	
}
