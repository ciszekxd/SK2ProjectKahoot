#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <QObject>
#include "../server/server.h"
#include "questions/QnAManager.hpp"
#include <iostream>

class GameServer : public QObject
{
    Q_OBJECT
public:
    GameServer(Server*, QnAManager*);
    ~GameServer();
    void sendQuestion(int);
    void writeToClients(std::string);
signals:
    void usersNumberChanged();
public slots:
    void onUsersNumberChanged();
    int getUsersNumber();
private:
    Server* serverObj;
    QnAManager* QnAMObj;
};

#endif // GAMESERVER_H
