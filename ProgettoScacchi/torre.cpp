#include "torre.h"

Torre::Torre(bool c, int p, Scacchiera* parent, bool m) : Pezzi(c,p,parent), mosseacroce(c, p, parent), moved(m)
{}

bool Torre::hasmoved() const
{
    return moved;
}

Torre *Torre::clone() const
{
    return new Torre(*this);
}

void Torre::setPosizione(int p)
{
    pos=p;
    if(!moved)
    moved=true;
}

