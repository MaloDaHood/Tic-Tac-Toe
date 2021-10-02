/**
 * @file board.hpp
 * @author MaloDaHood (malomr2002@gmail.com)
 * @brief The header file for the Board class.
 */

#pragma once

#include <iostream>
#include <vector>
#include <array>

class Board
{
    public:
        Board();
        void draw();
        bool setCase(int const &spot, char const &player);
        int getTurns();
        void increaseTurns();
        std::array<std::array<char, 3>, 3> getBoard();
    private:
        std::array<std::array<char, 3>, 3> m_board;
        int m_turns {0};
};