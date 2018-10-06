#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "show_mana.h"
#include "tower.h"

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Player();
    bool send_minion(int id);
    void keyPressEvent(QKeyEvent * event);
    Show_mana * show_mana;
    Tower * tower;

public slots:
    void add_mana();

private:
    const static int DECK_SIZE = 2;
};

#endif // PLAYER_H
