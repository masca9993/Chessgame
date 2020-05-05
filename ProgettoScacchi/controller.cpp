#include "controller.h"
#include"pezzi.h"
#include "chessbutton.h"

Controller::Controller(Scacchiera *s, QObject *p):  QObject(p), scacchiera(s) , vista(nullptr)
{}

void Controller::setView(Scacchi *s)
{
    vista=s;
}

void Controller::vedimosse(int pos) const
{
    cancellamosse();
    if(scacchiera->getStato(pos)!=0){
        Pezzi* p=scacchiera->getPedina(pos);
        std::vector<int> v=p->move();
        for(unsigned int i=0;i<v.size();i++){
            QWidget* c=vista->getBoardItem(56-(v[i]/8)*8+v[i]%8)->widget();
            QFile file(":/styleselected.css");
            file.open(QFile::ReadOnly);
            QString styleSheet = QLatin1String(file.readAll());
            c->setStyleSheet(styleSheet);
        }
    }
}

void Controller::cancellamosse() const
{
    for(int i=0;i<8;i++){
       if(i%2!=0){
            for(int y=0;y<8;y++){
                QWidget* button=vista->getBoardItem(i*8+y)->widget();
                if(y%2==0){
                    QFile file(":/styleBlack.css");
                    file.open(QFile::ReadOnly);
                    QString styleSheet = QLatin1String(file.readAll());
                    button->setStyleSheet(styleSheet);
                }
                else{
                    QFile file(":/styleWhithe.css");
                    file.open(QFile::ReadOnly);
                    QString styleSheet = QLatin1String(file.readAll());
                    button->setStyleSheet(styleSheet);
                }
            }
       }
       else{
           for(int y=0;y<8;y++){
               QWidget* button=vista->getBoardItem(i*8+y)->widget();
               if(y%2==0){
                   QFile file(":/styleWhithe.css");
                   file.open(QFile::ReadOnly);
                   QString styleSheet = QLatin1String(file.readAll());
                   button->setStyleSheet(styleSheet);
               }
               else{
                   QFile file(":/styleBlack.css");
                   file.open(QFile::ReadOnly);
                   QString styleSheet = QLatin1String(file.readAll());
                   button->setStyleSheet(styleSheet);
               }
           }
       }
    }
}
