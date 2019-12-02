/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommunicatingSocket.cpp
 * Author: ilya
 * 
 * Created on November 12, 2019, 6:07 PM
 */

#include "CommunicatingSocket.h"
#include "FillAddress.h"

CommunicatingSocket::CommunicatingSocket(int type, int protocol) throw (SocketException)
: Socket(type, protocol) {
}

CommunicatingSocket::CommunicatingSocket(int newConnSD)
: Socket(newConnSD) {
}

void CommunicatingSocket::connect(const std::string& foreignAddress, unsigned short foreignPort) throw (SocketException) {
    sockaddr_in destAddr;
    fillAddr(foreignAddress, foreignPort, destAddr);
    if (::connect(sockDesc, (sockaddr *) & destAddr, sizeof (destAddr)) < 0) {
        throw SocketException("Connect failed (connect())", true);
    }
}

void CommunicatingSocket::send(const void* buffer, int bufferLen) throw (SocketException) {
    if (::send(sockDesc, (raw_type *) buffer, bufferLen, 0) < 0) {
        throw SocketException("Send failed (send())", true);
    }
}

int CommunicatingSocket::recv(void *buffer, int bufferLen) throw (SocketException) {
    int rtn;
    if ((rtn = ::recv(sockDesc, (raw_type *) buffer, bufferLen, 0)) < 0) {
        throw SocketException("Received failed (recv())", true);
    }
    return rtn;
}

std::string CommunicatingSocket::getForeignAddress() throw (SocketException) {
    sockaddr_in addr;
    unsigned int addr_len = sizeof (addr);
    if (getpeername(sockDesc, (sockaddr *) & addr, (socklen_t *) & addr_len) < 0) {
        throw SocketException("Fetch of foreign address failed (getpeername())", true);
    } else {
        std::cout << "Fetch of foreign address SUCCESSFULLY" << std::endl;
    }
    return inet_ntoa(addr.sin_addr);
}

unsigned short CommunicatingSocket::getForeignPort() throw (SocketException) {
    sockaddr_in addr;
    unsigned int addr_len = sizeof (addr);
    if (getpeername(sockDesc, (sockaddr *) & addr, (socklen_t *) & addr_len) < 0) {
        throw SocketException("Fetch of foreign port failed (getpeername())", true);
    }
    return ntohs(addr.sin_port);
}

CommunicatingSocket::~CommunicatingSocket() {
}

