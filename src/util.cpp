#include <iostream>
using namespace std;

int charToInt(char* s) {
    int n = 0;
    while (*s != 0)
        n = n * 10 + ((int) (*s++) - '0');
    return n;
}

void die(string msg) {
  cerr << msg << endl;
  exit(1);
}