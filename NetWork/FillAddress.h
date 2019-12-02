/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FillAddress.h
 * Author: ilya
 *
 * Created on November 12, 2019, 6:57 PM
 */

#ifndef FILLADDRESS_H
#define FILLADDRESS_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>

static void fillAddr(const std::string &address, unsigned short port, sockaddr_in &addr) {
    memset(&addr, 0, sizeof (addr));
    addr.sin_family = AF_INET;
    hostent *host;
    if ((host = gethostbyname(address.c_str())) == NULL) {
        throw SocketException("Failed to resolve name (gethostbyname())");
    }
    addr.sin_addr.s_addr = *((unsigned long *) host->h_addr_list[0]);
    addr.sin_port = htons(port);
}

#endif /* FILLADDRESS_H */

