#ifndef TORRE_H
#define TORRE_H
#include "mosseacroce.h"


class Torre : public mosseacroce
{
public:
    Torre(bool c, int p, Scacchiera* parent, bool m=false);
    bool hasmoved() const;
private:
    bool moved;
};

#endif // TORRE_H
