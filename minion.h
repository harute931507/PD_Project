#ifndef MINION_H
#define MINION_H

#include <QObject>
#include <QGraphicsRectItem>
#include "show_hp.h"
#include "minion_image.h"
#include "attack_area.h"

class Minion: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Minion(int get_id);
    int get_hp();
    int get_cost();
    void injured(int damage);
    Show_hp * show_hp;
    Minion_image * image;
    Attack_area * area;

public slots:
    void attack();
    void move();

private:
    static const int SCENE_X = 1600;
    static const int START_Y = 200;
    static const int IMAGE_W = 100;
    static const int IMAGE_H = 100;
    static const int HP_POS_X = 20;
    static const int HP_POS_Y = 25;
    static const int MOVE = 5;

    int id;
    int cost;
    int hp;
    int atk;
    int speed;
    int range;
    bool enemy;

    void initial();
};

#endif // MINION_H
