#ifndef ATTACK_AREA_H
#define ATTACK_AREA_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Attack_area: public QGraphicsRectItem{
public:
    Attack_area(int length, int get_damage);
    bool minion_attack();
    bool enemy_attack();

private:
    int damage;
    int distance_to(QGraphicsItem * item);
};

#endif // ATTACK_AREA_H
