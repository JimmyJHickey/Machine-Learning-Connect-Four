// CPP CnnectFour game_board header
// Ben Andrews | Jimmy Hickey
// 2018-1-26

#ifndef MACHINE_LEARNING_CONNECT_FOUR_GAME_BOARD_H
#define MACHINE_LEARNING_CONNECT_FOUR_GAME_BOARD_H

#endif //MACHINE_LEARNING_CONNECT_FOUR_GAME_BOARD_H

#ifndef MACHINE_LEARNING_CONNECT_FOUR_CONSTANTS_H
#include "constants.h"
#endif

class GameBoard
{
public:
    GameBoard();
    int playPiece(int player, Position *pos);
    int checkWinner(Position *pos, int player);
    void printBoard(void);

private:
    int board[COLUMNS][ROWS];

};