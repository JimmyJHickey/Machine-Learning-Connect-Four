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

	/*
	 * makeMove will allow each type of player to make a move the way they wish.
	 * The player is not responsible if it makes an illegal move, but should return that status of
	 *  game_board.playPiece to the caller.
	 */
	virtual int makeMove(GameBoard &game_board, Position *pos) = 0;

protected:
	const char *player_name;
	int player_number;
};