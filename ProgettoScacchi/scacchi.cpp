#include "scacchi.h"
#include "ui_scacchi.h"

Scacchi::Scacchi(QWidget *parent) : QWidget(parent)
{
    mainlayout= new QVBoxLayout(this);
    hlayout= new QHBoxLayout();
    gridlayout= new QGridLayout();

    addMenu();

    addButtons();
    gridlayout->setSpacing(0);
    mainlayout->addLayout(hlayout);
    hlayout->addLayout(gridlayout);
    setLayout(mainlayout);
}

Scacchi::~Scacchi()
{

}

void Scacchi::addMenu()
{
    QMenuBar* menubar=new QMenuBar(this);
    QMenu* menu= new QMenu("File",menubar);
    QAction* reset= new QAction("Reset",menu);
    QAction* exit = new QAction("Exit",menu);
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));
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
                QPushButton* button=new QPushButton(this);
                button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
                if(y%2==0){
                    QFile file(":/resources/styleBlack.css");
                    file.open(QFile::ReadOnly);
                    QString styleSheet = QLatin1String(file.readAll());
                    button->setStyleSheet(styleSheet);
                }
                else{
                    QFile file(":/resources/styleWhithe.css");
                    file.open(QFile::ReadOnly);
                    QString styleSheet = QLatin1String(file.readAll());
                    button->setStyleSheet(styleSheet);
                }
               gridlayout->addWidget(button,i*8,y);
            }
       }
       else{
           for(int y=0;y<8;y++){
               QPushButton* button=new QPushButton(this);
               button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
               if(y%2==0){
                   QFile file(":/resources/styleWhithe.css");
                   file.open(QFile::ReadOnly);
                   QString styleSheet = QLatin1String(file.readAll());
                   button->setStyleSheet(styleSheet);
               }
               else{
                   QFile file(":/resources/styleBlack.css");
                   file.open(QFile::ReadOnly);
                   QString styleSheet = QLatin1String(file.readAll());
                   button->setStyleSheet(styleSheet);
               }
            gridlayout->addWidget(button,i*8,y);
           }
       }
    }
}



