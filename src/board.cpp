#include "../include/board.hpp"

Board::Board()
{
    for(int i {0}; i<3; i++)
    {
        for(int j {0}; j<3; j++)
        {
            m_board[i][j]=' ';
        }
    }
}

void Board::draw()
{
    std::cout << m_board[2][0] << '|' << m_board[2][1] << '|' << m_board[2][2] << std::endl;
    std::cout << "-+-+-" << std::endl;
    std::cout << m_board[1][0] << '|' << m_board[1][1] << '|' << m_board[1][2] << std::endl;
    std::cout << "-+-+-" << std::endl;
    std::cout << m_board[0][0] << '|' << m_board[0][1] << '|' << m_board[0][2] << std::endl;
}

bool Board::setCase(int const &spot, char const &player)
{
    if(spot == -1)
    {
        return false;
    }
    else if(spot < 4)
    {
        if(m_board[0][spot-1] == ' ')
        {
            m_board[0][spot-1] = player;
            return true;
        }
        else
        {
            std::cout << "You must choose a free spot." << std::endl;
            return false;
        }
    }
    else if(spot < 7)
    {
        if(m_board[1][spot-4] == ' ')
        {
            m_board[1][spot-4] = player;
            return true;
        }
        else
        {
            std::cout << "You must choose a free spot." << std::endl;
            return false;
        }
    }
    else
    {
        if(m_board[2][spot-7] == ' ')
        {
            m_board[2][spot-7] = player;
            return true;
        }
        else
        {
            std::cout << "You must choose a free spot." << std::endl;
            return false;
        }
    }
}

int Board::getTurns()
{
    return m_turns;
}

void Board::increaseTurns()
{
    m_turns++;
}

std::array<std::array<char, 3>, 3> Board::getBoard()
{
    return m_board;
}