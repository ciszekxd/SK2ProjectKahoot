#include "clientconnectionmanager.h"
#include <iostream>

ClientConnectionManager::ClientConnectionManager(Client* newClient){
    this->clientObj = newClient;
    //connect(clientObj->getSocket(), SIGNAL(readyRead()), this, SLOT(readFromServer()));
    connect(clientObj->getSocket(), SIGNAL(readyRead()), this, SLOT(emitReadingStarts()));

}

void ClientConnectionManager::writeToServer(){
    clientObj->getSocket()->write("hello amigo client here");
    std::cout << "write to server" << std::endl;
}

void ClientConnectionManager::emitReadingStarts(){
    emit readingStarts();
}

std::string ClientConnectionManager::readFromServer(){
    QByteArray buffer;
    buffer = clientObj->getSocket()->readAll();
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



