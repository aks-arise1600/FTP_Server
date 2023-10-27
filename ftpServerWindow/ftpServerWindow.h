#ifndef FTPSERVERWINDOW_H
#define FTPSERVERWINDOW_H

#include <QMainWindow>
#include <ftpserver.h>
#include <QSettings>
#include <QDateTime>
#include <QDir>
#include <QFileDialog>
#include <QObject>
#include <QIntValidator>
#include <QDebug>

#define OutputMark(className,func)      QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss")+" "+className+"->"+func
#define PRINT()                         qDebug().noquote()

namespace Ui {
class ftpServerWindow;
}

class ftpServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ftpServerWindow(QWidget *parent = 0);
    ~ftpServerWindow();
    void m_loadSettings();
    void m_SaveSettings();
    void m_StartServer();
private slots:    
    void on_pushButton_ReStart_clicked();
    void on_toolButton_Browse_clicked();
    void sl_onPeerIpChanged(const QString &peerIP);
private:
    Ui::ftpServerWindow *ui;
    FtpServer *fServer = 0;
};

#endif // FTPSERVERWINDOW_H
