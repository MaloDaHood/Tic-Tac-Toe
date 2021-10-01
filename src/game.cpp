#include "../include/game.hpp"

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

bool Game::init()
{
    clearScreen();
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

char Game::getCurrentPlayer(int const &turns, char const &player1, char const &player2)
{
    if(turns%2 == 0)
        return player1;
    else
        return player2;
}