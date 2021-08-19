#include "controller.h"
#include <iostream>
Controller::Controller(){
    gui= new Gui(this);
}

void Controller::setController(){
    connect(gui, &Gui::send_data, this, &Controller::add_Corpo);
    //connect(gui, &Gui::send_data, gui, &Gui::sclear);
    //connect(gui, &Gui::send_data, gui, &Gui::pclear);
    //connect(gui, &Gui::send_data, gui, &Gui::saclear);
}

Gui *Controller::get_gui(){
    return gui;
}

void Controller::add_Corpo(QStringList st){
    Deep_ptr<Corpo_celeste> corpo;
    if(st[0]=="Stella"){
        QString n= st[1];
        float d= st[2].toFloat();
        float f= st[3].toFloat(), t= st[4].toFloat();
        corpo= new Stella(n, d, f, t);
        Sistema_stellare<Deep_ptr<Corpo_celeste>>* sistema= new Sistema_stellare<Deep_ptr<Corpo_celeste>>(corpo);
        corpo= nullptr;
        sistemi.push_back(*sistema);
        sistema= nullptr;

        std::cout<<"dentro if stella"<<std::endl;

    }else if(st[0]=="Pianeta"){
        QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>>::Iterator it= sistemi.begin();
        auto i=-1;
        for(; i==-1 && it<sistemi.end();++it){
            i= it->search(st[1]);
        }
        if(i>-1){
            corpo= new Pianeta(st[2],st[3].toFloat(),st[4].toFloat(),st[5].toFloat());
            it->add(corpo);
        }
        corpo= nullptr;

        std::cout<<"dentro if pianeta"<<std::endl;

    }else if(st[0]=="Satellite"){
        QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>>::Iterator it= sistemi.begin();
        auto i=0;
        for(;i==-1 && it<sistemi.end();++it);
        Deep_ptr<Corpo_celeste> po= it->get(it->search(st[6]));
        if(i>-1){
            corpo= new Satellite(st[2],st[3].toFloat(),st[4].toFloat(),st[5].toFloat(),dynamic_cast<Pianeta*>(po.get_pointer()));
            it->add(corpo);
        }
        corpo= nullptr;

        std::cout<<"dentro if satellite"<<std::endl;

    }

    std::cout<<"fuori if add corpo"<<std::endl;

    emit show_corpo(st[0], corpo);
}
