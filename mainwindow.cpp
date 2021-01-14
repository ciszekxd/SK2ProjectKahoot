#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_3->setVisible(false);
    connect(ui->ServerButton, &QPushButton::clicked, this, &MainWindow::P1B1onClick);
    connect(ui->ClientButton, &QPushButton::clicked, this, &MainWindow::P1B2onClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printer()
{
    std::cout << "server was clicked" << std::endl;
}

//change screen
void MainWindow::P1B2onClick(){
    ui->stackedWidget->setCurrentIndex(3);
    //connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::P2B1onClick);
    this->clientObj = new Client("12137","127.0.0.1");
}

void MainWindow::P2B1onClick(){
    //takeing things from screen
    QString fromScreen;
    fromScreen = ui->lineEdit->text();

    //debug
    qDebug("%s", qUtf8Printable(fromScreen));

    //running Q'n A manager
    this->pathToConfig = fromScreen.toStdString();
    std::cout << this->pathToConfig << std::endl;
    this->QAM = new QnAManager(this->pathToConfig);

   // if(QAM->isPathValid()){
        QAM->loadQuestions();
        this->serverObj = new Server;
        ui->stackedWidget->setCurrentIndex(2);
   // }else{
    //    ui->label_3->setVisible(true);
   // }
}


//go to setting path
void MainWindow::P1B1onClick(){
    ui->stackedWidget->setCurrentIndex(1);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::P2B1onClick);
}





/*void MainWindow::changeUi()
{
    delete ui;
    uiT2->setupUi(this);
}*/
