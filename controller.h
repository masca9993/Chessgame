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
 void ColoraMuovi(int r, int pos) const;
 void EseguiPromozione(char t, int p) const;
 void reset();
private:
    Scacchiera* scacchiera;
    Scacchi* vista;
    void cancellamosse() const;
    void vedimosse(int pos) const;
    void AggiornaIcone(int posi, int posf) const;
    void EseguiMossa(int posi, int posf) const;
    void mostravincitore() const;
};

#endif // CONTROLLER_H
