#include "scacchi.h"
#include "torre.h"
#include "cavallo.h"
#include <vector>
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
   /* QApplication a(argc, argv);
    Scacchi w;
    w.show();
    return a.exec();*/
    std::vector<int> v;
    Scacchiera* s=new Scacchiera();
    Pezzi* p=new Cavallo(1, 1, s);
   v=p->move();
   for (unsigned int i =0; i<v.size(); i++)
       std::cout<<v[i]<<" ";
    return 0;
}
