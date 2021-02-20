#include "clientconnectionmanager.h"
#include <iostream>


ClientConnectionManager::ClientConnectionManager(){
    clientObj = NULL;
    std::cout << "empty client manager initiated" << std::endl;

}
ClientConnectionManager::~ClientConnectionManager(){
    if(clientObj != NULL) delete clientObj;
}

void ClientConnectionManager::setClient(Client* Cli){
    this->clientObj = Cli;

}

Client *ClientConnectionManager::getClient(){
    return this->clientObj;
}

void ClientConnectionManager::writeToServer(std::string mes){
     QByteArray byteArray(mes.c_str(), mes.length());
    clientObj->getSocket()->write(byteArray);
    std::cout << "write to server" << std::endl;
}

void ClientConnectionManager::emitReadingStarts(){
    emit readingStarts();
}

std::string ClientConnectionManager::readFromServer(){
    QByteArray buffer;
    buffer = clientObj->getSocket()->readLine();
    std::string text = buffer.toStdString();
    //std::cout << text << std::endl;
    return text;
}

void ClientConnectionManager::endConnection(){
    std::cout << "client delates socket" << std::endl;
    this->clientObj->getSocket()->disconnect();
    this->clientObj->getSocket()->disconnectFromHost();
    this->clientObj->getSocket()->deleteLater();
}

bool ClientConnectionManager::isConnected(){
    if(this->clientObj->getSocket()->state() == QAbstractSocket::ConnectedState){
        return true;
    }else{
        return false;
    }
}



