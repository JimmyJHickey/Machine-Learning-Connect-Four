// CPP Cnnect Four game board class
// Ben Andrews | Jimmy Hickey
// 2018-1-26

#include <stdio.h>

#ifndef MACHINE_LEARNING_CONNECT_FOUR_GAME_BOARD_H
#include "game_board.h"
#endif

#define MIN(a,b) (((a)<(b)) ? a : b)


GameBoard::GameBoard(void)
{
    printf("making gameboard\n");

	// initilize the game board to blank spaces
	// [0][0] is bottom left
	for(int i = 0; i < COLUMNS; ++i)
	{
	    for(int j = 0; j < ROWS; ++j)
	    {
	        board[i][j] = BLANK_SPACE;
	    }
	} // end outer for -- i
}

/*
 * Plays a piece in the column specified of the player specified.
 * Returns: the row the piece was played in, or a negative number
 *          indicating error
 */
int GameBoard::playPiece(int player, Position *pos)
{
	printf("attempting to play piece...");
	fflush(stdout);

	if(pos->col < 0 || pos->col > 6)
	{
	    printf("invalid column...");
		fflush(stdout);
		pos->row = -1;
	    return INVALID_COLUMN;
	}

	if(board[pos->col][ROWS -1] != BLANK_SPACE)
	{
	    printf("column is full...");
		fflush(stdout);
		pos->row = -1;
	    return COLUMN_FULL;
	}

	// find first blank space in column, play the piece
	int i;
	for(i = 0; i < ROWS; ++i)
	{
	    if(board[pos->col][i] == BLANK_SPACE)
	    {
	        printf("piece played\n");
	        board[pos->col][i] = player;
		    pos->row = i;
	        break;
	    }
	}

	return 0;
}

/*
 * Checks to see if the piece as pos is part of a winning connection
 * *Returns as soon as a win is found, does not find all possible wins.
 */
int GameBoard::checkWinner(Position *pos, int player)
{
	// thanks to Jared Dupont for the winner checking algorithm
	// https://github.com/jrddupont/

	int seq_counter = 0;
	int return_value = NOT_WIN;

	// check for horizontal - win
	for(int i = 0; i < COLUMNS; ++i)
	{
		if(board[i][pos->row] == player)
			seq_counter++;
		else if(seq_counter >= 4)
			break;
		else
			seq_counter = 0;
	}
	if(seq_counter >= 4)
	{
		return_value = HORZ_WIN;
		goto done;
	}
	else
		seq_counter = 0;


	// check for vertical | win
	for(int i = 0; i < ROWS; ++i)
	{
		if(board[pos->col][i] == player)
			seq_counter++;
		else if(seq_counter >= 4)
			break;
		else
			seq_counter = 0;
	}
	if(seq_counter >= 4)
	{
		return_value = VERT_WIN;
		goto done;
	}
	else
		seq_counter = 0;


	// check for +1 slope / win
	Position checkPos;
	checkPos.col = pos->col - MIN(pos->col, pos->row);
	checkPos.row = pos->row - MIN(pos->col, pos->row);
	for(int i = 0; i < COLUMNS; ++i)
	{
		if(!(checkPos.col < COLUMNS && checkPos.row < ROWS))
			break;

		if(board[checkPos.col++][checkPos.row++] == player)
			seq_counter++;
		else if(seq_counter >= 4)
			break;
		else
			seq_counter = 0;
	}
	if(seq_counter >= 4)
	{
		return_value = POS_DIAG_WIN;
		goto done;
	}
	else
		seq_counter = 0;


	// check for -1 slope \ win
	checkPos.col = pos->col - MIN(pos->col, COLUMNS - pos->row);
	checkPos.row = pos->row + MIN(pos->col, COLUMNS - pos->row);
	for(int i = 0; i < COLUMNS; ++i)
	{
		if(!(checkPos.col >= 0 && checkPos.row >= 0))
			break;

		if(board[checkPos.col++][checkPos.row--] == player)
			seq_counter++;
		else if(seq_counter >= 4)
			break;
		else
			seq_counter = 0;
	}
	if(seq_counter >= 4)
	{
		return_value = NEG_DIAG_WIN;
		goto done;
	}
	else
		seq_counter = 0;

	done:
	switch(return_value)
	{
		case NOT_WIN:
			break;
		case HORZ_WIN:
			printf("Horizontal Win!\n");
			break;
		case VERT_WIN:
			printf("Vertical Win!\n");
			break;
		case POS_DIAG_WIN:
			printf("Positive Slope Win!\n");
			break;
		case NEG_DIAG_WIN:
			printf("Negative Slope Win!\n");
			break;
		default:
			printf("If you are reading this, something very bad has happened\n");
	}

	return return_value;
}

void GameBoard::printBoard(void)
{
	for(int i = ROWS -1; i >= 0; --i)
	{
	    for(int j = 0; j < COLUMNS; ++j)
	    {
	        printf("%c ", board[j][i] == BLANK_SPACE ? '-' :
	                        (board[j][i] == PLAYER_ONE ? 'X' : 'O') );
	    }
    printf("\n");
	}

	printf("0 1 2 3 4 5 6\n\n");
}