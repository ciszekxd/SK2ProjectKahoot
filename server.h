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

    void onDisconnect();
    void onNewConnection();
    void signalTest();
    void readFromClient();
    //void sendQuestionAndAnswers();


public:
    int getUsersNumber();
    void runServer();
    void writeToClients();

private:
    QTcpServer *serverObj;
    QList<Client*> PlayerList;

public:

    int connectedUsers;

};

#endif // SERVER_H
