#include "client.h"
#include <iostream>


// version with auto connection
Client::Client(QString port, QString ip, QString name)
{
    this->socketObj = new QTcpSocket();
    this->socketObj->abort();
    this->socketObj->connectToHost(ip, port.toInt());
    std::string convStr = name.toStdString();
    this->name = convStr;
    this->score = 0;

}

// version without auto connection
Client::Client()
{
    this->score = 0;
    this->socketObj = new QTcpSocket();
}
/*
void Client::writeToServer(){
    this->socketObj->write("hello amigo client here");
    std::cout << "write to server" << std::endl;
}

void Client::readFromServer(){
    QByteArray buffer;
    buffer = this->getSocket()->readAll();

    std::string mytext = buffer.toStdString();
    std::cout << mytext << std::endl;
}
*/

std::string Client::getName(){
    return this->name;
}

void Client::setName(std::string newName){
    this->name = newName;
}

int Client::getScore(){
    return this->score;
}

void Client::setScore(int newScore){
    this->score = newScore;
}

QTcpSocket*  Client::getSocket(){
    return this->socketObj;
}

void Client::setSocket(QTcpSocket* newSocket){
    this->socketObj = newSocket;
}
