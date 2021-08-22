#include "gui.h"
#include "ui_gui.h"
#include "controller.h"

Gui::Gui(Controller* control, QWidget *parent) : QWidget(parent), ui(new Ui::Gui){
    controller= control;
    ui->setupUi(this);
    tree= ui->treeWidget;

}

Gui::~Gui(){
    delete ui;
}

void Gui::on_sSubmit_clicked(){
    QStringList dati {"Stella", ui->sNomeBox->text(), ui->sDiametroBox->textFromValue(ui->sDiametroBox->value()),
                ui->sForzaBox->textFromValue(ui->sForzaBox->value()), ui->sTemperaturaBox->textFromValue(ui->sTemperaturaBox->value())};
    emit send_data(dati);

}

void Gui::on_pSubmit_clicked(){
    QStringList dati {"Pianeta",ui->pSistemaBox->text() , ui->pNomeBox->text(), ui->pDiametroBox->textFromValue(ui->pDiametroBox->value()),
                ui->pForzaBox->textFromValue(ui->pForzaBox->value()), ui->pTipoBox->currentText()};
    emit send_data(dati);
}

void Gui::on_saSubmit_clicked(){
    QStringList dati {"Satellite", ui->saSistemaBox->text(), ui->saNomeBox->text(), ui->saDiametroBox->textFromValue(ui->saDiametroBox->value()),
                ui->saForzaBox->textFromValue(ui->saForzaBox->value()), ui->saTipoBox->currentText(), ui->saOrbitatoBox->text()};
    emit send_data(dati);
}

void Gui::sclear(){
    ui->sNomeBox->clear();
    ui->sDiametroBox->clear();
    ui->sForzaBox->clear();
    ui->sTemperaturaBox->clear();
}

void Gui::pclear(){
    ui->pSistemaBox->clear();
    ui->pNomeBox->clear();
    ui->pDiametroBox->clear();
    ui->pForzaBox->clear();
}

void Gui::saclear(){
    ui->saSistemaBox->clear();
    ui->saNomeBox->clear();
    ui->saDiametroBox->clear();
    ui->saForzaBox->clear();
    ui->saOrbitatoBox->clear();
}

void Gui::add_data(const Deep_ptr<Corpo_celeste>* corpo, int nSistema){
    if(corpo->get_pointer()->type_name() =="Stella"){
        QTreeWidgetItem* sistema= new QTreeWidgetItem(tree), * stella= new QTreeWidgetItem();
        sistema->setText(0, "Sistema");
        sistema->setText(1,corpo->get_pointer()->get_nome());
        tree->addTopLevelItem(sistema);

        stella->setText(0, "Stella");
        stella->setText(1, corpo->get_pointer()->get_nome());
        sistema->addChild(stella);
        QTreeWidgetItem* dato= new QTreeWidgetItem();
        dato->setText(0,"Diametro");
        dato->setText(1, QString::number(corpo->get_pointer()->get_diametro()));
        stella->addChild(dato);
        dato= new QTreeWidgetItem();
        dato->setText(0,"Forza di Gravità");
        dato->setText(1, QString::number(corpo->get_pointer()->get_forza_gravita()));
        stella->addChild(dato);
        dato= new QTreeWidgetItem();
        dato->setText(0,"Temperatura");
        dato->setText(1, QString::number(corpo->get_pointer()->get_temperatura()));
        stella->addChild(dato);
        dato= new QTreeWidgetItem();
        dato->setText(0,"Colore");
        dato->setText(1, corpo->get_pointer()->get_colore());
        stella->addChild(dato);

    }else if(corpo->get_pointer()->type_name()=="Pianeta"){
        QTreeWidgetItem* pianeta= new QTreeWidgetItem();
        pianeta->setText(0, "Pianeta");
        pianeta->setText(1, corpo->get_pointer()->get_nome());
        tree->topLevelItem(nSistema)->addChild(pianeta);
        QTreeWidgetItem* dato= new QTreeWidgetItem();
        dato->setText(0,"Diametro");
        dato->setText(1, QString::number(corpo->get_pointer()->get_diametro()));
        pianeta->addChild(dato);
        dato= new QTreeWidgetItem();
        dato->setText(0,"Forza di Gravità");
        dato->setText(1, QString::number(corpo->get_pointer()->get_forza_gravita()));
        pianeta->addChild(dato);
        dato= new QTreeWidgetItem();
        dato->setText(0,"Tipo");
        dato->setText(1, corpo->get_pointer()->get_tipo());
        pianeta->addChild(dato);

    }else if(corpo->get_pointer()->type_name()=="Satellite"){
        QTreeWidgetItem* pianeta= new QTreeWidgetItem();
        pianeta->setText(0, "Satellite");
        pianeta->setText(1, corpo->get_pointer()->get_nome());
        tree->topLevelItem(nSistema)->addChild(pianeta);

        QTreeWidgetItem* dato= new QTreeWidgetItem();
        dato->setText(0,"Diametro");
        dato->setText(1, QString::number(corpo->get_pointer()->get_diametro()));
        pianeta->addChild(dato);
        dato= new QTreeWidgetItem();
        dato->setText(0,"Forza di Gravità");
        dato->setText(1, QString::number(corpo->get_pointer()->get_forza_gravita()));
        pianeta->addChild(dato);
        dato= new QTreeWidgetItem();
        dato->setText(0,"Tipo");
        dato->setText(1, corpo->get_pointer()->get_tipo());
        pianeta->addChild(dato);
        dato= new QTreeWidgetItem();
        dato->setText(0,"Pianeta orbitato");
        dato->setText(1, corpo->get_pointer()->get_pianeta_orbitato()->get_nome());
        pianeta->addChild(dato);

    }
}
