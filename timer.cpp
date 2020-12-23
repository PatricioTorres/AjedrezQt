#include "timer.h"
#include "game.h"
#include <QDebug>
#include <QTimer>

extern game *juego;

timer::timer(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()),this,SLOT(onTimeOut()));
}

void timer::iniciar()
{
    m_timer->start(1000);
}

void timer::onTimeOut()
{
    QString out{""};
    if(juego->getTurn() == "BLACK")
    {

        int &time = juego->getTimeBlack();
        out += "Black time: ";
        out += refactor(time/60);
        out += ":";
        out += refactor(time%60);

        if(time == 0)
            juego->addItem(new QGraphicsPixmapItem((QPixmap(":/TimeB.png"))));
        else
        {
            time--;
            juego->timeLabelBlack->reText(out);
        }

    }
    else
    {
        int &time = juego->getTimeWhite();
        out += "White time: ";
        out += refactor(time/60);
        out += ":";
        out += refactor(time%60);

        if(time==0)
            juego->addItem(new QGraphicsPixmapItem((QPixmap(":/TimeW,png"))));
        else
        {
            time--;
            juego->timeLabelWhite->reText(out);
        }

    }
}

QString timer::refactor(int t)
{
    if(t<10)
        return "0"+QString::number(t);
    else
        return QString::number(t);
}
