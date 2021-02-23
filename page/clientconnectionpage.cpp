#include "clientconnectionpage.h"

clientConnectionPage::clientConnectionPage()
{
    this->pageIndex = 4;
    this->connected = false;
    this->CCMObj = new ClientConnectionManager;
    CCpassed = false;
    GCpassed = false;
    GCsetted = false;
    ip = "127.0.0.1";
    emit newGCMade();


}

clientConnectionPage::~clientConnectionPage(){
    if(!CCpassed) delete CCMObj;
    std::cout << "CCMObj deleted" << std::endl;
    if(!GCpassed && GCsetted) delete GCObj;
    std::cout << "GCObj deleted" << std::endl;

}

bool clientConnectionPage::isNumber(std::string str)
{
    int size = str.size();
    for (int i=0; i < size; i ++) {
        if (std::isdigit(str.at(i)) == 0) return false;
    }
    return true;
}


void clientConnectionPage::setClientsName(){
    Client* tempCli = CCMObj->getClient();
    tempCli->setName(tempUi->nameLine->text().toStdString());
    this->GCObj->sendClientsName();
}

void clientConnectionPage::setIpFromUi(){
    ip = tempUi->ipLine->text();



    if(ip.size() == 12 && isNumber(ip.toStdString())){

        QString trueIp = QString::fromStdString(codeToIp(ip.toStdString()));

        Client* newClient = new Client("12137",trueIp, "PlaceguHolderName");
        this->CCMObj->setClient(newClient);
        this->GCObj->reconnectClient();

        //name setting
        tempUi->submitName->setDisabled(false);
        tempUi->submitName->setVisible(true);

        tempUi->nameLine->setDisabled(false);
        tempUi->nameLine->setVisible(true);

        tempUi->setName->setVisible(true);

        connect(tempUi->submitName,&QPushButton::clicked,this,&clientConnectionPage::setClientsName);

        connected = true;

    }else{
        tempUi->badCode->setVisible(true);
    }
}


std::string clientConnectionPage::codeToIp(std::string code){
    std::string ip = "";
    std::string tempStr = "";
    bool notFirstZ = false;

    for(int i=0; i<4; i++){
        tempStr = code.substr(i*3,i*3+3);
        for(int j=0; j<3; j++){
            if(tempStr.at(j) != '0' || notFirstZ || j == 2){
                ip += tempStr.at(j);
                notFirstZ = true;
            }
        }
        notFirstZ = false;
        if(i != 3) ip += ".";
    }
    return ip;
}

void clientConnectionPage::gameStarts(){
    if(this->connected){
        goToGamePage();
    }
}

void clientConnectionPage::setUpPage(Ui::MainWindow* ui){

    this->tempUi = ui;

    //set ui
    tempUi->badCode->setVisible(false);

    tempUi->submitName->setDisabled(true);
    tempUi->submitName->setVisible(false);

    tempUi->nameLine->setDisabled(true);
    tempUi->nameLine->setVisible(false);

    tempUi->setName->setVisible(false);


    Client* newClient = new Client();

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
    connect(tempUi->submitIp, &QPushButton::clicked, this, &clientConnectionPage::setIpFromUi);


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
