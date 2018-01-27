// CPP CnnectFour abstract player header, to be shared among all players
// Ben Andrews | Jimmy Hickey
// 2018-1-27

#ifndef MACHINE_LEARNING_CONNECT_FOUR_PLAYER_H
#define MACHINE_LEARNING_CONNECT_FOUR_PLAYER_H

#endif //MACHINE_LEARNING_CONNECT_FOUR_PLAYER_H

#ifndef MACHINE_LEARNING_CONNECT_FOUR_GAME_BOARD_H
#include "game_board.h"
#endif

class Player
{
public:
	Player(const char *player_name, int player_num);
	virtual int makeMove(GameBoard &game_board) = 0;

protected:
	const char *name;
	int number;
};