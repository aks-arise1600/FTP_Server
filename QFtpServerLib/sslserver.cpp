#include "sslserver.h"

#include <QSslSocket>
#include <QSslKey>
#include <QDir>

SslServer::SslServer(QObject *parent) :
    QTcpServer(parent)
{
}

void SslServer::setLocalCertificateAndPrivateKey(QSslSocket *socket)
{

    QFile file(QDir::currentPath()+QDir::separator()+"softcom.key");

    if(file.exists())
        qDebug().noquote() <<QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss") <<__FUNCTION__<<":: "<<file.fileName();
    else
        qDebug().noquote() << QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss") <<__FUNCTION__<<":: "<<QDir::currentPath()<<file.fileName();

    socket->setPrivateKey(QDir::currentPath()+QDir::separator()+"softcom.key", QSsl::Rsa, QSsl::Pem, "39129380423984234012312");
    qDebug().noquote() <<QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss") <<__FUNCTION__<<":: "<<socket <<socket->privateKey().isNull();
//    Q_ASSERT(!socket->privateKey().isNull());
    socket->setLocalCertificate(QDir::currentPath()+QDir::separator()+"softcom.crt");
//    Q_ASSERT(!socket->localCertificate().isNull());
    qDebug().noquote()<<QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss") <<__FUNCTION__<<":: "<<socket <<socket->privateKey().isNull();

}

void SslServer::incomingConnection(PortableSocketDescriptorType socketDescriptor)
{
    QSslSocket *socket = new QSslSocket(this);
    if (socket->setSocketDescriptor(socketDescriptor)) {
        addPendingConnection(socket);
    } else {
        delete socket;
    }
}
