#ifndef SCACCHI_H
#define SCACCHI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QFile>
#include "chessbutton.h"

class Controller;


class Scacchi : public QWidget
{
    Q_OBJECT

public:
    Scacchi(Controller* p,QWidget *parent = nullptr);
    ~Scacchi();
    QLayoutItem* getBoardItem(int pos) const;
private:
    Controller* controller;
    QVBoxLayout* mainlayout;
    QHBoxLayout* hlayout;
    QGridLayout* gridlayout;
    void addMenu();
    void addButtons();
public slots:
    void setButtons();

};
#endif // SCACCHI_H
