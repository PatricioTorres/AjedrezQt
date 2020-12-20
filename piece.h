#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include "box.h"
#include <QGraphicsSceneMouseEvent>

class box;
class Piece:public QGraphicsPixmapItem
{
public:
    Piece();
    bool isPlaced;
    Piece(QString team = "",QGraphicsItem *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setCurrentBox(box *Box);
    box *getBox();
    QString getTeam();
    void setTeam(QString value);
    virtual void setImage() = 0;
    virtual void resizeImage() = 0;
    bool getIsPlaced() ;
    void setIsPlaced(bool value);
    QList <box *> moveLocation();
    virtual void moves() = 0;
    void color();
    bool firstMove;
    bool boxSetting(box *box);
    box *getCurrentBox() ;
    QString getType();

protected:
    box *currentBox;
    QString Team;
    //bool isPlaced;
    QList <box *> location;
    QString type;

};

#endif // PIECE_H
