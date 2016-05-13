#ifndef GAMEPLAYRESULT_H
#define GAMEPLAYRESULT_H


#include <string>

using namespace std;

class GamePlayResult
{
    public:
        GamePlayResult();

        string oveName;
        int score;
        float correctPercent;
        int combo;

        int greatAmount;
        int goodAmount;
        int badAmount;
};

#endif // GAMEPLAYRESULT_H
