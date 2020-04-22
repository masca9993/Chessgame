#ifndef PEDONE_H
#define PEDONE_H
#include "pezzi.h"


class Pedone: public Pezzi
{
public:
    Pedone(bool c,int p, Scacchiera* parent, bool f=false, bool b =false);
    std::vector<int> move() const;
    Pedone* clone() const;
    std::vector<int> enpassant() const;
    bool setpass(bool p);
    void setPosizione(int p);
private:
    bool firstmove;  //prima mossa del pedone
    bool pass;  //viene inpostata a true solo quando viene effettuata una mossa di sue caselle, e viene rimessa false quando passa un turno
};

#endif // PEDONE_H
