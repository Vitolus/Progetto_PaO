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
    connect(this, &Controller::show_corpo, gui, &Gui::add_data);

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
        emit show_corpo(new Deep_ptr<Corpo_celeste>(corpo));

    }else if(st[0]=="Pianeta"){
        auto i=-1, nSistema= -1;
        QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>>::iterator it= sistemi.begin();
        for(; i==-1 && it<sistemi.end(); ++it){
            i= it->search(st[1]);
            ++nSistema;
        }
        if(i>-1){
            --it;
            bool tipo= true;
            if(st[5]=="roccioso") tipo= true;
            else if(st[5]=="gassoso") tipo= false;
            corpo= new Pianeta(st[2],loc.toFloat(st[3]),loc.toFloat(st[4]),tipo);
            it->add(corpo);
            emit show_corpo(new Deep_ptr<Corpo_celeste>(corpo), nSistema);
        }

    }else if(st[0]=="Satellite"){
        auto i=-1, nSistema= -1;
        QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>>::iterator it= sistemi.begin();
        for(; i==-1 && it<sistemi.end();++it){
            i= it->search(st[1]);
            ++nSistema;
        }
        --it;
        if(i>-1){
            auto j= -1;
            j= it->search(st[6]);
            if(j>-1){
                Deep_ptr<Corpo_celeste> po= it->get(j);
                bool tipo= true;
                if(st[5]=="roccioso") tipo= true;
                else if(st[5]=="gassoso") tipo= false;
                corpo= new Satellite(st[2],loc.toFloat(st[3]),loc.toFloat(st[4]),tipo,dynamic_cast<Pianeta*>(po.get_pointer()));
                it->add(corpo);
                emit show_corpo(new Deep_ptr<Corpo_celeste>(corpo), nSistema);
            }
        }
    }
}
