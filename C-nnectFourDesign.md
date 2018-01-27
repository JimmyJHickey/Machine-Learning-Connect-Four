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

		gameboard[7][6]

		playPiece(column, player)

		checkWinner(position, player)


Abstract Player

	/* Empty shell for the different kinds of players */

	makeMove()


HumanPlayer -> Player

	/* A player that takes human input to make moves */

	makeMove(board)

		Prompt human

		return input


MinimaxPlayer -> Player

	/* A player that makes moves with a minimax algorithm */

	makeMove()

		run minimax to set depth

		return move


NeuralPlayer -> Player

	/* A player that makes moves using a trained neural network */

	makeMove()

		runBoard through neural network

		return move


constants.h

	#define PLAYER_ONE 0
	#define PLAYER_TWO 1
	#define BLANK_SPACE -1

	#define COLUMNS 6
	#define ROWS 7
