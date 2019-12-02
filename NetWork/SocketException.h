#ifndef SOCKETEXCEPTION_H
#define SOCKETEXCEPTION_H

#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <exception>
#include <cstring>

class SocketException : public std::exception {
public:
    SocketException(const std::string &message, bool sysMessage = false) throw ();
    virtual ~SocketException() throw ();
    const char* what() const throw ();
private:
    std::string userMessage;
};

#endif /* SOCKETEXCEPTION_H */

