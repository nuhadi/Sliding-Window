<<<<<<< HEAD:Ack.cpp
/* Sliding Window Acknowledgement
13516120 Nuha Adinata
13516135 Untung Tanujaya
13516141 Ilham Wahabi
*/

#define ACKLEN 6

=======
>>>>>>> fc2c6938548798ad25cf1128b93819f11c267461:src/Ack.cpp
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
    // operations
    char* getRaw();
};

Ack::Ack(char ack, int nextSeqNum, char checksum) {
    this->ack = ack;
    this->nextSeqNum = nextSeqNum;
    this->checksum = checksum;
}

Ack::~Ack() {}

char* Ack::getRaw() {
    char* raw = new char [ACKLEN + 1];
    raw[ACKLEN] = '\0';
    raw[0] = ack;
    
    raw[5] = checksum;
    return raw;
}
