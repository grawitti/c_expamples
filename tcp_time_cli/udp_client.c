#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define IP "127.0.0.1"

int main() {
	int sockfd;
	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket error");
		exit(1);
	}
	printf("The socket application is up and running\n");

	struct sockaddr_in server_addr, client_addr={AF_INET,INADDR_ANY,INADDR_ANY};
	memset(&server_addr, 0, sizeof(struct sockaddr_in));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr(IP);

	int serror = bind(sockfd, (struct sockaddr *)&client_addr, sizeof(struct sockaddr_in));
	if (serror < 0) {
		perror("bind error");
		exit(1);
	}

	char buf[81];
	memset(buf,0,81);
	strcpy(buf,"sldghosihgosbegsoebg osheosei121854%$^#");

	sendto(sockfd, &buf, strlen(buf), 0, (struct sockaddr *)&server_addr \
		   	,sizeof(struct sockaddr_in));
	
	memset(buf,0,81);

	recvfrom(sockfd,buf,80,0,NULL,0);

	puts(buf);

	int error = close(sockfd);
	if (error == -1) {
		perror("close");
		exit(1);
	}
	return 0;
}
