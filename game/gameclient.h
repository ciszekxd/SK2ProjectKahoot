#ifndef GAMECLIENT_H
#define GAMECLIENT_H
#include "../client/clientconnectionmanager.h"
#include <QObject>
#include "../questions/Question.hpp"

class GameClient : public QObject
{
    Q_OBJECT

public:

    GameClient(ClientConnectionManager*);
    ~GameClient();


    std::string getQuestion();
    std::string getAnswer(int);
    void sendClientsName();
    void sendUserAnswer1();
    void sendUserAnswer2();
    void sendUserAnswer3();
    void sendUserAnswer4();


public slots:

    void processIncData();
    //void sendResponce();
    //void chooseResponce();

signals:
    void gameStarts();
    void changeQuestions();
private:

    Question* currQuestion;
    ClientConnectionManager* gameCCM;
    int rcvdAnswers;

};

#endif // GAMECLIENT_H
