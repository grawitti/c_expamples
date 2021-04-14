#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define PORT 5000

char *daytime() {
	time_t now;
	now = time(NULL);
	return ctime(&now);
}

int main() {
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = INADDR_ANY;

	int sock, c_sock;

	if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("Socket error");
		exit(1);
	}

	int serror = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
	if (serror < 0) {
		perror("Bind error");
		exit(1);
	}

	for (;;) {
		struct sockaddr from;
		unsigned int len = sizeof(from);
		char buf[81];
		memset(buf, 0, 81);
		recvfrom(sock, &buf, 80, 0, &from, &len);
		printf("udp incoming:%s", buf);

		memset(buf, 0, 81);
		strncpy(buf, daytime(), 80);

		sendto(sock, buf, strlen(buf), 0, &from, len);
		puts("\nanswer udp");
	}
	return 0;
}
