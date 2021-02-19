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
    this->QAMObj = NULL;
    this->serverObj = NULL;
    this->gameServerObj = NULL;
    this->gameClientObj = NULL;


    //ClientConnectionPage------------------------
    connect(this, SIGNAL(endAll()), clientConnectionObj->getCCMObj(), SLOT(endConnection()));
    //END-----------------------------------------

    //general-------------------------------------
    connect(this->currentPage, SIGNAL(readyForChange()),this,SLOT(changePage()));
    connect(this->setPathPageObj, SIGNAL(newServerMade()),this,SLOT(setServerObj()));
    connect(this->setPathPageObj, SIGNAL(newQAMMade()),this,SLOT(setQAMObj()));
    //END-----------------------------------------

    //GM------------------------------------------
    connect(this->GMObj,SIGNAL(readyForSetUp()),this,SLOT(setUpGM()));
    //END-----------------------------------------

    //GC------------------------------------------
    connect(this->clientConnectionObj, SIGNAL(newGCMade()),this, SLOT(setGameClient()));
    //END-----------------------------------------

    //GP------------------------------------------
    connect(this->gamePageObj,SIGNAL(readyForSetUp()),this,SLOT(setUpGP()));
    //END-----------------------------------------

    currentPage = selectionPageObj;

    setUpPage();
    runPage();

}

void MainWindow::setUpGM(){
    this->gameServerObj = new GameServer(serverObj,QAMObj);
    this->GMObj->setGameServerObj(gameServerObj);
    connect(this->gameServerObj,SIGNAL(usersNumberChanged()),this->GMObj,SLOT(showUsersNumber()));
    connect(gameServerObj, SIGNAL(updateCliNaS()), GMObj, SLOT(showPlayersNames()));
    connect(ui->debugSendQuestion,&QPushButton::clicked,gameServerObj,&GameServer::sendQuestion);

}

void MainWindow::setUpGP()
{
    this->gameClientObj = clientConnectionObj->getGameClient();
    this->gamePageObj->setGameClient(gameClientObj);
    connect(ui->debugSendName,&QPushButton::clicked,gameClientObj,&GameClient::sendClientsName);
    connect(gameClientObj,SIGNAL(changeQuestions()),gamePageObj,SLOT(setQuestionsAtPage()));
    //this->gamePageObj = new GameClient(this->clientConnectionObj);

    //answer buttons
    connect(ui->Answer1, &QPushButton::clicked, gameClientObj, &GameClient::sendUserAnswer1);
    connect(ui->Answer2, &QPushButton::clicked, gameClientObj, &GameClient::sendUserAnswer2);
    connect(ui->Answer3, &QPushButton::clicked, gameClientObj, &GameClient::sendUserAnswer3);
    connect(ui->Answer4, &QPushButton::clicked, gameClientObj, &GameClient::sendUserAnswer4);
}

void MainWindow::setServerObj(){
    this->serverObj = setPathPageObj->getServerObj();
}

void MainWindow::setGameClient(){
    this->gameClientObj = clientConnectionObj->getGameClient();
}

void MainWindow::setQAMObj(){
    this->QAMObj = setPathPageObj->getQAMObj();
}

void MainWindow::updatePageObjects(){
    connect(this->currentPage, SIGNAL(readyForChange()),this,SLOT(changePage()));
    //this->GMObj->setGameServerObj();
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
    }else if(newPage.compare("gamePage") == 0){
        currentPage = gamePageObj;
    }else if(newPage.compare("selectionPage") == 0){
        currentPage = selectionPageObj;
    }

    updatePageObjects();
    setUpPage();
    runPage();
}


MainWindow::~MainWindow()
{
    std::cout << "finishing starts1" << std::endl;
    delete this->selectionPageObj;
    std::cout << "finishing starts2" << std::endl;
    delete this->setPathPageObj;
    std::cout << "finishing starts3" << std::endl;
    delete this->GMObj;
    std::cout << "finishing starts4" << std::endl;
    delete this->gamePageObj;
    std::cout << "finishing starts5" << std::endl;
    delete this->clientConnectionObj;
    std::cout << "finishing starts6" << std::endl;
    if(serverObj != NULL) delete this->serverObj;
    std::cout << "finishing starts7" << std::endl;
    if(QAMObj != NULL) delete this->QAMObj;
    std::cout << "finishing starts8" << std::endl;
    if(gameServerObj != NULL) delete this->gameServerObj;
    std::cout << "finishing starts9" << std::endl;
    if(gameClientObj != NULL) delete this->gameClientObj;
    std::cout << "finishing starts10" << std::endl;

    delete ui;
    std::cout << "finished" << std::endl;

}
