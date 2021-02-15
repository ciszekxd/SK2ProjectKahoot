#include "gameserver.h"

GameServer::GameServer(Server* server, QnAManager* QAM)
{
    this->serverObj = server;
    this->QnAMObj = QAM;
}

GameServer::~GameServer(){
    delete serverObj;
    delete QnAMObj;
}

void GameServer::sendQuestion(int Qnumber){
    serverObj->writeToClients("Q");

    //send question
    Question tempQue = QnAMObj->getQuestion(Qnumber);
    serverObj->writeToClients(tempQue.getQuestion());

    Answer* tempAns = tempQue.getAnswer();
    for(int j=0; j < 4; j++){
        serverObj->writeToClients(tempAns[j].getContent());
    }


}
//dorobić write to clients
void GameServer::writeToClients(std::string str){
    serverObj->writeToClients(str);
}
