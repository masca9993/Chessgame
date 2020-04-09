#include "torre.h"

Torre::Torre(bool c, int p, Scacchiera* parent) : Pezzi(c, p, parent)
{}

std::vector<int> Torre::move() const
{
    std::vector<int> mossepossibili;
    if (colore)
    {
    for (int i=1; i<8-pos/8; i++)  //aggiungo le mossepossibili in verticale verso l'alto, pezzo bianco
    {
        if (parent->getStato(pos+i*8)==none)
            mossepossibili.push_back(pos+i*8);
        else if (parent->getStato(pos+i*8)==bianco)
        {
            break;
        }
        else
        {
            mossepossibili.push_back(pos+i*8);
            break;
        }
    }
    for (int i=1; i<=0+pos/8; i++)  //aggiungo le mossepossibili in verticale verso il basso, pezzo bianco
    {
        if (parent->getStato(pos-i*8)==none)
            mossepossibili.push_back(pos-i*8);
        else if (parent->getStato(pos-i*8)==bianco)
        {
            break;
        }
        else
        {
            mossepossibili.push_back(pos-i*8);
            break;
        }
    }
    for (int i=1; i<8-pos%8; i++)  //aggiungo le mossepossibili in orizzontale verso destra, pezzo bianco
    {
        if (parent->getStato(pos+i)==none)
            mossepossibili.push_back(pos+i);
        else if (parent->getStato(pos+i)==bianco)
        {
            break;
        }
        else
        {
            mossepossibili.push_back(pos+i);
            break;
        }
    }
    for (int i=1; i<=0+pos%8; i++)  //aggiungo le mossepossibili in orizzontale verso sinistra, pezzo bianco
    {
        if (parent->getStato(pos-i)==none)
            mossepossibili.push_back(pos-i);
        else if (parent->getStato(pos-i)==nero)
        {
            break;
        }
        else
        {
            mossepossibili.push_back(pos-i);
            break;
        }
    }
    }
    else                          // pezzo nero
    {
        for (int i=1; i<8-pos/8; i++)
        {
            if (parent->getStato(pos+i*8)==none)
                mossepossibili.push_back(pos+i*8);
            else if (parent->getStato(pos+i*8)==nero)
            {
                break;
            }
            else
            {
                mossepossibili.push_back(pos+i*8);
                break;
            }
        }
        for (int i=1; i<=0+pos/8; i++)
        {
            if (parent->getStato(pos-i*8)==none)
                mossepossibili.push_back(pos-i*8);
            else if (parent->getStato(pos-i*8)==nero)
            {
                break;
            }
            else
            {
                mossepossibili.push_back(pos-i*8);
                break;
            }
        }
        for (int i=1; i<8-pos%8; i++)
        {
            if (parent->getStato(pos+i)==none)
                mossepossibili.push_back(pos+i);
            else if (parent->getStato(pos+i)==nero)
            {
                break;
            }
            else
            {
                mossepossibili.push_back(pos+i);
                break;
            }
        }
        for (int i=1; i<=0+pos%8; i++)
        {
            if (parent->getStato(pos-i)==none)
                mossepossibili.push_back(pos-i);
            else if (parent->getStato(pos-i)==nero)
            {
                break;
            }
            else
            {
                mossepossibili.push_back(pos-i);
                break;
            }
        }
    }
    return mossepossibili;
}

void Torre::setPos(int posizione)
{

}
