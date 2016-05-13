#ifndef TESTTIMER_H
#define TESTTIMER_H


#include <ctime>

using namespace std;

class TestTimer
{
    public:
        TestTimer();

        void start();
        void checkTime();
        void fromLastTime();

    private:
        clock_t startTime;
        clock_t saveTime;
};
#endif // TESTTIMER_H
