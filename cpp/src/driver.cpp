// CPP Connect Four Driver
// Ben Andrews | Jimmy Hickey
// 2018-1-26

#include <stdio.h>

#ifndef MACHINE_LEARNING_CONNECT_FOUR_CONSTANTS_H
#include "constants.h"
#endif

#ifndef MACHINE_LEARNING_CONNECT_FOUR_GAME_BOARD_H
#include "game_board.h"
#endif

#ifndef MACHINE_LEARNING_CONNECT_FOUR_HUMAN_PLAYER_H
#include "human_player.h"
#endif

int main(int argc, char *argv[])
{
	printf("Hello World\n");

	HumanPlayer player1("Jimmy", PLAYER_ONE);

	GameBoard gb;
	gb.printBoard();

	gb.playPiece(3, PLAYER_ONE);
	gb.printBoard();

	gb.playPiece(3, PLAYER_TWO);
	gb.printBoard();

	gb.playPiece(6, PLAYER_ONE);
	gb.printBoard();
}