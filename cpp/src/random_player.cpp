// CPP Cnnect Four random player class
// Ben Andrews | Jimmy Hickey
// 2018-2-17

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef MACHINE_LEARNING_CONNECT_FOUR_CONSTANTS_H
#include "constants.h"
#endif

#include "random_player.h"

RandomPlayer::RandomPlayer(const char *player_name, int player_num)
	: Player::Player(player_name, player_num)
{
	printf("RandomPlayer: %s created as #%d\n", player_name, player_num);
	srand(time(NULL));
}

int RandomPlayer::makeMove(GameBoard &game_board, Position *pos)
{
	pos->col = rand() % COLUMNS;

	printf("RandomPlayer \"%s\" is making a move in colmun %d\n", player_name, pos->col);

	return game_board.playPiece(player_number, pos);
}

