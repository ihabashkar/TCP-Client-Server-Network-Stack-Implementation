CXX = c++
CXXFLAGS = -Wall -Wextra

all: server client

server: server.cpp
	$(CXX) $(CXXFLAGS) -o server server.cpp

client: client.cpp
	$(CXX) $(CXXFLAGS) -o client client.cpp

run-server: server
	./server

run-client: client
	./client

clean:
	rm -f server client
