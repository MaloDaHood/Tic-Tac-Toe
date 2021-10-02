#include "../include/game.hpp"
#include "../include/board.hpp"
#include "../include/player.hpp"
#include "../include/cpu.hpp"

void playerVSplayer();
void playerVScpu();

/**
 * @brief Starts the game
 * 
 * @return int 
 */
int main()
{
    //Game::clearScreen();
    if(Game::init())
        playerVSplayer();
    else
        playerVScpu();
    return EXIT_SUCCESS;
}

/**
 * @brief Makes two players play against each other
 * 
 */
void playerVSplayer()
{
    Player player1, player2;
    player1.setLetter(1, player2);
    player2.setLetter(2, player1);
    do
    {
        Board board;
        char winner {' '};
        while(!Game::isOver(board.getBoard(), board.getTurns(), winner))
        {
            char const currentPlayer {Game::getCurrentPlayer(board.getTurns(), player1.getLetter(), player2.getLetter())};
            board.draw();
            int spot;
            do
            {
                std::cout << currentPlayer << " > ";
                std::cin >> spot;
                if(std::cin.fail() || spot < 1 || spot > 9)
                {
                    Game::inputErrorInt(1, 9);
                    spot = -1;
                }
            } while(!board.setCase(spot, currentPlayer));
            board.increaseTurns();
        }
        board.draw();
        Game::displayWinnerAndScore(winner, player1, player2);
    } while(Game::keepPlaying());
}

/**
 * @brief Makes the player play against the computer
 * 
 */
void playerVScpu()
{
    Player player;
    player.setLetter(1, player);
    CPU cpu;
    cpu.setLetter(player.getLetter());
    do
    {
        Board board;
        char winner {' '};
        while(!Game::isOver(board.getBoard(), board.getTurns(), winner))
        {
            char currentPlayer {Game::getCurrentPlayer(board.getTurns(), player.getLetter(), cpu.getLetter())};
            board.draw();
            int spot;
            do
            {
                std::cout << player.getLetter() << " > ";
                std::cin >> spot;
                if(std::cin.fail() || spot < 1 || spot > 9)
                {
                    Game::inputErrorInt(1, 9);
                    spot = -1;
                }
            } while(!board.setCase(spot, currentPlayer));
            board.increaseTurns();
            if(Game::isOver(board.getBoard(), board.getTurns(), winner))
                break;
            board.draw();
            currentPlayer = Game::getCurrentPlayer(board.getTurns(), player.getLetter(), cpu.getLetter());
            board.setCase(cpu.findBestMove(board.getBoard(), player.getLetter()), cpu.getLetter());
            board.increaseTurns();
        }
        board.draw();
        Game::displayWinnerAndScore(winner, player, cpu);
    } while(Game::keepPlaying());
}