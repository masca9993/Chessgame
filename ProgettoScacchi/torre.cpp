#include "torre.h"

Torre::Torre(bool c, int p, Scacchiera* parent, bool m) : Pezzi(c,p,parent), mosseacroce(c, p, parent), moved(m)
{}

bool Torre::hasmoved() const
{
    return moved;
}

