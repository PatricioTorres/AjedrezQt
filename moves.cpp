#include "moves.h"
#include "game.h"
#include <iostream>

extern game *juego;


moves::moves(int x, int y, QString &text, QGraphicsItem *parent):QGraphicsSimpleTextItem(parent)
{
    this->setText(text);
    this->setPos(x,y);
    juego->addItem(this);
}

void moves::draw()
{
    this->setPos(1150,50);
    juego->addItem(this);
}
