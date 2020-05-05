#include "scacchi.h"
#include "ui_scacchi.h"
#include <QIcon>
#include <QSize>
#include "controller.h"
#include <QString>

Scacchi::Scacchi(Controller* p,QWidget *parent) : controller(p), QWidget(parent)
{
    mainlayout= new QVBoxLayout(this);
    hlayout= new QHBoxLayout();
    gridlayout= new QGridLayout();
    setMinimumSize(QSize(600, 600));
    addMenu();

    addButtons();
    setButtons();
    gridlayout->setSpacing(0);
    mainlayout->addLayout(hlayout);
    hlayout->addLayout(gridlayout);
    setLayout(mainlayout);
}

Scacchi::~Scacchi()
{

}

QLayoutItem *Scacchi::getBoardItem(int pos) const
{
    return gridlayout->itemAtPosition(pos/8, pos%8);
}

void Scacchi::setButtons()
{
    QPushButton* p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 0)->widget());
    p->setIcon(QIcon(":/TorreNera.png"));
    QString k="O";
    p->setText(k);
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 1)->widget());
    p->setIcon(QIcon(":/CavalloNero.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 2)->widget());
    p->setIcon(QIcon(":/AlfiereNero.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 3)->widget());
    p->setIcon(QIcon(":/ReginaNera.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 4)->widget());
    p->setIcon(QIcon(":/ReNero.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 5)->widget());
    p->setIcon(QIcon(":/AlfiereNero.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 6)->widget());
    p->setIcon(QIcon(":/CavalloNero.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 7)->widget());
    p->setIcon(QIcon(":/TorreNera.png"));
    for (int i=0; i<8; i++)
    {
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(1, i)->widget());
        p->setIcon(QIcon(":/PedoneNero.png"));
    }

    for (int i=0; i<32; i++)
    {
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(2+i/8, i%8)->widget());
        p->setIcon(QIcon(""));
    }
    for (int i=0; i<8; i++)
    {
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(6, i)->widget());
        p->setIcon(QIcon(":/PedoneBianco.png"));
    }
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 0)->widget());
        p->setIcon(QIcon(":/TorreBianca.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 1)->widget());
        p->setIcon(QIcon(":/CavalloBianco.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 2)->widget());
        p->setIcon(QIcon(":/AlfiereBianco.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 3)->widget());
        p->setIcon(QIcon(":/ReginaBianca.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 4)->widget());
        p->setIcon(QIcon(":/ReBianco.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 5)->widget());
        p->setIcon(QIcon(":/AlfiereBianco.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 6)->widget());
        p->setIcon(QIcon(":/CavalloBianco.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 7)->widget());
        p->setIcon(QIcon(":/TorreBianca.png"));

        for (int i=0; i<64; i++)
        {
           p=static_cast<QPushButton*>(gridlayout->itemAtPosition(i/8, i%8)->widget());
           p->setIconSize(QSize(60, 60));
        }
}

void Scacchi::addMenu()
{
    QMenuBar* menubar=new QMenuBar(this);
    QMenu* menu= new QMenu("File",menubar);
    QAction* reset= new QAction("Reset",menu);
    QAction* exit = new QAction("Exit",menu);
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));
    connect(reset,SIGNAL(triggered()),this,SLOT(setButtons()));
    menubar->addMenu(menu);
    menu->addAction(reset);
    menu->addAction(exit);
    mainlayout->addWidget(menubar);
}

void Scacchi::addButtons()
{
    for(int i=0;i<8;i++){
       if(i%2!=0){
            for(int y=0;y<8;y++){
                ChessButton* button=new ChessButton((i*8-56)*-1+y,this);
                connect(button,SIGNAL(buttonclicked(int)),controller,SLOT(vedimosse(int)));
                button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
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
               gridlayout->addWidget(button,i,y);
            }
       }
       else{
           for(int y=0;y<8;y++){
               ChessButton* button=new ChessButton((i*8-56)*-1+y,this);
               connect(button,SIGNAL(buttonclicked(int)),controller,SLOT(vedimosse(int)));
               button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
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
            gridlayout->addWidget(button,i,y);
           }
       }
    }
}
