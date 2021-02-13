#include "mainwindowv2.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    this->selectionPageObj = new selectionPage;
    this->setPathPageObj = new setPathPage;
    this->clientConnectionObj = new clientConnectionPage;
    this->GMObj = new GMPage;
    this->gamePageObj = new GamePage;

    this->currentPage = this->selectionPageObj;

    //selectionPageConnections-------------------
    connect(ui->ServerButton,&QPushButton::clicked,selectionPageObj,&selectionPage::goToSetPathPage);
    connect(ui->ClientButton,&QPushButton::clicked,selectionPageObj,&selectionPage::goToClientConnectionPage);
    //END-----------------------------------------

    //ClientConnectionPage------------------------
    connect(this, SIGNAL(endAll()), clientConnectionObj->getCCMObj(), SLOT(endConnection()));
    //END-----------------------------------------

    //general-------------------------------------
    connect(this->currentPage, SIGNAL(readyForChange()),this,SLOT(changePage()));
    connect(this->setPathPageObj, SIGNAL(newServerMade()),this,SLOT(setServerObj()));
    //END-----------------------------------------

    runPage();

}
void MainWindow::setServerObj(){
    this->serverObj = setPathPageObj->getServerObj();
}

void MainWindow::updatePageObjects(){
    this->GMObj->setServerObj(serverObj);
}

void MainWindow::runPage(){
     ui->stackedWidget->setCurrentIndex(currentPage->getPageIndex());
}
void MainWindow::setUpPage(){
    currentPage->setUpPage(ui);
}

void MainWindow::changePage(){
    std::string newPage = currentPage->getNextPage();
    if(newPage.compare("setPathPage") == 0){
        currentPage = setPathPageObj;
    }else if(newPage.compare("clientConnectionPage") == 0){
        currentPage = clientConnectionObj;
    }else if(newPage.compare("GMPage") == 0){
        currentPage = GMObj;
    }else if(newPage.compare("GamePage") == 0){
        currentPage = gamePageObj;
    }
    updatePageObjects();
    setUpPage();
    runPage();
}


MainWindow::~MainWindow()
{
    emit endAll();
    std::cout << "finish" << std::endl;
    delete ui;
}
