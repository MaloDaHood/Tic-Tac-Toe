/**
 * @file player.hpp
 * @author MaloDaHood (malomr2002@gmail.com)
 * @brief The header file for the Player class.
 */

#pragma once

#include <iostream>

//class Board;
class Player
{
    public:
        void setLetter(int const &num, Player const &otherPlayer);
        char getLetter();
        int getScore();
        void increaseScore();
    protected:
        char m_letter {' '};
        int m_score {0};
};