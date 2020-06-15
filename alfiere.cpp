#include "alfiere.h"

Alfiere::Alfiere(bool c, int p, Scacchiera* parent) :Pezzi(c, p, parent), Mosseax(c, p, parent){}

Alfiere *Alfiere::clone() const
{
    return new Alfiere(*this);
}

