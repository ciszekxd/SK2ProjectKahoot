#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_3->setVisible(false);

    connect(ui->ServerButton, &QPushButton::clicked, this, &MainWindow::P1B1onClick);
    connect(ui->ClientButton, &QPushButton::clicked, this, &MainWindow::P1B2onClick);
    connect(ui->testClient, &QPushButton::clicked, this, &MainWindow::P4B1onClick);
    connect(ui->testServer, &QPushButton::clicked, this, &MainWindow::P3B1onClick);
}

MainWindow::~MainWindow()
{
    emit endAll();
    std::cout << "finish" << std::endl;
    delete ui;
}

void MainWindow::printer()
{
    std::cout << "server was clicked" << std::endl;
}

//set program in client mode
void MainWindow::P1B2onClick(){
    ui->stackedWidget->setCurrentIndex(3);
    this->CCMObj = new ClientConnectionManager(new Client("12137","127.0.0.1", "PlaceHolderName"));
    connect(this, SIGNAL(endAll()), this->CCMObj,SLOT(endConnection()));
}

//button to take path for server
void MainWindow::P2B1onClick(){

    QString fromScreen;
    fromScreen = ui->lineEdit->text();

    //debug
    qDebug("%s", qUtf8Printable(fromScreen));
    //

    this->pathToConfig = fromScreen.toStdString();
    std::cout << this->pathToConfig << std::endl;
    this->QAM = new QnAManager(this->pathToConfig);

    if(QAM->isPathValid()){
        QAM->loadQuestions();

        //create and run server
        this->serverObj = new Server;
        connect(this->serverObj, SIGNAL(usersNumberChanged()),this, SLOT(updateServerUsers()));
        //connect(this, SIGNAL(endAll()), this->serverObj, SLOTS(onDisconnect));
        serverObj->runServer();
        //

        ui->stackedWidget->setCurrentIndex(2);
    }else{
        ui->label_3->setVisible(true);
    }
}


//go to setting path
void MainWindow::P1B1onClick(){
    ui->stackedWidget->setCurrentIndex(1);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::P2B1onClick);
}

// send message to server
void MainWindow::P4B1onClick(){
    this->CCMObj->writeToServer();

}

//send message to client
void MainWindow::P3B1onClick(){
    this->serverObj->writeToClients();
}


void MainWindow::updateServerUsers(){
    std::cout << "updated" << std::endl;
    QString uNum = QString::number(serverObj->getUsersNumber());
    ui->numOfusers->setText(uNum);
}



