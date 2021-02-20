#include "clientconnectionpage.h"

clientConnectionPage::clientConnectionPage()
{
    this->pageIndex = 4;
    this->connected = false;
    this->CCMObj = new ClientConnectionManager;
    CCpassed = false;
    GCpassed = false;
    GCsetted = false;

    emit newGCMade();


}

clientConnectionPage::~clientConnectionPage(){
    if(!CCpassed) delete CCMObj;
    std::cout << "CCMObj deleted" << std::endl;
    if(!GCpassed && GCsetted) delete GCObj;
    std::cout << "GCObj deleted" << std::endl;

}

void clientConnectionPage::gameStarts(){
    if(this->connected){
        goToGamePage();
    }
}

void clientConnectionPage::setUpPage(Ui::MainWindow* ui){

    this->tempUi = ui;

    Client* newClient = new Client("12137","127.0.0.1", "PlaceHolderName");

    this->CCMObj->setClient(newClient);
    this->GCObj = new GameClient(CCMObj);
    GCsetted = true;
    connect(this->GCObj,SIGNAL(gameStarts()),this,SLOT(gameStarts()));

    if(CCMObj->isConnected()){
        ui->statusConnected->setVisible(true);
        ui->statusDisconnected->setVisible(false);
        //important
        connected = true;
    }else{
        ui->statusConnected->setVisible(false);
        ui->statusDisconnected->setVisible(true);
    }

    connect(tempUi->checkAgain, &QPushButton::clicked, this, &clientConnectionPage::checkAgain);

    std::cout << "client connection page is runnung" << std::endl;
}
void clientConnectionPage::checkAgain(){
    if(CCMObj->isConnected()){
        tempUi->statusConnected->setVisible(true);
        tempUi->statusDisconnected->setVisible(false);
        //importana
        connected = true;
    }else{
        tempUi->statusConnected->setVisible(false);
        tempUi->statusDisconnected->setVisible(true);
        connected = false;
    }
}

void clientConnectionPage::goToGamePage(){
    nextPage = "gamePage";
    emit readyForChange();
}


ClientConnectionManager* clientConnectionPage::getCCMObj(){
    CCpassed = true;
    return this->CCMObj;

}
GameClient* clientConnectionPage::getGameClient(){
    GCpassed = true;
    return this->GCObj;
}
