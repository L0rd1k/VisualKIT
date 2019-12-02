#include "NetWork/SocketException.h"

SocketException::SocketException(const std::string &message, bool sysMessage) throw ()
: userMessage(message) {
    if (sysMessage) {
        userMessage.append(" EXCEPTION : ");
        userMessage.append(strerror(errno));
    }
}

SocketException::~SocketException() throw () {
}

const char* SocketException::what() const throw () {
    return userMessage.c_str();
}

//static void fillAddress(const std::string &address, unsigned short port, sockaddr_in &addr) {
//    memset(&addr, 0 , sizeof(address));
//}