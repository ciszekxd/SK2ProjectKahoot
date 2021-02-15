#include "gamepage.h"

GamePage::GamePage()
{
    this->pageIndex = 3;
}

GamePage::~GamePage(){
    std::cout << "dec active gp" << std::endl;
}

void GamePage::setUpPage(Ui::MainWindow *){
    std::cout << "game page set up!" << std::endl;
}
