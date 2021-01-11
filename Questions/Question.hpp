//
// Created by ciszek on 29.12.2020.
//
#pragma once
#include <string>
#include "Answer.hpp"

using namespace std;

class Question{

private:
    string content;
    Answer QAnswers[4];
    int AnsIte = 0;
public:

    string getQuestion(){
        return content;
    }

    void setAnswer(string text, bool val){
        QAnswers[AnsIte].setContent(text);
        QAnswers[AnsIte].setIsGood(val);
        if(AnsIte < 4) AnsIte++;
    }

    void setQuestion(string content){
        this->content = content;
    }


};