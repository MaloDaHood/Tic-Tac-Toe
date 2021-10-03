/**
 * @file cpu.hpp
 * @author MaloDaHood (malomr2002@gmail.com)
 * @brief The header file for the CPU class.
 */

#pragma once

#include <array>
#include <iostream>
#include <vector>

class CPU
{
    public:
        void setLetter(char const &player);
        char getLetter();
        int getScore();
        void increaseScore();
        int randomMove(std::array<std::array<char, 3>, 3> board);

        int findBestMove(std::array<std::array<char, 3>, 3> board, char const &player);
        int minimax(std::array<std::array<char, 3>, 3> board, int depth, bool isMaximizingPlayer, char const &player);
        bool isMovesLeft(std::array<std::array<char, 3>, 3> board);
        int evaluate(std::array<std::array<char, 3>, 3> board, char const &player);
    private:
        char m_letter;
        int m_score {0};
};