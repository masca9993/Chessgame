#include "scacchi.h"
#include "torre.h"
#include "cavallo.h"
#include "alfiere.h"
#include "scacchiera.h"
#include <vector>
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scacchi w;
    w.show();
    return a.exec();
    //Scacchiera s;

    return 0;
}
