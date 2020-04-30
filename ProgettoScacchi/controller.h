#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "scacchi.h"
#include "scacchiera.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(Scacchiera* s, Scacchi* v);
    void move();
private:
    Scacchiera* scacchiera;
    Scacchi* vista;
};

#endif // CONTROLLER_H
