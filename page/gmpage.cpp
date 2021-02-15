#include "gmpage.h"

GMPage::GMPage()
{
    this->pageIndex = 2;
}

GMPage::~GMPage(){
    delete gameServerObj;
    delete QAMObj;
}

void GMPage::setUpPage(Ui::MainWindow* ui){
    this->tempUi = ui;
    emit readyForSetUp();
    std::cout << "Game Master Page just set up!" << std::endl;
}

void GMPage::setGameServerObj(GameServer *newServer){
    this->gameServerObj = newServer;
}

void GMPage::startGame(){
    this->gameServerObj->writeToClients("START");
    tempUi->startGame->setDisabled(true);
}
