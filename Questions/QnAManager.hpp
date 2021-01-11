//
// Created by ciszek on 31.12.2020.
//
#pragma once
#include "ABCQandAInterface.hpp"
#include <vector>
#include <fstream>
#include "Question.hpp"
#include "Answer.hpp"

class QnAManager: public QandAInterface{
private:
    std::string path;
    std::vector<Question> questions;
    Question tempQue;
public:
    QnAManager(std::string path){
        this->path=path;
    }

    bool isPathValid(){
        ifstream inFile(this->path);
        if(!inFile){
            return 0;
        }else{
            return 1;
        }
    }

    void loadQuestions() override{

        string tempStr;
        bool TorF;

        ifstream inFile(this->path);
        if (!inFile) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }

        while (inFile.peek() != EOF) {
            inFile >> tempStr;
            if (!tempStr.compare("Q")){
                std::getline(inFile,tempStr);
                tempQue.setQuestion(tempStr);
                for(int i=0; i<4; i++){
                    inFile >> TorF;
                    std::getline(inFile, tempStr);
                    tempQue.setAnswer(tempStr,TorF);
                }
            }else{
                std::getline(inFile,tempStr);
            }
        }

        inFile.close();

    }

    Question getQuestion(int nr) override{
        return questions[nr+1];
    }

};
