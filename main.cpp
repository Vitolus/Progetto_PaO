#include "view.h"
#include <QApplication>
#include "corpo_celeste.h"
#include "stella.h"
#include "pianeta.h"
#include "satellite.h"
#include "deep_ptr.h"
#include "sistema_stellare.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    View v;
    v.show();
    return a.exec();
    return 0;
}
