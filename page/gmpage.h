#ifndef GMPAGE_H
#define GMPAGE_H

#include "page.h"

class GMPage : public Page
{
public:
    GMPage();
    void setUpPage(Ui::MainWindow*);
    void startGame();
    void setServerObj(Server*);
private:
    Server* serverObj;

};

#endif // GMPAGE_H
