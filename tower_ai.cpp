#include "tower_ai.h"

#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "show_hp.h"
#include "minion.h"
#include "game.h"

extern Game * game;

Tower_ai::Tower_ai(){
    //set Tower_ai
    setPos(0, START_Y);
    hp = 3000;
    atk = 30;
    range = 500;
    setRect(0, 0, IMAGE_W, IMAGE_H);
    setPos(SCENE_X - IMAGE_W, START_Y);

    //set image
    image = new Minion_image();
    image->set_image(false);
    image->setPos(x(), y());

    //set attack area
    area = new Attack_area(range, atk);
    area->setPos(x() - range, y() + IMAGE_H / 2);

    //connect attack
    QTimer * attack_timer = new QTimer();
    connect(attack_timer, SIGNAL(timeout()), this, SLOT(attack()));
    attack_timer->start(500);

    //initialize show_hp
    show_hp = new Show_hp();
    show_hp->set_hp(hp);
    show_hp->setPos(x()+HP_POS_X, y()-HP_POS_Y);
}

void Tower_ai::injured(int damage){
    hp -= damage;
    show_hp->set_hp(hp);

    //if hp <=0, minion dead
    if(hp <= 0){
        delete this;
        delete show_hp;
        delete area;
        delete image;
        qDebug() << "Tower_ai destroyed";
        game->game_over("You Win!!");
    }
}

void Tower_ai::attack(){
    //if minion in attack area, attack
    area->enemy_attack();
}
