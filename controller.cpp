#include "controller.h"
#include <iostream>
Controller::Controller(){
    gui= new Gui(this);
}

void Controller::setController(){
    connect(gui, &Gui::send_data, this, &Controller::add_Corpo);
    connect(gui, &Gui::send_data, gui, &Gui::sclear);
    connect(gui, &Gui::send_data, gui, &Gui::pclear);
    connect(gui, &Gui::send_data, gui, &Gui::saclear);

}

Gui *Controller::get_gui(){
    return gui;
}

void Controller::add_Corpo(const QStringList& st){
    QLocale loc(QLocale::Italian);
    Deep_ptr<Corpo_celeste> corpo;
    if(st[0]=="Stella"){
        corpo= new Stella(st[1], loc.toFloat(st[2]), loc.toFloat(st[3]), loc.toFloat(st[4]));
        Sistema_stellare<Deep_ptr<Corpo_celeste>>* sistema= new Sistema_stellare<Deep_ptr<Corpo_celeste>>(corpo);
        sistemi.push_back(*sistema);
        sistema= nullptr;

    }else if(st[0]=="Pianeta"){
        QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>>::Iterator it= sistemi.begin();
        auto i=-1;
        for(; i==-1 && it<sistemi.end();++it){
            i= it->search(st[1]);
        }
        if(i>-1){
            corpo= new Pianeta(st[2],loc.toFloat(st[3]),loc.toFloat(st[4]),loc.toFloat(st[5]));
            sistemi[i].add(corpo);
        }

    }else if(st[0]=="Satellite"){
        QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>>::Iterator it= sistemi.begin();
        auto i=0;
        for(;i==-1 && it<sistemi.end();++it);
        Deep_ptr<Corpo_celeste> po= it->get(it->search(st[6]));
        if(i>-1){
            corpo= new Satellite(st[2],loc.toFloat(st[3]),loc.toFloat(st[4]),loc.toFloat(st[5]),dynamic_cast<Pianeta*>(po.get_pointer()));
            sistemi[i].add(corpo);
            std::cout<<"dentro if satellite"<<std::endl;
        }
    }
    emit show_corpo(st[0], corpo);
}
