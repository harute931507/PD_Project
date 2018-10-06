#include "enemy.h"

#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "show_hp.h"
#include "minion.h"

Enemy::Enemy(int get_id){
    //set enemy
    id = get_id;
    initial();
    setRect(0, 0, IMAGE_W, IMAGE_H);
    setPos(SCENE_X - IMAGE_W, START_Y);

    //set image
    image = new Minion_image();
    image->set_image(id, QString("R"));
    image->setPos(x(), y());

    //set attack area
    area = new Attack_area(range, atk);
    area->setPos(x() - range, y() + IMAGE_H -2);

    //connect move
    QTimer * move_timer = new QTimer();
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(1000 / speed);

    //connect attack
    QTimer * attack_timer = new QTimer();
    connect(attack_timer, SIGNAL(timeout()), this, SLOT(attack()));
    attack_timer->start(5000 / speed);

    //initialize show_hp
    show_hp = new Show_hp();
    show_hp->set_hp(hp);
    show_hp->setPos(x()+HP_POS_X, y()-HP_POS_Y);
}

int Enemy::get_id(){
    return id;
}

int Enemy::get_cost(){
    return cost;
}

void Enemy::injured(int damage){
    //when minion be injured
    hp -= damage;
    show_hp->set_hp(hp);

    //if hp <=0, minion dead
    if(hp <= 0){
        delete this;
        delete show_hp;
        delete area;
        delete image;
        qDebug() << "enemy " << id << " destroyed";
    }
}

void Enemy::move(){
    //if is not out of scene and has no minion, move
    if((pos().x() + MOVE >= 0) && !minion){
        setPos(x() - MOVE, y());
        show_hp->setPos(show_hp->x() - MOVE, show_hp->y());
        area->setPos(area->x() - MOVE, area->y());
        image->setPos(image->x() - MOVE, image->y());
        //image->setPos(x() - 5, y());
    }
}

void Enemy::attack(){
    //if minion in attack area, attack
    if (area->enemy_attack() == true)
        minion = true;
    else
        minion = false;
}

void Enemy::initial(){
    switch(id){
        case 1: //normal
            cost = 1;
            hp = 300;
            atk = 10;
            speed = 10;
            range = 1;
            break;

        case 2: //tank
            cost = 7;
            hp = 1200;
            atk = 20;
            speed = 8;
            range = 1;
            break;

        case 3: //assassin
            cost = 5;
            hp = 200;
            atk = 30;
            speed = 15;
            range = 2;
            break;

        case 4: //shooter
            cost = 8;
            hp = 100;
            atk = 40;
            speed = 5;
            range = 5;
            break;
    }

    range *= 50;
}

