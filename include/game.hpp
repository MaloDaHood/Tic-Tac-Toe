#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <array>
#include <limits>

class Game
{
    public:
        Game(std::array<int, 2> const &scores); // Constructor
        bool checkEnd(); // Checks if the game is over or not
        void increaseTurns(); // Increases m_turns by 1 each turn
        void displayBoard(); // Displays m_board
        bool setCase(int const &place, char const &player); // Sets the value of a given case in m_board
        void displayScoreAndWinner(char const &player); // Displays the score and tells who won
        static bool keepPlaying(); // Asks user if he wants to play a new game (conserving the current score)
        std::array<int, 2> getScoreArray(); // Returns m_scores
        static void inputError(int const &min, int const &max); // Signals input errors and clears buffer
        static void clear(); // Clears the terminal checking the current OS
    private:
        // Array representing the playing board ([0]=1, [1]=2, ...)
        char m_board[9] {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        int m_turns {0}; // Number of turns played in the current game (max=9)
        std::array<int, 2> m_scores; // [0]==score for X  &&  [1]==score for O
};

#endif