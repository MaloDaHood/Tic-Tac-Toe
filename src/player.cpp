#include "../include/player.hpp"

/**
 * @brief Asks the player for the letter he wants to use
 * 
 * @param num Whether it is the first or the second player
 * @param otherPlayer Object representing the opponent player to the one choosing a letter
 */
void Player::setLetter(int const &num, Player const &otherPlayer)
{
    char letter;
    bool valid {true};
    do
    {
        valid = true;
        std::cout << "Player n°" << num << " chooses a letter.\n> ";
        std::cin >> letter;
        if(std::cin.fail() || !isalpha(letter))
        {
            std::cout << "You have to input only one letter." << std::endl;
            valid = false;
        }
        if(num == 2 && std::toupper(letter) == otherPlayer.m_letter)
        {
            std::cout << "It can't be the same as the other player's." << std::endl;
            valid = false;
        }
    } while (!valid);
    m_letter = std::toupper(letter);
}

/**
 * @brief Returns the player's letter
 * 
 * @return char 
 */
char Player::getLetter()
{
    return m_letter;
}

/**
 * @brief Returns the player's score
 * 
 * @return int 
 */
int Player::getScore()
{
    return m_score;
}

/**
 * @brief Increases the player's score by one
 * 
 */
void Player::increaseScore()
{
    m_score++;
}