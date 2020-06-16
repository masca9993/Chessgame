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
 void ColoraMuovi(const int& r,const int& pos) const;
 void EseguiPromozione(const char& t, const int& p) const;
 void reset();
private:
    Scacchiera* scacchiera;
    Scacchi* vista;
    void cancellamosse() const;
    void vedimosse(const int& pos) const;
    void AggiornaIcone(const int& posi, const int& posf) const;
    void EseguiMossa(const int& posi,const int& posf) const;
    void mostravincitore() const;
};

#endif // CONTROLLER_H
