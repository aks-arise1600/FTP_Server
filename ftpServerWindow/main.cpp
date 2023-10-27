#include "ftpServerWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ftpServerWindow w;
    w.show();

    return a.exec();
}
