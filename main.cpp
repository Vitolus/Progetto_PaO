#include <QApplication>
#include <iostream>
#include "controller.h"
#include "sistema_stellare.h"
#include "deep_ptr.h"
#include "corpo_celeste.h"
#include "stella.h"
#include "pianeta.h"
#include "satellite.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Controller c;
    c.get_gui()->show();
    return a.exec();
    return 0;
}
