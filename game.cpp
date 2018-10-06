#include "game.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#include "player.h"
#include "deck.h"

Game::Game(){
    //initialize timestamp for random
    srandom(time(NULL));

    //initialize pool
    int initial_pool[POOL_SIZE] = {1,2,3,4};
    for(int i=0; i<POOL_SIZE; i++)
        pool.push_back(initial_pool[i]);

    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1600, 600);

    //add player
    player = new Player();
    scene->addItem(player);
    scene->addItem(player->show_mana);
    //show player's tower
    scene->addItem(player->tower);
    scene->addItem(player->tower->image);
    scene->addItem(player->tower->area);
    scene->addItem(player->tower->show_hp);
    //focus on player
    player->setFocus();

    //create deck
    for(int i=0; i<DECK_SIZE; ++i){
        Deck * new_deck = new Deck(pool.at(i), i);
        deck.push_back(new_deck);

        scene->addItem(deck.at(i));
        scene->addItem(deck.at(i)->image);
    }
    //align
    align();

    //add AI
    ai = new Ai();
    scene->addItem(ai);
    scene->addItem(ai->show_mana);
    //show AI's tower
    scene->addItem(ai->tower_ai);
    scene->addItem(ai->tower_ai->image);
    scene->addItem(ai->tower_ai->area);
    scene->addItem(ai->tower_ai->show_hp);

    //set game view
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1600, 600);
}

void Game::game_over(QString text){
    qDebug() << text;

    //disable all items
    for(int i=0; i<scene->items().size(); ++i){
        scene->items()[i]->setEnabled(false);
    }

    delete player;
    delete ai;

    //pop up semi transparent panel
    draw_panel(0, 0, 1600, 600, Qt::black, 0.85);

    //pop up words "Game Over" and announce winner
    QGraphicsTextItem * winner = new QGraphicsTextItem(text);
    winner->setDefaultTextColor(Qt::white);
    winner->setFont(QFont("Times", 72));
    winner->setPos(600, 200);
    scene->addItem(winner);
}

void Game::draw(){
    //draw randomly
    int r = rand()%POOL_SIZE;
    cout << r << endl;
    qDebug() << "draw " <<  pool.at(r);
    Deck * new_deck = new Deck(pool.at(r), DECK_SIZE-1);
    deck.push_back(new_deck);
    scene->addItem(deck.at(DECK_SIZE-1));
    scene->addItem(deck.at(DECK_SIZE-1)->image);

    //align left
    align();
}

void Game::align()
{
    //align left
    for(int i=0; i<deck.size(); ++i){
        Deck * buffer = deck.at(i);
        buffer->set_num(i);
        buffer->setPos(i*IMAGE_W, 400);
        buffer->image->setPos(i*IMAGE_W, 400);
        deck.at(i) = buffer;
    }
}

void Game::draw_panel(int x, int y, int w, int h, QColor color, double opcacity){
    QGraphicsRectItem * panel = new QGraphicsRectItem(x, y, w, h);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opcacity);
    scene->addItem(panel);
}


