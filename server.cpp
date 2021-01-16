#include "server.h"
#include <QObject>
#include <QString>
#include <QTcpSocket>

Server::Server(){

    connect(serverObj, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    connectedUsers = 0;
}

void Server::runServer(){
    if(!serverObj->listen(QHostAddress::LocalHost,12137)){
        std::cout << "server unable to listen" << std::endl;
    }
}


void Server::onNewConnection(){
    QTcpSocket *TempCli = serverObj->nextPendingConnection();
    this->cliList.push_back(TempCli);

    connect(this->cliList.last(), SIGNAL(readyRead()), this, SLOT(readFromClient()));
    std::cout << "new connection" << std::endl;

    connectedUsers++;
    emit usersNumberChanged();
}

int Server::getUsersNumber(){
    return this->connectedUsers;
}

void Server::signalTest(){
    std::cout << "test string" << std::endl;
}

void Server::readFromClient(){
     QByteArray buffer;
     QTcpSocket* readSocket = qobject_cast<QTcpSocket*>(sender());
     buffer = readSocket->readAll();

     std::string mytext = buffer.toStdString();
     std::cout << mytext << std::endl;

}
