#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	uint32_t ip = 0;
	int ret = 1;
	char *str_addr = "192.168.1.1";
// Переводим строку с адресом в тип uint32_t == sa_addr
	ret = inet_pton(AF_INET, str_addr, &ip);
	if(ret < 0){
		printf("Error: %s\n",strerror(errno));
		return ret;
	}
	if(ret == 0){
		printf("Error: unavalable address string: %s\n",str_addr);
		return ret;
	}
	printf("IP uint32_t:%i\n",ip);

	char str[16];
// Переводим значение адреса из uint32_t обратно в строку
	if(inet_ntop(AF_INET, &ip, str, 16) == NULL) {
		printf("Error: %s\n",strerror(errno));
		return -1;
	}
	printf("IP str:%s\n",str);

	return 0;
}
