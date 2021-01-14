#include "server.h"


Server::Server(){
    serverObj->listen(QHostAddress::LocalHost,12332);
    connect(serverObj, SIGNAL(onNewConnection()), this, SLOT(onNewConnection));
}

void Server::onNewConnection(){
    QTcpSocket *TempCli = serverObj->nextPendingConnection();
    this->cliList.push_back(TempCli);
    std::cout << "new connection" << std::endl;
}
