#include "chessbutton.h"

ChessButton::ChessButton(int p,  QWidget* parent,  int r) : QPushButton(parent), pos(p), red(r)
{
    connect(this, SIGNAL(clicked()), this, SLOT(clicked()));
}

void ChessButton::setRed(int r)
{
    red=r;
}

void ChessButton::clicked()
{
 emit buttonclicked(red, pos);
}
