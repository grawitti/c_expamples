#include <dirent.h>
#include <string.h>
#include <stdio.h>

int main() {
	const char* name = "dhclient";

	DIR* dir;
	struct dirent* ent;

	if ((dir = opendir("/var/run/")) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			if (strstr(ent->d_name, name)) {
				printf("%s\n", ent->d_name);
			}
		}
		closedir(dir);
	} else {
		perror("");
		return (-1);
	}

	return 0;
}
