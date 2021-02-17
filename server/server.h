#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <iostream>
#include "../client/client.h"

class Server : public QObject
{
    Q_OBJECT

public:

    Server();
    ~Server();

signals:

    void usersNumberChanged();
    void newCliName();

private slots:

    void onDisconnect();
    void onNewConnection();
    void signalTest();
    void readFromClient();
    //void sendQuestionAndAnswers();


public:
    int getUsersNumber();
    QList<Client *> getPlayerList();
    void runServer();
    void writeToClients(std::string);

private:
    QTcpServer *serverObj;
    QList<Client*> PlayerList;

public:

    int connectedUsers;

};

#endif // SERVER_H
