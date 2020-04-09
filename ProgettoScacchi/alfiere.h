#ifndef ALFIERE_H
#define ALFIERE_H
#include "pezzi.h"
class Alfiere : public Pezzi
{
public:
    Alfiere(bool c, int p, Scacchiera* parent);
    std::vector<int> move() const;
};

#endif // ALFIERE_H
