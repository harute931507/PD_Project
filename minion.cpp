#include "minion.h"

#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QList>
#include "show_hp.h"
#include "enemy.h"
#include "tower.h"

#include <QDebug>

Minion::Minion(int get_id){
    //set minion
    setPos(0, START_Y);
    id = get_id;
    initial();
    setRect(0, 0, IMAGE_W, IMAGE_H);

    //set image
    image = new Minion_image();
    image->set_image(id, QString("L"));
    image->setPos(0, START_Y);

    //set attack area
    area = new Attack_area(range, atk);
    area->setPos(x() + IMAGE_W, y() + 1);

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

int Minion::get_cost(){
    return cost;
}

void Minion::injured(int damage){
    //when minion be injured
    hp -= damage;
    show_hp->set_hp(hp);

    //if hp <=0, minion dead
    if(hp <= 0){
        delete this;
        delete show_hp;
        delete area;
        delete image;
        qDebug() << "minion " << id << " destroyed";
    }
}

void Minion::attack(){
    //if enemy in attack area, attack
    if (area->minion_attack() == true)
        enemy = true;
    else
        enemy = false;
}

void Minion::move(){
    //if is not out of scene and has no enemy, move
    if((pos().x() + MOVE <= SCENE_X - IMAGE_W) && !enemy){
        setPos(x() + MOVE, y());
        image->setPos(image->x() + MOVE, image->y());
        show_hp->setPos(show_hp->x() + MOVE, show_hp->y());
        area->setPos(area->x() + MOVE, area->y());
    }
}

void Minion::initial(){
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

