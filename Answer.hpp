//
// Created by ciszek on 30.12.2020.
//
#pragma once
#include <string>
using namespace std;
class Answer{
private:
    bool isGood;
    string content;
public:

    void setIsGood(bool val){
        this->isGood = val;
    }

    void setContent(string text){
        this->content = text;
    }

    bool getIsGood(){
        return isGood;
    }

    string getContent(){
        return content;
    }
};
