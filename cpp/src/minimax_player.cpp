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

			printf("evalVert ");
            printf("vert score: %d\n", evalVert(board, &pos));

            printf("evalHorz \n");
            printf("horz score: %d\n", evalHorz(board, &pos));

			printf("\n");
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
	if((*board)[pos->col][check_row] == player_number)
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

	return consecutive;
}


/*
 * Find and return the horizontal score for position pos
 */
int MinimaxPlayer::evalHorz(gameboard *board, Position *pos)
{
	int left_scoring_player = -1;
    int left_consecutive = 0;
	int right_scoring_player = -1;
    int right_consecutive =  0;
    int check_left_col = pos->col;
	int check_right_col = pos->col;

    // count any pieces to the left first

	// Ugly incoming
	//  if there is no space to the left, or
	//  if there is no piece to the left goto scoring the right side
	//  reset left check and check the right side
	// scoring_player gets assigned to the space on the left if the space exists
    if(check_left_col == 0 || (left_scoring_player = (*board)[check_left_col -1][pos->row]) == BLANK_SPACE)
	    goto score_right;

    while(--check_left_col >= 0 && (*board)[check_left_col][pos->row] == left_scoring_player)
        ++left_consecutive;


    // count the score to the right
	//  unfortunately very similar to count left
	//  if you, dear reader, can think of a way to do both the left and right scores together without
	//  repeating code and without hurting performance that would be lovely
	//  until then, forgive us our code duplication
score_right:
	// Symmetric ugly
	//  if there is no space to the right, or
	//  if there is no piece to the right goto scoring the right side
	//  reset right check and calculate the total score
	// scoring_player gets assigned to the space on the right if the space exists
	if(check_right_col == COLUMNS -1 || (right_scoring_player = (*board)[check_right_col +1][pos->row]) == BLANK_SPACE)
		goto calc_score;

    while(++check_right_col <= COLUMNS -1 && (*board)[check_right_col][pos->row] == right_scoring_player)
        ++right_consecutive;


calc_score:
	// if no one scored
	if(left_consecutive + right_consecutive <= 1)
		return 0;

	int score = 0;
	int left_pot = 0;
	int right_pot = 0;

	// find the potential for the left and right consecutive pieces
	//   how many blank spaces there are after the consecutive pieces
	for(int i = 0; i < 3 - left_consecutive; ++i)
		if(check_left_col >= 0 && (*board)[check_left_col--][pos->row] == BLANK_SPACE)
			++left_pot;
		else
			break;

	for(int i = 0; i < 3 - right_consecutive; ++i)
		if(check_right_col <= COLUMNS -1 && (*board)[check_right_col++][pos->row] == BLANK_SPACE)
			++right_pot;
		else
			break;

	printf("left  pot: %d\n", left_pot);
	printf("right pot: %d\n", right_pot);

	// if only one player has consecutive pieces
	if(left_scoring_player == right_scoring_player
	|| left_consecutive == 0 || right_consecutive == 0)
	{
		// if there consecutive pieces can become a winning sequence
		score = left_consecutive + right_consecutive;
		if(score > 1 && score + left_pot + right_pot >= 4)
			// if the pieces aren't ours, negate the score
			if(left_scoring_player != player_number || right_scoring_player != player_number)
				score *= -1;
	}

	// find the score if both players have consecutive pieces


	return score;
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


















