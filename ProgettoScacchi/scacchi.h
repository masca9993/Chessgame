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


class Scacchi : public QWidget
{
    Q_OBJECT

public:
    Scacchi(QWidget *parent = nullptr);
    ~Scacchi();

private:
    QVBoxLayout* mainlayout;
    QHBoxLayout* hlayout;
    QGridLayout* gridlayout;
    void addMenu();
    void addButtons();
public slots:
    void setButtons();

};
#endif // SCACCHI_H
