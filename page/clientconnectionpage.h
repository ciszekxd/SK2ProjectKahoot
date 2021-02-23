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
    bool isNumber(std::string);
    std::string codeToIp(std::string);


public slots:
    void gameStarts();
    void setIpFromUi();
    void setClientsName();



private:
    ClientConnectionManager* CCMObj;
    GameClient* GCObj;
    bool connected;
    bool CCpassed;
    bool GCpassed;
    bool GCsetted;
    QString ip;
    QString clientName;

};

#endif // CLIENTCONNECTIONPAGE_H
