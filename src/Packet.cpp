#include <iostream>
#include <string>
using namespace std;

class Packet {
  private:
    char soh;
    int sequenceNumber;
    int dataLength;
    string data;
    int checksum;

  public:
    Packet(char soh, int sequenceNumber, string data, int checksum);
};

Packet::Packet(char soh, int sequenceNumber, string data, int checksum) {
  this->soh = soh;
  this->sequenceNumber = sequenceNumber;
  this->data = data;
  this->checksum = checksum;
}
