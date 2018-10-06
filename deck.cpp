#include "deck.h"
#include "game.h"

#include <QDebug>

extern Game * game;

Deck::Deck(){}

Deck::Deck(int get_id, int number){
    //initialize deck
    setRect(0, 0, IMAGE_W, IMAGE_H);
    id = get_id;
    num = number;

    //set image
    image = new Minion_image();
    image->set_deck(id);

    //counter++
    ++deck_counter;
}

Deck::~Deck(){
    delete image;
    --deck_counter;
}

void Deck::set_id(int get_id){
    id = get_id;
    image->set_deck(id);
}

void Deck::set_num(int number)
{
    num = number;
}

void Deck::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug() << "click" << id;
    if(game->player->send_minion(id)){
        game->deck.erase(game->deck.begin() + num);
        delete this;
        game->draw();
    }
}
