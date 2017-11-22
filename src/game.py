# Connect 4 Game
# To be used for machine learning final project
# Ben Andrews
# 11-11-17 <- fix that date Jimmy, I dare you
# *11 November 2017

# inspired by code from Jared Dupont
# www.github.com/jrddupont

# still learning python, will break many many python conventions

import players
import settings
import time
settings.init()


class GameBoard:

    ROWS = settings.ROWS
    COLUMNS = settings.COLUMNS
    RED = settings.RED
    BLACK = settings.BLACK
    turn = RED
    players = [0, 0, 0]

    def __init__(self, players):
        self.players[players[0].player] = players[0]
        self.players[players[1].player] = players[1]

    def game_loop(self):
        game_turns = []
        self.print_board()
        print("\n")

        #file = open("../data/6v6.txt", "w")

        while 1:
            now = time.time()

            play_column = int(self.players[self.turn].make_move())
            game_turns.append(play_column)
            winner = self.play_piece(play_column)

            move_time = "Move took: " + str(round(time.time() - now, 2)) + " seconds"
            print(move_time)

            self.print_board()
            print("\n")

            #file.write(str(settings.board) + " " + str(play_column) + "\n")

            if winner > 0:
                print("Winner is: " + str(winner))
                print("Number of moves " + str(settings.moves_played))
                print("Moves: ", game_turns)
                #file.close()
                return winner
            elif winner < 0:
                print("illegal move, try again")
            else:

                if self.turn == self.RED:
                    self.turn = self.BLACK
                else:
                    self.turn = self.RED



    # accepts the column that would like to be played in
    def play_piece(self, col):
            """play a piece on the board"""

            # if the selected column doesn't exist
            if col < 0 or col > 6:
                return -1

            # if the selected column is full of pieces
            if settings.board[col][0] != 0:
                return -1

            # topmost open slot in the column
            row = 0
            while row < self.ROWS - 1 and settings.board[col][row + 1] == 0:
                row += 1

            settings.board[col][row] = self.turn

            # check for winner
            winner = self.find_winner(col, row)
            settings.moves_played += 1

            return winner

    # accepts the column and row of the play that might have caused a win
    def find_winner(self, col, row, board_in=settings.board):
        """finds if the last play resulted in a winning play"""

        # check for a horizontal win
        counter = 0
        for i in range(self.COLUMNS):
            if board_in[i][row] == self.turn:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break

            if counter >= 4:
                print("!!! winner 0")
                return self.turn

            i += 1

        # check for vertical win
        counter = 0
        for i in range(self.ROWS):
            if board_in[col][i] == self.turn:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break
            if counter >= 4:
                print("!!! winner 1")
                return self.turn

            i += 1

        # check for wins with slope -1
        counter = 0
        start_col = col - min(col, row)
        start_row = row - min(col, row)
        for i in range(self.COLUMNS):
            if start_col + i < 7 and start_row + i < 6 and board_in[start_col + i][start_row + i] == self.turn:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break
            if counter >= 4:
                print("!!! winner 2")
                return self.turn

        # check for wins with slope of 1
        counter = 0
        start_col = col - min(col, self.COLUMNS - row)
        start_row = row + min(col, self.COLUMNS - row)
        for i in range(self.COLUMNS):
            if start_col + i < 7 and start_row - i < 6 and board_in[start_col + i][start_row - i] == self.turn:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break
            if counter >= 4:
                print("!!! winner 3")
                return self.turn

        # return there wasn't a winner this turn
        return 0

    def print_board(self):
        i = 0
        j = 0

        while i < self.ROWS:
            while j < self.COLUMNS:
                print('-' if settings.board[j][i] == 0 else 'X' if settings.board[j][i] == 1 else 'O', end=' ')
                # print(settings.board[j][i], end=' ')
                j += 1
            print("")
            i += 1
            j = 0

        print("0 1 2 3 4 5 6")

    def print_hi(self):
        print("Hi -Jimmy")


def main():
    print("hello world")
    human1 = players.HumanPlayer("Evan", 1)
    human2 = players.HumanPlayer("Ben", 2)
    randplayer = players.RandomPlayer(2)
    best_player = players.NegaMaxPlayer(2)

    mini_player1 = players.MinimaxPlayer(1)
    mini_player2 = players.MinimaxPlayer(2)

    game_board = GameBoard([mini_player1, mini_player2])
    game_board.game_loop()  # there has to be a better way to do this

if __name__ == "__main__":
    main()
