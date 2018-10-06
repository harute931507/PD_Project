#ifndef SHOW_MANA_H
#define SHOW_MANA_H

#include <QGraphicsTextItem>

class Show_mana: public QGraphicsTextItem{
public:
    Show_mana(QGraphicsItem * parent = 0);
    void increase();
    void decrease(int x);
    int get_mana();

private:
    int mana;
};

#endif // SHOW_MANA_H
