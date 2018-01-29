// Constants shared among the whole project
// Ben Andrews | Jimmy Hickey
// 2018-1-26

#ifndef MACHINE_LEARNING_CONNECT_FOUR_CONSTANTS_H
#define MACHINE_LEARNING_CONNECT_FOUR_CONSTANTS_H

#endif //MACHINE_LEARNING_CONNECT_FOUR_CONSTANTS_H

#define PLAYER_ONE 0
#define PLAYER_TWO 1
#define BLANK_SPACE -1

#define COLUMNS 7
#define ROWS 6


#define INVALID_COLUMN -1
#define COLUMN_FULL -2

#define NOT_WIN 0
#define HORZ_WIN 1
#define VERT_WIN 2
#define POS_DIAG_WIN 3
#define NEG_DIAG_WIN 4

struct Position
{
	int col;
	int row;
};
