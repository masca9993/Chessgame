#include "controller.h"
#include"pezzi.h"
#include "chessbutton.h"
#include "Arrocco_Exc.h"
#include "EnPassant_Exc.h"
Controller::Controller(Scacchiera *s, QObject *p):  QObject(p), scacchiera(s) , vista(nullptr)
{}

void Controller::setView(Scacchi *s)
{
    vista=s;
}

void Controller::ColoraMuovi(int r, int pos) const
{
    cancellamosse();
    if (r==-1)
        vedimosse(pos);
    else
        EseguiMossa(r, pos);
}

void Controller::vedimosse(int pos) const
{
    if(scacchiera->getStato(pos)!=0){
        Pezzi* p=scacchiera->getPedina(pos);
        std::vector<int> v=p->move();
        std::cout<<std::endl;
        for(unsigned int i=0;i<v.size();i++){
            std::cout<<v[i]<<" ";
            ChessButton* c=static_cast<ChessButton*>(vista->getBoardItem(56-(v[i]/8)*8+v[i]%8)->widget());
            QFile file(":/styleselected.css");
            file.open(QFile::ReadOnly);
            QString styleSheet = QLatin1String(file.readAll());
            c->setStyleSheet(styleSheet);
            c->setRed(pos);

        }
    }
}

void Controller::AggiornaIcone(int posi, int posf) const
{
    QPushButton* i=static_cast<QPushButton*>(vista->getBoardItem(56-(posi/8)*8+posi%8)->widget());
    QPushButton* f=static_cast<QPushButton*>(vista->getBoardItem(56-(posf/8)*8+posf%8)->widget());
    f->setIcon(i->icon());
    i->setIcon(QIcon(" "));
}

void Controller::EseguiMossa(int posi, int posf) const
{
        try
    {
        scacchiera->doMove(posi, posf);
        AggiornaIcone(posi, posf);
    }
        catch (EnPassant_Exc)
    {
        if (posi<posf)  //il bianco muove
         {
            AggiornaIcone(posi, posf);
            QPushButton* t=static_cast<QPushButton*>(vista->getBoardItem(56-((posf-8)/8)*8+(posf-8)%8)->widget());
            t->setIcon(QIcon(" "));

         }
        else
        {
            AggiornaIcone(posi, posf);
            QPushButton* t=static_cast<QPushButton*>(vista->getBoardItem(56-((posf+8)/8)*8+(posf+8)%8)->widget());
            t->setIcon(QIcon(" "));
        }
    }
    catch (Arrocco_Exc)
    {
          if (posi==4)     //re bianco
          {
              if (posf==2)     //sinistra
              {
                AggiornaIcone(posi, posf);
                AggiornaIcone(0, 3);
              }
              else             //destra
               {
                  AggiornaIcone(posi, posf);
                  AggiornaIcone(7, 5);
              }
          }
          else             //re nero
          {
             if (posf==58)    //destra
             {
                 AggiornaIcone(posi, posf);
                 AggiornaIcone(56, 59);
             }
             else             //sinistra
             {
                 AggiornaIcone(posi, posf);
                 AggiornaIcone(63, 61);
             }
          }
    }

}

void Controller::cancellamosse() const
{
    for(int i=0;i<8;i++){
       if(i%2!=0){
            for(int y=0;y<8;y++){
                ChessButton* button=static_cast<ChessButton*>(vista->getBoardItem(i*8+y)->widget());
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
                 button->setRed(-1);
            }
       }
       else{
           for(int y=0;y<8;y++){
               ChessButton* button=static_cast<ChessButton*>(vista->getBoardItem(i*8+y)->widget());
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
               button->setRed(-1);
           }
       }
    }
}
