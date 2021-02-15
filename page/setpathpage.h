#ifndef SETPATHPAGE_H
#define SETPATHPAGE_H
#include "page.h"

class setPathPage : public Page
{
public:
    explicit setPathPage();
    ~setPathPage();
    void setUpPage(Ui::MainWindow*);
    void goToGMPage();
    Server* getServerObj();
    QnAManager* getQAMObj();


    void submitPath();

    std::string pathToConfig;

signals:


private:

    QnAManager* QAM;
    Server* serverObj;

};

#endif // SETPATHPAGE_H
