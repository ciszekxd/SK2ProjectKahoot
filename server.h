#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <iostream>
#include "client.h"

class Server : public QObject
{
    Q_OBJECT



public:
    Server();

signals:
    void usersNumberChanged();

private slots:
    void onNewConnection();
    void signalTest();
    void readFromClient();
    //void sendQuestionAndAnswers();
    //void onDisconnect();

public:
    int getUsersNumber();
    void runServer();
    void writeToClients();

private:
    QTcpServer *serverObj = new QTcpServer();
    QList<Client*> PlayerList;

public:
    int connectedUsers;


};

#endif // SERVER_H
