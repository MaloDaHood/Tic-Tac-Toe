#include "../include/board.hpp"

void Board::init()
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
    if(spot < 4)
    {
        if(m_board[0][spot-1] != ' ')
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
        if(m_board[1][spot-4] != ' ')
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
        if(m_board[2][spot-7] != ' ')
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

bool Board::isGameOver()
{
    if(m_turns < 5)
        return false;

    else if(m_turns == 9)
    {
        std::cout << "It's a tie !" << std::endl;
        return true;
    }

    for(int i {0}; i < 3; i++)
    {
        for(int j {0}; j < 3; j++)
        {
            if((m_board[i][j] == m_board[i][j+1])&&(m_board[i][j+1] == m_board[i][j+2])&&(m_board[i][j] != ' '))
            {
                return true;
            }
        }
    }

    for(int i {0}; i < 3; i++)
    {
        for(int j {0}; j < 3; j++)
        {
            if((m_board[i][j] == m_board[i+1][j])&&(m_board[i+1][j] == m_board[i+2][j])&&(m_board[i][j] != ' '))
            {
                return true;
            }
        }
    }

    if((m_board[0][0] == m_board[1][1])&&(m_board[1][1] == m_board[2][2])&&(m_board[0][0] != ' '))
    {
        return true;
    }
    else if((m_board[0][2] == m_board[1][1])&&(m_board[1][1] == m_board[2][2])&&(m_board[2][0] != ' '))
    {
        return true;
    }

    return false;
}