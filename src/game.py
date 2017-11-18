# Connect 4 Game
# To be used for machine learning final project
# Ben Andrews
# 11-11-17 <- fix that date Jimmy, I dare you
# *11 November 2017

# inspired by code from Jared Dupont
# www.github.com/jrddupont

# still learning python, will break many many python conventions

import settings
settings.init()


class GameBoard:
    board = settings.board
    ROWS = settings.ROWS
    COLUMNS = settings.COLUMNS
    RED = settings.RED
    BLACK = settings.BLACK
    turn = RED

    def game_loop(self):
        game_turns = []
        while 1:
            prompt = "Red" if self.turn == 1 else "Black"
            prompt += " enter a column to play a piece: "
            play_column = input(prompt)
            game_turns.append(play_column)
            winner = self.play_piece(self, int(play_column))

            self.print_board(self)

            if winner > 0:
                print("Winner is: " + str(winner))
                print("Moves: ", *game_turns)
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
            if self.board[col][0] != 0:
                return -1

            # topmost open slot in the column
            row = 0
            while row < self.ROWS - 1 and self.board[col][row + 1] == 0:
                row += 1

            self.board[col][row] = self.turn

            # check for winner
            winner = self.find_winner(self, col, row)

            return winner

    # accepts the column and row of the play that might have caused a win
    def find_winner(self, col, row):
        """finds if the last play resulted in a winning play"""

        # check for a horizontal win
        counter = 0
        for i in range(self.COLUMNS):
            if self.board[i][row] == self.turn:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break

            if counter >= 4:
                print("!!! winner !!!")
                return self.turn

            i += 1

        # check for vertical win
        counter = 0
        for i in range(self.ROWS):
            if self.board[col][i] == self.turn:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break
            if counter >= 4:
                print("!!! winner !!!")
                return self.turn

            i += 1

        # check for wins with slope -1
        counter = 0
        start_col = col - min(col, row)
        start_row = row - min(col, row)
        for i in range(self.COLUMNS):
            if start_col + i < 7 and start_row + i < 6 and self.board[start_col + i][start_row + i] == self.turn:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break
            if counter >= 4:
                print("!!! winner !!!")
                return self.turn

        # check for wins with slope of 1
        counter = 0
        start_col = col - min(col, self.COLUMNS - row)
        start_row = row + min(col, self.COLUMNS - col)
        for i in range(self.COLUMNS):
            if start_col + i < 7 and start_row - i < 6 and self.board[start_col + i][start_row - i] == self.turn:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break
            if counter >= 4:
                print("!!! winner !!!")
                return self.turn

        # return there wasn't a winner this turn
        return 0

    def print_board(self):
        i = 0
        j = 0

        while i < self.ROWS:
            while j < self.COLUMNS:
                print('-' if self.board[j][i] == 0 else 'X' if self.board[j][i] == 1 else 'O', end=' ')
                # print(self.board[j][i], end=' ')
                j += 1
            print("")
            i += 1
            j = 0


def main():
    print("hello world")
    game_board = GameBoard
    game_board.game_loop(game_board)  # there has to be a better way to do this


if __name__ == "__main__":
    main()
