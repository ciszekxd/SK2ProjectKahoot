#include "gmpage.h"

GMPage::GMPage()
{
    this->pageIndex = 2;
}

void GMPage::setUpPage(Ui::MainWindow* ui){
    this->tempUi = ui;
    std::cout << "Game Master Page just set up!" << std::endl;
}

void GMPage::setServerObj(Server *newServer){
    this->serverObj = newServer;
}

void GMPage::startGame(){
    this->serverObj->writeToClients("START");
    tempUi->startGame->setDisabled(true);
}
