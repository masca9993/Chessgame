#ifndef REGINA_H
#define REGINA_H
#include "mosseacroce.h"
#include "mosseax.h"


class Regina : public mosseacroce , public Mosseax
{
public:
    Regina(bool c, int p, Scacchiera* parent);
    std::vector<int> move() const;
    Regina* clone() const;
};

#endif // REGINA_H
