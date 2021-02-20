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
    void sendQuestion();
    void writeToClients(std::string);
    Server* getServer();
    Client *findClient(QTcpSocket*);
    void givePoints(Client*);
    int getCurrClock();
    //void endGame();
    Client* findWinner();

signals:
    void usersNumberChanged();
    void updateCliNaS();
    void nextSec();
    void nextQue();

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
    int timeForQuestion;
    int numOfQuestions;
    QTimer* Timer;
};

#endif // GAMESERVER_H
