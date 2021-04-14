#include <netinet/in.h>
#include <stdio.h>


int main () {

	const long ip_n = 15248;
	char str[16]; // по 3 цифры и точки между ними, и концевой 0

	const long ip = ntohl(ip_n);
	sprintf(str, "%u.%u.%u.%u", (ip>>24)&255, (ip>>16)&255, (ip>>8)&255, (ip)&255);

	int i;
	for(i=0; i<16; ++i){
		printf("%c",str[i]);
	}
	printf("\n");


	char const* str2;
	long ip_n2;
	int ok;

	unsigned b0, b1, b2, b3;
	ok = 4==sscanf(str2, "%i.%i.%i.%i", b3,b2,b1,b0); // %i принимает и 8-, и 10-, и 16-ричные числа
	long ip2 = (b3&255<<24) | (b2&255<<16) | (b1&255<<8) | (b0&255);

	ip_n2 = htonl(ip2);

	uint32_t l = 10;
	uint32_t s = 0xAABBCCDD;

	uint32_t net = htonl(l);
	printf("net_l: %u\n", net);

	uint32_t hl = ntohl(net);
	printf("host_l: %u\n", hl);

	uint32_t net16 = htonl(s);
	printf("net_s: %x\n", net16);

	uint32_t hs = ntohl(net16);
	printf("host_s: %x\n", hs);

	return 0;
}
