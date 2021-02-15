#ifndef CLIENTCONNECTIONPAGE_H
#define CLIENTCONNECTIONPAGE_H
#include "page.h"

class clientConnectionPage : public Page
{
public:
    clientConnectionPage();
    ~clientConnectionPage();
    void setUpPage(Ui::MainWindow*);
    void checkAgain();
    ClientConnectionManager* getCCMObj();
private:
    ClientConnectionManager* CCMObj;
    bool connected;

};

#endif // CLIENTCONNECTIONPAGE_H
