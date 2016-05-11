#include <iostream>
#include "TestTimer.h"

using namespace std;

TestTimer::TestTimer()
{

}

void TestTimer::start()
{
    startTime = clock();
}

void TestTimer::checkTime()
{
    cout<<"經過了"<<(clock() - startTime)/(double)(CLOCKS_PER_SEC) << "秒"<<endl;
}
