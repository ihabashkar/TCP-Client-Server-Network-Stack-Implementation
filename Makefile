CXX = g++
CXXFLAGS = -Wall -Wextra

all: client server


client: client.cpp
	$(CXX) $(CXXFLAGS) -o client client.cpp

server: server.cpp
	$(CXX) $(CXXFLAGS) -o server server.cpp

run-client: client
	./client

run-server: server
	./server

clean:
	rm -f client server
