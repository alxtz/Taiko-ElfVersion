#include <iostream>
#include <QTimer>
#include "TestQTimer.h"
#include "TestTimer.h"

extern TestTimer timer;

using namespace std;

TestQTimer::TestQTimer()
{
    cout<<"testQTimer ctor"<<endl;
}

void TestQTimer::start()
{
    cout<<"Qtimer要跑10秒"<<endl;
    timer.start();
    QTimer::singleShot(100 , this , SLOT(qTimerStop()));
}

void TestQTimer::qTimerStop()
{
    cout<<"Qtimer結束"<<endl;
    timer.fromLastTime();
}
