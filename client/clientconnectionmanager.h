#ifndef CLIENTCONNECTIONMANAGER_H
#define CLIENTCONNECTIONMANAGER_H

#include <QObject>
#include "client.h"

class ClientConnectionManager: public QObject
{
    Q_OBJECT

public:

    //ClientConnectionManager(Client*);
    ClientConnectionManager();
    ~ClientConnectionManager();

    void writeToServer();
    bool isConnected();
    void setClient(Client*);

public slots:
    void emitReadingStarts();
    std::string readFromServer();
    void endConnection();

signals:
    void readingStarts();

private:
    Client* clientObj;
};

#endif // CLIENTCONNECTIONMANAGER_H
