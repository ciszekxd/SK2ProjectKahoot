#include "gameserver.h"

GameServer::GameServer(Server* server, QnAManager* QAM)
{
    this->serverObj = server;
    this->QnAMObj = QAM;
    connect(this->serverObj, SIGNAL(usersNumberChanged()),this,SLOT(onUsersNumberChanged()));
    currentQuestion = 0;
    Timer = new QTimer(this);
    Timer->start(1000);
    connect(Timer,SIGNAL(timeout()),this,SLOT(nextSecond()));
    timerClock = 0;


}

GameServer::~GameServer(){
    delete Timer;
    std::cout << "dec active s" << std::endl;
}

int GameServer::getCurrClock(){
    return timerClock;
}

void GameServer::nextSecond(){
    if(timerClock++ >= 60){
        timerClock = 0;
    }
    emit nextSec();
}


void GameServer::onUsersNumberChanged(){
    emit usersNumberChanged();
}

int GameServer::getUsersNumber(){
    return serverObj->getUsersNumber();
}

void GameServer::startGame()
{
    QList<Client*> tempQL = getServer()->getPlayerList();

    for(int i=0; i<tempQL.size(); i++){
        connect(tempQL[i]->getSocket(),SIGNAL(readyRead()),this,SLOT(readFromClient()));
    }

    writeToClients("START");
    //tempUi->startGame->setDisabled(true);
}

void GameServer::sendQuestion(int Qnumber){
    //serverObj->writeToClients("Q");
    std::string tempStr = "Q ";
    //send question
    Question tempQue = QnAMObj->getQuestion(0);
    serverObj->writeToClients(tempStr + tempQue.getQuestion() + "\n");
    tempStr = "A ";
    Answer* tempAns = tempQue.getAnswer();
    for(int j=0; j < 4; j++){
        serverObj->writeToClients(tempStr + tempAns[j].getContent() + "\n");
    }


}

void GameServer::writeToClients(std::string str){
    serverObj->writeToClients(str);
}



Server *GameServer::getServer()
{
    return this->serverObj;
}

Client *GameServer::findClient(QTcpSocket* sockToLookFor)
{
    QList<Client*> tempQL = serverObj->getPlayerList();
    for (int i=0; i<tempQL.count();i++){
        if(tempQL[i]->getSocket() == sockToLookFor) return tempQL[i];
    }
    return NULL;
}

void GameServer::givePoints(Client *certCli)
{
    int curScore = certCli->getScore();
    certCli->setScore(curScore + 100);
}


void GameServer::readFromClient(){

    QList<Client*> tempQL = getServer()->getPlayerList();

    QByteArray buffer;
    QTcpSocket* readSocket = qobject_cast<QTcpSocket*>(sender());

    buffer = readSocket->readLine();
    std::string myText = buffer.toStdString();
    std::string myTextContent = myText.substr(2,myText.size());

    //std::string tempStr = myText.at(0);
    if(myText.at(0) == 'N'){
        /*
        for (int i=0; i<tempQL.count();i++){
            if(tempQL[i]->getSocket() == readSocket) tempQL[i]->setName(myTextContent);
        }*/
        findClient(readSocket)->setName(myTextContent);
        emit updateCliNaS();
    }else if(myText.at(0) == 'R'){
        int rcvedAns = std::stoi(myTextContent);
        Client* tempCli = findClient(readSocket);
        if(rcvedAns == QnAMObj->getQuestion(currentQuestion).getRightAnswer()+1) givePoints(tempCli);
        emit updateCliNaS();



    }

   // std::cout << mytext << std::endl;

}






