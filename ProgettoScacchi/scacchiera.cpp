#include "scacchiera.h"

Scacchiera::Scacchiera()
{
  for (int i=0; i<16; i++)
  board.push_back(bianco);
  for (int i=0; i<32; i++)
  board.push_back(none);
  for (int i=0; i<16; i++)
  board.push_back(nero);
}

giocatore Scacchiera::getStato(int pos) const
{
  return board[pos];
}
