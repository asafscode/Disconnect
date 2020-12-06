//
//  Disconnect.cpp
//  Disconnect
//
//  Created by Asaf Niv on 06/12/2020.
//

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include "../oshooks/hooks.hpp"
int connect_hook(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
__attribute__((constructor)) void start() {
    hookFuncByName("connect", (void *)connect_hook);
}
int connect_hook(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    restoreFunc("connect");
    if(addr->sa_family == AF_INET || addr->sa_family == AF_INET6 || addr->sa_family == AF_NETBIOS) {
        return -1;
    }
    int retval = connect(sockfd, addr, addrlen);
    hookAgain("connect");
    return retval;
}
