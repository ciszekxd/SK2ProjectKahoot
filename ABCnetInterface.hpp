//
// Created by ciszek on 30.12.2020.
//
#pragma once
#include <string>

using namespace std;

class netInterface{
public:
    virtual string generatePin()=0;
    virtual string submitPin()=0;
    //get players returned type may change in the future
    virtual int* getPlayersData()=0;

};
