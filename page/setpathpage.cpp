#include "setpathpage.h"

setPathPage::setPathPage()
{
    this->pageIndex = 1;
}

setPathPage::~setPathPage(){
    delete tempUi;
    delete QAM;
    delete serverObj;

}

/*
int setPathPage::getPageIndex(){
    return this->pageIndex;
}
*/
void setPathPage::setUpPage(Ui::MainWindow* ui){
    this->tempUi = ui;
    connect(ui->submitPath, &QPushButton::clicked, this, &setPathPage::submitPath);
    tempUi->label_3->setVisible(false);

    std::cout << "page of path setting runs" << std::endl;
}

void setPathPage::submitPath(){
    QString fromScreen;
        fromScreen = tempUi->lineEdit->text();

        //debug
        qDebug("%s", qUtf8Printable(fromScreen));
        //

        this->pathToConfig = fromScreen.toStdString();
        std::cout << this->pathToConfig << std::endl;
        this->QAM = new QnAManager(this->pathToConfig);

        if(QAM->isPathValid()){
            QAM->loadQuestions();

            //give QAM to mainwindow
            emit newQAMMade();

            //create and run server
            this->serverObj = new Server;

            emit newServerMade();

            serverObj->runServer();
            goToGMPage();

        }else{
            tempUi->label_3->setVisible(true);
        }
}

void setPathPage::goToGMPage(){
    this->nextPage = "GMPage";
    emit readyForChange();
}

Server* setPathPage::getServerObj(){
    return this->serverObj;
}

QnAManager* setPathPage::getQAMObj(){
    return this->QAM;
}
