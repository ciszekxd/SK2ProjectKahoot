#pragma once

#include <vector>
#include "Question.cpp"
#include "ABCnetInterface.cpp"
#include "ABCuserInterface.cpp"
#include <string>


class Kahoot{

public:
    userInterface userContact;
    netInterface netContact;

    Kahoot(){


    }

private:
    vector<Question>;
    string pathToConfigFile;

public:


    void runKahoot(){
        //ask about operating mode


    }
};
