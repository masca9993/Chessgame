#ifndef SCACCHIERA_H
#define SCACCHIERA_H
#include <vector>
#include<iostream>
class Pezzi;
enum giocatore{none = 0, bianco =1, nero =2};

class Scacchiera
{
public:
    Scacchiera();
    Scacchiera(const Scacchiera& s);
    giocatore getStato(int pos) const;  //ritorna se nella posizione 'pos' la casella è libera oppure è occupata da un giocatore bianco o nero
    Pezzi* getPedina(int pos) const;  //ritorna un puntatore al pezzo che risiede nela casella pos
    ~Scacchiera();
    bool Check(int re_pos, bool colore) const;   //verifica se il re nella posizione re_pos e del colore è sottoscacco
    std::vector<int> Mosse(bool g) const;
    giocatore Winner(bool p);
   bool doMove(int pos1, int pos2);   //doMove è la funzione che muove le pedine (nel caso di arrocco (cioè re di muove di due passi rispetto alla sua posizione) deve preoccuparsi di muovere anche la torre coinvolta)
private:
    std::vector<Pezzi*> board;
    bool W(bool p) const;  // p è il colore del re di cui si vuole controllare lo scacco
};

#endif // SCACCHIERA_H

