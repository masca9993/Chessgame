#ifndef TORRE_H
#define TORRE_H
#include "pezzi.h"


class Torre : public Pezzi
{
public:
    Torre(bool c, int p, Scacchiera* parent);
    std::vector<int> move() const;
private:
    void setPos(int posizione);
};

#endif // TORRE_H
