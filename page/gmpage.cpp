#include "gmpage.h"

GMPage::GMPage()
{
    this->pageIndex = 2;

}

GMPage::~GMPage(){
    std::cout << "gm page deleted" << std::endl;
}

void GMPage::setUpPage(Ui::MainWindow* ui){
    this->tempUi = ui;
    emit readyForSetUp();

    connect(tempUi->startGame,&QPushButton::clicked,this,&GMPage::startGame);
    std::cout << "Game Master Page just set up!" << std::endl;
}

void GMPage::showUsersNumber(){
    usersNumber = this->gameServerObj->getUsersNumber();
    tempUi->numOfusers->setText(QString::number(usersNumber));
}

void GMPage::setGameServerObj(GameServer *newServer){
    this->gameServerObj = newServer;
}

void GMPage::startGame(){
    this->gameServerObj->writeToClients("START");
    tempUi->startGame->setDisabled(true);
}
