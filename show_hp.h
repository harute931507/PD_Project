#ifndef SHOW_HP_H
#define SHOW_HP_H

#include <QGraphicsTextItem>

class Show_hp: public QGraphicsTextItem{
public:
    Show_hp(QGraphicsItem * parent = 0);
    void set_hp(int hp);
};

#endif // SHOW_HP_H
