#include <iostream>
using namespace std;

class Ack {
private:
    char ack;
    int nextSeqNum;
    char checksum;
public:
    Ack(char ack, int nextSeqNum, char checksum) {
        this->ack = ack;
        this->nextSeqNum = nextSeqNum;
        this->checksum = checksum;
    }

    ~Ack() {};
};
