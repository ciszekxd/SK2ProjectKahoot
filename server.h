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
   void onNewConnection();
   void sendQuestionAndAnswers();
   void onDisconnect();

private:
   QTcpServer *serverObj = new QTcpServer();
   QList<QTcpSocket*> cliList;



};

#endif // SERVER_H
