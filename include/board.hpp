#pragma once

#include <iostream>
#include "player.hpp"
#include "cpu.hpp"

class Board
{
    public:
        void init();
        void draw();
        void setCase(int const &spot);
        int getTurns();
        void increaseTurns();
        bool isGameOver();
    protected:
        char m_board[3][3];
        int m_turns {0};
};