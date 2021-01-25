#ifndef CLIENTCONNECTIONMANAGER_H
#define CLIENTCONNECTIONMANAGER_H

#include <QObject>
#include "client.h"

class ClientConnectionManager: public QObject
{
    Q_OBJECT

public:

    ClientConnectionManager(Client*);

    void writeToServer();

public slots:

    void readFromServer();
    void endConnection();

private:
    Client* clientObj;
};

#endif // CLIENTCONNECTIONMANAGER_H
