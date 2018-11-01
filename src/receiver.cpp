// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>

#include "Util.cpp"
using namespace std;

#define MAXLINE 1024

int main(int argc, char* argv[]) {
    if (argc < 5) {
        die("wrong input");
    }

    // read from argument
    char* fName = argv[1];
    int rWS = charToInt(argv[2]);
    int nBuff = charToInt(argv[3]);
    int port = charToInt(argv[4]);
    struct sockaddr_in recvAddr, sendAddr;

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
        die("bind failed");
    }

    while (1) {
        // recv from client (Packet)
        int n;
        socklen_t nCli;
        char* raw_packet = new char [MAXLINE];
        n = recvfrom(sockfd, raw_packet, MAXLINE, MSG_WAITALL, (struct sockaddr *) &sendAddr, &nCli);
        for(size_t i = 0; i < n; i++)
        {
            cout << raw_packet[i];
        }

        // init buffer and message (ACK)
        char* ack = (char*) "Pura-puranya ack";

        // send to client
        if ((sendto(sockfd, (const char*) ack, strlen(ack), 0, (const struct sockaddr *) &sendAddr, nCli)) < 0) {
            die("failed to send message")
        }
        cout << "Ack sent" << endl;
    }

    close(sockfd);
    return 0;
}
