all: recvfile sendfile

recvfile: src/receiver.cpp
	g++ -std=c++11 -pthread src/receiver.cpp -o recvfile

sendfile: src/sender.cpp
	g++ -std=c++11 -pthread src/sender.cpp -o sendfile

clean: recvfile sendfile
	rm -f recvfile sendfile
