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
    Client *findClient(QTcpSocket*);
    void givePoints(Client*);
    int getCurrClock();

signals:
    void usersNumberChanged();
    void updateCliNaS();
    void nextSec();

public slots:
    void readFromClient();
    void onUsersNumberChanged();
    int getUsersNumber();
    void startGame();
    void nextSecond();
private:
    Server* serverObj;
    QnAManager* QnAMObj;
    int currentQuestion;
    int timerClock;
    QTimer* Timer;
};

#endif // GAMESERVER_H
