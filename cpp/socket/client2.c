#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int sockfd;
	int len;

	struct sockaddr_un address;
	int result;
	char *str = "Hello";
	char ch = 'A';
	char s[10] = "Hello";

	*(s + 4) = 'P';

	printf("%s\n", s);


	int bytes;

	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_socket");

	len = sizeof(address);

	result = connect(sockfd, (struct sockaddr *)&address, len);
	if (result == -1) {
		printf("oops: client1");
		exit(1);
	}

	write(sockfd, &ch, 2);
	bytes = read(sockfd, s, 6);
	printf("types = %d\t char from server = %s\n", bytes, s);
	close(sockfd);
	exit(0);
}
