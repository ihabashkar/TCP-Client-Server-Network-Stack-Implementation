# Simple Transmission Control Protocol (TCP) Client-Server Application 

This project implements a minimal TCP client and server using POSIX sockets in C++.  
It demonstrates how networked applications communicate over TCP, how to structure source files, and how to automate compilation using a Makefile.  
The project is designed to run on FreeBSD inside a VirtualBox environment but also works on most UNIX-like systems with small adjustments.

---

## 1. Project Description

This project contains two C++ programs:

- _**server.cpp**_ 
  Listens on TCP port **8080**, accepts an incoming connection, receives a message, and prints it.

- _**client.cpp**
  Connects to the server using an IP address from the command line and sends a message (`"Hello from client!"`).

The main goals are:

- Learn how to create TCP sockets in C++
- Understand the basic client/server model
- Build applications using a Makefile
- Run and test programs across multiple terminal windows
- Gain experience using FreeBSD as a programming environment

---

## 2. Project Structure
project/
│
├── src/
│ ├── server.cpp
│ └── client.cpp
│
├── bin/
│ (compiled binaries appear here after running make)
│
└── Makefile


- All source files are inside **src/**
- The Makefile automatically places compiled binaries inside **bin/**

---

## 3. Building the Project

To compile both the client and server, run the following from the **project root directory** (the folder containing the Makefile):

**make**

This produces:

- `bin/server`
- `bin/client`

### Cleaning the build
To delete compiled binaries:

**make clean**


---

## 4. Running the Programs

You must run the program using **two terminals**.

---

### Terminal 1 — Run the Server

Navigate to your project root directory and start the server:

**./bin/server**


If successful, it will display:

"**Server listening on port 8080...**"


The server will wait until a client connects.

---

### Terminal 2 — Run the Client

In a second terminal, run:

**./bin/client 127.0.0.1**


If successful, you will see:

**Connected to server!
Message sent.**


Meanwhile, the server terminal will display:

**Client connected!
Received message: Hello from client!**


This confirms the client successfully connected and communicated with the server.

---

## 5. Common Errors & Fixes

### Error: “Connection refused”
Possible causes:

- The server is not running
- You ran the client first
- Using the wrong IP address
- Another process is using port 8080

### Error: Port already in use
Run:

**sockstat -4l**


Find the process using port 8080, then:

**kill -9 <pid>**


### Error: “No such file or directory”
Ensure:
- You are inside the correct project folder
- You compiled the project with `make`
- You are running the binary using the correct path (`./bin/server` or `./bin/client`)

---

## 6. Requirements Completed by This Project

- A functional TCP server using POSIX sockets  
- A functional TCP client that connects to a user-provided IP  
- Ability to send and receive data reliably  
- Proper use of:
  - `socket()`
  - `bind()`
  - `listen()`
  - `accept()`
  - `connect()`
  - `send()`
  - `recv()`
- Compilation using a Makefile  
- Output files organized into `/bin`  
- Instructions on how to run across two terminals  
- Compatibility with FreeBSD

---

## 7. Optional Future Improvements

If you want to expand the project beyond its basic requirements, here are some good next steps:

- Allow the server to handle multiple clients  
- Implement threading or forking  
- Add bidirectional communication (client can also receive messages)  
- Add custom ports via command-line arguments  
- Create a chatroom-style application  
- Add logging and error files  
- Implement graceful shutdown signals  

---

## 8. Author

**Ihab Ashkar
  Chibueze Eburuoh
  Xannia Simpson**  
Computer Science  
Bowie State University  

---

## 9. License

This project is intended for educational use and learning purposes only. :D

