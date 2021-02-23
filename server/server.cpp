#include "server.h"
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <string>

Server::Server(){

    serverObj = new QTcpServer();
    connect(serverObj, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    //connect(, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
    connectedUsers = 0;
}

Server::~Server(){

    qDeleteAll(PlayerList.begin(), PlayerList.end());
    serverObj->deleteLater();


}

void Server::runServer(){
    if(!serverObj->listen(QHostAddress::AnyIPv4,12137)){
        std::cout << "server unable to listen" << std::endl;
    }
}


void Server::onNewConnection(){

    Client* tempPlayer = new Client();


    //REMEMBER
    //connect on tempPlayer's socket won't work if declared befor setSocket below
    tempPlayer->setSocket(serverObj->nextPendingConnection());
    connect(tempPlayer->getSocket(),&QTcpSocket::disconnected, this, &Server::onDisconnect);

    this->PlayerList.push_back(tempPlayer);



    std::cout << "new connection" << std::endl;

    connectedUsers++;
    emit usersNumberChanged();
}

void Server::onDisconnect(){


    QTcpSocket* tempSoc = qobject_cast<QTcpSocket*>(sender());
    for(int i=0; i<PlayerList.size(); i++){
        if (PlayerList[i]->getSocket() == tempSoc){
            disconnect(PlayerList[i], SIGNAL(readyRead()), 0, 0);
            PlayerList.removeAt(i);
        }
    }

    connectedUsers--;
    std::cout << "user left" << std::endl;
    emit usersNumberChanged();
}

int Server::getUsersNumber(){
    return this->connectedUsers;
}

QTcpServer* Server::getServer()
{
    return this->serverObj;
}

QList<Client *> Server::getPlayerList()
{
    return this->PlayerList;
}




void Server::writeToClients(std::string text){

    QByteArray byteArray(text.c_str(),text.length());
    for(int i=0; i<PlayerList.size(); i++){
        PlayerList[i]->getSocket()->write(byteArray);
    }
    std::cout << "server wrote to clients" << std::endl;
}
