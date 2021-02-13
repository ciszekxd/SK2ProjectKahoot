#ifndef SELECTIONPAGE_H
#define SELECTIONPAGE_H

#include <QObject>
#include "page.h"

class selectionPage : public Page
{
    Q_OBJECT
public:
    explicit selectionPage();
    int getPageIndex();
    void setUpPage(Ui::MainWindow*);

    void goToSetPathPage();
    void goToClientConnectionPage();

signals:

private:


};

#endif // SELECTIONPAGE_H
