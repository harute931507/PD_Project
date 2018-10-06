#include "show_hp.h"
#include <QFont>

Show_hp::Show_hp(QGraphicsItem *parent){
    setDefaultTextColor(Qt::red);
    setFont(QFont("Times", 12));
}

void Show_hp::set_hp(int hp){
    setPlainText(QString::number(hp));
} 
