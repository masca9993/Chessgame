#ifndef CHESSBUTTON_H
#define CHESSBUTTON_H

#include <QPushButton>

class ChessButton : public QPushButton
{
    Q_OBJECT
public:
    ChessButton(int p, QWidget* parent=nullptr,  int r=-1);
    void setRed(int r) ;
private:
    int pos;
    int red;
signals:
    void buttonclicked(int r, int pos);
public slots:
   void clicked();
};

#endif // CHESSBUTTON_H
