#ifndef SCACCHIERA_H
#define SCACCHIERA_H
#include <vector>


enum giocatore{none = 0, bianco =1, nero =2};


class Scacchiera
{
public:
    Scacchiera();
    giocatore getStato(int pos) const;  //ritorna se un bottone nella posizione 'pos' è libero oppure occupato da un giocatore bianco o nero
    ~Scacchiera();
private:
    std::vector<giocatore> board;
};

#endif // SCACCHIERA_H
