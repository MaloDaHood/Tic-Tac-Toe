#include "../include/board.hpp"

/**
 * @brief Construct a new Board:: Board object and fills m_board with spaces
 * 
 */
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

/**
 * @brief Draws the game board
 * 
 */
void Board::draw()
{
    std::cout << m_board[2][0] << '|' << m_board[2][1] << '|' << m_board[2][2] << std::endl;
    std::cout << "-+-+-" << std::endl;
    std::cout << m_board[1][0] << '|' << m_board[1][1] << '|' << m_board[1][2] << std::endl;
    std::cout << "-+-+-" << std::endl;
    std::cout << m_board[0][0] << '|' << m_board[0][1] << '|' << m_board[0][2] << std::endl;
}

/**
 * @brief Puts the letter of the player on the chosen spot if possible
 * 
 * @param spot The spot chosen by the player
 * @param player The letter of the current player
 * @return true if it was able to set the chosen spot
 * @return false if it was not able to set the chosen spot
 */
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

/**
 * @brief Returns the number of turns played yet
 * 
 * @return int 
 */
int Board::getTurns()
{
    return m_turns;
}

/**
 * @brief Increases the number of turns by one
 * 
 */
void Board::increaseTurns()
{
    m_turns++;
}

/**
 * @brief Returns the game board
 * 
 * @return std::array<std::array<char, 3>, 3> 
 */
std::array<std::array<char, 3>, 3> Board::getBoard()
{
    return m_board;
}