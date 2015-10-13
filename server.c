#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int server_sockfd,client_sockfd;
	int server_len,client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	server_sockfd = socket(AF_INET,SOCK_STREAM,0);

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");			//127.0.0.1默认为localhost，即本机地址
	server_address.sin_port = 9734;
	server_len = sizeof(server_address);

	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	listen(server_sockfd,5);

	while(1)
	{
		client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd,(struct sockaddr_in *)&client_sockfd,&client_len);

		char ch[256];
		char a[]="accept!";
		read(client_sockfd,&ch,256);
		write(client_sockfd,&a,sizeof(a));
		printf("%s\n",ch);
		close(client_sockfd);

	}


	
}
