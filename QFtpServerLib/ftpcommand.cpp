#include "ftpcommand.h"



FtpCommand::FtpCommand(QObject *parent) :
    QObject(parent)
{
    started = false;
}

void FtpCommand::start(QSslSocket *socket)
{
    started = true;
    this->socket = socket;
    socket->setParent(this);
    connect(socket, SIGNAL(disconnected()), this, SLOT(deleteLater()));
    startImplementation();
}
