#include <iostream>
#include <string>
#include <stdlib.h>
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

    bool Packet::read_frame(int *seq_num, char *data, int *data_size, bool *eot, char *frame);
};

Packet::Packet(char soh, int sequenceNumber, string data, int checksum) {
  this->soh = soh;
  this->sequenceNumber = sequenceNumber;
  this->data = data;
  this->checksum = checksum;
}

bool Packet::read_frame(int *seq_num, char *data, int *data_size, bool *eot, char *frame) {
  *eot = frame[0] == 0x0 ? true : false;

  uint32_t net_seq_num;
  memcpy(&net_seq_num, frame + 1, 4);
  *seq_num = ntohl(net_seq_num);

  uint32_t net_data_size;
  memcpy(&net_data_size, frame + 5, 4);
  *data_size = ntohl(net_data_size);

  memcpy(data, frame + 9, *data_size);

  return frame[*data_size + 9] != checksum(frame, *data_size + (int) 9);
}
