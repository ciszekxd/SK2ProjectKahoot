#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QString>


class Client
{
public:
    Client(QString, QString, QString);
   // void writeToServer();
  //  void readFromServer();



    Client();
    std::string getName();
    void setName(std::string);
    int getScore();
    void setScore(int);
    QTcpSocket*  getSocket();
    void setSocket(QTcpSocket*);

private:
    int score;
    std::string name;
    QTcpSocket* socketObj;
};

#endif // CLIENT_H
