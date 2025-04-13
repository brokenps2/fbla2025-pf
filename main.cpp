#include "mainwindow.h"
#include "welcomedialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    WelcomeDialog d;
    w.show();
    d.show();
    return a.exec();
}
