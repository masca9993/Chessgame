#ifndef RE_H
#define RE_H
#include "pezzi.h"
#include "scacchiera.h"

class Re : public Pezzi
{
public:
    Re(bool c, int p, Scacchiera* parent, bool ch=false, bool m=false);
    std::vector<int> move() const;
    bool hasmoved() const;
    bool check;
    private:
    bool moved;
};

#endif // RE_H
