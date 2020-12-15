#include "moves.h"
#include "game.h"
#include <iostream>

extern game *juego;
moves::moves(QGraphicsItem *parent):QGraphicsSimpleTextItem(parent)
{
    this->setText("Aloha");
}

void moves::draw()
{
    this->setPos(50,50);
    juego->addItem(this);
}
