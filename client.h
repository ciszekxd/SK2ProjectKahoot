#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>


class Client
{
public:
    Client(QString, QString);

private:
    QTcpSocket socketObj;
};

#endif // CLIENT_H
