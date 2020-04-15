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
    virtual void domove(int p);
protected:
    bool colore; // 0=nero // 1=bianco
    //posizione
    int pos;
    Scacchiera* parent;
};

#endif // PEZZI_H
