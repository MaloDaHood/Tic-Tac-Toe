/**
 * @file game.hpp
 * @author MaloDaHood (malomr2002@gmail.com)
 * @brief The header file for the Game class.
 */

#pragma once

#include <iostream>
#include <limits>
#include <array>
#include "player.hpp"
#include "cpu.hpp"

class Game
{
    public:
        static bool keepPlaying();
        static void inputErrorInt(int const &min, int const &max);
        static void clearScreen();
        static bool init();
        static char getCurrentPlayer(int const &turns, char const &player1, char const &player2);
        static bool isOver(std::array<std::array<char, 3>, 3> const &board, int const &turns, char &winner);
        static void displayWinnerAndScore(char const &winner, Player &player1, Player &player2);
        static void displayWinnerAndScore(char const &winner, Player &player, CPU &cpu);
};