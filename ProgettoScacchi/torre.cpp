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

void Torre::domove(int p)
{
    try {
        parent->doMove(pos,p);
        setPosizione(p);
        if(!moved)
        moved=true;
    } catch (Mossa_illegale) {

        std::cout<<"mossa illegale"<<std::endl;

    }
    catch (Mossa_Imposs){

        std::cout<<"mossa impossibile"<<std::endl;
    }
}

