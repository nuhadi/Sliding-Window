// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "Util.cpp"
using namespace std;

#define MAXLINE 1024

int main(int argc, char* argv[])
{
    if (argc < 5) {
        perror("wrong input");
        exit(EXIT_FAILURE);
    }

    // read from argument
    char* fName = argv[1];
    int rWS = charToInt(argv[2]);
    int nBuff = charToInt(argv[3]);
    int port = charToInt(argv[4]);
    struct sockaddr_in servAddr, cliAddr;

    // init buffer and message
    char buffer[MAXLINE];
    char* ack = (char*)"Pura-puranya ack";

    // creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servAddr, 0, sizeof(servAddr));
    memset(&cliAddr, 0, sizeof(cliAddr));

    // filling server information
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(port);

    // binding socket with server addrress
    if ((bind(sockfd, (const struct sockaddr *) &servAddr,  sizeof(servAddr))) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int n;
        socklen_t nCli;
        n = recvfrom(sockfd, (char*) buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &cliAddr, &nCli);
        buffer[n] = '\0';
        printf("Client : %s\n", buffer);
        sendto(sockfd, (const char*) ack, strlen(ack), 0, (const struct sockaddr *) &cliAddr, nCli);
        printf("Ack sent \n");
    }

    close(sockfd);
    return 0;
}
