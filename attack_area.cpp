#include "attack_area.h"

#include <QList>
#include <QDebug>
#include <QLineF>

#include "minion.h"
#include "enemy.h"
#include "tower.h"
#include "tower_ai.h"

Attack_area::Attack_area(int length, int get_damage){
    setRect(0, 0, length, 1);
    setOpacity(0);
    damage = get_damage;
}

bool Attack_area::minion_attack(){
    QList <QGraphicsItem *> in_area = collidingItems();
    Enemy * target;
    Tower_ai * tower;
    double min_l = 2000;
    bool is_tower = false;

    //find the closest
    for(int i=0; i<in_area.size(); ++i){
        Enemy * enemy = dynamic_cast <Enemy *> (in_area[i]);

        if(enemy){
            double distance = distance_to(enemy);
            if(distance<min_l){
                target = enemy;
                min_l = distance;
                is_tower = false;
            }
        }

        //check tower_ai
        tower = dynamic_cast <Tower_ai *> (in_area[i]);
        if(tower){
            double distance = distance_to(tower);
            if(distance<min_l){
                min_l = distance;
                is_tower = true;
            }
        }
    }

    if(min_l == 2000) return false;

    if(is_tower){
        tower->injured(damage);
    }else{
        target->injured(damage);
    }
    return true;
}

bool Attack_area::enemy_attack(){
    QList <QGraphicsItem *> in_area = collidingItems();
    Minion * target;
    Tower * tower;
    double max_l = 0;
    bool is_tower = false;
    int record_i = 0;

    //find the closest
    for(int i=0; i<in_area.size(); ++i){
        Minion * minion = dynamic_cast <Minion *> (in_area[i]);

        if(minion){
            double distance = distance_to(minion);
            if(distance > max_l){
                target = minion;
                max_l = distance;
                is_tower = false;
                record_i = i;
            }
        }

        //check tower_ai
        tower = dynamic_cast <Tower *> (in_area[i]);
        if(tower){
            double distance = distance_to(tower);
            if(distance > max_l){
                max_l = distance;
                is_tower = true;
            }
        }
    }

    if(max_l == 0) return false;

    if(is_tower){
        tower->injured(damage);
    }else{
        target->injured(damage);
    }
    return true;
}

int Attack_area::distance_to(QGraphicsItem *item){
    QLineF line(pos(), item->pos());
    return line.length();
}
