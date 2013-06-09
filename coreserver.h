#ifndef CORESERVER_H
#define CORESERVER_H

#include <QTcpServer>
#include <QList>
#include <QString>
#include <QVariant>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>

#include "func.h"

class CoreServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit CoreServer(QObject *parent = 0);
    
signals:
    
public slots:
    void incoming();
    void receiving();
    void leaving();
private:
    QTcpSocket *client;
    quint16 length;
};

#endif // CORESERVER_H
