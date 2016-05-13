#include <iostream>
#include "TestTimer.h"

using namespace std;

TestTimer::TestTimer()
{
    //clock();
    //cout<<"每個clock的長度是"<<(double)(CLOCKS_PER_SEC)<<endl;
}

void TestTimer::start()
{
    startTime = clock();
    saveTime = startTime;
    cout<<"clock開始於0"<<endl;
}

void TestTimer::checkTime()
{
    saveTime = clock();

    cout<<"從0經過了"<<(double)(clock() - saveTime)*10/(double)(CLOCKS_PER_SEC) << "秒"<<endl;
}

void TestTimer::fromLastTime()
{
    clock_t getTime = clock();
    cout<<"從上次經過了"<<(double)(getTime - saveTime)*10/(double)(CLOCKS_PER_SEC) << "秒"<<endl;

    saveTime = getTime;
}
