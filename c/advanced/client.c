// Client side C/C++ program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
#define BUFFER_SIZE 1024
#define IP_ADDRESS "127.0.0.1"

int main(int argc, char const* argv[])
{
	int status, valread, client_fd;
	struct sockaddr_in serv_addr;
	//char* hello = "Hello from client";
	char buffer[BUFFER_SIZE] = { 0 };

    // (1) Setup socket client file-descriptor

	client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0)
    {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, IP_ADDRESS, &serv_addr.sin_addr) <= 0) 
    {
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

    status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if (status < 0) 
    {
		printf("\nConnection Failed \n");
		return -1;
	}
    char msg[BUFFER_SIZE];
    printf("Enter a message: ");
    fgets(msg, sizeof(msg), stdin);         // Input from keyboard 
	send(client_fd, msg, strlen(msg)-1, 0); // omitting the "\n" 

	printf("<<< Message sent: %s\n", msg);
	
    valread = read(client_fd, buffer, BUFFER_SIZE);
	printf(">>> Message recieved from server: %s\n", buffer);

	// closing the connected socket
	close(client_fd);
	return 0;
}

