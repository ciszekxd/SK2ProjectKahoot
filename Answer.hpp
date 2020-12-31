//
// Created by ciszek on 30.12.2020.
//

#include <string>
using namespace std;
class Answer{
    Answer(string content, bool isGood){
        this->content = content;
        this->isGood = isGood;
    }
private:
    bool isGood;
    string content;
public:

    bool getIsGood(){
        return isGood;
    }

    string getContent(){
        return content;
    }
};
