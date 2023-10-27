#include "ftpServerWindow.h"
#include "ui_ftpServerWindow.h"

ftpServerWindow::ftpServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ftpServerWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Port->setValidator(new QIntValidator(1, 65535, this));

    m_loadSettings();
    m_StartServer();
}

ftpServerWindow::~ftpServerWindow()
{
    PRINT()<<OutputMark(metaObject()->className(),__FUNCTION__);
    m_SaveSettings();
    delete ui;
}

void ftpServerWindow::m_loadSettings()
{
    PRINT()<<OutputMark( metaObject()->className(),__FUNCTION__);

    QString defaultPort = "2323";

    QSettings *settings = new QSettings("ftp.conf",QSettings::IniFormat);
    ui->lineEdit_Port->setText(settings->value("settings/port", defaultPort).toString());
    ui->lineEdit_UserId->setText(settings->value("settings/username", "admin").toString());
    ui->lineEdit_UserPass->setText(settings->value("settings/password", "admin123").toString());
    ui->lineEdit_RootPath->setText(settings->value("settings/rootpath", QDir::rootPath()).toString());
    ui->checkBox_AllowAnonymous->setChecked(settings->value("settings/anonymous", false).toBool());
    ui->checkBox_ReadOnly->setChecked(settings->value("settings/readonly", false).toBool());
    ui->checkBox_OnlyOneIP->setChecked(settings->value("settings/oneip", true).toBool());

    delete settings;
}

void ftpServerWindow::m_SaveSettings()
{
    PRINT()<<OutputMark(metaObject()->className(),__FUNCTION__);
    QSettings *settings = new QSettings("ftp.conf",QSettings::IniFormat);
    settings->setValue("settings/port", ui->lineEdit_Port->text());
    settings->setValue("settings/username", ui->lineEdit_UserId->text());
    settings->setValue("settings/password", ui->lineEdit_UserPass->text());
    settings->setValue("settings/rootpath", ui->lineEdit_RootPath->text());
    settings->setValue("settings/anonymous", ui->checkBox_AllowAnonymous->isChecked());
    settings->setValue("settings/readonly", ui->checkBox_ReadOnly->isChecked());
    settings->setValue("settings/oneip", ui->checkBox_OnlyOneIP->isChecked());

    delete settings;
}

void ftpServerWindow::m_StartServer()
{
    PRINT()<<OutputMark(metaObject()->className(),__FUNCTION__);
    QString userName, password;
    if (!ui->checkBox_AllowAnonymous->isChecked()) {
        userName = ui->lineEdit_UserId->text();
        password = ui->lineEdit_UserPass->text();
    }
    delete fServer;
    fServer = new FtpServer(this, ui->lineEdit_RootPath->text(), ui->lineEdit_Port->text().toInt(), userName,
                           password, ui->checkBox_ReadOnly->isChecked(), ui->checkBox_OnlyOneIP->isChecked());
    connect(fServer,SIGNAL(newPeerIp(QString)),this,SLOT(sl_onPeerIpChanged(QString)));
    if (fServer->isListening()) {
        ui->statusBar->showMessage("Listening at " + FtpServer::lanIp());
    } else {
        ui->statusBar->showMessage("Not listening");
    }
}

void ftpServerWindow::on_pushButton_ReStart_clicked()
{
    PRINT()<<OutputMark(metaObject()->className(),__FUNCTION__);
    m_StartServer();
}

void ftpServerWindow::on_toolButton_Browse_clicked()
{
    PRINT()<<OutputMark(metaObject()->className(),__FUNCTION__);
    QString rootPath = QFileDialog::getExistingDirectory(this, QString(), ui->lineEdit_RootPath->text());
    if (rootPath.isEmpty())
    {
        return;
    }
    ui->lineEdit_RootPath->setText(rootPath);
}

void ftpServerWindow::sl_onPeerIpChanged(const QString &peerIP)
{
    ui->statusBar->showMessage("Connected to " + peerIP);

}
