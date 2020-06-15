#ifndef PROMBUTTON_H
#define PROMBUTTON_H
#include <QPushButton>

class PromButton : public QPushButton
{
    Q_OBJECT
public:
    PromButton(char t, int p, QWidget* parent=nullptr);
private:
    char tipo;
    int pos;
signals:
    void buttonclicked(char t, int p);
public slots:
    void clicked();
};

#endif // PROMBUTTON_H
