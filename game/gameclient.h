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
    void reconnectClient();
    ClientConnectionManager* getCCM();
    std::string prepareGameHistory();

public slots:

    void processIncData();
    std::string getWinner();
    //void sendResponce();
    //void chooseResponce();

    void sendUserAnswer1();
    void sendUserAnswer2();
    void sendUserAnswer3();
    void sendUserAnswer4();


signals:
    void endGame();
    void gameStarts();
    void changeQuestions();
    void block();
    void unblock();
private:

    Question* currQuestion;
    ClientConnectionManager* gameCCM;
    int rcvdAnswers;
    std::string winner;
    int queNumber;
    std::vector<std::string> queContents;
    std::vector<int> corrAnsVec;


};

#endif // GAMECLIENT_H
