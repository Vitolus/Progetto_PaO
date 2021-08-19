#include "gui.h"
#include "ui_gui.h"
#include "controller.h"

Gui::Gui(Controller* control, QWidget *parent) : QWidget(parent), ui(new Ui::Gui){
    controller= control;
    ui->setupUi(this);
    tree= ui->treeWidget;
    sistemi= new QTreeWidgetItem(tree);
    sistemi->setText(0,"Sistemi");
    tree->addTopLevelItem(sistemi);
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
