int charToInt(char* s) {
    int n = 0;
    while (*s != 0)
        n = n * 10 + ((int) (*s++) - '0');
    return n;
}
