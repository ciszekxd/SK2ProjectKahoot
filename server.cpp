#include "server.h"


Server::Server(){
    if(!serverObj->listen(QHostAddress::LocalHost,12137)){
        std::cout << "server unable to listen" << std::endl;
    }
    connect(serverObj, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void Server::onNewConnection(){
    QTcpSocket *TempCli = serverObj->nextPendingConnection();
    this->cliList.push_back(TempCli);
    std::cout << "new connection" << std::endl;
}
