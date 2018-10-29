/* Sliding Window Acknowledgement
13516120 Nuha Adinata
13516135 Untung Tanujaya
13516141 Ilham Wahabi


*/

#include <iostream>
using namespace std;

class Ack {
private:
    char ack;
    int nextSeqNum;
    char checksum;
public:
    Ack(char ack, int nextSeqNum, char checksum);
    ~Ack();
};

Ack::Ack(char ack, int nextSeqNum, char checksum) {
    this->ack = ack;
    this->nextSeqNum = nextSeqNum;
    this->checksum = checksum;
}

Ack::~Ack() {}
