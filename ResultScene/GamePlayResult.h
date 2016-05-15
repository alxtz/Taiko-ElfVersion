#ifndef GAMEPLAYRESULT_H
#define GAMEPLAYRESULT_H


#include <string>

using namespace std;

class GamePlayResult
{
    public:
        GamePlayResult();

        string oveName; //資料夾名稱
        int score;
        float correctPercent;
        int highestCombo;

        int greatAmount;
        int goodAmount;
        int badAmount;

        int rank;
        //SS , S , A , B , F
        //4 , 3 , 2 , 1 , 0
};

#endif // GAMEPLAYRESULT_H
