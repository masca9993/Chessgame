#ifndef PEDONE_H
#define PEDONE_H
#include "pezzi.h"


class Pedone: public Pezzi
{
public:
    Pedone(bool c,int p, Scacchiera* parent, bool f=false);
    std::vector<int> move() const;
    Pedone* clone() const;
    void domove(int p);
private:
    bool firstmove;  //prima mossa del pedone
};

#endif // PEDONE_H
