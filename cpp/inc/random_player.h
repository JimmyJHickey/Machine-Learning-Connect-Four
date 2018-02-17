// CPP Cnnect Four random player header
// Ben Andrews | Jiummy Hickey
// 2018-2-17

#ifndef MACHINE_LEARNING_CONNECT_FOUR_RANDOM_PLAYER_H
#define MACHINE_LEARNING_CONNECT_FOUR_RANDOM_PLAYER_H

#endif //MACHINE_LEARNING_CONNECT_FOUR_RANDOM_PLAYER_H

#ifndef MACHINE_LEARNING_CONNECT_FOUR_PLAYER_H
#include "player.h"
#endif

class RandomPlayer: public Player
{
public:
	RandomPlayer(const char *player_name, int player_num);
	int makeMove(GameBoard &game_board, Position *pos);
};