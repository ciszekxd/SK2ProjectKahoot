#include "gameclient.h"
#include <QObject>
#include <iostream>

GameClient::GameClient(ClientConnectionManager* CCM)
{
   this->gameCCM = CCM;
   this->currQuestion = new Question();
   connect(gameCCM, SIGNAL(readingStarts()),this,SLOT(processIncData()));
}

void GameClient::processIncData(){
    std::string tempString;
    std::string key = gameCCM->readFromServer();
    std::cout << key << std::endl;
    if(key.compare("Q") == 0){
        tempString = gameCCM->readFromServer();
        currQuestion->setQuestion(tempString);
        for(int i=0; i<4; i++){
            tempString = gameCCM->readFromServer();
            currQuestion->setAnswer(tempString);
        }
    }else if(key.compare("START") == 0){
        emit gameStarts();
    }
}


std::string GameClient::getQuestion(){
    return this->currQuestion->getQuestion();

}
std::string GameClient::getAnswer(int AnsNum){
    Answer* tempAns = this->currQuestion->getAnswer();
    return tempAns[AnsNum].getContent();
}
