#ifndef GMPAGE_H
#define GMPAGE_H

#include "page.h"

class GMPage : public Page
{
    Q_OBJECT
public:
    GMPage();
    ~GMPage();
    void setUpPage(Ui::MainWindow*);
//    void showUsersNumber();
    void startGame();

    void setGameServerObj(GameServer*);
    void setQAMObj();
    std::string ipToCode(std::string);



public slots:
    void showUsersNumber();
    void showPlayersNames();
    void showTimer();
    void showIP();

private:
    GameServer* gameServerObj;
    int usersNumber;

};

#endif // GMPAGE_H
