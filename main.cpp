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
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */
    Sistema_stellare<Deep_ptr<Corpo_celeste>> sistema1(3);
    sistema1.push_back(Deep_ptr<Corpo_celeste>(new Stella(30,5)));
    sistema1.push_back(Deep_ptr<Corpo_celeste>(new Pianeta(20,2,true)));
    for(Sistema_stellare<Deep_ptr<Corpo_celeste>>::Iterator cit= sistema1.begin(); cit==sistema1.end(); cit++){
        cout<< cit->get()<<endl;
    }
    return 0;
}
