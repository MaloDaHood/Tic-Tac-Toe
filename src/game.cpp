#include "../include/game.hpp"

Game::Game(std::array<int, 2> const &scores, std::array<char, 2> const &letters) // Constructor
{
    m_scores=scores;
    m_letters=letters;
}

bool Game::checkEnd() // Returns true if the game is over or false if it's not
{
    // Checks if it is even possible for someone to have won
    if(m_turns<5)
        return false;

    // Checks if board is full
    else if(m_turns==9)
    {
        std::cout << "Nobody wins !" << std::endl;
        return true;
    }

    // Checks each line from the bottom
    for(int i {0}; i<7; i+=3)
    {
        if((m_board[i]==m_board[i+1])&&(m_board[i+1]==m_board[i+2])&&(m_board[i]!=' '))
        {
            displayScoreAndWinner(m_board[i]);
            return true;
        }
    }

    // Checks each column from the left
    for(int i {0}; i<3; i++)
    {
        if((m_board[i]==m_board[i+3])&&(m_board[i+3]==m_board[i+6])&&(m_board[i]!=' '))
        {
            displayScoreAndWinner(m_board[i]);
            return true;
        }
    }

    // Checks each diagonal
    if((m_board[0]==m_board[4])&&(m_board[4]==m_board[8])&&(m_board[0]!=' '))
    {
        displayScoreAndWinner(m_board[0]);
        return true;
    }
    else if((m_board[2]==m_board[4])&&(m_board[4]==m_board[6])&&(m_board[2]!=' '))
    {
        displayScoreAndWinner(m_board[2]);
        return true;
    }

    else
    {
        return false;
    }
}

void Game::increaseTurns() // Increases m_turns by 1
{
    m_turns++;
}

void Game::displayBoard() // Displays m_board the right way
{
    std::cout << m_board[6] << '|' << m_board[7] << '|' << m_board[8] << std::endl;
    std::cout << "-+-+-" << std::endl;
    std::cout << m_board[3] << '|' << m_board[4] << '|' << m_board[5] << std::endl;
    std::cout << "-+-+-" << std::endl;
    std::cout << m_board[0] << '|' << m_board[1] << '|' << m_board[2] << std::endl;
}

bool Game::setCase(int const &place, char const &player) // Sets the value of a given case in m_board, returns true if it worked
{
    // Checks if the wanted case isn't already allocated
    if(m_board[place]==' ')
    {
        m_board[place]=player;
        return true;
    }
    // If it is then tells the user and returns false
    else
    {
        std::cout << "This case is already taken. Choose another one." << std::endl;
        return false;
    }
}

void Game::displayScoreAndWinner(char const &player) // Displays the score and tells who won (only if someone won)
{
    clear();
    displayBoard();
    std::cout << player << " wins !" << std::endl;
    if(player==m_letters[0])m_scores[0]++;else m_scores[1]++; // Increases the score(m_scores) depending on which player won
    std::cout << m_letters[0] << " : " << m_scores[0] << " points." << std::endl;
    std::cout << m_letters[1] << " : " << m_scores[1] << " points." << std::endl;
}

bool Game::keepPlaying() // Asks user if he wants to play a new game (conserving the current score)
{                       // Returns true if user plays again, returns false otherwise 
    bool valid {false};
    int answer {0};
    do // Loop to check if user input is valid
    {
        std::cout << "Do you want to play a new game ?\n1. YES\n2. NO" << std::endl;
        std::cin >> answer;
        if(std::cin.fail()||answer<1||answer>2)
            inputError(1, 2);
        else
            valid=true;
    } while (!valid);
    return answer==1;
}

std::array<int, 2> Game::getScoreArray() // Returns m_scores 
{
    return m_scores;
}

void Game::inputError(int const &min, int const &max) // Signals input errors and clears buffer
{
    // Output is adapted depending on what's expected (function reserved to numbers)
    if(max-min==1)
        std::cout << "You have to input either " << min << " or " << max << "." << std::endl;
    else
        std::cout << "You have to input a number between " << min << " and " << max << "." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Clears the buffer
}

void Game::clear() // Clears the terminal
{
    #ifdef _WIN32 // Checks for Windows systems
        system("cls"); 
    #elif __linux__ || __unix__ // Checks for UNIX systems
        system("clear");
    #else
        std::cout << "OS not suported for \"clear()\" function." << std::endl;
    #endif
}

std::array<char, 2> Game::getLetters()
{
    std::array<char, 2> letters;
    for(int i {0}; i<2; i++)
    {
        bool valid {false};
        do
        {
            char letter;
            std::cout << "Player n°" << i+1 << " has to choose a letter : ";
            std::cin >> letter;
            if((std::isalpha(letter))&&(toupper(letter)!=letters[0])&&(toupper(letter)!=letters[1])&&(!std::cin.fail()))
            {
                letters[i]=toupper(letter);
                valid=true;
            }
            else
            {
                std::cout << "You have to input only a letter and it has to be different from the other player's." << std::endl;
                valid=false;
            }
        } while (!valid);
    }
    return letters;
}

char Game::getPlayer()
{
    if(m_turns%2==0)
        return m_letters[0];
    else
        return m_letters[1];
}

bool Game::init()
{
    clear();
    std::cout << "Welcome to this game of tic-tac-toe !" << std::endl;
    std::cout << "The board game is a grid, there are 9 positions layered just like a numpad.\nThe bottom left position is 1 and the top right one is 9." << std::endl;
    bool valid {false};
    int answer;
    do
    {
        std::cout << "Do you want to play aginst another person or the computer ?\n1. PvP\n2. PvC" << std::endl;
        std::cin >> answer;
        if(std::cin.fail()||answer<1||answer>2)
        {
            inputError(1, 2);
            valid=false;
        }
        else valid=true;
    }while(!valid);
    return answer==1;
}
