#include "../include/game.hpp"

/**
 * @brief Clears the teminal using OS specific commands 
 * 
 */
void Game::clearScreen()
{
    #ifdef _WIN32 // Checks for Windows systems
        system("cls"); 
    #elif __linux__ || __unix__ // Checks for UNIX systems
        system("clear");
    #else
        std::cout << "OS not suported for \"clearScreen()\" function." << std::endl;
    #endif
}

/**
 * @brief Warns user about input error when asking for integers and clears the buffer
 * 
 * @param min The minimum integer asked
 * @param max The maximum integer asked
 */
void Game::inputErrorInt(int const &min, int const &max)
{
    // Output is adapted depending on what's expected (function reserved to numbers)
    if(max-min==1)
        std::cout << "You have to input either " << min << " or " << max << "." << std::endl;
    else
        std::cout << "You have to input a number between " << min << " and " << max << "." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Clears the buffer
}

/**
 * @brief Asks the player if he wants to play again
 * 
 * @return true if the player wants to play again
 * @return false if the player doesn't want to play again
 */
bool Game::keepPlaying()
{
    bool valid {false};
    int answer {0};
    do // Loop to check if user input is valid
    {
        std::cout << "Do you want to play a new game ?\n1. YES\n2. NO" << std::endl;
        std::cin >> answer;
        if(std::cin.fail()||answer<1||answer>2)
            inputErrorInt(1, 2);
        else
            valid=true;
    } while (!valid);
    return answer==1;
}

/**
 * @brief Starts the game and asks for game mode
 * 
 * @return true if game mode is PvP
 * @return false if game mode is PvC
 */
bool Game::init()
{
    //clearScreen();
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
            inputErrorInt(1, 2);
            valid=false;
        }
        else valid=true;
    }while(!valid);
    return answer==1;
}

/**
 * @brief Returns the letter of the player currently playing
 * 
 * @param turns The number of turns played yet
 * @param player1 Letter of the first player
 * @param player2 Letter of the second player
 * @return char 
 */
char Game::getCurrentPlayer(int const &turns, char const &player1, char const &player2)
{
    if(turns%2 == 0)
        return player1;
    else
        return player2;
}

/**
 * @brief Checks if the game is over.
 * 
 * @param board The game board
 * @param turns The number of turns played yet
 * @param winner The letter of the winning player, modified by reference
 * @return true if the game is over
 * @return false if the game is not over
 */
bool Game::isOver(std::array<std::array<char, 3>, 3> const &board, int const &turns, char &winner)
{
    if(turns < 5)
        return false;

    else if(turns == 9)
    {
        std::cout << "It's a tie !" << std::endl;
        return true;
    }

    for(int i {0}; i < 3; i++)
    {
        for(int j {0}; j < 3; j++)
        {
            if((board[i][j] == board[i][j+1])&&(board[i][j+1] == board[i][j+2])&&(board[i][j] != ' '))
            {
                winner = board[i][j];
                return true;
            }
        }
    }

    for(int i {0}; i < 3; i++)
    {
        for(int j {0}; j < 3; j++)
        {
            if((board[i][j] == board[i+1][j])&&(board[i+1][j] == board[i+2][j])&&(board[i][j] != ' '))
            {
                winner = board[i][j];
                return true;
            }
        }
    }

    if((board[0][0] == board[1][1])&&(board[1][1] == board[2][2])&&(board[0][0] != ' '))
    {
        winner = board[0][0];
        return true;
    }
    else if((board[0][2] == board[1][1])&&(board[1][1] == board[2][0])&&(board[2][0] != ' '))
    {
        winner = board[0][2];
        return true;
    }

    return false;
}

/**
 * @brief Displays the score and the letter of the winner
 * 
 * @param winner The letter of the winning player
 * @param player1 Object representing the first player
 * @param player2 Object representing the second player
 */
void Game::displayWinnerAndScore(char const &winner, Player &player1, Player &player2)
{
    if(std::isspace(winner))
        std::cout << "Nobody wins." << std::endl;
    else
    {
        std::cout << winner << " wins !" << std::endl;
        if(winner == player1.getLetter())
            player1.increaseScore();
        else
            player2.increaseScore();
    }
    std::cout << player1.getLetter() << " : " << player1.getScore() << " points" << std::endl;
    std::cout << player2.getLetter() << " : " << player2.getScore() << " points" << std::endl;
}

/**
 * @brief Displays the score and the letter of the winner
 * 
 * @param winner The letter of the winning player
 * @param player Object representing the player
 * @param cpu Object representing the computer
 */
void Game::displayWinnerAndScore(char const &winner, Player &player, CPU &cpu)
{
    if(std::isspace(winner))
        std::cout << "Nobody wins." << std::endl;
    else
    {
        std::cout << winner << " wins !" << std::endl;
        if(winner == player.getLetter())
            player.increaseScore();
        else
            cpu.increaseScore();
    }
    std::cout << player.getLetter() << " : " << player.getScore() << " points" << std::endl;
    std::cout << cpu.getLetter() << " : " << cpu.getScore() << " points" << std::endl;
}