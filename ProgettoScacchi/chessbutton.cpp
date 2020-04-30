#include "chessbutton.h"

ChessButton::ChessButton(int p, QWidget* parent) : QPushButton(parent), pos(p)
{
    connect(this, SIGNAL(clicked()), this, SLOT(clicked()));
}

void ChessButton::clicked()
{
 emit buttonclicked(pos);
}
