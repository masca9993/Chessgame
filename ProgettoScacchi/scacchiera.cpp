#include "scacchiera.h"
#include "cavallo.h"
#include "torre.h"
#include "regina.h"
#include "re.h"
#include "alfiere.h"
#include "pedone.h"


Scacchiera::Scacchiera()
{/*
  board.push_back(new Torre(0, 0, this));
  board.push_back(new Cavallo(0, 1, this));
  board.push_back(new Alfiere(0, 2, this));
  board.push_back(new Regina(0, 3, this));
  board.push_back(new Re(0, 4, this));
  board.push_back(new Alfiere(0, 5, this));
  board.push_back(new Cavallo(0, 6, this));
  board.push_back(new Torre(0, 7, this));
  for (int i=0; i<8; i++)
  board.push_back(new Pedone(0, 8+i, this));
  for (int i=0; i<32; i++)
  board.push_back(nullptr);
  for (int i=0; i<8; i++)
  board.push_back(new Pedone(1, 48+i, this));
  board.push_back(new Torre(1, 56, this));
  board.push_back(new Cavallo(1, 57, this));
  board.push_back(new Alfiere(1, 58, this));
  board.push_back(new Regina(1, 59, this));
  board.push_back(new Re(1, 60, this));
  board.push_back(new Alfiere(1, 61, this));
  board.push_back(new Cavallo(1, 62, this));
  board.push_back(new Torre(1, 63, this));*/

  //board.resize(64);
  for (unsigned int i=0; i<64; i++)
      board.push_back(nullptr);
  //board[0]=new Torre(0, 0, this);
  //board[3]=new Regina(0, 3, this);
  //board[4]=new Re(0, 4, this);
  //board[7]=new Torre(0, 7, this);
}

giocatore Scacchiera::getStato(int pos) const
{
  if (board[pos])
  {
      if (!board[pos]->getColore())
          return bianco;
      else
          return nero;
  }
  else
      return none;
}

Pezzi* Scacchiera::getPedina(int pos) const
{
    return board[pos];
}

bool Scacchiera::Check(int re_pos, bool colore) const
{
    bool check=false;
    if (colore)   // re bianco
    {
        for (unsigned int i=0; i<board.size() && !check; i++)
        {
          if (this->getStato(i)==nero)
          {
              std::vector<int> mosse_nero;
              mosse_nero=board[i]->move();
              for (unsigned int i=0; i<board.size() && !check; i++)
              {
                  if (mosse_nero[i]==re_pos)
                      check=true;
                  //winner(re_pos,colore)
              }
          }
        }
    }
    else
    {
        for (unsigned int i=0; i<board.size() && !check; i++)
        {
          if (this->getStato(i)==bianco)
          {
              std::vector<int> mosse_bianco;
              mosse_bianco=board[i]->move();
              for (unsigned int i=0; i<board.size() && !check; i++)
              {
                  if (mosse_bianco[i]==re_pos)
                      check=true;
              }
          }
        }
    }
    return check;
}

bool Scacchiera::doMove(int pos1, int pos2)
{
    if(board[pos1]){
        std::vector<int> v=board[pos1]->move();
        bool check=false;
        for(unsigned int i=0; i<v.size();i++){
            if(v[i]==pos2){
                if(board[pos2])
                    delete board[pos2];
                board[pos2]=board[pos1];
                board[pos1]=nullptr;
                check=true;
                break;
            }
        }
    return check;
    }
}

giocatore Scacchiera::winner(int pos,bool colore) const
{
    bool winner=true;
    if(colore){
        if(board[pos]->move().size()!=0)
            winner=false;
        else{
            std::vector<int> mossepossibili;
            for(std::vector<Pezzi*>::const_iterator it=board.begin(); it!=board.end(); it++){
                if(it && (*it)->getColore()){
//                    mossepossibili=(*it)->move();
//                    for(int i=0; i<mossepossibili.size(); i++)
                    mossepossibili.insert(mossepossibili.end(),(*it)->move().begin(),(*it)->move().end())
                }
            }
            for(int i=0; i<mossepossibili.size(); i++){

            }
        }
    }
}


