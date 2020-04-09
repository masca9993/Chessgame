#ifndef CAVALLO_H
#define CAVALLO_H
#include "pezzi.h"


class Cavallo : public Pezzi
{
public:
    Cavallo(bool c, int p, Scacchiera* parent);
     std::vector<int> move() const;
};

#endif // CAVALLO_H
