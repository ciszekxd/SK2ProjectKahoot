#ifndef GAMEPAGE_H
#define GAMEPAGE_H
#include "page.h"

class GamePage : public Page
{
    Q_OBJECT
public:
    GamePage();
    ~GamePage();
    void setGameClient(GameClient*);
    void setUpPage(Ui::MainWindow*);

public slots:
    void setQuestionsAtPage();
    //void disableAnswers();
   // void enableAnswers();
    void showWinner();

private:
    GameClient* GCObj;
};

#endif // GAMEPAGE_H
