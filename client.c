#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
	int sockfd;
	int len;
	struct sockaddr_in addr;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = 9734;

	len = sizeof(addr);

	connect(sockfd, (struct sockaddr_in *)&addr, len);

	char a[256];

	printf("connected!\n");
	scanf("%s",a);
	int str_len = sizeof(a);

	write(sockfd,&a,str_len);
	read(sockfd,&a,str_len);

	printf("%s",a);
	close(sockfd);

}
