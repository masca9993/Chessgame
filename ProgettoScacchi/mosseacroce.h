#ifndef MOSSEACROCE_H
#define MOSSEACROCE_H
#include "pezzi.h"

class mosseacroce: virtual public Pezzi
{
public:
    mosseacroce(bool c, int p, Scacchiera* parent);
    virtual std::vector<int> move() const;
};

#endif // MOSSEACROCE_H
