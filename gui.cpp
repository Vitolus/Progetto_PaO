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

QStringList Gui::on_sSubmit_clicked(){
    return {"Stella", ui->sNomeBox->text(), ui->sDiametroBox->textFromValue(ui->sDiametroBox->value()),
                ui->sForzaBox->textFromValue(ui->sForzaBox->value()), ui->sTemperaturaBox->textFromValue(ui->sTemperaturaBox->value())};
}


QStringList Gui::on_pSubmit_clicked(){
    return {"Pianeta",ui->pSistemaBox->text() , ui->pNomeBox->text(), ui->pDiametroBox->textFromValue(ui->pDiametroBox->value()),
                ui->pForzaBox->textFromValue(ui->pForzaBox->value()), ui->pTipoBox->currentText()};
}


QStringList Gui::on_saSubmit_clicked(){
    return {"Satellite", ui->saSistemaBox->text(), ui->saNomeBox->text(), ui->saDiametroBox->textFromValue(ui->saDiametroBox->value()),
                ui->saForzaBox->textFromValue(ui->saForzaBox->value()), ui->saTipoBox->currentText(), ui->saOrbitatoBox->text()};
}

