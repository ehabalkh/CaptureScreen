#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Remove the extra "char" before "argv"
    MainWindow w;
    w.show();
    return a.exec();
}
