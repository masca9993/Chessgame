#include "pedone.h"

Pedone::Pedone(bool c,int p, Scacchiera* parent, bool f) : Pezzi(c,p, parent), firstmove(f){}

std::vector<int> Pedone::move() const
{
    std::vector<int> mossepossibili;
    //sx e dx guardando il pedone
    if(colore){//se il colore è bianco sommo, e la mossa +7 va in diagonale a sinistra, mentre, +9 va in diagonale a destra
        if(!firstmove){
            if(!parent->getStato(pos+8))
                mossepossibili.push_back(pos+8);
            if(!parent->getStato(pos+8) && !parent->getStato(pos+16))
                mossepossibili.push_back(pos+16);
            if((pos%8)!=0 && parent->getStato(pos+7)==nero)
                mossepossibili.push_back(pos+7);
            if((pos%8)!=7 && parent->getStato(pos+9)==nero)
            mossepossibili.push_back(pos+9);
        }
        else{
            if(!parent->getStato(pos+8))
                mossepossibili.push_back(pos+8);
            if((pos%8)!=0 &&parent->getStato(pos+7)==nero)
                mossepossibili.push_back(pos+7);
            if((pos%8)!=7 &&parent->getStato(pos+9)==nero)
                mossepossibili.push_back(pos+9);
        }
    }
    else{
        //se il colore è nero, la mossa -7 va in diagole a sinistra, mentre -9 va in diagonale a destra
        if(!firstmove){
            if(!parent->getStato(pos-8))
                mossepossibili.push_back(pos-8);
            if(!parent->getStato(pos-8) && !parent->getStato(pos-16))
                mossepossibili.push_back(pos-16);
            if((pos%8)!=7 && parent->getStato(pos-7)==bianco)
                mossepossibili.push_back(pos-7);
            if((pos%8)!=0 && parent->getStato(pos-9)==bianco)
            mossepossibili.push_back(pos-9);
        }
        else{
            if(!parent->getStato(pos-8))
                mossepossibili.push_back(pos-8);
            if((pos%8)!=7 &&parent->getStato(pos-7)==bianco)
                mossepossibili.push_back(pos+7);
            if((pos%8)!=0 &&parent->getStato(pos-9)==bianco)
                mossepossibili.push_back(pos-9);
        }
    }
return mossepossibili;
}
