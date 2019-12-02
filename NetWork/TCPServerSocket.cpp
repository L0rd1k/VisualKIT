/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPServerSocket.cpp
 * Author: ilya
 * 
 * Created on November 12, 2019, 6:22 PM
 */

#include "TCPServerSocket.h"
#include "CommunicatingSocket.h"
#include "SocketException.h"

#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <exception>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

TCPServerSocket::TCPServerSocket(unsigned short localPort, int queueLen)
throw (SocketException)
: Socket(SOCK_STREAM, IPPROTO_TCP) {
    setLocalPort(localPort);
    setListen(queueLen);
}

TCPServerSocket::TCPServerSocket(const std::string &localAddress, unsigned short localPort, int queueLen)
throw (SocketException)
: Socket(SOCK_STREAM, IPPROTO_TCP) {
    setLocalAddressAndPort(localAddress, localPort);
    setListen(queueLen);
}

TCPSocket *TCPServerSocket::accepted()
throw (SocketException) {
    
    int newConnSD = accept(sockDesc, NULL, NULL);
    std::cout << "sockDesc = " << sockDesc << std::endl;
    
    
    //    if ((newConnSD) < 0) {
    //        throw SocketException("Accept failed (accept())", true);
    //    } else {
    //        std::cout << " - Accept SUCCESSFULLY " << newConnSD << " " << sockDesc << std::endl;
    //    }
    std::cout << "newConnSD = " << newConnSD << std::endl;
    return new TCPSocket(newConnSD);
}

void TCPServerSocket::setListen(int queueLen) throw (SocketException) {
    
    std::cout << "SET LISTEN" << std::endl;
    if (listen(sockDesc, queueLen) < 0) {
        throw SocketException("Set listening socket failed (listen())", true);
    } else {
        std::cout << " + Socket listening going SUCCESSFULLY | queueLen = " << queueLen << " sockDesk = " << sockDesc << std::endl;
    }
}

TCPServerSocket::~TCPServerSocket() {
}

