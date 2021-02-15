#ifndef GAMEPAGE_H
#define GAMEPAGE_H
#include "page.h"

class GamePage : public Page
{
public:
    GamePage();
    ~GamePage();

    void setUpPage(Ui::MainWindow*);
};

#endif // GAMEPAGE_H
