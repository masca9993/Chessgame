#ifndef ALFIERE_H
#define ALFIERE_H
#include "mosseax.h"

class Alfiere : public Mosseax
{
public:
    Alfiere(bool c, int p, Scacchiera* parent);
     Alfiere* clone() const;
};

#endif // ALFIERE_H
