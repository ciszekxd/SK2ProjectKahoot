#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <QObject>
#include "../server/server.h"
#include "Questions/QnAManager.hpp"

class GameServer : public QObject
{
    Q_OBJECT
public:
    GameServer(Server*, QnAManager*);
    void sendQuestion(int);
signals:

private:
    Server* serverObj;
    QnAManager* QnAMObj;
};

#endif // GAMESERVER_H
