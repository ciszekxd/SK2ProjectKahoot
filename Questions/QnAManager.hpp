//
// Created by ciszek on 31.12.2020.
//
#pragma once

#include <vector>
#include <fstream>
#include "Question.hpp"
#include "Answer.hpp"
#include <iostream>
#include <string>

class QnAManager{
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
            inFile.close();
            return 0;
        }else{
            inFile.close();
            return 1;
        }
    }

    void loadQuestions(){

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
                questions.push_back(tempQue);
            }else{
                std::getline(inFile,tempStr);
            }
        }

        inFile.close();

    }

    Question getQuestion(int nr) {
        return questions[nr];
    }

    int AmountOfQuestions(){
        return questions.size();
    }
};
