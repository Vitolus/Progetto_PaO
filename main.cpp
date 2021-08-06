#include "mainwindow.h"
#include <QApplication>
#include "corpo_celeste.h"
#include "stella.h"
#include "pianeta.h"
#include "satellite.h"
#include "deep_ptr.h"
#include "sistema_stellare.h"
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    return 0;
}
