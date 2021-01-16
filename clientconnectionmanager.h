#ifndef CLIENTCONNECTIONMANAGER_H
#define CLIENTCONNECTIONMANAGER_H

#include <QObject>
#include "client.h"

class ClientConnectionManager: QObject
{
    Q_OBJECT
public:
    ClientConnectionManager(Client*);

    void writeToServer();
public slots:
    void readFromServer();

private:
    Client* clientObj;
};

#endif // CLIENTCONNECTIONMANAGER_H
