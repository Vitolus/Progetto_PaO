#include "mainwindow.h"
#include <QApplication>
#include "corpo_celeste.h"
#include "stella.h"
#include "pianeta.h"
#include "satellite.h"
#include "deep_ptr.h"
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[]){
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */
    Deep_ptr<Corpo_celeste> p(new Stella(24,10));
    cout<<p->get_diametro()<<endl<<p->get_forza_gravita()<<endl<<p->get_luminoso()<<endl
       <<p->get_temperatura()<<endl<<p->get_colore()<<endl<<p->get_tipo()<<endl<<p->get_pianeta_orbitato();
    return 0;
}
