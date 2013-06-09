#include "coreserver.h"

CoreServer::CoreServer(QObject *parent) :
    QTcpServer(parent)
{
    if(!this->listen(QHostAddress::Any, 11111))
    {
        log("ERROR: could not start server. Reason:"+this->errorString());
        return;
    }
    log("Server was started on port"+QString::number(this->serverPort()));
    QObject::connect(this, SIGNAL(newConnection()), this, SLOT(incoming()));
    length = 0;

}

void CoreServer::receiving(){
    if(client == NULL)
        return;
    QDataStream in(client);

    if (length == 0)
    {
        if (client->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> length;
    }

    if (client->bytesAvailable() < length)
        return;

    QString command;
    in >> command;
    log("Received command from client: "+command);
}

void CoreServer::incoming()
{
    if(client != NULL)
    {
        log("A client tries to connect while another is already connected.");
    } else {
        client = this->nextPendingConnection();
        QObject::connect(client, SIGNAL(disconnected()), this, SLOT(leaving()));
        QObject::connect(client, SIGNAL(readyRead()), this, SLOT(receiveClient()));
    }
}

void CoreServer::leaving()
{
    //There is only one client possible so we remove it as it already disconnected
    client->deleteLater();
}

