#include "../include/cpu.hpp"

void CPU::setLetter(char const &player)
{
    if(player != 'X')
        m_letter = 'X';
    else
        m_letter = 'O';
}

char CPU::getLetter()
{
    return m_letter;
}

int CPU::getScore()
{
    return m_score;
}

void CPU::increaseScore()
{
    m_score++;
}