#include "controller.h"
#include <iostream>
Controller::Controller(){
    gui= new Gui(this);
}

void Controller::setController(){
    connect(gui, &Gui::send_data, this, &Controller::add_corpo);
    connect(gui, &Gui::send_data, gui, &Gui::sclear);
    connect(gui, &Gui::send_data, gui, &Gui::pclear);
    connect(gui, &Gui::send_data, gui, &Gui::saclear);
    connect(this, &Controller::show_corpo, gui, &Gui::add_data);
    connect(gui, &Gui::notify_remove, this, &Controller::remove_corpo);

}

Gui *Controller::get_gui(){
    return gui;
}

void Controller::add_corpo(const QStringList& st){
    QLocale loc(QLocale::Italian);
    Deep_ptr<Corpo_celeste> corpo;
    if(st[0]=="Stella"){
        corpo= new Stella(st[1], loc.toFloat(st[2]), loc.toFloat(st[3]), loc.toFloat(st[4]));
        Sistema_stellare<Deep_ptr<Corpo_celeste>> sistema(corpo);
        sistemi.push_back(sistema);
        emit show_corpo(corpo);

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
            emit show_corpo(corpo, nSistema);
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
                emit show_corpo(corpo, nSistema);
            }
        }
    }
}

void Controller::remove_corpo(const QString sistema, const QString corpo){
    auto i= 0;
    for(QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>>::iterator it= sistemi.begin(); it<sistemi.end(); ++it){
        auto cIndex= it->search(corpo);
        if(it->get_nome()==sistema && cIndex!=-1){
            sistemi[i].remove(cIndex);
            if(cIndex==0){
                sistemi.remove(i);
            }
            return;
        }
        ++i;
    }
}
