#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Create Qt application object
    QApplication a(argc, argv);

    // Create main window
    MainWindow w;

    // Show main window
    w.show();

    // Start event loop
    return a.exec();
}
