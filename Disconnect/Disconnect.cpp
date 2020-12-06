//
//  Disconnect.cpp
//  Disconnect
//
//  Created by Asaf Niv on 06/12/2020.
//

#include <iostream>
#include "Disconnect.hpp"
#include "DisconnectPriv.hpp"

void Disconnect::HelloWorld(const char * s)
{
    DisconnectPriv *theObj = new DisconnectPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void DisconnectPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

