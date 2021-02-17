#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <QObject>
#include "../server/server.h"
#include "questions/QnAManager.hpp"
#include <iostream>
#include <QTimer>

class GameServer : public QObject
{
    Q_OBJECT
public:
    GameServer(Server*, QnAManager*);
    ~GameServer();
    void interpreteMesFromClients();
    void sendQuestion(int);
    void writeToClients(std::string);
    Server* getServer();
signals:
    void usersNumberChanged();
    void newCliName();
public slots:
    void onUsersNumberChanged();
    int getUsersNumber();
private:
    Server* serverObj;
    QnAManager* QnAMObj;
    int currentQuestion;
    QTimer* Timer;
};

#endif // GAMESERVER_H
