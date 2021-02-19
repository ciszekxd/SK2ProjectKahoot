#include "gamepage.h"

GamePage::GamePage()
{
    this->pageIndex = 3;
}

GamePage::~GamePage(){
    std::cout << "dec active gp" << std::endl;
}

void GamePage::setGameClient(GameClient* GCObj)
{
    this->GCObj = GCObj;
}

void GamePage::setUpPage(Ui::MainWindow *ui){
    tempUi = ui;
    emit readyForSetUp();

    std::cout << "game page set up!" << std::endl;
}



void GamePage::setQuestionsAtPage()
{
    QString tempQstr;
    tempQstr = QString::fromUtf8(GCObj->getQuestion().c_str());
    tempUi->questionField->setText(tempQstr);


    //QString::fromUtf8(content.c_str());
    tempQstr = QString::fromUtf8(GCObj->getAnswer(0).c_str());
    tempUi->Answer1->setText(tempQstr);

    tempQstr = QString::fromUtf8(GCObj->getAnswer(1).c_str());
    tempUi->Answer2->setText(tempQstr);

    tempQstr = QString::fromUtf8(GCObj->getAnswer(2).c_str());
    tempUi->Answer3->setText(tempQstr);

    tempQstr = QString::fromUtf8(GCObj->getAnswer(3).c_str());
    tempUi->Answer4->setText(tempQstr);
}

void GamePage::disableAnswers()
{
    tempUi->Answer1->setDisabled(true);
    tempUi->Answer2->setDisabled(true);
    tempUi->Answer3->setDisabled(true);
    tempUi->Answer4->setDisabled(true);
}

void GamePage::enableAnswers()
{
    tempUi->Answer1->setEnabled(true);
    tempUi->Answer2->setEnabled(true);
    tempUi->Answer3->setEnabled(true);
    tempUi->Answer4->setEnabled(true);
}
