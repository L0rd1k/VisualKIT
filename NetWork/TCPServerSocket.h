/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPServerSocket.h
 * Author: ilya
 *
 * Created on November 12, 2019, 6:22 PM
 */

#ifndef TCPSERVERSOCKET_H
#define TCPSERVERSOCKET_H

#include "Socket.h"
#include "TCPSocket.h"

class TCPServerSocket : public Socket {
public:
    TCPServerSocket(unsigned short localPort, int queueLen = 5) throw (SocketException);
    TCPServerSocket(const std::string &localAddress, unsigned short localPort, int queueLen = 5) throw (SocketException);
    TCPSocket *accepted() throw (SocketException);
    virtual ~TCPServerSocket();
private:
    void setListen(int queueLen) throw (SocketException);
};

#endif /* TCPSERVERSOCKET_H */

