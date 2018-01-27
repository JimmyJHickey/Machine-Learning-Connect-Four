// CPP Cnnect Four game board class
// Ben Andrews | Jimmy Hickey
// 2018-1-26

#include <stdio.h>
#include "constants.h"
#include "game_board.h"


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
int GameBoard::playPiece(int column, int player)
{
    printf("attempting to play piece\n");

    if(column < 0 || column > 6)
    {
        fprintf(stderr, "Invalid column\n");
        return INVALID_COLUMN;
    }

    if(board[column][ROWS -1] != BLANK_SPACE)
    {
        fprintf(stderr, "Column is full\n");
        return COLUMN_FULL;
    }

    // find first blank space in column, play the piece
    int i;
    for(i = 0; i < ROWS; ++i)
    {
        if(board[column][i] == BLANK_SPACE)
        {
            board[column][i] = player;
            break;
        }
    }

    return i;
}

int GameBoard::checkWinner(Position pos, int player)
{
    return 0;
}

void GameBoard::printBoard(void)
{
    for(int i = ROWS -1; i >= 0; --i)
    {
        for(int j = 0; j < COLUMNS; ++j)
        {
            printf("%c ", board[j][i] == BLANK_SPACE ? '-' :
                            (board[j][i] == PLAYER_ONE ? 'X' : 'O') );

            //printf("%2d ", board[j][i]);
        }
        printf("\n");
    }

    printf("0 1 2 3 4 5 6\n");
}