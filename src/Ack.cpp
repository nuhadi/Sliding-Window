/* Sliding Window Acknowledgement
13516120 Nuha Adinata
13516135 Untung Tanujaya
13516141 Ilham Wahabi
*/

#define ACKLEN 6

#include <iostream>
#include <stdlib.h>
#include "util.cpp"
using namespace std;

class Ack {
private:
    char ack;
    uint32_t nextSeqNum;
    unsigned char checksum;
public:
    Ack(char ack, int nextSeqNum, bool error);
    ~Ack();
    // operations
    char* getRaw();
    void generateChecksum();
};

Ack::Ack(char ack, int nextSeqNum, bool error) {
    this->ack = error ? 0x0, 0x1;
    this->nextSeqNum = nextSeqNum;
    this->checksum = ;
}

Ack::~Ack() {}

char* Ack::getRaw() {
    // make array raw from ack info
    char* raw = new char [ACKLEN + 1];
    raw[ACKLEN] = '\0';
    raw[0] = this->ack;
    memcpy(raw + 1, &this->nextSeqNum, 4);
    raw[5] = this->checksum;
    return raw;
}
