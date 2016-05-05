#include "TestExtern.h"
#include "GameView.h"

extern GameView * gameView1;

TestExtern::TestExtern()
{
    gameView1->setSongMenu();
}
