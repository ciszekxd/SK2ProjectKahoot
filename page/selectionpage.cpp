#include "selectionpage.h"
#include <iostream>

selectionPage::selectionPage()
{
    this->pageIndex = 0;
    //connect(MainWindow::ui->ServerButton, &QPushButton::clicked, this, &MainWindow::changePage);
    //connect(ui->ClientButton, &QPushButton::clicked, this, &MainWindow::selectClientMode);
}
selectionPage::~selectionPage(){
    std::cout << "dec active sp" << std::endl;
}


void selectionPage::setUpPage(Ui::MainWindow* ui){

    this->tempUi = ui;

    connect(tempUi->ServerButton,&QPushButton::clicked,this,&selectionPage::goToSetPathPage);
    connect(tempUi->ClientButton,&QPushButton::clicked,this,&selectionPage::goToClientConnectionPage);

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
