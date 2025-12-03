#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <server_ip>\n";
        return 1;
    }

    const char* server_ip = argv[1];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Error creating socket.\n";
        return 1;
    }

    // Setup server address struct
    struct sockaddr_in server_addr;
    std::memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    // Convert IP string → binary form
    if (inet_pton(AF_INET, server_ip, &(server_addr.sin_addr)) <= 0) {
        std::cerr << "Invalid IP address format.\n";
        close(sock);
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connect failed.\n";
        close(sock);
        return 1;
    }

    // Message to send
    const char* msg = "Hello from client!";
    send(sock, msg, strlen(msg), 0);

    // Close socket
    close(sock);
    return 0;
}

