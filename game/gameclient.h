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

public slots:

    void processIncData();
    //void sendResponce();
    //void chooseResponce();

signals:
    void gameStarts();
private:

    Question* currQuestion;
    ClientConnectionManager* gameCCM;

};

#endif // GAMECLIENT_H
