#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;

	struct sockaddr_un server_address;
	struct sockaddr_un client_address;

	//移除旧的socket并创建一个未命名的服务器socket
	unlink("server_socket");
	server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

	//命名socket
	server_address.sun_family = AF_UNIX;
	strcpy(server_address.sun_path, "server_socket");
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);	
	
	//创建连接队列并等待连接
	listen(server_sockfd, 5);	
	while (1) {
		char ch;
		printf("server waiting\n");

		//接收连接
		client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, (socklen_t *)&client_len);
		read(client_sockfd, &ch, 2);
		printf("%c\n", ch);
		write(client_sockfd, "hele", 5);
		close(client_sockfd);
	}
}
