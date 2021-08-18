#include "controller.h"
#include <iostream>
Controller::Controller(){
    gui= new Gui(this);
}

Gui *Controller::get_gui(){
    return gui;
}

void Controller::add_Corpo(QStringList st){
    if(st[0]=="Stella"){
        Sistema_stellare<Deep_ptr<Corpo_celeste>> sistema(new Stella(st[1],st[2].toFloat(), st[3].toFloat(), st[4].toFloat()));
        sistemi.push_back(sistema);
    }else if(st[0]=="Pianeta"){
        QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>>::Iterator it= sistemi.begin();
        for(;it->get_nome()==st[1] && it<sistemi.end();++it);
        if(it<sistemi.end()) it->add(new Pianeta(st[2],st[3].toFloat(),st[4].toFloat(),st[5].toFloat()));
    }else if(st[0]=="Satellite"){
        QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>>::Iterator it= sistemi.begin();
        for(;it->get_nome()==st[1] && it<sistemi.end();++it);
        Deep_ptr<Corpo_celeste> po= it->get(it->search(st[6]));
        if(it<sistemi.end())it->add(new Satellite(st[2],st[3].toFloat(),st[4].toFloat(),st[5].toFloat(),dynamic_cast<Pianeta*>(po.get_pointer())));
    }
}
