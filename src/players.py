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

    def __init__(self, player, depth):
        super().__init__("MinimaxPlayer " + str(depth), player)
        self.depth = depth

    def make_move(self):
        changed_board = self.change_board(settings.board)

        m = Minimax(changed_board)

        x = m.bestMove(self.depth, changed_board, 'x' if self.player == 1 else 'o')

        x = x[0]

        output = self.name + " played in column " + str(x) + "."

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

    difficulty_dict = {
        "Random": "../trained_networks/RvR.sav",
        "Easy": "../trained_networks/6vRliterally10nodes.sav",
        "Medium": "../trained_networks/6vRlessnodes.sav",
        "Hard": "../trained_networks/6vR.sav"}

    def __init__(self, player, difficulty):
        import pickle
        name = "Neural Net Player "
        name += str(difficulty)
        super().__init__(name, player)
        self.network = pickle.load(open(self.difficulty_dict[difficulty], 'rb'))

    def make_move(self):
        flat = [[item for sublist in settings.board for item in sublist]]
        pred = self.network.predict(flat)

        output = self.name + " played in column " + str(pred[0]) + "."
        print(output)

        return pred
