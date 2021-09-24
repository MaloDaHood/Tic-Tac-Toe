#include "../include/game.hpp"
#include "../include/cpu.hpp"

void pvp(std::array<int, 2> &scores, std::array<char, 2> &letters);
void pvc(std::array<int, 2> &scores, std::array<char, 2> &letters);

int main()
{
    // scores[0]=X's score && scores[1]=O's score
    std::array<int, 2> scores {0, 0};
    std::array<char, 2> letters {' ', ' '};
    if(Game::init())
        pvp(scores, letters);
    else
        pvc(scores, letters);
    return 0;
}

void pvp(std::array<int, 2> &scores, std::array<char, 2> &letters)
{
    letters=Game::getLetters();
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

void pvc(std::array<int, 2> &scores, std::array<char, 2> &letters)
{
    letters=CPU::getLetters();
    do
    {
        CPU cpu(scores, letters);
        Game game(scores, letters);
        char player {letters[0]};
        while(!game.checkEnd())
        {
            /*if(cpu.isPlayer())
            {
                //Game::clear();
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
            }
            else
            {
                //Game::clear();
                game.displayBoard();
                std::cout << "cpu" << std::endl;
                game.setCase(cpu.findBestMove(), letters[1]);
                game.increaseTurns();
            }*/

            //Game::clear();
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
            
            if(game.checkEnd())
                break;

            //Game::clear();
            game.displayBoard();
            std::cout << "cpu : ";
            game.setCase(cpu.findBestMove(), letters[1]);
            game.increaseTurns();
        }
        scores=game.getScoreArray();
    }while(Game::keepPlaying());
    
}