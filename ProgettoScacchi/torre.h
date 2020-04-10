#ifndef TORRE_H
#define TORRE_H
#include "mosseacroce.h"


class Torre : public mosseacroce
{
public:
    Torre(bool c, int p, Scacchiera* parent);
private:
    void setPos(int posizione);
};

#endif // TORRE_H
