#include "player.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <iostream>
using namespace std;

#include "tower.h"
#include "minion.h"
#include "show_mana.h"

Player::Player(){
    //initialize player
    setFlag(QGraphicsItem::ItemIsFocusable);

    //connect mana
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(add_mana()));
    timer->start(1000);     //add mana per second

    //initialize show_mana
    show_mana = new Show_mana();

    //initialize tower
    tower = new Tower();
}

bool Player::send_minion(int id){
    //if wrong key pressed: do nothing
    if(id == 0) return false;

    //generate minion according to id
    Minion * minion = new Minion(id);

    //if mana is not enough: do nothing
    if(show_mana->get_mana() < minion->get_cost()){
        qDebug() << "Mana shortage.";
        delete minion;
        return false;
    }

    //else: send minion
    cout << "Send minion " << id << endl;
    scene()->addItem(minion);
    scene()->addItem(minion->show_hp);
    scene()->addItem(minion->image);
    scene()->addItem(minion->area);

    //mana decrease
    show_mana->decrease(minion->get_cost());
    return true;
}

void Player::keyPressEvent(QKeyEvent *event){
    int id = 0;

    switch(event->key()){
        case Qt::Key_1: id = 1; break;
        case Qt::Key_2: id = 2; break;
        case Qt::Key_3: id = 3; break;
        case Qt::Key_4: id = 4; break;
    }

    //if wrong key pressed: do nothing
    if(id == 0) return;

    //generate minion according to id
    Minion * minion = new Minion(id);

    //if mana is not enough: do nothing
    if(show_mana->get_mana() < minion->get_cost()){
        qDebug() << "Mana shortage.";
        delete minion;
        return;
    }

    //else: send minion
    cout << "Send minion " << id << endl;
    scene()->addItem(minion);
    scene()->addItem(minion->show_hp);
    scene()->addItem(minion->image);
    scene()->addItem(minion->area);

    //mana decrease
    show_mana->decrease(minion->get_cost());
}

void Player::add_mana(){
    //add mana per seconds
    show_mana->increase();
}
