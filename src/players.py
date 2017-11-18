import settings
settings.init()


class Player:
    def __init__(self, name):
        self.name = name

    def make_move(self):
        return 0


class RandomPlayer(Player):
    random = __import__('random')

    def __init__(self):
        super().__init__("Random AI")

    def make_move(self):
        return self.random.randint(0, 6)


rp1 = RandomPlayer()
move = rp1.make_move()
print(move)
print(settings.board)