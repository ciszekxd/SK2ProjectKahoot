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
    serverObj->deleteLater();

    qDeleteAll(PlayerList.begin(), PlayerList.end());

}

void Server::runServer(){
    if(!serverObj->listen(QHostAddress::LocalHost,12137)){
        std::cout << "server unable to listen" << std::endl;
    }
}


void Server::onNewConnection(){

    Client* tempPlayer = new Client();

    // a place in code to set connections for all clients
    //connect(tempPlayer->getSocket(),&QTcpSocket::disconnected, this, &Server::onDisconnect);

    //REMEMBER
    //connect on tempPlayer's socket won't work if declared befor setSocket below
    tempPlayer->setSocket(serverObj->nextPendingConnection());
    connect(tempPlayer->getSocket(),&QTcpSocket::disconnected, this, &Server::onDisconnect);
    connect(tempPlayer->getSocket(),&QTcpSocket::disconnected,tempPlayer->getSocket(), &QTcpSocket::deleteLater);
    this->PlayerList.push_back(tempPlayer);

    //connect(this->PlayerList.last()->getSocket(), SIGNAL(readyRead()), this, SLOT(readFromClient()));

    //connect(this->PlayerList.last()->getSocket(), &QTcpSocket::disconnected, this, &Server::onDisconnect);
    std::cout << "new connection" << std::endl;

    connectedUsers++;
    emit usersNumberChanged();
}

void Server::onDisconnect(){
    connectedUsers--;
    std::cout << "user left" << std::endl;
    emit usersNumberChanged();
}

int Server::getUsersNumber(){
    return this->connectedUsers;
}

QList<Client *> Server::getPlayerList()
{
    return this->PlayerList;
}

void Server::signalTest(){
    std::cout << "test string" << std::endl;
}

//void Server::readFromClient(){

//    emit readingHandlerNeeded();

/*
    QByteArray buffer;
    QTcpSocket* readSocket = qobject_cast<QTcpSocket*>(sender());

    buffer = readSocket->readLine();
    std::string myText = buffer.toStdString();
    std::string myTextContent = myText.substr(2,myText.size());

    //std::string tempStr = myText.at(0);
    if(myText.at(0) == 'N'){
        for (int i=0; i<PlayerList.count();i++){
            if(PlayerList[i]->getSocket() == readSocket) PlayerList[i]->setName(myTextContent);
        }
        emit newCliName();
    }else if(myText.at(0) == 'R'){
        int rcvedAns = std::stoi(myTextContent);


    }

   // std::cout << mytext << std::endl;
*/
//}


void Server::writeToClients(std::string text){

    QByteArray byteArray(text.c_str(),text.length());
    for(int i=0; i<PlayerList.size(); i++){
        PlayerList[i]->getSocket()->write(byteArray);
    }
    std::cout << "server wrote to clients" << std::endl;
}
