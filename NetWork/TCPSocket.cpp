/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPSocket.cpp
 * Author: ilya
 * 
 * Created on November 12, 2019, 6:17 PM
 */

#include "TCPSocket.h"
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

TCPSocket::TCPSocket() throw (SocketException) : CommunicatingSocket(SOCK_STREAM, IPPROTO_TCP) {
}

TCPSocket::TCPSocket(int newConnSD)
: CommunicatingSocket(newConnSD) {
}

TCPSocket::TCPSocket(const std::string &foreignAddress, unsigned short foreignPort)
throw (SocketException) : CommunicatingSocket(SOCK_STREAM, IPPROTO_TCP) {
    connect(foreignAddress, foreignPort);
}

TCPSocket::~TCPSocket() {
}

