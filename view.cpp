#include "view.h"

View::View(QWidget *parent) : QWidget(parent){
    QGridLayout* mainLayout= new QGridLayout();
    QTabWidget* tabWidget= new QTabWidget(this);
    tabWidget->addTab(new QWidget(),"Form per inserimento dati");
    tabWidget->addTab(new QWidget(),"Database");
    tabWidget->setTabShape(QTabWidget::Triangular);
    mainLayout->addWidget(tabWidget);
    QHBoxLayout* hBox= new QHBoxLayout(tabWidget->widget(0));

    QGroupBox* group= new QGroupBox("Stella");
    QVBoxLayout* vBox= new QVBoxLayout(group);
    hBox->addWidget(group);
    QFormLayout* form= new QFormLayout();
    form->addRow("Nome", new QLineEdit());
    form->addRow("Diametro", new QDoubleSpinBox());
    form->addRow("Forza di gravità", new QDoubleSpinBox());
    form->addRow("Temperatura", new QDoubleSpinBox());
    vBox->addLayout(form);
    QPushButton* submit= new QPushButton();
    submit->setText("Submit");
    vBox->addWidget(submit);

    group= new QGroupBox("Pianeta");
    vBox= new QVBoxLayout(group);
    hBox->addWidget(group);
    form= new QFormLayout(group);
    form->addRow("Nome", new QLineEdit());
    form->addRow("Diametro", new QDoubleSpinBox());
    form->addRow("Forza di gravità", new QDoubleSpinBox());
    QComboBox* combo= new QComboBox();
    combo->addItem("roccioso");
    combo->addItem("gassoso");
    form->addRow("Tipo", combo);
    vBox->addLayout(form);
    submit= new QPushButton();
    submit->setText("Submit");
    vBox->addWidget(submit);

    group= new QGroupBox("Satellite");
    vBox= new QVBoxLayout(group);
    hBox->addWidget(group);
    form= new QFormLayout(group);
    form->addRow("Nome", new QLineEdit());
    form->addRow("Diametro", new QDoubleSpinBox());
    form->addRow("Forza di gravità", new QDoubleSpinBox());
    combo= new QComboBox();
    combo->addItem("roccioso");
    combo->addItem("gassoso");
    form->addRow("Tipo", combo);
    form->addRow("Pianeta orbitato", new QLineEdit());
    vBox->addLayout(form);
    submit= new QPushButton();
    submit->setText("Submit");
    vBox->addWidget(submit);

    setLayout(mainLayout);
}
