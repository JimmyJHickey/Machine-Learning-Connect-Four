// CPP CnnectFour human player header
// Ben Andrews | Jimmy Hickey
// 2018-1-27

#ifndef MACHINE_LEARNING_CONNECT_FOUR_HUMAN_PLAYER_H
#define MACHINE_LEARNING_CONNECT_FOUR_HUMAN_PLAYER_H

#endif //MACHINE_LEARNING_CONNECT_FOUR_HUMAN_PLAYER_H

#include "player.h"

class HumanPlayer: public Player
{
public:
	HumanPlayer(const char *player_name, int player_num);
	int makeMove(GameBoard &game_board);
};