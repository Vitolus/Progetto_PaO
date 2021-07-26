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
    /*Pianeta pia(30,1,true);
    Deep_ptr<Pianeta> p(new Satellite(24,10,true,pia));
    Satellite sa= static_cast<Pianeta>(*p);
    cout<<p->get_diametro()<<endl<<p->get_forza_gravita()<<endl<<p->get_luminoso()<<endl<<p->get_temperatua();*/
}
