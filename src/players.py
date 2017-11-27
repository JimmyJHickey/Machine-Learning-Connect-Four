import settings
from minimax import Minimax
import game
import copy
settings.init()


class Player:
    def __init__(self, name, player):
        self.name = name
        self.player = player

    def make_move(self):
        return 0


class RandomPlayer(Player):
    random = __import__('random')

    def __init__(self, player):
        super().__init__("Random AI", player)

    def make_move(self):
        return self.random.randint(0, 6)


class HumanPlayer(Player):
    def __init__(self, name, player):
        super().__init__(name, player)

    def make_move(self):
        prompt = self.name + ", enter a column to play a piece: "
        return input(prompt)


# Uses a Connect 4 Minimax implementation created by Erik Ackermann and  Charlene Wang
# https://github.com/erikackermann/Connect-Four
class MinimaxPlayer(Player):

    def __init__(self, player):
        super().__init__("MinimaxPlayer", player)

    def make_move(self):
        changed_board = self.change_board(settings.board)

        m = Minimax(changed_board)

        x = m.bestMove(6, changed_board, 'x' if self.player == 1 else 'o')

        x = x[0]

        output = self.name + " played in column " + str(x)

        print(output)

        return x

    def change_board(self, board_in):
        return_board = [[' ', ' ', ' ', ' ', ' ', ' ', ' '],
                        [' ', ' ', ' ', ' ', ' ', ' ', ' '],
                        [' ', ' ', ' ', ' ', ' ', ' ', ' '],
                        [' ', ' ', ' ', ' ', ' ', ' ', ' '],
                        [' ', ' ', ' ', ' ', ' ', ' ', ' '],
                        [' ', ' ', ' ', ' ', ' ', ' ', ' ']]

        for i in range(settings.ROWS):
            for j in range(settings.COLUMNS):
                if board_in[j][settings.ROWS - (i + 1)] == 1:
                    return_board[i][j] = 'x'
                elif board_in[j][settings.ROWS - (i + 1)] == 2:
                    return_board[i][j] = 'o'

        return return_board


class NetPlayer(Player):

    def __init__(self, player, network_path):
        import pickle
        super().__init__("Neural Net Player", player)
        self.network = pickle.load(open(network_path, 'rb'))

    def make_move(self):
        flat = [[item for sublist in settings.board for item in sublist]]
        pred = self.network.predict(flat)
        return pred



class NegaMaxPlayer(Player):
    """
    Thanks a bunch to Pacal Pons: https://github.com/PascalPons/connect4
    """

    def __init__(self, player):
        super().__init__("NegaMax", player)

    def can_play(self, col):

        """play a piece on the board"""

        # if the selected column doesn't exist
        if col < 0 or col > settings.COLUMNS:
            return -1

        # if the selected column is full of pieces
        if settings.board[col][0] != 0:
            return -1

        # topmost open slot in the column
        row = 0
        while row < settings.ROWS - 1 and settings.board[col][row + 1] == 0:
            row += 1

        return row if settings.board[col][row] == 0 else -1

    def is_winning_move(self, col, row, board_in, turn_in):
        """finds if the last play resulted in a winning play"""
        print("finding winning move")
        print(turn_in)
        print(board_in)
        # check for a horizontal win
        counter = 0
        for i in range(settings.COLUMNS):
            if board_in[i][row] == turn_in:
                print("this is very bad")
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break

            if counter >= 4:
                print("!!! winner !!! 0")
                return turn_in

            i += 1

        # check for vertical win
        counter = 0
        for i in range(settings.ROWS):
            if board_in[col][i] == turn_in:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break
            if counter >= 4:
                print("!!! winner !!! 1")
                return turn_in

            i += 1

        # check for wins with slope -1
        counter = 0
        start_col = col - min(col, row)
        start_row = row - min(col, row)
        for i in range(settings.COLUMNS):
            if start_col + i < 7 and start_row + i < 6 and board_in[start_col + i][start_row + i] == turn_in:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break
            if counter >= 4:
                print("!!! winner !!! 2")
                return turn_in

        # check for wins with slope of 1
        counter = 0
        start_col = col - min(col, settings.COLUMNS - row)
        start_row = row + min(col, settings.COLUMNS - col)
        for i in range(settings.COLUMNS):
            if start_col + i < 7 and start_row - i < 6 and board_in[start_col + i][start_row - i] == turn_in:
                counter += 1
            else:
                if counter < 4:
                    counter = 0
                else:
                    break
            if counter >= 4:
                print("!!! winner !!! 3")
                return turn_in

        # return there wasn't a winner this turn
        return 0

    def play(self, col, row, board_in):
        board_in[col][row] = self.player
        return board_in

    def negamax(self, turn, board_in=settings.board):
        print("negamaxing")
        print(turn)
        print(board_in)

        # Check if draw
        if settings.moves_played == settings.ROWS * settings.COLUMNS:
            print("is draw")
            return 0

        for col in range(settings.COLUMNS):
            row = self.can_play(col)
            if row >= 0:
                print("board_in")
                print(board_in)
                current_board = copy.deepcopy(board_in)
                current_board = self.play(col, row, current_board)
                if self.is_winning_move(col, row, current_board, turn_in=turn):
                    print("winning")
                    return ((settings.COLUMNS * settings.ROWS + 1) - settings.moves_played) / 2

        best_score = -settings.COLUMNS * settings.ROWS

        for col in range(settings.COLUMNS):
            row = self.can_play(col)
            if row >= 0:
                recursive_board = board_in
                self.play(col, row, recursive_board)
                score = -self.negamax(turn%2 + 1, recursive_board)
                best_score = score if score > best_score else best_score

        print(best_score)
        print("~~~~~~~~~~~~~~~~ THIS SHOULD BREAK HERE ~~~~~~~~~~~~~~~~~~~~")
        return best_score

    def make_move(self):
        return self.negamax(self.player, settings.board)



