#pragma once

#include <vector>
#include "Question.hpp"
#include "ABCnetInterface.hpp"
#include "ABCuserInterface.hpp"
#include <string>
#include "QnAManager.hpp"


class Kahoot{

public:


    Kahoot(){

        runKahoot();
    }

private:
    string pathToConfigFile;

public:
    void setPathToConfigFile(string path){
        this->pathToConfigFile = path;
    }

    void runKahoot(){
        //ask about operating mode
        //
        //in future arg below would be taken from user
        setPathToConfigFile("/home/ciszek/SK2/SK2ProjectKahoot/GameConfig.txt");

        QnAManager QnA(this->pathToConfigFile);


        QnA.loadQuestions();

    }

};
