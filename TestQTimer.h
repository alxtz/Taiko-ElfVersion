#ifndef TESTQTIMER_H
#define TESTQTIMER_H


#include <QObject>

class TestQTimer : public QObject
{
    Q_OBJECT
    public:
        TestQTimer();

        void start();

    public slots:
        void qTimerStop();
};

#endif // TESTQTIMER_H
