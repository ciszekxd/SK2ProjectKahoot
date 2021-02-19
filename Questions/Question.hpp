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

    void setAnswer(string text){
        QAnswers[AnsIte].setContent(text);
        if(AnsIte < 3) AnsIte++;
        else AnsIte = 0;
    }

    void setAnswer(string text, bool val){
        QAnswers[AnsIte].setContent(text);
        QAnswers[AnsIte].setIsGood(val);
        if(AnsIte < 3) AnsIte++;
        else AnsIte = 0;
    }

    void setQuestion(string content){
        this->content = content;
    }

    Answer* getAnswer(){
        Answer * ans = &QAnswers[0];
        return ans;
    }

    std::string getAnswer(int x){
        return QAnswers[x].getContent();
    }

    int getRightAnswer(){
        for(int i=0; i<4; i++){
            if(QAnswers[i].getIsGood()) return i;
        }
        return -1;
    }

};
