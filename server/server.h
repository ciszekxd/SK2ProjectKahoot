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

  //  void readingHandlerNeeded();
    void onDisconnect();
    void onNewConnection();



public:
    int getUsersNumber();
    QTcpServer* getServer();
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
