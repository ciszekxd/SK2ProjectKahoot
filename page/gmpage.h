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



public slots:
    void showUsersNumber();
    void showPlayersNames();
    void showTimer();

private:
    GameServer* gameServerObj;
    int usersNumber;

};

#endif // GMPAGE_H
