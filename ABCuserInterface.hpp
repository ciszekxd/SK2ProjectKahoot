//
// Created by ciszek on 30.12.2020.
//

#pragma once

class userInterface{
public:
    virtual void putOnScreen()=0;
    virtual void askUser(string question)=0;
};
