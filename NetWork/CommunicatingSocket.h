/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommunicatingSocket.h
 * Author: ilya
 *
 * Created on November 12, 2019, 6:07 PM
 */

#ifndef COMMUNICATINGSOCKET_H
#define COMMUNICATINGSOCKET_H

typedef char raw_type; 

#include "Socket.h"

class CommunicatingSocket : public Socket {
public:
    CommunicatingSocket();
    virtual ~CommunicatingSocket();
    void connect(const std::string &foreignAddress, unsigned short foreignPort) throw (SocketException);
    void send(const void *buffer, int bufferLen) throw (SocketException);
    int recv(void *buffer, int bufferLen) throw (SocketException);
    std::string getForeignAddress() throw (SocketException);
    unsigned short getForeignPort() throw (SocketException);
private:
protected:
    CommunicatingSocket(int type, int protocol) throw (SocketException);
    CommunicatingSocket(int newConnSD);

};

#endif /* COMMUNICATINGSOCKET_H */

