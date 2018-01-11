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

GameLogic

	/* Checks for valid moves, and checks to see if the game has ended */

	makeMove(board, position, player)

	checkWinner(board, position, player)


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
