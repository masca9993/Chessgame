#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "scacchi.h"
#include "scacchiera.h"
#include <vector>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(Scacchiera* s,QObject* p =nullptr);
    void move();
    void setView(Scacchi* s);
public slots:
    void vedimosse(int pos) const;
private:
    Scacchiera* scacchiera;
    Scacchi* vista;
    void cancellamosse() const;
};

#endif // CONTROLLER_H
