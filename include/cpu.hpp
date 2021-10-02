#pragma once

class CPU
{
    public:
        void setLetter(char const &player);
        char getLetter();
        int getScore();
        void increaseScore();
    private:
        char m_letter;
        int m_score {0};
};