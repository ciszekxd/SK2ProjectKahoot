#include "clientconnectionmanager.h"
#include <iostream>

ClientConnectionManager::ClientConnectionManager(Client* newClient){
    this->clientObj = newClient;
    connect(clientObj->getSocket(), SIGNAL(readyRead()), this, SLOT(readFromServer()));

}

void ClientConnectionManager::writeToServer(){
    clientObj->getSocket()->write("hello amigo client here");
    std::cout << "write to server" << std::endl;
}

void ClientConnectionManager::readFromServer(){
    QByteArray buffer;
    buffer = clientObj->getSocket()->readAll();

    std::string mytext = buffer.toStdString();
    std::cout << mytext << std::endl;
}
