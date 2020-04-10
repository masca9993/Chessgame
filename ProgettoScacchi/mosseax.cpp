#include "mosseax.h"

Mosseax::Mosseax(bool c, int p, Scacchiera *parent): Pezzi(c, p, parent){}


std::vector<int> Mosseax::move() const
{
    std::vector<int> mossepossibili;
    if(colore){
        int i=pos+7;
        int limitesuperiore=8-pos/8;
        int j=1;
        while(i>=0 && (pos%8)!=0 && parent->getStato(i)!=bianco && j<limitesuperiore){//mosse in diagonale in alto a sinistra
            mossepossibili.push_back(i);
            if(parent->getStato(i)==nero || (i%8)==0)
                j=limitesuperiore;
            else{
                i+=7;
                j++;
            }
        }
        i=pos+9;
        j=1;
        while(i>=0 && (pos%8)!=7 && parent->getStato(i)!=bianco && j<limitesuperiore){//mosse in diagonale in alto a destra
            mossepossibili.push_back(i);
            if(parent->getStato(i)==nero || (i%8)==7)
                j=limitesuperiore;
            else{
                i+=9;
                j++;
            }
        }
        i=pos-9;
        j=1;
        int limiteinferiore=pos/8;
        while(i>=0 && (pos%8)!=0 && parent->getStato(i)!=bianco && j<=limiteinferiore){//mosse in diagonale in basso a sinistra
            mossepossibili.push_back(i);
            if(parent->getStato(i)==nero || (i%8)==0)
                j=limiteinferiore+1;
            else{
                i-=9;
                j++;
            }
        }
        i=pos-7;
        j=1;
        while(i>=0 && (pos%8)!=7 &&  parent->getStato(i)!=bianco && j<=limiteinferiore){//mosse in diagonale in basso a destra
            mossepossibili.push_back(i);
            if(parent->getStato(i)==nero || (i%8)==7)
                j=limiteinferiore+1;
            else{
                i-=7;
                j++;
            }
        }
    }
    else{
        int i=pos+7;
        int limitesuperiore=8-pos/8;
        int j=1;
        while( i>=0 && (pos%8)!=0 && parent->getStato(i)!=nero && j<limitesuperiore){//mosse in diagonale in alto a sinistra
            mossepossibili.push_back(i);
            if(parent->getStato(i)==bianco || (i%8)==0)
                j=limitesuperiore;
            else{
                i+=7;
                j++;
            }
        }
        i=pos+9;
        j=1;
        while(i>=0 && (pos%8)!=7 &&  parent->getStato(i)!=nero && j<limitesuperiore){//mosse in diagonale in alto a destra
            mossepossibili.push_back(i);
            if(parent->getStato(i)==bianco || (i%8)==7)
                j=limitesuperiore;
            else{
                i+=9;
                j++;
            }
        }
        i=pos-9;
        j=1;
        int limiteinferiore=pos/8;
        while(i>=0 && (pos%8)!=0 && parent->getStato(i)!=nero && j<=limiteinferiore){//mosse in diagonale in basso a sinistra
            mossepossibili.push_back(i);
            if(parent->getStato(i)==bianco || (i%8)==0)
                j=limiteinferiore+1;
            else{
                i-=9;
                j++;
            }
        }
        i=pos-7;
        j=1;
        while(i>=0 && (pos%8)!=7 &&  parent->getStato(i)!=nero && j<=limiteinferiore){//mosse in diagonale in basso a destra
            mossepossibili.push_back(i);
            if(parent->getStato(i)==bianco || (i%8)==7)
                j=limiteinferiore+1;
            else{
                i-=7;
                j++;
            }
        }
    }
    return mossepossibili;
}
