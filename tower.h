#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QGraphicsRectItem>
#include "show_hp.h"
#include "minion_image.h"
#include "attack_area.h"

class Tower: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Tower();
    void injured(int damage);
    Show_hp * show_hp;
    Minion_image * image;
    Attack_area * area;

public slots:
    void attack();

private:
    static const int START_Y = 200;
    static const int IMAGE_W = 100;
    static const int IMAGE_H = 100;
    static const int HP_POS_X = 20;
    static const int HP_POS_Y = 25;

    int hp;
    int atk;
    int range;
};

#endif // TOWER_H
