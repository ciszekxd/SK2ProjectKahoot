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
}
GameClient::~GameClient(){
    delete currQuestion;
    delete gameCCM;
}

void GameClient::processIncData(){
    /*std::string tempString;
    std::string key = gameCCM->readFromServer();
    std::cout << key << std::endl;*/

    std::string tempString = gameCCM->readFromServer();


    if(tempString.compare("START") == 0){
            emit gameStarts();
            sendClientsName();
    }else{

        std::string tempMes = tempString.substr(2,tempString.size()-2);

        if(tempString.at(0) == 'Q'){
            currQuestion->setQuestion(tempMes);
            for(int j=0; j<4; j++){
                tempString = gameCCM->readFromServer();
                tempMes = tempString.substr(2,tempString.size()-2);

                if(tempString.at(0) == 'A'){
                    currQuestion->setAnswer(tempMes);
                    //rcvdAnswers++;
                    //if(rcvdAnswers >= 4){

                        //rcvdAnswers = 0;
                    //}
                }
            }
            emit changeQuestions();
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
