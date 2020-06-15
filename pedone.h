#ifndef PEDONE_H
#define PEDONE_H
#include "pezzi.h"


class Pedone: public Pezzi
{
public:
    Pedone(bool c,int p, Scacchiera* parent, bool f=false, bool b =false);
    vector<int> move() const;
    Pedone* clone() const;
    vector<int> enpassant() const;
    void setpass(bool c) ;
    void setPosizione(int p);
private:
    bool firstmove;  //prima mossa del pedone
    bool pass;  //viene inpostata a true solo quando viene effettuata una mossa di sue caselle, e viene rimessa false quando passa un turno
};

#endif // PEDONE_H
