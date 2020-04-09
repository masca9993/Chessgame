#include "pezzi.h"

Pezzi::Pezzi(bool c,int p, Scacchiera* g): colore(c) , pos(p), parent(g) {}

bool Pezzi::getColore() const
{
    return colore;
}

int Pezzi::getPosizione() const
{
    return pos;
}
