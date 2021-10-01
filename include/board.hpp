#pragma once

#include <iostream>

class Board
{
    public:
        void init();
        void draw();
        bool setCase(int const &spot, char const &player);
        int getTurns();
        void increaseTurns();
        bool isGameOver();
    protected:
        char m_board[3][3];
        int m_turns {0};
};