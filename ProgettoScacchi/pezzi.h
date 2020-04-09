#ifndef PEZZI_H
#define PEZZI_H
#include <vector>
#include "scacchiera.h"

class Pezzi
{
public:
     Pezzi(bool c,int p, Scacchiera* g =nullptr);
    bool getColore() const;// 0=bianco; 1=nero;
    int getPosizione() const;
    virtual std::vector<int> move() const =0;
protected:
    bool colore;
    //posizione
    int pos;
    Scacchiera* parent;
};

#endif // PEZZI_H
