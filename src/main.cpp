#include "../include/game.hpp"
#include "../include/board.hpp"
#include "../include/player.hpp"
#include "../include/cpu.hpp"

void playerVSplayer();
void playerVScpu();

int main()
{
    //Game::clearScreen();
    if(Game::init())
        playerVSplayer();
    else
        playerVScpu();
    return 0;
}

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

void playerVScpu()
{
    Player player;
    player.setLetter(1, player);
    CPU cpu;
    cpu.setLetter(player.getLetter());
    Board board;
    char currentPlayer {Game::getCurrentPlayer(board.getTurns(), player.getLetter(), cpu.getLetter())};
}