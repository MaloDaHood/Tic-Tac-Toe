#include "../include/game.hpp"

int main()
{
    // scores[0]=X's score && scores[1]=O's score
    std::array<int, 2> scores {0, 0};
    std::array<char, 2> letters {Game::init()};
    do  // Loops while the user wants to keep playing
    {
        Game game(scores, letters);
        char player {game.getPlayer()}; // Current player
        while(!game.checkEnd()) // Main game loop
        {
            Game::clear();
            game.displayBoard();
            bool valid {false}; 
            int place;
            do // Loop to check if user input is valid
            {
                std::cout << player << " > ";
                std::cin >> place;
                if(std::cin.fail()||place<1||place>9)
                    Game::inputError(1, 9);
                else
                    valid=true; 
            }while(!valid||!game.setCase(place-1, player));
            game.increaseTurns();
            player=game.getPlayer();
        }
        scores=game.getScoreArray(); // Saves m_scores before it's reset 
    } while(Game::keepPlaying());
}