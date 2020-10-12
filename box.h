#ifndef BOX_H
#define BOX_H
#include <QGraphicsRectItem>
#include <QBrush>


class box:public QGraphicsRectItem
{
public:
    box(QGraphicsItem *parent=0);
    int rowLoc;
    int colLoc;
    void setOriginalColor(QColor value);
    void setColor(QColor color);
private:
    QBrush brush;
    QColor originalColor;
};

#endif // BOX_H
