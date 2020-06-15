#include "scacchi.h"
#include "torre.h"
#include "cavallo.h"
#include "alfiere.h"
#include "scacchiera.h"
#include "vector.h"
#include <QApplication>
#include <iostream>
#include "controller.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scacchiera m;
    Controller c(&m);
    Scacchi v(&c);
    c.setView(&v);
    v.show();
    return a.exec();

//     Scacchiera* s=new Scacchiera();
//     delete s;
//    vector<int> s;
//    for(int i=0; i<10;i++)//se parte da 1 funziona mentre se parte da zero no perche pensa che sia l'ultimo elemento cioè s.end()==s[0] visto che entrambi sono 0
//        s.push_back(i);
//    for(int i=0;i<s.getSize();i++)
//        std::cout<<s[i]<<" ";
//     std::cout<<std::endl;
//    for(vector<int>::iterator it=s.begin();it!=s.end(); it++)
//        std::cout<<*it<<" ";
//    vector<int>::iterator g=s.begin();


  
//    std::vector<int> s;
//    for(unsigned int i=0;i<10;i++)
//        s.push_back(i);
//    for(unsigned int i=0;i<s.size();i++)
//        std::cout<<s[i]<<" ";
//    std::cout<<std::endl;
//    s.pop_back();
//    std::vector<int>::iterator ca=s.begin();
//    std::vector<int>::const_iterator po(ca);
//    std::cout<<*po<<std::endl;
//    for(unsigned int i=0;i<s.size();i++)
//        std::cout<<s[i]<<" ";
//    std::cout<<std::endl;
//    std::vector<int> m;
//    for(int i=0;i<10;i++)
//        m.push_back(i);
//    std::vector<int>::iterator it=m.begin();
//    std::vector<int>::iterator p;
//    std::cout<<&p<<"    "<<&it<<std::endl;
//    p=it;
//    std::cout<<&p[0]<<"    "<<&it[0];
//    std::cout<<std::endl;
//    std::cout<<&p[1]<<"    "<<&it[1];
//    std::cout<<std::endl;

//    vector<int> m;
//    //for(int i=0;i<10;i++)
//        //m.push_back(i);
//    vector<int> c;
//    for(int i=0;i<10;i++)
//        c.push_back(i);
//    vector<int>::iterator p=c.begin();
//    vector<int>::const_iterator it(p);
//    std::cout<<&p<<"    "<<&it<<std::endl;
//    //p=it;
//    it++;
//    it++;
//    std::cout<<*it<<std::endl;
//    std::cout<<&p<<"    "<<&it;
//    std::cout<<std::endl;


   //std::cout<<&p[1]<<"    "<<&it[1];
    //for(int i=0;i<s.getSize();i++)
      //  std::cout<<s[i]<<" ";
    return 0;
}
