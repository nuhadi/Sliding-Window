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

#include "Packet.cpp"
#include "Ack.cpp"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 5) {
        die("wrong input");
    }

    // read from argument
    char* fileName = argv[1];
    int rWS = charToInt(argv[2]);
    int nBuff = charToInt(argv[3]);
    int port = charToInt(argv[4]);
    struct sockaddr_in recvAddr, sendAddr;

    // creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        die("Socket creation failed");
    }

    // making time for sliding window
	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 255000;
	setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
	
    // fill recv and send address in memory
    memset(&recvAddr, 0, sizeof(recvAddr));
    memset(&sendAddr, 0, sizeof(sendAddr));

    // filling server information
    recvAddr.sin_family = AF_INET;
    recvAddr.sin_addr.s_addr = htons(INADDR_ANY);
    recvAddr.sin_port = htons(port);

    // binding socket with server addrress

    if (::bind(sockfd, (struct sockaddr *) &recvAddr,  sizeof(recvAddr)) < 0) {
        die("bind failed");
    }

    // open file
    FILE* file = fopen(fileName, "w");

    // Initialize sliding window variables
    char frame[MAXFRAME];
    char data[MAX_DATA_SIZE];
    char ack[ACK_SIZE];
    int frame_size;
    int data_size;
    int lfr, laf;
    int recv_seq_num;
    bool eot;
    bool frame_error;

    // receive file
    bool recv_done = false;
    int buffer_num = 0;
    while (!recv_done) {
        buffer_size = max_buffer_size;
        memset(buffer, 0, buffer_size);
    
        int recv_seq_count = (int) max_buffer_size / MAX_DATA_SIZE;
        bool window_recv_mask[window_len];
        for (int i = 0; i < window_len; i++) {
            window_recv_mask[i] = false;
        }
        lfr = -1;
        laf = lfr + window_len;

        while (1) {
            // recv from client (Packet)
            socklen_t nCli;
            char* raw_packet = new char [MAXLINE];
            frame_size = recvfrom(sockfd, raw_packet, MAXLINE, MSG_WAITALL, (struct sockaddr *) &sendAddr, &nCli);
            frame_error = read_frame(&recv_seq_num, data, &data_size, &eot, frame);

            for(size_t i = 0; i < n; i++)
            {
                cout << raw_packet[i];
            }

            // init buffer and message (ACK)
            char* ack = (char*) "Pura-puranya ack";

            // send to client
            if ((sendto(sockfd, (const char*) ack, strlen(ack), 0, (const struct sockaddr *) &sendAddr, nCli)) < 0) {
                die("failed to send message");
            }
            cout << "Ack sent" << endl;
        }
    }

        

    close(sockfd);
    return 0;
}
