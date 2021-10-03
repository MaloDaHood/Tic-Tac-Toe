/**
 * @file cpu.cpp
 * @author MaloDaHood (malomr2002@gmail.com)
 * @brief The source file for the CPU class.
 */

#include "../include/cpu.hpp"

/**
 * @brief Sets the letter the computer will use
 * 
 * @param player Letter chosen by the player
 */
void CPU::setLetter(char const &player)
{
    if(player != 'X')
        m_letter = 'X';
    else
        m_letter = 'O';
}

/**
 * @brief Returns the computer's letter
 * 
 * @return char 
 */
char CPU::getLetter()
{
    return m_letter;
}

/**
 * @brief Returns the computer's score
 * 
 * @return int 
 */
int CPU::getScore()
{
    return m_score;
}

/**
 * @brief Increases the computer's score by one
 * 
 */
void CPU::increaseScore()
{
    m_score++;
}

int CPU::randomMove(std::array<std::array<char, 3>, 3> board)
{
    std::vector<int> freeSpots;
    for(int i {0}; i<3; i++)
    {
        for(int j {0}; j<3; j++)
        {
            if(board[i][j] == ' ')
            {
                if(i == 0)
                    freeSpots.push_back(j++);
                else if(i == 1)
                    freeSpots.push_back(i+j+3);
                else
                    freeSpots.push_back(i+j+5);
            }
        }
    }
    int randomIndex {rand()%freeSpots.size()};
    return freeSpots[randomIndex];
}

int CPU::findBestMove(std::array<std::array<char, 3>, 3> board, char const &player)
{
    int bestVal {-1000};
    int bestMove {-1};

    for(int i {0}; i<3; i++)
    {
        for(int j {0}; j<3; j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = m_letter;

                int moveVal {minimax(board, 0, false, player)};

                board[i][j] = ' ';

                if(moveVal > bestVal)
                {
                    if(i == 0)
                        bestMove = j++;
                    else if(i == 1)
                        bestMove = i+j+3;
                    else
                        bestMove = i+j+5;
                    bestVal = moveVal;
                }
            }
        }
    }
    std::cout << "CPU : " << bestMove << std::endl;
    return bestMove;
}

int CPU::minimax(std::array<std::array<char, 3>, 3> board, int depth, bool isMaximizingPlayer, char const &player)
{
    int score {evaluate(board, player)};

    if(score == 10)
        return score;
    
    if(score == -10)
        return score;

    if(!isMovesLeft(board))
        return 0;

    if(isMaximizingPlayer)
    {
        int best {-1000};

        for(int i {0}; i<3; i++)
        {
            for(int j {0}; j<3; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = m_letter;

                    best = std::max(best, minimax(board, depth+1, !isMaximizingPlayer, player));

                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
    else
    {
        int best {1000};

        for(int i {0}; i<3; i++)
        {
            for(int j {0}; j<3; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = player;

                    best = std::min(best, minimax(board, depth+1, !isMaximizingPlayer, player));

                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

bool CPU::isMovesLeft(std::array<std::array<char, 3>, 3> board)
{
    for(int i {0}; i<3; i++)
    {
        for(int j {0}; j<3; j++)
        {
            if(board[i][j] == ' ')
                return true;
        }
    }
    return false;
}

int CPU::evaluate(std::array<std::array<char, 3>, 3> board, char const &player)
{
    for(int i {0}; i<3; i++)
    {
        if((board[i][0] == board[i][1])&&(board[i][1] == board[i][2]))
        {
            if(board[i][0] == m_letter)
                return +10;
            else if(board[i][0] == player)
                return -10;
        }
    }

    for(int i {0}; i<3; i++)
    {
        if((board[0][i] == board[1][i])&&(board[1][i] == board[2][i]))
        {
            if(board[0][i] == m_letter)
                return +10;
            else if(board[0][i] == player)
                return -10;
        }
    }

    if((board[0][0] == board[1][1])&&(board[1][1] == board[2][2]))
    {
        if(board[0][0] == m_letter)
            return +10;
        else if(board[0][0] == player)
            return -10;
    }

    if((board[0][2] == board[1][1])&&(board[1][1] == board[2][0]))
    {
        if(board[0][2] == m_letter)
            return +10;
        else if(board[0][2] == player)
            return -10;
    }

    return 0;
}