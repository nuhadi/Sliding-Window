#include <iostream>;
#include <string>;
using namespace std;

class Packet {
  private:
    char SOH;
    int sequenceNumber;
    int dataLength;
    string data;
    int checksum;

  public:
    Packet(char SOH, int sequenceNumber, string data, int checksum);
};

Packet::Packet(char SOH, int sequenceNumber, string data, int checksum) {
  this->SOH = SOH;
  this->sequenceNumber = sequenceNumber;
  this->data = data;
  this->checksum = checksum;
}
