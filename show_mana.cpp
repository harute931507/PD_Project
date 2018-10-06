#include "show_mana.h"
#include <QFont>

Show_mana::Show_mana(QGraphicsItem *parent){
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Times", 16));
    mana = 0;
    setPlainText(QString("mana: ") + QString::number(mana));
}

void Show_mana::increase(){
    //add mana until mana is full(= 10)
    if(mana >= 10) return;
    ++mana;
    setPlainText(QString("mana: ") + QString::number(mana));
}

void Show_mana::decrease(int x){
    //if sending minion success, decrease mana
    mana -= x;
    setPlainText(QString("mana: ") + QString::number(mana));
}

int Show_mana::get_mana(){
    return mana;
}
