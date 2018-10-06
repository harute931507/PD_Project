#include "ai.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "enemy.h"
#include "show_mana.h"
#include "tower_ai.h"

Ai::Ai(){
    //initialize AI
    setFlag(QGraphicsItem::ItemIsFocusable);

    //connect mana
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(add_mana()));
    timer->start(1000);     //add mana per second

    //connect aquire
    QTimer * attack_timer = new QTimer();
    connect(attack_timer, SIGNAL(timeout()), this,SLOT(aquire()));
    attack_timer->start(5000);

    //initialize show_mana
    show_mana = new Show_mana();
    show_mana->setPos(1500, 0);

    //initialize tower
    tower_ai = new Tower_ai();
    tower_ai->setPos(1500, 200);
}

void Ai::aquire(){
    int id = 0;
    //id = rand() % 4 + 1;

    if(id == 0) return;

    //generate enemy according to id
    Enemy * enemy = new Enemy(id);

    //if mana is not enough: do nothing
    if(show_mana->get_mana() < enemy->get_cost()){
        delete enemy;
        return;
    }

    //else: send enemy
    cout << "Send enemy " << id << endl;
    scene()->addItem(enemy);
    scene()->addItem(enemy->image);
    scene()->addItem(enemy->show_hp);
    scene()->addItem(enemy->area);
    //scene()->addItem(enemy->image);

    //mana decrease
    show_mana->decrease(enemy->get_cost());
}

void Ai::add_mana(){
    //add mana per seconds
    show_mana->increase();
}
