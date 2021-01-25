#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QString>


class Client : public QObject
{
    Q_OBJECT
public:

    Client(QString, QString, QString);
    Client();

//getters and setters
    std::string getName();
    void setName(std::string);
    int getScore();
    void setScore(int);
    QTcpSocket*  getSocket();
    void setSocket(QTcpSocket*);


public slots:
//    void quitFromServerGracefully();

private:
    int score;
    std::string name;
    QTcpSocket* socketObj;
};

#endif // CLIENT_H
