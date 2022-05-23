#include <stdio.h>
#include <dirent.h>

void list_dir(void) {
	DIR *d;

	struct dirent *dir;

	d = opendir(".");

	if (d) {
		while((dir = readdir(d)) != NULL) {
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
}