#include "var.h"

Var::Var()
{
    gameScreenWidth = 12345;
    gameScreenHeight = 67890;
}

int Var::getGameScreenWidth()
{
    return gameScreenWidth;
}

int Var::getGameScreenHeight()
{
    return gameScreenHeight;
}
