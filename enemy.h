#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>
#include "show_hp.h"
#include "attack_area.h"
#include "minion_image.h"

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Enemy(int get_id);
    int get_id();
    int get_cost();
    void injured(int damage);
    Show_hp * show_hp;
    Attack_area * area;
    Minion_image * image;

public slots:
    void move();
    void attack();

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
    bool minion;

    void initial();
};

#endif // ENEMY_H
