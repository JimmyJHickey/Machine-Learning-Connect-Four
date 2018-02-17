// CPP CnnectFour human player class
// Ben Andrews | Jimmy Hickey
// 2018-1-27

#include <stdio.h>

#ifndef MACHINE_LEARNING_CONNECT_FOUR_CONSTANTS_H
#include "constants.h"
#endif

#include "human_player.h"


HumanPlayer::HumanPlayer(const char *player_name, int player_num)
: Player(player_name, player_num)
{
	printf("HumanPlayer: %s created as #%d\n", player_name, player_num);
}


int HumanPlayer::makeMove(GameBoard &game_board, Position *pos)
{
	printf("%s, enter a column number to play a piece: ", player_name);

	scanf("%d", &pos->col);

	return game_board.playPiece(player_number, pos);
}
