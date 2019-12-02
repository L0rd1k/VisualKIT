/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Socket.h
 * Author: ilya
 *
 * Created on November 12, 2019, 5:38 PM
 */



#ifndef SOCKET_H
#define SOCKET_H

#include "SocketException.h"
#include <iostream>

class Socket {
public:
    virtual ~Socket();
    std::string getLocalAddress() throw (SocketException);
    unsigned short getLocalPort() throw (SocketException);
    void setLocalPort(unsigned short localPort) throw (SocketException);
    void setLocalAddressAndPort(const std::string &localAddress, unsigned short localPort = 0) throw (SocketException);
    static unsigned short resolveService(const std::string &service, const std::string &protocol = "tcp");
private:
    Socket(const Socket &sock);
    void operator=(const Socket &sock);
protected:
    int sockDesc;
    Socket(int type, int protocol) throw (SocketException);
    Socket(int sockDesc);
};

#endif /* SOCKET_H */

