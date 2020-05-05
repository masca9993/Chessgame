#ifndef RE_H
#define RE_H
#include "pezzi.h"
#include "scacchiera.h"

class Re : public Pezzi
{
public:
    Re(bool c, int p, Scacchiera* parent, bool m=false);
    std::vector<int> move() const;
    bool hasmoved() const;
    Re* clone() const;
   void setPosizione(int p);
    private:
    bool moved=false;
};

#endif // RE_H
