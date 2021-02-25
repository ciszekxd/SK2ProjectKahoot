#include "client.h"
#include <iostream>
#include <QObject>

// version with auto connection
Client::Client(QString port, QString ip, QString name)
{
    this->socketObj = new QTcpSocket();
    this->socketObj->abort();
    this->socketObj->connectToHost(ip, port.toInt());
    std::string convStr = name.toStdString();
    this->name = convStr;
    this->score = 0;
    readSet = false;
    lastAns = "";


}
Client::~Client(){
    std::cout << "dellsocket start" << std::endl;
    socketObj->deleteLater();
    std::cout << "dellsocket end" << std::endl;
}


// version without auto connection
Client::Client()
{
    lastAns = "";
    readSet = false;
    this->score = 0;
    this->socketObj = new QTcpSocket();
}


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

bool Client::isReadingSet()
{
    return readSet;
}

void Client::ReadingSet()
{
    readSet = true;
}

void Client::setLastAns(std::string x)
{
    lastAns = x;
    if(x != "") ansHistory.push_back(x);

}

std::string Client::getLastAns()
{
    return lastAns;
}

std::vector<std::string> Client::getAnsHistory()
{
    return ansHistory;
}
