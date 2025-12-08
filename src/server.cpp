#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (::bind(serverSocket,
               (struct sockaddr*)&serverAddress,
               sizeof(serverAddress)) < 0)
    {
        perror("Bind Failed");
        return 1;
    }

    // Retrieve the bound IP/port
    struct sockaddr_in bound_addr;
    socklen_t len = sizeof(bound_addr);

    if (getsockname(serverSocket, (struct sockaddr*)&bound_addr, &len) == 0)
    {
        char ip_str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &bound_addr.sin_addr, ip_str, sizeof(ip_str));

        cout << "Server Socket bounded to IP " << ip_str
             << " port " << ntohs(bound_addr.sin_port) << endl;
    }
    else
    {
        perror("getsockname failed");
    }

    listen(serverSocket, 5);
    cout << "Server is now Listening" << endl;

    int clientSocket = accept(serverSocket, nullptr, nullptr);

    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Message from Client: " << buffer << endl;

    close(serverSocket);
    close(clientSocket);

    return 0;
}
