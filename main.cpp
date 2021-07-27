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
    Deep_ptr<Stella> s;
   // if(dynamic_cast<Stella*>(*p)) ;
   // else cout<<"non convertibile"<<endl;
    cout<<p->get_diametro()<<endl<<p->get_forza_gravita()<<endl<<p->get_luminoso()<<endl;
    return 0;
}
