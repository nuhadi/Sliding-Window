#include <iostream>
#include <stdlib.h>
#include <thread>
#include <mutex>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdexcept>
#include <unistd.h>

#include "Packet.cpp"
#include "Ack.cpp"
#include "util.cpp"

using namespace std;

int main(int argc, char** argv) {
  if (argc < 6) die("<filename> <windowsize> <buffersize> <destination_ip> <destination_port>");

  // Lakukan pembacaan file

  // Buat penampung untuk semua paket yang dikirim sejumlah window

  // Lakukan pengiriman semua paket sejumlah window dalam secara sekuens

  // Jika ada kesalahan lakukan pengiriman ulang untuk data tersebut

  return 0;
}