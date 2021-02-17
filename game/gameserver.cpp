#include "gameserver.h"

GameServer::GameServer(Server* server, QnAManager* QAM)
{
    this->serverObj = server;
    this->QnAMObj = QAM;
    connect(this->serverObj, SIGNAL(usersNumberChanged()),this,SLOT(onUsersNumberChanged()));
    currentQuestion = 0;
    Timer = new QTimer(this);


}

GameServer::~GameServer(){
    delete Timer;
    std::cout << "dec active s" << std::endl;
}
void GameServer::onUsersNumberChanged(){
    emit usersNumberChanged();
}

int GameServer::getUsersNumber(){
    return serverObj->getUsersNumber();
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
