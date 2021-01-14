#include "client.h"

Client::Client(QString port, QString ip)
{
    this->socketObj.abort();
    this->socketObj.connectToHost(ip, port.toInt());
}
