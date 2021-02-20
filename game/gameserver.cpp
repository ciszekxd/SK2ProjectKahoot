#include "gameserver.h"

GameServer::GameServer(Server* server, QnAManager* QAM)
{
    this->serverObj = server;
    this->QnAMObj = QAM;
    connect(this->serverObj, SIGNAL(usersNumberChanged()),this,SLOT(onUsersNumberChanged()));
    currentQuestion = 0;
    numOfQuestions = QnAMObj->AmountOfQuestions();
    Timer = new QTimer(this);
    Timer->start(1000);
    connect(Timer,SIGNAL(timeout()),this,SLOT(nextSecond()));
    timerClock = 0;
    timeForQuestion = 30;

}

GameServer::~GameServer(){
    delete Timer;
    std::cout << "dec active s" << std::endl;
}

int GameServer::getCurrClock(){
    return timerClock;
}

Client *GameServer::findWinner()
{
    QList<Client*> tempQL = getServer()->getPlayerList();
    Client* maxScore = NULL;
    for(int i=0; i<tempQL.size(); i++){
        if(maxScore->getScore()<tempQL[i]->getScore() || maxScore == NULL){
            maxScore = tempQL[i];
        }
    }
    return maxScore;
}

void GameServer::nextSecond(){
    if(timerClock++ >= timeForQuestion){
        timerClock = 0;
        emit nextQue();
    }
    emit nextSec();
}


void GameServer::onUsersNumberChanged(){
    emit usersNumberChanged();
}

int GameServer::getUsersNumber(){
    return serverObj->getUsersNumber();
}
//start game loop
void GameServer::startGame()
{
    QList<Client*> tempQL = getServer()->getPlayerList();

    for(int i=0; i<tempQL.size(); i++){
        connect(tempQL[i]->getSocket(),SIGNAL(readyRead()),this,SLOT(readFromClient()));
    }

    writeToClients("START");
    connect(this, SIGNAL(nextQue()),this,SLOT(sendQuestion()));
    //tempUi->startGame->setDisabled(true);
}
//end game loop
void GameServer::sendQuestion(){
    //serverObj->writeToClients("Q");
    std::string tempStr = "Q ";
    //send question
    Question tempQue = QnAMObj->getQuestion(currentQuestion);
    serverObj->writeToClients(tempStr + tempQue.getQuestion() + "\n");
    tempStr = "A ";
    Answer* tempAns = tempQue.getAnswer();
    for(int j=0; j < 4; j++){
        serverObj->writeToClients(tempStr + tempAns[j].getContent() + "\n");
    }
    currentQuestion++;
    if(currentQuestion == numOfQuestions){
        disconnect(Timer, SIGNAL(timeout()), 0, 0);
        Client* tempCli = findWinner();
        serverObj->writeToClients("W " + tempCli->getName());
    }

}

void GameServer::writeToClients(std::string str){
    serverObj->writeToClients(str);
}

Server *GameServer::getServer()
{
    return this->serverObj;
}

Client *GameServer::findClient(QTcpSocket* sockToLookFor)
{
    QList<Client*> tempQL = serverObj->getPlayerList();
    for (int i=0; i<tempQL.count();i++){
        if(tempQL[i]->getSocket() == sockToLookFor) return tempQL[i];
    }
    return NULL;
}

void GameServer::givePoints(Client *certCli)
{
    int curScore = certCli->getScore();
    certCli->setScore(curScore + 100);
}


void GameServer::readFromClient(){

    QList<Client*> tempQL = getServer()->getPlayerList();

    QByteArray buffer;
    QTcpSocket* readSocket = qobject_cast<QTcpSocket*>(sender());

    buffer = readSocket->readLine();
    std::string myText = buffer.toStdString();
    std::string myTextContent = myText.substr(2,myText.size());

    if(myText.at(0) == 'N'){
        findClient(readSocket)->setName(myTextContent);
        emit updateCliNaS();
    }else if(myText.at(0) == 'R'){
        int rcvedAns = std::stoi(myTextContent);
        Client* tempCli = findClient(readSocket);
        if(rcvedAns == QnAMObj->getQuestion(currentQuestion).getRightAnswer()+1) givePoints(tempCli);
        emit updateCliNaS();






    }

   // std::cout << mytext << std::endl;

}






