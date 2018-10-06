#include "mainwindow.h"
#include <QApplication>

#include "game.h"
#include "deck.h"

Game * game;
int Deck::deck_counter = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
