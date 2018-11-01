#include <iostream>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdexcept>
#include <unistd.h>
#include "Packet.cpp"
#include "Ack.cpp"
using namespace std;

void die(string msg) {
  cerr << msg << endl;
  exit(1);
}

int main(int argc, char** argv) {
  if (argc < 6) die("<filename> <windowsize> <buffersize> <destination_ip> <destination_port>");

  // Lakukan pembacaan file

  // Buat penampung untuk semua paket yang dikirim sejumlah window

  // Lakukan pengiriman semua paket sejumlah window dalam secara sekuens

  // Jika ada kesalahan lakukan pengiriman ulang untuk data tersebut

  return 0;
}