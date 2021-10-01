#pragma once

#include "board.hpp"
#include <iostream>

class Player : Board
{
    public:
        void setLetter(int const &num, Player const &otherPlayer);
        char getLetter();
        int getScore();
        void increaseScore();
    private:
        char m_letter {' '};
        int m_score {0};
};