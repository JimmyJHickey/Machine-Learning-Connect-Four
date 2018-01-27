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

	Player *players[2];

	// create two players on the heap
	players[PLAYER_ONE] = new HumanPlayer("Jimmy", PLAYER_ONE);
	players[PLAYER_TWO] = new HumanPlayer("Ben", PLAYER_TWO);

	GameBoard gb;
	gb.printBoard();

	int turn = PLAYER_ONE;
	Position position;
	for(;;)
	{
		position.col = -1;
		position.row = -1;

		players[turn]->makeMove(gb, &position);
		gb.printBoard();

		// cycle turn
		turn = (++turn, turn % 2);
	}

}