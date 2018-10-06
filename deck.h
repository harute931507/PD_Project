#ifndef DECK_H
#define DECK_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "minion_image.h"

class Deck: public QGraphicsRectItem{
public:
    Deck();
    Deck(int get_id, int number);
    ~Deck();

    Minion_image * image;

    void set_id(int get_id);
    void set_num(int number);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

    static int deck_counter;

private:
    int id;
    int num;
    const static int IMAGE_W = 100;
    const static int IMAGE_H = 100;
};

#endif // DECK_H
