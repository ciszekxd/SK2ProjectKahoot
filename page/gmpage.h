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
    QnAManager* QAMObj;

};

#endif // GMPAGE_H
