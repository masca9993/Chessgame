#include "pezzi.h"
Pezzi::Pezzi(bool c,int p, Scacchiera* g): colore(c) , pos(p), parent(g) {}

bool Pezzi::getColore() const
{
    return colore;
}

void Pezzi::setPosizione(int p)
{
    pos=p;
}

int Pezzi::getPosizione() const
{
    return pos;
}

Pezzi::~Pezzi()
{

}
void Pezzi::domove(int p)
{
    try {
         parent->doMove(pos,p);

        setPosizione(p);
    } catch (Mossa_illegale) {
        std::cout<<"mossa illlegale"<<std::endl;
    }
    catch (Mossa_Imposs){
        std::cout<<"mossa impossibile"<<std::endl;
    }

}

void Pezzi::setParent(Scacchiera *s)
{
 parent=s;
}
