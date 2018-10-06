#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
using namespace std;

#include "player.h"
#include "ai.h"
#include "deck.h"

class Game: public QGraphicsView{
public:
    const static int DECK_SIZE = 3;

    Game();
    void game_over(QString text);
    void draw();
    vector <int> pool;
    vector <Deck *> deck;
    QGraphicsScene * scene;
    Player * player;
    Ai * ai;

private:
    const static int POOL_SIZE = 4;
    const static int IMAGE_W = 100;

    void align();
    void draw_panel(int x, int y, int w, int h, QColor color, double opcacity);
};

#endif // GAME_H
