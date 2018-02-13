// CPP CnnectFour human player header
// Ben Andrews | Jimmy Hickey
// 2018-1-29

#ifndef MACHINE_LEARNING_CONNECT_FOUR_MINIMAX_PLAYER_H
#define MACHINE_LEARNING_CONNECT_FOUR_MINIMAX_PLAYER_H

#endif //MACHINE_LEARNING_CONNECT_FOUR_MINIMAX_PLAYER_H

#ifndef MACHINE_LEARNING_CONNECT_FOUR_PLAYER_H
#include "player.h"
#endif

class MinimaxPlayer: public Player
{
public:
	MinimaxPlayer(const char *player_name, int player_num, int depth);
	int makeMove(GameBoard &game_board, Position *pos);

private:
	int depth;
	int minimax(gameboard *board, int depth);
	int evaluateBoard(gameboard *board);
};

