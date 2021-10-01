#include "../include/player.hpp"

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
        if(num == 2 && letter == otherPlayer.m_letter)
        {
            std::cout << "It can't be the same as the other player's." << std::endl;
            valid = false;
        }
    } while (!valid);
    m_letter = letter;
}

char Player::getLetter()
{
    return m_letter;
}

int Player::getScore()
{
    return m_score;
}

void Player::increaseScore()
{
    m_score++;
}