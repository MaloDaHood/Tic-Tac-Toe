#include "../include/cpu.hpp"

CPU::CPU(std::array<int, 2> const &scores, std::array<char, 2> const &letters)
    :Game(scores, letters){}

int CPU::findBestMove()
{
    char board[9];
    for(int i {0}; i<9; i++)
    {
        board[i]=m_board[i];
    }

    int bestVal {-1000};
    int move {-1};

    for(int i {0}; i<9; i++)
    {
        if(board[i]==' ')
        {
            board[i]=m_letters[1];

            int moveVal {minimax(board, 0, false)};


            board[i]=' ';

            if(moveVal>bestVal)
            {
                move=i;
                bestVal=moveVal;
            }
            std::cout << move << std::endl;
        }
    }
    //std::cout << move << std::endl;
    return move;
}

int CPU::minimax(char board[9], int depth, bool isMax)
{
    int score {evaluate(board)};

    if(score==10)
        return score;
    if(score==-10)
        return score;

    if(!isMovesLeft())
        return 0;

    if(isMax)
    {
        int bestScore {-1000};

        for(int i {0}; i<9; i++)
        {
            if(board[i]==' ')
            {
                board[i]=m_letters[1];

                int score {minimax(board, depth+1, false)};

                board[i]=' ';

                bestScore=std::max(score, bestScore);
            }
        }
        //std::cout << best << std::endl;
        return bestScore;
    }
    else
    {
        int bestScore {1000};

        for(int i {0}; i<9; i++)
        {
            if(board[i]==' ')
            {
                board[i]=m_letters[0];

                int score {minimax(board, depth+1, true)};

                board[i]=' ';

                bestScore=std::min(score, bestScore);
            }
        }
        return bestScore;
    }
}

int CPU::evaluate(char board[9])
{
    char player {m_letters[0]};
    char cpu {m_letters[1]};

    // Checks each line from the bottom
    for(int i {0}; i<7; i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]!=' '))
        {
            if(board[i]==cpu)
                return 10;
            else if(board[i]==player)
                return -10;
        }
    }

    // Checks each column from the left
    for(int i {0}; i<3; i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]!=' '))
        {
            if(board[i]==cpu)
                return 10;
            else if(board[i]==player)
                return -10;
        }
    }

    // Checks each diagonal
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]!=' '))
    {
        if(board[0]==cpu)
            return 10;
        else if(board[0]==player)
            return -10;
    }
    else if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]!=' '))
    {
        if(board[2]==cpu)
            return 10;
        else if(board[2]==player)
            return -10;
    }

    return 0;
}

bool CPU::isMovesLeft()
{
    for(char const &place : m_board)
    {
        if(place==' ')
            return true;
    }
    return false;
}

std::array<char, 2> CPU::getLetters()
{
    std::array<char, 2> letters;
    bool valid {false};
    do
    {
        char letter;
        std::cout << "You have to choose a letter : ";
        std::cin >> letter;
        if((std::isalpha(letter))&&(!std::cin.fail()))
        {
            letters[0]=toupper(letter);
            valid=true;
        }
        else
        {
            std::cout << "You have to input only a letter." << std::endl;
            valid=false;
        }
    } while (!valid);
    if(letters[0]!='X')
        letters[1]='X';
    else
        letters[1]='O';
    return letters;
}

bool CPU::isPlayer()
{
    if(m_turns%2==0)
        return true;
    else
        return false;
}