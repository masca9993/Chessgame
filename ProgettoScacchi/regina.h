#ifndef REGINA_H
#define REGINA_H
#include "pezzi.h"


class Regina : public Pezzi
{
public:
    Regina(bool c, int p, Scacchiera* parent);
    std::vector<int> move() const;
};

#endif // REGINA_H
