Driver

	/* Kicks off the program */

	main()

		create player1

		create player2

		start GameLoop

GameLoop

	/* Takes care of the top level game orchestration */

	gameBoard

	playGame()

		build gameBoard

		prompt player for move

		check for valid move

		check for winning move

		rotate turn or end game

GameBoard

		/* Holds and operates on the gameboard */

		gameboard[COLUMNS][ROWS]

		playPiece(player, *pos)

		checkWinner(*position, player)
		
		printBoard(void)


Abstract Player

	/* Empty shell for the different kinds of players */

	makeMove(&GameBoard, *Pos)


HumanPlayer -> Player

	/* A player that takes human input to make moves */

	makeMove(&GameBoard, *Pos)

		Prompt human

		return input


MinimaxPlayer -> Player

	/* A player that makes moves with a minimax algorithm */

	makeMove(&GameBoard, *Pos)

		run minimax to set depth

		return move


NeuralPlayer -> Player

	/* A player that makes moves using a trained neural network */

	makeMove(&GameBoard, *Pos)

		runBoard through neural network

		return move


constants.h

	#define PLAYER_ONE 0
	#define PLAYER_TWO 1
	#define BLANK_SPACE -1

	#define COLUMNS 6
	#define ROWS 7
	
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
