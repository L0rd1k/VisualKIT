#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "CommunicatingSocket.h"
#include "SocketException.h"

class TCPSocket : public CommunicatingSocket {
public:
    TCPSocket() throw(SocketException);
    virtual ~TCPSocket();
    TCPSocket(const std::string &foreignAddress, unsigned short foreignPort) throw (SocketException);
private:
    friend class TCPServerSocket;
    TCPSocket(int newConnSD);
};

#endif /* TCPSOCKET_H */

