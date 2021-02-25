#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QString>
#include <vector>


class Client : public QObject
{
    Q_OBJECT
public:

    Client(QString, QString, QString);
    Client();
    ~Client();

//getters and setters
    std::string getName();
    void setName(std::string);
    int getScore();
    void setScore(int);
    QTcpSocket*  getSocket();
    void setSocket(QTcpSocket*);
    bool isReadingSet();
    void ReadingSet();
    void setLastAns(std::string);
    std::string getLastAns();
    std::vector<std::string> getAnsHistory();


public slots:
//    void quitFromServerGracefully();

private:
    int score;
    std::string name;
    QTcpSocket* socketObj;
    bool readSet;
    std::string lastAns;
    std::vector<std::string> ansHistory;

};

#endif // CLIENT_H
