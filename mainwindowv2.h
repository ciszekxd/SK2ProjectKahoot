#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include "./server/server.h"
#include "./client/client.h"
#include "./client/clientconnectionmanager.h"
#include "./questions/QnAManager.hpp"
#include "./game/gameclient.h"
#include "./game/gameserver.h"
#include "./page/selectionpage.h"
#include "./page/setpathpage.h"
#include "./page/clientconnectionpage.h"
#include "./page/gmpage.h"
#include "./page/gamepage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setUpPage();
    void runPage();
    //setters




signals:
    void endAll();
public slots:
    void changePage();
    void updatePageObjects();
    void setUpGM();
    void setUpGP();
    void setServerObj();
    void setGameClient();
    void setQAMObj();


private:

    //ui
    Ui::MainWindow *ui;

    //pages
    Page* currentPage;
    selectionPage* selectionPageObj;
    setPathPage* setPathPageObj;
    clientConnectionPage* clientConnectionPageObj;
    GMPage* GMObj;
    GamePage* gamePageObj;
    //others
    Server* serverObj;
    QnAManager* QAMObj;

    GameServer* gameServerObj;
    GameClient* gameClientObj;



};
#endif // MAINWINDOW_H
