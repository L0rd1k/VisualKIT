/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UDPSocket.h
 * Author: ilya
 *
 * Created on November 12, 2019, 6:25 PM
 */

#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "CommunicatingSocket.h"

class UDPSocket : public CommunicatingSocket {
public:
    UDPSocket() throw (SocketException);
    UDPSocket(unsigned short localPort) throw (SocketException);
    UDPSocket(const std::string &localAddress, unsigned short localPort) throw (SocketException);
    void disconnect() throw (SocketException);
    void sendTo(const void *buffer, int bufferLen, const std::string &foreignAddress, unsigned short foreignPort) throw (SocketException);
    int recvFrom(void *buffer, int bufferLen, std::string &sourceAddress, unsigned short &sourcePort) throw (SocketException);
    void setMulticastTTL(unsigned char multicastTTL) throw (SocketException);
    void joinGroup(const std::string &multicastGroup) throw (SocketException);
    void leaveGroup(const std::string &multicastGroup) throw (SocketException);
    virtual ~UDPSocket();
private:
    void setBroadcast();
};

#endif /* UDPSOCKET_H */

