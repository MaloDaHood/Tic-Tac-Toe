#pragma once

#include <iostream>
#include <limits>

class Game
{
    public:
        static bool keepPlaying();
        static void inputErrorInt(int const &min, int const &max);
        static void clearScreen();
        static bool init();
        static char getCurrentPlayer(int const &turns, char const &player1, char const &player2);
};