#ifndef TIMER_H
#define TIMER_H

#include <QObject>

class QTimer;

class timer : public QObject
{
    Q_OBJECT
public:
    explicit timer(QObject *parent = 0);

    void iniciar();

public slots:
    void onTimeOut();

private:
    QTimer *m_timer;

    QString refactor(int t);

};

#endif // TIMER_H
