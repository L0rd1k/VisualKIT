#include "Socket.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>

#include "FillAddress.h"

Socket::Socket(int type, int protocol) throw (SocketException) {
    if ((sockDesc = socket(PF_INET, type, protocol)) < 0) {
        throw SocketException("Socket creation failed (socket())", true);
    }
}

Socket::Socket(int sockDesc) {
    this->sockDesc = sockDesc;
}

Socket::~Socket() {
    sockDesc = -1;
}

std::string Socket::getLocalAddress() throw (SocketException) {
    sockaddr_in addr;
    unsigned int addr_len = sizeof (addr);

    if (getsockname(sockDesc, (sockaddr *) & addr, (socklen_t *) & addr_len) < 0) {
        throw SocketException("Fetch of local address failed (getsockname())", true);
    }
    return inet_ntoa(addr.sin_addr);
}

unsigned short Socket::getLocalPort() throw (SocketException) {
    sockaddr_in addr;
    unsigned int addr_len = sizeof (addr);
    if (getsockname(sockDesc, (sockaddr *) & addr, (socklen_t *) & addr_len) < 0) {
        throw SocketException("Fetch of local port failed (getsockname())", true);
    }
    return ntohs(addr.sin_port);
}

void Socket::setLocalPort(unsigned short localPort) throw (SocketException) {
    sockaddr_in localAddr;

    memset(&localAddr, 0, sizeof (localAddr));
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    localAddr.sin_port = htons(localPort);
    std::cout << "SET LOCAL PORT" << std::endl;
    std::cout << " +  Sin_addr.s_addr : " << localAddr.sin_addr.s_addr << std::endl;
    std::cout << " +  Sin_port : " << localAddr.sin_port << std::endl;
    if (bind(sockDesc, (sockaddr *) & localAddr, sizeof (sockaddr_in)) < 0) {
        throw SocketException("Set of local port failed (bind())", true);
    } else {
        std::cout << " +  Local port " << localPort << " set SUCCESFULLY" << std::endl;
    }
    std::cout << std::endl;
}

void Socket::setLocalAddressAndPort(const std::string &localAddress, unsigned short localPort) throw (SocketException) {
    sockaddr_in localAddr;
    fillAddr(localAddress, localPort, localAddr);
    if (bind(sockDesc, (sockaddr *) & localAddr, sizeof (sockaddr_in)) < 0) {
        throw SocketException("Set of local address and port failed (bind())", true);
    }
}

unsigned short Socket::resolveService(const std::string& service, const std::string& protocol) {
    struct servent *serv;
    if ((serv = getservbyname(service.c_str(), protocol.c_str())) == NULL)
        return atoi(service.c_str());
    else
        return ntohs(serv->s_port);
}