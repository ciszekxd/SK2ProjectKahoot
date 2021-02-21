#include "gameclient.h"
#include <QObject>
#include <iostream>

GameClient::GameClient(ClientConnectionManager* CCM)
{
   this->gameCCM = CCM;
   this->currQuestion = new Question();
   //I!!!!!!!!!!!!!!!!!!!!!!!!!!
   std::cout << "connect starts" << std::endl;
   connect(gameCCM->getClient()->getSocket(), SIGNAL(readyRead()),this,SLOT(processIncData()));
   std::cout << "connect ends" << std::endl;
   rcvdAnswers = 0;
   winner = "NONE";




}

GameClient::~GameClient(){
    std::cout << "del currQuestuin" << std::endl;
    delete currQuestion;
    std::cout << "del clientconnectionmanager" << std::endl;
    delete gameCCM;
    std::cout << "del clientconnectionmanager end" << std::endl;
}

std::string GameClient::getWinner(){
    return winner;
}

void GameClient::reconnectClient(){
    connect(gameCCM->getClient()->getSocket(), SIGNAL(readyRead()),this,SLOT(processIncData()));
}



void GameClient::processIncData(){

    std::string tempString = gameCCM->readFromServer();
    if(tempString.compare("START\n") == 0){
            emit gameStarts();
            sendClientsName();
            processIncData();
    }else{
        std::string tempMes = tempString.substr(2,tempString.size()-2);
        if(tempString.at(0) == 'Q'){
            currQuestion->setQuestion(tempMes);
            for(int j=0; j<4; j++){
                tempString = gameCCM->readFromServer();
                tempMes = tempString.substr(2,tempString.size()-2);
                if(tempString.at(0) == 'A'){
                    currQuestion->setAnswer(tempMes);
                }
            }
            emit changeQuestions();
            emit unblock();
        }else if(tempString.at(0) == 'W'){
            winner = tempMes;
            emit endGame();

        }
    }
}


std::string GameClient::getQuestion(){
    return this->currQuestion->getQuestion();

}
std::string GameClient::getAnswer(int AnsNum){
    Answer* tempAns = this->currQuestion->getAnswer();
    return tempAns[AnsNum].getContent();
}

void GameClient::sendClientsName()
{
    std::string tempName = "N " + gameCCM->getClient()->getName();
    this->gameCCM->writeToServer(tempName);
}

void GameClient::sendUserAnswer1()
{
    this->gameCCM->writeToServer("R 1");
    emit block();
}
void GameClient::sendUserAnswer2()
{
    this->gameCCM->writeToServer("R 2");
    emit block();
}
void GameClient::sendUserAnswer3()
{
    this->gameCCM->writeToServer("R 3");
    emit block();
}
void GameClient::sendUserAnswer4()
{
    this->gameCCM->writeToServer("R 4");
    emit block();
}
