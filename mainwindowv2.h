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

    void setQAMObj();


signals:
    void endAll();
public slots:
    void changePage();
    void updatePageObjects();
    void setUpGM();
    void setServerObj();


private:
    Ui::MainWindow *ui;
    Page* currentPage;
    selectionPage* selectionPageObj;
    setPathPage* setPathPageObj;
    clientConnectionPage* clientConnectionObj;
    GMPage* GMObj;
    Server* serverObj;
    GamePage* gamePageObj;
    QnAManager* QAMObj;
    GameServer* gameServerObj;



};
#endif // MAINWINDOW_H
