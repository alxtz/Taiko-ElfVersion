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

    private:
        clock_t startTime;
};
#endif // TESTTIMER_H
