#include "moves.h"
#include "game.h"
#include <iostream>

extern game *juego;


moves::moves(int x, int y, QString &text, QGraphicsItem *parent):QGraphicsSimpleTextItem(parent)
{
    this->setText(text);
    this->setPos(x,y);
    this->rowLoc = y;
    this->colLoc = x;
    this->text = text;
    juego->addItem(this);
}

moves::moves(int x, int y, QString &text, QColor color, QGraphicsItem *parent):QGraphicsSimpleTextItem(parent)
{
    this->setText(text);
    this->text = text;
    this->setPos(x,y);
    juego->addItem(this);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    this->setBrush(brush);
}

void moves::draw()
{
    this->setPos(1150,50);
    juego->addItem(this);
}

/*moves& moves::operator = (const moves &m)
{
    if(this!=&m)
    {
        this->rowLoc = m.rowLoc;
        this->colLoc = m.colLoc;
        this->setText(m.text());
    }
    return *this;
}*/

void moves::rePos(int x, int y)
{
    this->setPos(x,y);
}
