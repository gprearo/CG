#include <QApplication>
#include <iostream>
#include "principal.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Principal mw;
    mw.show();

    return a.exec();
}
