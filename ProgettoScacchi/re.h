#ifndef RE_H
#define RE_H
#include "pezzi.h"


class Re : public Pezzi
{
public:
    Re(bool c, int p, Scacchiera* parent);
    std::vector<int> move() const;
};

#endif // RE_H
