#ifndef PAGE_H
#define PAGE_H

#include <QObject>
#include <QMainWindow>
#include <iostream>
#include <QNetworkInterface>
#include "client/clientconnectionmanager.h"
#include "../ui_mainwindow.h"
#include "../questions/QnAManager.hpp"
#include "../server/server.h"
#include "../game/gameserver.h"
#include "../game/gameclient.h"

class Page : public QObject
{
    Q_OBJECT
public:

    virtual void setUpPage(Ui::MainWindow*)=0;
    int getPageIndex();
    std::string getNextPage();



signals:
    void readyForChange();
    void newServerMade();
    void newQAMMade();
    void newGCMade();
    void readyForSetUp();



protected:
    int pageIndex;
    std::string nextPage;
    Ui::MainWindow* tempUi;
};

#endif // PAGE_H
