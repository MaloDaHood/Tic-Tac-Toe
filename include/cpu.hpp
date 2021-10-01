#pragma once

#include "board.hpp"

class CPU : Board
{
    public:
        void setLetter(char const &player);
        char getLetter();
        int getScore();
        void increaseScore();
    private:
        char m_letter;
        int m_score {0};
};