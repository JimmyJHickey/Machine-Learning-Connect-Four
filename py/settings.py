def init():
    global RED
    RED = 1
    global BLACK
    BLACK = 2
    global COLUMNS
    COLUMNS = 7
    global ROWS
    ROWS = 6
    global board
    board = []
    for i in range(COLUMNS):
        board.append([0] * ROWS)
    global moves_played
    moves_played = 0