#include "tower.h"

#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "show_hp.h"
#include "enemy.h"
#include "game.h"

extern Game * game;

Tower::Tower(){
    //set tower
    setPos(0, START_Y);
    hp = 3000;
    atk = 30;
    range = 500;
    setRect(0, 0, IMAGE_W, IMAGE_H);

    //set image
    image = new Minion_image();
    image->set_image(true);
    image->setPos(0, START_Y);

    //set attack area
    area = new Attack_area(range, atk);
    area->setPos(x() + IMAGE_W, y() + IMAGE_H/2);

    //connect attack
    QTimer * attack_timer = new QTimer();
    connect(attack_timer, SIGNAL(timeout()), this, SLOT(attack()));
    attack_timer->start(500);

    //initialize show_hp
    show_hp = new Show_hp();
    show_hp->set_hp(hp);
    show_hp->setPos(x()+HP_POS_X, y()-HP_POS_Y);
}

void Tower::injured(int damage){
    hp -= damage;
    show_hp->set_hp(hp);

    //if hp <=0, minion dead
    if(hp <= 0){
        delete this;
        delete show_hp;
        delete area;
        delete image;
        qDebug() << "Tower destroyed";

        game->game_over("You Lose!!");
    }
}

void Tower::attack(){
    //if enemy in attack area, attack
    area->minion_attack();
}
