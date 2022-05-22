#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUF 200

void get_pwd(void) {
	char path[MAX_BUF];

	errno = 0;

	if (getcwd(path, MAX_BUF) == NULL) {
		if (errno == ERANGE) {
			printf("[ERROR] pathname exceeds the buffer size");
		} else {
			perror("getcwd");
		}
	}
	printf("\n%s\n", path);
}