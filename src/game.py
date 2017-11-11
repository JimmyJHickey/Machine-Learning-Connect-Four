# Connect 4 Game
# To be used for machine learning
# Ben Andrews
# 11-11-17 <- fix that date Jimmy, I dare you

# still learning python, will break many many python paradigms

RED = 1
BLACK = 2

COLUMNS = 7
ROWS = 6

turn = RED

#         top             bottom
board = [[0, 0, 0, 0, 0, 0],  # left
         [0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0]]  # right

def gameLoop():
    global turn


    while 1:
        playColumn = input("Enter a column to play a piece: ")
        playPiece(int(playColumn));

        printBoard()

        if turn == RED:
            turn = BLACK
        else:
            turn = RED

# accepts the column that would like to be played in
def playPiece(col):
        """play a piece on the board"""

        # if the selected column is full of pieces
        if board[col][0] != 0:
            return 1

        # topmost open slot in the column
        row = 0
        while row < ROWS - 1 and board[col][row + 1] == 0:
            row += 1

        board[col][row] = turn

        # check for winner
        findWinner(col, row)

        return 0

# accepts the column and row of the play that might have caused a win
def findWinner(col, row):
    """finds if the last play resulted in a winning play"""
    maybeWinSlots = [-1, -1]
    winSlots = [-1, -1]

    # check for a horizotal win
    counter = 0
    col_counter = 0
    while col_counter < COLUMNS:
        if board[col_counter][row] == turn:
            counter += 1
            maybeWinSlots.append([col_counter, row])
        else:
            if counter < 4:
                counter = 0;
                maybeWinSlots = [-1, -1]
            else:
                break

        if counter >= 4:
            print("!!! winner !!!")
            winSlots.append([maybeWinSlots])
            maybeWinSlots = [-1, -1]

        col_counter += 1

    # check for vertical win
    counter = 0
    row_counter = 0
    while row_counter < ROWS:
        if board[col][row_counter] == turn:
            counter += 1
            maybeWinSlots.append([col, row_counter])
        else:
            if counter < 4:
                counter = 0;
                maybeWinSlots = [-1, -1]
            else:
                break
        if counter >= 4:
            print("!!! winner !!!")
            winSlots.append([maybeWinSlots])
            maybeWinSlots = [-1, -1]

        row_counter += 1

    return 0

def printBoard():
    i = 0
    j = 0

    while i < ROWS:
        while j < COLUMNS:
            print(board[j][i], end=' ')
            j += 1
        print("")
        i += 1
        j = 0

def main():
    print("hello world")
    gameLoop();


if __name__ == "__main__": main()














