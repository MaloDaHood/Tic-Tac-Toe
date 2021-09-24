#ifndef CPU_HPP
#define CPU_HPP

#include "game.hpp"
#include <bits/stdc++.h>

class CPU : Game
{
    public:
        CPU(std::array<int, 2> const &scores, std::array<char, 2> const &letters);

        int findBestMove();
        int minimax(char board[9], int depth, bool isMax);
        int evaluate(char board[9]);
        bool isMovesLeft();
        bool isPlayer();
        
        static std::array<char, 2> getLetters();
};

#endif