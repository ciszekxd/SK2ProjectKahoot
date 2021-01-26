#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include "server.h"
#include "client.h"
#include "clientconnectionmanager.h"
#include "./Questions/QnAManager.hpp"
#include "gameclient.h"
#include "gameserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printer();
    void P1B1onClick();
    void P1B2onClick();
    void P2B1onClick();
    void P3B1onClick();
    void P4B1onClick();
    void SetUpGamerPage();
    void checkAgain();


public slots:

    void updateServerUsers();
    void DisplayGamerPage();

signals:

    void endAll();
private:

    Ui::MainWindow *ui;
    std::string pathToConfig;
    Server *serverObj;
    QnAManager *QAM;

public:
    GameServer* GM;
    GameClient* GClient;
    ClientConnectionManager* CCMObj;

};
#endif // MAINWINDOW_H
