// CPP Connect Four Driver
// Ben Andrews | Jimmy Hickey
// 2018-1-26

#include <stdio.h>
#include "constants.h"
#include "game_board.h"
#include "human_player.h"

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