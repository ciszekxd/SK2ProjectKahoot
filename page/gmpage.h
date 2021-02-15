#ifndef GMPAGE_H
#define GMPAGE_H

#include "page.h"

class GMPage : public Page
{
public:
    GMPage();
    ~GMPage();
    void setUpPage(Ui::MainWindow*);
    void startGame();
    void setGameServerObj(GameServer*);
    void setQAMObj();
private:
    GameServer* gameServerObj;

};

#endif // GMPAGE_H
