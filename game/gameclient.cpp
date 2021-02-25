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
   queNumber = -1;




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

ClientConnectionManager *GameClient::getCCM()
{
    return gameCCM;
}



std::string GameClient::prepareGameHistory(){
    std::string ENDstirng;
    Client* tempCli = getCCM()->getClient();
    std::vector<std::string> tempVec = tempCli->getAnsHistory();
    int vecIte = 0;
    int rcvedQuestions = queContents.size();
        for(int i=0; i < rcvedQuestions; i++){
            ENDstirng += queContents[i];
            ENDstirng += "your answer: ";
            int dbugCliAns = -1;
            //if digit at the end of string is the same as question
            if(tempVec.size()!=0){
                dbugCliAns = (int)tempVec[vecIte].at(tempVec[vecIte].size()-1) - 48;
            }
            if(dbugCliAns == i){
                ENDstirng += tempVec[vecIte].substr(1,tempVec[vecIte].size()-8);
                if((int)tempVec[vecIte].at(0) == corrAnsVec[i]){
                    ENDstirng += " (correct answer)";
                }else{
                    ENDstirng += " (incorrect answer)";
                }
                vecIte++;
            }else{
                ENDstirng += "<NONE>";
            }
            ENDstirng += "\n";

        }



    return ENDstirng;
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
            corrAnsVec.push_back((int)tempString.at(1));
            currQuestion->setQuestion(tempMes);
            queContents.push_back(tempMes);
            for(int j=0; j<4; j++){
                tempString = gameCCM->readFromServer();
                tempMes = tempString.substr(2,tempString.size()-2);
                if(tempString.at(0) == 'A'){
                    currQuestion->setAnswer(tempMes);
                }
            }
            queNumber++;
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
    gameCCM->getClient()->setLastAns("0"+ currQuestion->getAnswer(0)
                                     + "<que>" + std::to_string(queNumber));
    this->gameCCM->writeToServer("R 1");
    emit block();
}
void GameClient::sendUserAnswer2()
{
    gameCCM->getClient()->setLastAns("1"+currQuestion->getAnswer(1)
                                     + "<que>" + std::to_string(queNumber));
    this->gameCCM->writeToServer("R 2");
    emit block();
}
void GameClient::sendUserAnswer3()
{
    gameCCM->getClient()->setLastAns("2"+currQuestion->getAnswer(2)
                                     + "<que>" + std::to_string(queNumber));
    this->gameCCM->writeToServer("R 3");
    emit block();
}
void GameClient::sendUserAnswer4()
{
    gameCCM->getClient()->setLastAns("3"+currQuestion->getAnswer(3)
                                     + "<que>" + std::to_string(queNumber));
    this->gameCCM->writeToServer("R 4");
    emit block();
}
