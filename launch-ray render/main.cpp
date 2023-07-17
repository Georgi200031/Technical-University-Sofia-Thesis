#include "launchrayrender.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <QProcess>
#include <iostream>
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
 
    launchrayrender window;
    window.show();
    
    
    return a.exec();
}
