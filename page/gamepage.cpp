#include "gamepage.h"

GamePage::GamePage()
{
    this->pageIndex = 3;
}

void GamePage::setUpPage(Ui::MainWindow *){
    std::cout << "game page set up!" << std::endl;
}
