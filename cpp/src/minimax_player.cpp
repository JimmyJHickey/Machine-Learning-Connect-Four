// CPP CnnectFour human player class
// Ben Andrews | Jimmy Hickey
// 2018-1-27

#include <stdio.h>

#ifndef MACHINE_LEARNING_CONNECT_FOUR_CONSTANTS_H
#include "constants.h"
#endif

#include "minimax_player.h"

MinimaxPlayer::MinimaxPlayer(const char *player_name, int player_num, int depth)
	: Player::Player(player_name, player_num)
{
	printf("MinimaxPlayer: %s created as #%d with depth %d\n", player_name, player_num, depth);
	this->depth = depth;
}

int MinimaxPlayer::makeMove(GameBoard &game_board, Position *pos)
{
	printf("MinimaxPlayer \"%s\" is making a move\n", player_name);

	minimax(game_board.boardDup(), 1);

	pos->row = 0;
	pos->col = 0;

	return game_board.playPiece(player_number, pos);
}

int MinimaxPlayer::minimax(gameboard *board, int depth)
{
	printf("Minimax algorithm started\n");
	evaluateBoard(board);

	return 0;
}

int MinimaxPlayer::evaluateBoard(gameboard *board)
{
	printf("Evaluating board\n");


	printBoard(board);

	return 0;
}

/*
 * Print the board for debug puposes
 *
 * Our compiler who art in memory,
 * Forgive us our code duplication,
 * As we forgive those who duplicate code against us
 */
void MinimaxPlayer::printBoard(gameboard *board)
{
    printf("~~~ The duplicate board ~~~\n");

    for(int i = ROWS -1; i >= 0; --i)
    {
        for(int j = 0; j < COLUMNS; ++j)
        {
            printf("%c ", (*board)[j][i] == BLANK_SPACE ? '-' :
                          (*board[j][i] == PLAYER_ONE ? 'X' : 'O') );
        }
        printf("\n");
    }

    printf("0 1 2 3 4 5 6\n");

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}


















