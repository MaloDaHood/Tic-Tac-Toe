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
    while(Game::keepPlaying())
    {
        Board board;
        board.init();
        while(!board.isGameOver())
        {
            char currentPlayer {Game::getCurrentPlayer(board.getTurns(), player1.getLetter(), player2.getLetter())};

            board.increaseTurns();
        }
    }
}

void playerVScpu()
{
    Player player;
    player.setLetter(1, player);
    CPU cpu;
    cpu.setLetter(player.getLetter());
    Board board;
    board.init();
    char currentPlayer {Game::getCurrentPlayer(board.getTurns(), player.getLetter(), cpu.getLetter())};
}