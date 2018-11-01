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
    struct sockaddr_in recvAddr, sendAddr;

    // init buffer and message
    char buffer[MAXLINE];
    char* ack = (char*)"Pura-puranya ack";

    // creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&recvAddr, 0, sizeof(recvAddr));
    memset(&sendAddr, 0, sizeof(sendAddr));

    // filling server information
    recvAddr.sin_family = AF_INET;
    recvAddr.sin_addr.s_addr = INADDR_ANY;
    recvAddr.sin_port = htons(port);

    // binding socket with server addrress
    if ((bind(sockfd, (const struct sockaddr *) &recvAddr,  sizeof(recvAddr))) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int n;
        socklen_t nCli;
        n = recvfrom(sockfd, (char*) buffer, nBuff, MSG_WAITALL, (struct sockaddr *) &sendAddr, &nCli);
        buffer[n] = '\0';
        printf("Client : %s\n", buffer);
        sendto(sockfd, (const char*) ack, strlen(ack), 0, (const struct sockaddr *) &sendAddr, nCli);
        printf("Ack sent \n");
    }

    close(sockfd);
    return 0;
}
