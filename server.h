#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>


class server : public QObject
{
    Q_OBJECT
public:

private:
   QTcpServer *server = new QTcpServer();


};

#endif // SERVER_H
