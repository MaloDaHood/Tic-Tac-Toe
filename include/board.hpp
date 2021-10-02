#pragma once

#include <iostream>
#include <vector>
#include <array>

class Board
{
    public:
        void init();
        void draw();
        bool setCase(int const &spot, char const &player);
        int getTurns();
        void increaseTurns();
        std::array<std::array<char, 3>, 3> getBoard();
    protected:
        std::array<std::array<char, 3>, 3> m_board;
        int m_turns {0};
};