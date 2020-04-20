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

  board.push_back(new Torre(1, 0, this));
  board.push_back(new Cavallo(1, 1, this));
  board.push_back(new Alfiere(1, 2, this));
  board.push_back(new Regina(1, 3, this));
  board.push_back(new Re(1, 4, this));
  board.push_back(new Alfiere(1, 5, this));
  board.push_back(new Cavallo(1, 6, this));
  board.push_back(new Torre(1, 7, this));
  for (int i=0; i<8; i++)
  board.push_back(new Pedone(1, 8+i, this));
  for (int i=0; i<32; i++)
  board.push_back(nullptr);
  for (int i=0; i<8; i++)
  board.push_back(new Pedone(0, 48+i, this));
  board.push_back(new Torre(0, 56, this));
  board.push_back(new Cavallo(0, 57, this));
  board.push_back(new Alfiere(0, 58, this));
  board.push_back(new Regina(0, 59, this));
  board.push_back(new Re(0, 60, this));
  board.push_back(new Alfiere(0, 61, this));
  board.push_back(new Cavallo(0, 62, this));
  board.push_back(new Torre(0, 63, this));

/*
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
  }


for (int i=0; i<64; i++)
board.push_back(nullptr);
  board[60]=new Re(0, 60, this);
  //board[3]=new Regina(1, 3, this);
  board[56]=new Torre(0, 56, this);
  board[29]=new Torre(1, 29, this);
  board[35]=new Regina(1, 35, this);
  board[63]=new Torre(0, 63, this);*/
  try {
      doMove(12, 28);
      doMove(57, 42);
      doMove(5, 33);
      doMove(51,43);
      doMove(11, 27);
      doMove(58, 51);
      doMove(6, 21);
      doMove(42, 27);
      doMove(4,6);
  } catch (Mossa_illegale) {
      std::cout<<"mossa illegale";
  }
  catch (Mossa_Imposs) {
      std::cout<<"mossa impossibile";
  }

  for (int i=7; i>=0; i--)
  {
      for (int j=0; j<8; j++)
      {
          if (board[i*8+j])
          std::cout<<"x"<<" ";
          else
          std::cout<<board[i*8+j]<<" ";
      }
      std::cout<<std::endl;
  }
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

void Scacchiera::Arrocco(int pos1, int pos2)
{
      if (pos1==4)       //re bianco
      {
        if (pos2==2)     //arrocco lungo
        {
            Scacchiera* prova1=new Scacchiera(*this);
            prova1->board[pos1-1]=prova1->board[pos1];
            prova1->board[pos1-1]->setPosizione(pos1-1);
            prova1->board[pos1]=nullptr;
            Scacchiera* prova2=new Scacchiera(*this);
            prova2->board[pos1-2]=prova2->board[pos1];
            prova2->board[pos1-2]->setPosizione(pos1-2);
            prova2->board[pos1]=nullptr;
            if(!prova1->W(1) && !prova2->W(1))  //faccio l'arrocco lungo
            {
                board[pos2]=board[pos1];
                board[pos1]=nullptr;
                board[pos2]->setPosizione(pos2);
                board[pos2+1]=board[0];
                board[0]=nullptr;
                board[pos2+1]->setPosizione(pos2+1);
            }
            else
                throw Mossa_illegale();


        }
        else if (pos2==6)
        {
            Scacchiera* prova1=new Scacchiera(*this);
            prova1->board[pos1+1]=prova1->board[pos1];
            prova1->board[pos1+1]->setPosizione(pos1+1);
            prova1->board[pos1]=nullptr;
            Scacchiera* prova2=new Scacchiera(*this);
            prova2->board[pos1+2]=prova2->board[pos1];
            prova2->board[pos1+2]->setPosizione(pos1+2);
            prova2->board[pos1]=nullptr;
            if(!prova1->W(1) && !prova2->W(1))  //faccio l'arrocco corto
            {
                board[pos2]=board[pos1];
                board[pos1]=nullptr;
                board[pos2]->setPosizione(pos2);
                board[pos2-1]=board[7];
                board[7]=nullptr;
                board[pos2-1]->setPosizione(pos2-1);
            }
            else
                throw Mossa_illegale();
        }
      }
      else if (pos1==60)
      {
          if (pos2==58)     //arrocco lungo
          {
              Scacchiera* prova1=new Scacchiera(*this);
              prova1->board[pos1-1]=prova1->board[pos1];
              prova1->board[pos1-1]->setPosizione(pos1-1);
              prova1->board[pos1]=nullptr;
              Scacchiera* prova2=new Scacchiera(*this);
              prova2->board[pos1-2]=prova2->board[pos1];
              prova2->board[pos1-2]->setPosizione(pos1-2);
              prova2->board[pos1]=nullptr;
              if(!prova1->W(0) && !prova2->W(0))  //faccio l'arrocco lungo
              {
                  board[pos2]=board[pos1];
                  board[pos1]=nullptr;
                  board[pos2]->setPosizione(pos2);
                  board[pos2+1]=board[56];
                  board[56]=nullptr;
                  board[pos2+1]->setPosizione(pos2+1);
              }
              else
                  throw Mossa_illegale();
          }
          else if (pos2==62)
          {
              Scacchiera* prova1=new Scacchiera(*this);
              prova1->board[pos1+1]=prova1->board[pos1];
              prova1->board[pos1+1]->setPosizione(pos1+1);
              prova1->board[pos1]=nullptr;
              Scacchiera* prova2=new Scacchiera(*this);
              prova2->board[pos1+2]=prova2->board[pos1];
              prova2->board[pos1+2]->setPosizione(pos1+2);
              prova2->board[pos1]=nullptr;
              if(!prova1->W(0) && !prova2->W(0))  //faccio l'arrocco corto
              {
                  board[pos2]=board[pos1];
                  board[pos1]=nullptr;
                  board[pos2]->setPosizione(pos2);
                  board[pos2-1]=board[63];
                  board[63]=nullptr;
                  board[pos2-1]->setPosizione(pos2-1);
              }
              else
                  throw Mossa_illegale();
          }
      }
      else
          throw Mossa_Imposs();
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
            prova->doMove(j,mossebianco[i]);
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
                    if (i>=v.size()-2 && typeid(*getPedina(pos1))==typeid(Re)) //se devo muovere il re e la mossa è nelle ultime due posizioni devo fare l'arrocco
                    {
                     Arrocco(pos1, v[i]);
                        return;
                    }
                    else
                    {
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
                    board[pos2]->setPosizione(pos2);
                    return;
                    }
               }
            }
}
        throw Mossa_Imposs();
}


