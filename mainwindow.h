#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include "server.h"
#include "client.h"
#include "./Questions/QnAManager.hpp"

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
public slots:
    void updateServerUsers();

private:
    Ui::MainWindow *ui;
    std::string pathToConfig;
    Server *serverObj;
    QnAManager *QAM;
    Client *clientObj;


};
#endif // MAINWINDOW_H
