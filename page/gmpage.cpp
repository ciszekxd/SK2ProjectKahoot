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
    gameServerObj->startGame();
    tempUi->startGame->setDisabled(true);
}


void GMPage::showPlayersNames()
{
    QList<Client*> tempQlist = gameServerObj->getServer()->getPlayerList();
    std::string tempString = "";

    for(int i=0; i<tempQlist.count();i++){
        tempString = tempString + tempQlist[i]->getName() + " : ";
        tempString = tempString + std::to_string(tempQlist[i]->getScore());
        tempString = tempString + "\n";
    }

    QString tempQstr = QString::fromUtf8(tempString.c_str());

    tempUi->players->setText(tempQstr);
}
