#ifndef CPU_HPP
#define CPU_HPP

#include "game.hpp"

class CPU : Game
{
    public:
        void checkBoard();
        char pickLetter();
        
    private:
};

#endif