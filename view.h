#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QTabWidget>
#include <QGroupBox>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

class View : public QWidget{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

signals:

};

#endif // VIEW_H
