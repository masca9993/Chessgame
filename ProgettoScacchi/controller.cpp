#include "controller.h"
#include"pezzi.h"
#include "chessbutton.h"
#include "Arrocco_Exc.h"
#include "EnPassant_Exc.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include "Promozione.h"
#include "prombutton.h"
#include <QIcon>
#include "winner.h"
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

void Controller::EseguiPromozione(char t, int p) const
{
    QPushButton* f=static_cast<QPushButton*>(vista->getBoardItem(56-(p/8)*8+p%8)->widget());
    if (!scacchiera->getTurn())
    {
        if (t=='r')
        f->setIcon(QIcon(":/ReginaBianca.png"));
        if (t=='t')
        f->setIcon(QIcon(":/TorreBianca.png"));
        if (t=='a')
        f->setIcon(QIcon(":/AlfiereBianco.png"));
        if (t=='c')
        f->setIcon(QIcon(":/CavalloBianco.png"));
    }
    else
    {
        if (t=='r')
        f->setIcon(QIcon(":/ReginaNera.png"));
        if (t=='t')
        f->setIcon(QIcon(":/TorreNera.png"));
        if (t=='a')
        f->setIcon(QIcon(":/AlfiereNero.png"));
        if (t=='c')
        f->setIcon(QIcon(":/CavalloNero.png"));
    }
    try{
        scacchiera->Promozione(p, t);
    }
    catch(winner){
        mostravincitore();
    }
}

void Controller::reset()
{
    vista->reset();
    delete scacchiera;
    scacchiera=new Scacchiera();
}

void Controller::vedimosse(int pos) const
{
    if(scacchiera->getTurn()==scacchiera->getStato(pos)-1){
        Pezzi* p=scacchiera->getPedina(pos);
        vector<int> v=p->move();
        for(unsigned int i=0;i<v.getSize();i++){
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
        AggiornaIcone(posi, posf);
        if (posi<posf)  //il bianco muove
         {
            QPushButton* t=static_cast<QPushButton*>(vista->getBoardItem(56-((posf-8)/8)*8+(posf-8)%8)->widget());
            t->setIcon(QIcon(" "));

         }
        else
        {
            QPushButton* t=static_cast<QPushButton*>(vista->getBoardItem(56-((posf+8)/8)*8+(posf+8)%8)->widget());
            t->setIcon(QIcon(" "));
        }
    }
    catch (Arrocco_Exc)
    {
        AggiornaIcone(posi, posf);
          if (posi==4)     //re bianco
          {
              if (posf==2)     //sinistra        
                AggiornaIcone(0, 3);     
              else             //destra                       
                AggiornaIcone(7, 5);
          }
          else             //re nero
          {
             if (posf==58)    //destra                        
                 AggiornaIcone(56, 59);

             else             //sinistra                
                 AggiornaIcone(63, 61);       
          }
    }
    catch (Mossa_illegale)
    {
        QDialog* finestra=new QDialog(vista);
        QVBoxLayout* l=new QVBoxLayout(finestra);
        l->addWidget(new QLabel("Mossa Illegale"));
        finestra->show();

    }
    catch (Mossa_Imposs)
    {
        QDialog* finestra=new QDialog(vista);
        QVBoxLayout* l=new QVBoxLayout(finestra);
        l->addWidget(new QLabel("Mossa Impossibile"));
        finestra->show();
    }
    catch (promozione)
    {
        AggiornaIcone(posi, posf);
        QDialog* finestra=new QDialog(vista);
        QVBoxLayout* l=new QVBoxLayout(finestra);
        finestra->setMinimumSize(QSize(80, 80));
        if (!scacchiera->getTurn())               //tocca al bianco
        {
            PromButton* torre=new PromButton('t', posf, finestra);
            torre->setIcon(QIcon(":/TorreBianca.png"));
            connect(torre, SIGNAL(buttonclicked(char, int)), this, SLOT(EseguiPromozione(char, int)));
            connect(torre, SIGNAL(clicked()), finestra, SLOT(close()));
            PromButton* regina=new PromButton('r', posf, finestra);
            regina->setIcon(QIcon(":/ReginaBianca.png"));
            connect(regina, SIGNAL(buttonclicked(char, int)), this, SLOT(EseguiPromozione(char, int)));
            connect(regina, SIGNAL(clicked()), finestra, SLOT(close()));
            PromButton* cavallo=new PromButton('c', posf, finestra);
            cavallo->setIcon(QIcon(":/CavalloBianco.png"));
            connect(cavallo, SIGNAL(buttonclicked(char, int)), this, SLOT(EseguiPromozione(char, int)));
            connect(cavallo, SIGNAL(clicked()), finestra, SLOT(close()));
            PromButton* alfiere=new PromButton('a', posf, finestra);
            alfiere->setIcon(QIcon(":/AlfiereBianco.png"));
            connect(alfiere, SIGNAL(buttonclicked(char, int)), this, SLOT(EseguiPromozione(char, int)));
            connect(alfiere, SIGNAL(clicked()), finestra, SLOT(close()));
            l->addWidget(torre);
            l->addWidget(regina);
            l->addWidget(cavallo);
            l->addWidget(alfiere);

        }
        else
        {
            PromButton* torre=new PromButton('t', posf, finestra);
            torre->setIcon(QIcon(":/TorreNera.png"));
            connect(torre, SIGNAL(buttonclicked(char, int)), this, SLOT(EseguiPromozione(char, int)));
            connect(torre, SIGNAL(clicked()), finestra, SLOT(close()));
            PromButton* regina=new PromButton('r', posf, finestra);
            regina->setIcon(QIcon(":/ReginaNera.png"));
            connect(regina, SIGNAL(buttonclicked(char, int)), this, SLOT(EseguiPromozione(char, int)));
            connect(regina, SIGNAL(clicked()), finestra, SLOT(close()));
            PromButton* cavallo=new PromButton('c', posf, finestra);
            cavallo->setIcon(QIcon(":/CavalloNero.png"));
            connect(cavallo, SIGNAL(buttonclicked(char, int)), this, SLOT(EseguiPromozione(char, int)));
            connect(cavallo, SIGNAL(clicked()), finestra, SLOT(close()));
            PromButton* alfiere=new PromButton('a', posf, finestra);
            alfiere->setIcon(QIcon(":/AlfiereNero.png"));
            connect(alfiere, SIGNAL(buttonclicked(char, int)), this, SLOT(EseguiPromozione(char, int)));
            connect(alfiere, SIGNAL(clicked()), finestra, SLOT(close()));
            l->addWidget(torre);
            l->addWidget(regina);
            l->addWidget(cavallo);
            l->addWidget(alfiere);
        }
        finestra->show();

    }
    catch(winner)
    {
        AggiornaIcone(posi, posf);
        mostravincitore();
    }

}

void Controller::mostravincitore() const
{
    QDialog* finestra=new QDialog(vista);
    QVBoxLayout* l=new QVBoxLayout(finestra);
    finestra->setMinimumSize(QSize(80, 80));
    if (!scacchiera->getTurn())
    l->addWidget(new QLabel("Ha vinto il bianco"));
    else
    l->addWidget(new QLabel("Ha vinto il nero"));
    for (int i=0; i<64; i++)
    static_cast<QPushButton*>(vista->getBoardItem(i)->widget())->setEnabled(false);
    finestra->show();
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
