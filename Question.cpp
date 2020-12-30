//
// Created by ciszek on 29.12.2020.
//
#include <string>

using namespace std;

class Question{
    string Question;

    string getQuestion(){
        return Question;
    }

    void setQuestion(string content){
        Question = content;
    }
};