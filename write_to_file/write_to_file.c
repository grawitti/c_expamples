#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

const char* OUT_FILE = "test";
const int BUF_SIZE = 1;

int main()
{
    int fd = -1;
    fd = open(OUT_FILE, O_WRONLY);
    if(fd == -1) {
	perror("Can't open file");
	return fd;
    }

    while(1) {
	char str[BUF_SIZE];

	printf("Enter the string: ");
	scanf("%s", str);

	if (write(fd, str, BUF_SIZE) != BUF_SIZE) {
	    perror("Write error");
	    close(fd);
	    return -2;
	}
    }

    close(fd);
    return 0;
}
