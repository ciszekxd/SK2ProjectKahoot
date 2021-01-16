#include "client.h"
#include <iostream>

Client::Client(QString port, QString ip)
{
    this->socketObj.abort();
    this->socketObj.connectToHost(ip, port.toInt());
}

void Client::writeToServer(){
    this->socketObj.write("hello amigo client here");
    std::cout << "write to server" << std::endl;
}
