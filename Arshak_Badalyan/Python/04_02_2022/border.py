
WHITE = 1
BLACK = 2

fg = lambda text, color: "\33[38;5;" + str(color) + "m" + text + "\33[0m"
bg = lambda text, color: "\33[48;5;" + str(color) + "m" + text + "\33[0m"

def print_board(board,format):
    print('     +----+----+----+----+----+----+----+----+')
    for row in range(8,0, -1):
        print(' ',row, end='  ')
        for col in range(8):
            if (col+row)%2==0:
                bspace = format(board.cell(row, col),234)
                print('|',bspace, end=' ')
            else:
                wspace = format(board.cell(row, col),238)
                print('|',wspace, end=' ')
        print('|')
        print('     +----+----+----+----+----+----+----+----+')
    print(end='        ')
    for col in range(65,73):
        print(chr(col), end='    ')
    print()

class Board:
    def __init__(self):
        self.field = []
        for row in range(1,10):
            self.field.append([None] * 8)
        self.field[1] = [ Rook(WHITE), Knight(WHITE), Bishop(WHITE), Queen(WHITE), King(WHITE), Bishop(WHITE), Knight(WHITE), Rook(WHITE)]
        self.field[2] = [ Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE)]
        self.field[7] = [Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK)]
        self.field[8] = [ Rook(BLACK), Knight(BLACK), Bishop(BLACK), Queen(BLACK), King(BLACK), Bishop(BLACK), Knight(BLACK), Rook(BLACK)]

    def cell(self, row, col):
        piece = self.field[row][col]
        if piece is None:
            return '  '
        return  piece.char()

    def get_piece(self, row, col):
        return self.field[row][col]


def colored(color,smb):
        if color ==1:
            return "\033[38;2;{};{};{}m{}\033[38;2;255;255;255m".format(255, 255, 255,smb)
        elif color == 2:
            return "\033[38;2;{};{};{}m{}\033[38;2;255;255;255m".format(0, 0, 0,smb)


class Rook:

    def __init__(self, color):
        self.color = color
        self.castling = True

    def get_color(self):
        return self.color

    def char(self):
        return colored(self.color,' ♜')

class Pawn:

    def __init__(self, color):
        self.color = color

    def get_color(self):
        return self.color

    def char(self):
        return colored(self.color,' ♝')

class Knight:
    def __init__(self, color):
        self.color = color

    def get_color(self):
        return self.color

    def char(self):
        return colored(self.color,' ♞')

class King:
    def __init__(self, color):
        self.color = color

    def get_color(self):
        return self.color

    def char(self):
        return colored(self.color,' ♚')

class Queen:
    def __init__(self, color):
        self.color = color

    def get_color(self):
        return self.color

    def char(self):
        return colored(self.color,' ♛')

class Bishop:

    def __init__(self, color):
        self.color = color

    def get_color(self):
        return self.color

    def char(self):
        return colored(self.color,' ♟')

