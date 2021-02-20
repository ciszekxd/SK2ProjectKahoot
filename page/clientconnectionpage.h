#ifndef CLIENTCONNECTIONPAGE_H
#define CLIENTCONNECTIONPAGE_H
#include "page.h"

class clientConnectionPage : public Page
{
    Q_OBJECT
public:
    clientConnectionPage();
    ~clientConnectionPage();
    void setUpPage(Ui::MainWindow*);
    void checkAgain();
    GameClient* getGameClient();
    void goToGamePage();
    ClientConnectionManager* getCCMObj();
public slots:
    void gameStarts();



private:
    ClientConnectionManager* CCMObj;
    GameClient* GCObj;
    bool connected;
    bool CCpassed;
    bool GCpassed;
    bool GCsetted;

};

#endif // CLIENTCONNECTIONPAGE_H
