//
// Created by ciszek on 29.12.2020.
//
#include <string>
#include "Answer.cpp"

using namespace std;

class Question{
private:
    string Question;
    Answer QAnswers[4];
public:
    string getQuestion(){
        return Question;
    }

    void setQuestion(string content){
        Question = content;
    }
};