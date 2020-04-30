#ifndef CHESSBUTTON_H
#define CHESSBUTTON_H

#include <QPushButton>

class ChessButton : public QPushButton
{
    Q_OBJECT
public:
    ChessButton(int p, QWidget* parent=nullptr);
private:
    int pos;
signals:
    void buttonclicked(int p);
public slots:
   void clicked();
};

#endif // CHESSBUTTON_H
