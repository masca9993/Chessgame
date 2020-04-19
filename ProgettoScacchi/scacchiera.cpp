#include "scacchiera.h"
#include "cavallo.h"
#include "torre.h"
#include "regina.h"
#include "re.h"
#include "alfiere.h"
#include "pedone.h"
#include "Mossa_Imposs.h"
#include "Mossa_illegale.h"

Scacchiera::Scacchiera()
{
/*
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
  board.push_back(new Torre(1, 63, this));


  int posi, posf;
  int cont=0;
  while (1)
  {
      if (cont%2==0)
      {
         //per ogni pedone bianco if enpass=true enpass=false
          std::cout<<"tocca al bianco"<<std::endl;
          std::cin>>posi>>posf;
          try {
              board[posi]->domove(posf);
          } catch () {

          }

      }
  }*/


for (int i=0; i<64; i++)
board.push_back(nullptr);
  board[4]=new Re(1, 4, this);
  //board[3]=new Regina(1, 3, this);
  board[0]=new Torre(1, 0, this);
  //board[16]=new Torre(1, 16, this, true);
  board[7]=new Regina(0, 7, this);
  std::vector<int> v=board[4]->move();
  for (unsigned int i=0; i<v.size(); i++)
      std::cout<<v[i]<<" ";
  //board[12]=new Cavallo(0, 12, this);
  //board[57]=new Torre(1, 57, this, true);
  //board[15]=new Torre(0, 15, this);
}

Scacchiera::Scacchiera(const Scacchiera &s)
{
    for (int i=0; i<64; i++)
    {
        board.push_back(nullptr);    //inizializzo ogni casella a nullptr
        if (s.board[i])     // se nella scacchiera da copiare allora copio lo stesso pezzo in this
        {
            board[i]=s.board[i]->clone();
            board[i]->setParent(this);
        }
    }
}

giocatore Scacchiera::getStato(int pos) const
{
  if (board[pos])
  {
      if (board[pos]->getColore())
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

Scacchiera::~Scacchiera()
{
    for (int i=0; i<64; i++)
    {
        delete board[i];
    }
}

bool Scacchiera::W(bool p) const  //funzione che verifica se c'è uno scacco al giocatore p
{
    int re_pos;
  for (unsigned int i=0; i<64; i++)
  {
     if (board[i] && board[i]->getColore()==p && dynamic_cast<Re*>(board[i])!=nullptr)  //cerco il re
     re_pos=i;
  }
  std::vector<int> v;
  if (p)          //salvo tutte le mosse possibili dell'avversario
  v=Mosse(0);
   else
   v=Mosse(1);

  for (unsigned int i=0; i<v.size(); i++)   //se nelle mosse possibili dell'avversario c'è la posizione del re allora ritorno vero
  {
      if (v[i]==re_pos)
          return true;
  }
   return false;    //se esco dal ciclo senza ritornare nulla allora ritorno falso
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
              std::vector<int> mosse_nero=board[i]->move();
              for (unsigned int i=0; i<mosse_nero.size() && !check; i++)
              {
                  if (mosse_nero[i]==re_pos)
                      check=true;
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
              std::vector<int> mosse_bianco=board[i]->move();
              for (unsigned int i=0; i<mosse_bianco.size() && !check; i++)
              {
                  if (mosse_bianco[i]==re_pos)
                      check=true;
              }
          }
        }
    }
    return check;
}

std::vector<int> Scacchiera::Mosse(bool g) const
{
    std::vector<int> mossetot;
    for (int i=0; i<64; i++)
    {
        if (board[i] && board[i]->getColore()==g)
        {
            std::vector<int> t;
            t=board[i]->move();
            mossetot.insert(mossetot.end(), t.begin(), t.end());
        }
    }
    return mossetot;
}

giocatore Scacchiera::Winner(bool p)   //ipotizzo che il re sia sottoscacco, perche winner viene chiamata solo se dopo una mossa il re è sottoscacco
{
       for (int j=0; j<64; j++)   // scorro la scacchiera, se trovo un pezzo bianco salvo le sue mosse e le simulo nel for annidato
        {
         if (board[j] && board[j]->getColore()==p)
          {
             std::vector<int> mossebianco=board[j]->move();
         for (unsigned int i=0; i<mossebianco.size(); i++)
         {
            Scacchiera* prova=new Scacchiera(*this);
            prova->board[j]->domove(mossebianco[i]);
            if(!prova->W(p))
            return none;
         }
         }
    }
      return p ? nero : bianco;

}

void Scacchiera::doMove(int pos1, int pos2)
{
          if (board[pos1])
          {
            std::vector<int> v=board[pos1]->move();
            for(unsigned int i=0; i<v.size();i++){
                if(v[i]==pos2){
                    Scacchiera* prova=new Scacchiera(*this);
                    if(prova->board[pos2])
                     delete prova->board[pos2];
                      prova->board[pos2]=prova->board[pos1];
                      prova->board[pos1]=nullptr;
                      prova->board[pos2]->setPosizione(pos2);
                      if (prova->W(board[pos1]->getColore()))
                          throw Mossa_illegale();

                    if(board[pos2])
                        delete board[pos2];
                    board[pos2]=board[pos1];
                    board[pos1]=nullptr;
                    return;
               }
            }
}
        throw Mossa_Imposs();
}


