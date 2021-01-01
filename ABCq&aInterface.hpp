//
// Created by ciszek on 30.12.2020.
//
#include "Question.hpp"


class QandAInterface{

    virtual void loadQuestions()=0;
    virtual Question getQuestion(int nr)=0;
};
