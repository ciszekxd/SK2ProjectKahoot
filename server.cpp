#include "server.h"


Server::Server(){
    if(!serverObj->listen(QHostAddress::LocalHost,12137)){
        std::cout << "server unable to listen" << std::endl;
    }
    connect(serverObj, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    //connect(serverObj, SIGNAL(usersNumberChanged()),this, SLOT(signalTest()));
    connectedUsers = 0;
}

void Server::onNewConnection(){
    QTcpSocket *TempCli = serverObj->nextPendingConnection();
    this->cliList.push_back(TempCli);
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
