#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <iostream>

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
    //void sendQuestionAndAnswers();
    //void onDisconnect();
public:
    int getUsersNumber();

private:
    QTcpServer *serverObj = new QTcpServer();
    QList<QTcpSocket*> cliList;

public:
    int connectedUsers;


};

#endif // SERVER_H
