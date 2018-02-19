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
	int total_score = 0;

	// find a piece to evaluate
	int row_index;

	// for each column
	for(int col_index = 0; col_index < COLUMNS; ++col_index)
	{
		// for each row, from top to bottom or until we hit a piece
		for(row_index = ROWS -1; row_index >= 0 && (*board)[col_index][row_index] == BLANK_SPACE; --row_index)
		{
            // if we are on the bottom
			if(row_index == 0)
                goto evaluate;

            // if there is a piece below us
			if((*board)[col_index][row_index -1] != BLANK_SPACE)
                goto evaluate;

            // if there exists another column
			if(col_index +1 < COLUMNS)
			{
                // if there is a piece to the right
				if((*board)[col_index +1][row_index] != BLANK_SPACE)
                    goto evaluate;

                // if there is a piece down to the right
				if((*board)[col_index +1][row_index -1] != BLANK_SPACE)
                    goto evaluate;
			}

            // if there is a column of the left
            if(col_index > 0)
            {
	            // if there is a piece to the left
	            if((*board)[col_index -1][row_index] != BLANK_SPACE)
		            goto evaluate;

	            // if there is a piece down to the left
	            if((*board)[col_index -1][row_index -1] != BLANK_SPACE)
		            goto evaluate;
            }


            // if we are not evaluating continue and check the next row
            continue;

            // evaluate the space
        evaluate:
			printf("Evaluating col: %d row: %d\n", col_index, row_index);
			Position pos;
			pos.col = col_index;
			pos.row = row_index;

			printf("evalVert\n");
			evalVert(board, &pos);


		}


	}

	printBoard(board);

	// free the board you idiots

	return 0;
}


/*
 * Find and return the vertical score for position pos
 */
int MinimaxPlayer::evalVert(gameboard *board, Position *pos)
{
	// if on the bottom, no score
	if(pos->row == 0)
		return 0;

	int check_row = pos->row -1;
	int consecutive = 0;

	// if the pieces below our us, add score, else subtract
	if((*board)[pos->col][check_row -1] == player_number)
		while(check_row >= 0 && (*board)[pos->col][check_row] == player_number)
		{
			++consecutive;
			--check_row;
		}
	else
		// !player_number will get the other player
		while(check_row >= 0 && (*board)[pos->col][check_row] == !player_number)
		{
			--consecutive;
			--check_row;
		}

	// if the score is 1, 0, or -1 no score
	//  or if there is not enough room above to turn consecutive pieces into a winning sequence
	if( (consecutive <= 1 && consecutive >= -1) || (consecutive == 2 && pos->row > ROWS -2))
		return 0;

	printf("vert score: %d\n", consecutive);
	return consecutive;
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


















