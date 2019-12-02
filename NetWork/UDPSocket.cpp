/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UDPSocket.cpp
 * Author: ilya
 * 
 * Created on November 12, 2019, 6:25 PM
 */

#include "UDPSocket.h"
#include "CommunicatingSocket.h"
#include "SocketException.h"
#include "FillAddress.h"

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

UDPSocket::UDPSocket() throw (SocketException) : CommunicatingSocket(SOCK_DGRAM,
IPPROTO_UDP) {
    setBroadcast();
}

UDPSocket::UDPSocket(unsigned short localPort) throw (SocketException) :
CommunicatingSocket(SOCK_DGRAM, IPPROTO_UDP) {
    setLocalPort(localPort);
    setBroadcast();
}

UDPSocket::UDPSocket(const std::string &localAddress, unsigned short localPort)
throw (SocketException) : CommunicatingSocket(SOCK_DGRAM, IPPROTO_UDP) {
    setLocalAddressAndPort(localAddress, localPort);
    setBroadcast();
}

void UDPSocket::setBroadcast() {
    int broadcastPermission = 1;
    setsockopt(sockDesc, SOL_SOCKET, SO_BROADCAST,
            (raw_type *) & broadcastPermission, sizeof (broadcastPermission));
}

void UDPSocket::disconnect() throw (SocketException) {
    sockaddr_in nullAddr;
    memset(&nullAddr, 0, sizeof (nullAddr));
    nullAddr.sin_family = AF_UNSPEC;
    if (::connect(sockDesc, (sockaddr *) & nullAddr, sizeof (nullAddr)) < 0) {
        if (errno != EAFNOSUPPORT) {
            throw SocketException("Disconnect failed (connect())", true);
        }
    }
}

void UDPSocket::sendTo(const void *buffer, int bufferLen, const std::string &foreignAddress, unsigned short foreignPort)
throw (SocketException) {
    sockaddr_in destAddr;
    fillAddr(foreignAddress, foreignPort, destAddr);
    if (sendto(sockDesc, (raw_type *) buffer, bufferLen, 0,
            (sockaddr *) & destAddr, sizeof (destAddr)) != bufferLen) {
        throw SocketException("Send failed (sendto())", true);
    }
}

int UDPSocket::recvFrom(void *buffer, int bufferLen, std::string &sourceAddress,
        unsigned short &sourcePort) throw (SocketException) {
    sockaddr_in clntAddr;
    socklen_t addrLen = sizeof (clntAddr);
    int rtn;
    if ((rtn = recvfrom(sockDesc, (raw_type *) buffer, bufferLen, 0,
            (sockaddr *) & clntAddr, (socklen_t *) & addrLen)) < 0) {
        throw SocketException("Receive failed (recvfrom())", true);
    }
    sourceAddress = inet_ntoa(clntAddr.sin_addr);
    sourcePort = ntohs(clntAddr.sin_port);
    return rtn;
}

void UDPSocket::setMulticastTTL(unsigned char multicastTTL) throw (SocketException) {
    if (setsockopt(sockDesc, IPPROTO_IP, IP_MULTICAST_TTL,
            (raw_type *) & multicastTTL, sizeof (multicastTTL)) < 0) {
        throw SocketException("Multicast TTL set failed (setsockopt())", true);
    }
}

void UDPSocket::joinGroup(const std::string &multicastGroup) throw (SocketException) {
    struct ip_mreq multicastRequest;
    multicastRequest.imr_multiaddr.s_addr = inet_addr(multicastGroup.c_str());
    multicastRequest.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt(sockDesc, IPPROTO_IP, IP_ADD_MEMBERSHIP,
            (raw_type *) & multicastRequest,
            sizeof (multicastRequest)) < 0) {
        throw SocketException("Multicast group join failed (setsockopt())", true);
    }
}

void UDPSocket::leaveGroup(const std::string &multicastGroup) throw (SocketException) {
    struct ip_mreq multicastRequest;
    multicastRequest.imr_multiaddr.s_addr = inet_addr(multicastGroup.c_str());
    multicastRequest.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt(sockDesc, IPPROTO_IP, IP_DROP_MEMBERSHIP,
            (raw_type *) & multicastRequest,
            sizeof (multicastRequest)) < 0) {
        throw SocketException("Multicast group leave failed (setsockopt())", true);
    }
}

UDPSocket::~UDPSocket() {
}

