// CPP CnnectFour human player class
// Ben Andrews | Jimmy Hickey
// 2018-1-27

#include <stdio.h>
#include "constants.h"
#include "human_player.h"

HumanPlayer::HumanPlayer(const char *player_name, int player_num)
: Player(player_name, player_num)
{
	printf("HumanPlayer: %s created as #%d\n", player_name, player_num);
}

int HumanPlayer::makeMove(int column)
{
	return 0;
}
