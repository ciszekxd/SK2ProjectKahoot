#include "selectionpage.h"
#include <iostream>

selectionPage::selectionPage()
{
    this->pageIndex = 0;
    //connect(MainWindow::ui->ServerButton, &QPushButton::clicked, this, &MainWindow::changePage);
    //connect(ui->ClientButton, &QPushButton::clicked, this, &MainWindow::selectClientMode);
}
/*
int selectionPage::getPageIndex(){
    return this->pageIndex;
}
*/

void selectionPage::setUpPage(Ui::MainWindow*){
    std::cout << "selection page runs" << std::endl;
}

void selectionPage::goToSetPathPage(){
    this->nextPage = "setPathPage";
    emit readyForChange();
}

void selectionPage::goToClientConnectionPage(){
    this->nextPage = "clientConnectionPage";
    emit readyForChange();
}
