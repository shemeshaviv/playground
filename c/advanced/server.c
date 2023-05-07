// Server side C/C++ program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080
#define MAX_DATETIME_STRING_SIZE 20
#define BUFFER_SIZE 1024
#define MAX_MESSAGES 5

char* getDateTimeNow()
{
    time_t currentTime = time(NULL);
    struct tm now = *localtime(&currentTime);
    char* formatted = (char*)malloc(MAX_DATETIME_STRING_SIZE * sizeof(char));
    sprintf(formatted,"%d-%02d-%02d %02d:%02d:%02d",now.tm_year+1900,now.tm_mon+1,
                      now.tm_mday,now.tm_hour,now.tm_min,now.tm_sec);
    return formatted;
}

int main(int argc, char const* argv[])
{
	int server_fd, sockopt_ret, new_socket, valread;
	struct sockaddr_in address;
	int optval = 1;
    int msg_count = 0;
	int addrlen = sizeof(address);
	char buffer[BUFFER_SIZE] = { 0 };
	char* msg_to_client = NULL;                 //"Message from server";
    msg_to_client = (char*)malloc(BUFFER_SIZE * sizeof(char));

	// (1) Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0) 
    {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
    printf("Socket file-descriptor created (server_fd=%d)\n", server_fd);

	// The settings of sockopt here is not mandatory (At least when working on Linux)
	/* 
    sockopt_ret= setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optval, sizeof(optval));
    if(sockopt_ret)
    {
		perror("setsockopt failed");
		exit(EXIT_FAILURE);
	}
    printf("Attached socket successfully (sockopt_ret=%d)\n", sockopt_ret);
    */

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Binding with the sockaddr address information 
	if (bind(server_fd, (struct sockaddr*)&address,	sizeof(address)) < 0) 
    {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
    printf("Bind successfully\n");

	if (listen(server_fd, SOMAXCONN) < 0) 
    {
		perror("listen");
		exit(EXIT_FAILURE);
	}

    while(msg_count < MAX_MESSAGES)    // Limiting the amount of messages just for testings clean exit 
    {
        printf("Listening... (Press CTRL+C to exit)\n");

        new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*) &addrlen); 
        if (new_socket < 0) 
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("<<< Message accepted successfully at %s (socket= %d, msg #%d)\n", getDateTimeNow(), new_socket, ++msg_count);
        valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("<<< Content of message recieved from client (valread=%d). Buffer content: %s\n", valread, buffer);

        sprintf(msg_to_client, "Message to client from server. %d messages recieved", msg_count);
        send(new_socket, msg_to_client, strlen(msg_to_client), 0);
        printf(">>> Reply message sent to client\n");
    }
    printf("Maximum messages reached. Closing connected socket and exitting\n");
	// closing the connected socket
	close(new_socket);
	// closing the listening socket
	shutdown(server_fd, SHUT_RDWR);
	return 0;
}

