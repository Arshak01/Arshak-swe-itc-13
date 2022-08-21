def print_board(board):
    print('     +---+---+---+---+---+---+---+---+')
    for row in range(8, 0, -1):
        print("  ", row, end=" ")
        for col in range(8):
            pass
            print("|", board.cell(row - 1, col), end=" ")
        print("|")
        print('     +---+---+---+---+---+---+---+---+')
    print(end="       ")
    for col in "ABCDEFGH":
        print(col, end="   ")
    print()


class Board:
    def __init__(self):
        self.field = []
        for row in range(8):
            self.field.append([None] * 8)
        self.field[0] = [
            Rook("black"), Knight("black"), Bishop("black"), Queen("black"),
            King("black"), Bishop("black"), Knight("black"), Rook("black")
        ]
        self.field[1] = [
            Pawn("black"), Pawn("black"), Pawn("black"), Pawn("black"),
            Pawn("black"), Pawn("black"), Pawn("black"), Pawn("black"),
        ]
        self.field[6] = [
            Pawn("white"), Pawn("white"), Pawn("white"), Pawn("white"),
            Pawn("white"), Pawn("white"), Pawn("white"), Pawn("white")
        ]
        self.field[7] = [
            Rook("white"), Knight("white"), Bishop("white"), Queen("white"),
            King("white"), Bishop("white"), Knight("white"), Rook("white")
        ]

    def cell(self, row, col):
        figure_or_empty_cell = self.field[row][col]
        if figure_or_empty_cell is None:
            return " "
        else:
            return figure_or_empty_cell.view


class Pawn:
    def __init__(self, c):
        self._color = c
        self.abbr = "P"
        if self._color == "white":
            self.view = "♙"
        else:
            self.view = "♟"

    @property
    def color(self):
        return self._color

    @color.setter
    def color(self, c):
        if c == "white":
            self._color = c
        elif c == "black":
            self._color = c


class Knight:
    def __init__(self, c):
        self._color = c
        self.abbr = "N"
        if self._color == "white":
            self.view = "♘"
        else:
            self.view = "♞"

    @property
    def color(self):
        return self._color

    @color.setter
    def color(self, c):
        if c == "white":
            self._color = c
        elif c == "black":
            self._color = c


class Bishop:
    def __init__(self, c):
        self._color = c
        self.abbr = "B"
        if self._color == "white":
            self.view = "♗"
        else:
            self.view = "♝"

    @property
    def color(self):
        return self._color

    @color.setter
    def color(self, c):
        if c == "white":
            self._color = c
        elif c == "black":
            self._color = c


class Rook:
    def __init__(self, c):
        self._color = c
        self.abbr = "R"
        if self._color == "white":
            self.view = "♖"
        else:
            self.view = "♜"

    @property
    def color(self):
        return self._color

    @color.setter
    def color(self, c):
        if c == "white":
            self._color = c
        elif c == "black":
            self._color = c


class Queen:
    def __init__(self, c):
        self._color = c
        self.abbr = "Q"
        if self._color == "white":
            self.view = "♕"
        else:
            self.view = "♛"

    @property
    def color(self):
        return self._color

    @color.setter
    def color(self, c):
        if c == "white":
            self._color = c
        elif c == "black":
            self._color = c


class King:
    def __init__(self, c):
        self._color = c
        self.abbr = "K"
        self._can_castle = True
        if self._color == "white":
            self.view = "♔"
        else:
            self.view = "♚"

    @property
    def color(self):
        return self._color

    @color.setter
    def color(self, c):
        if c == "white":
            self._color = c
        elif c == "black":
            self._color = c

    @property
    def can_castle(self):
        return self.can_castle

    def castling(self):
        self.can_castle = False

    @can_castle.setter
    def can_castle(self, value):
        self._can_castle = value


def main():
    board = Board()
    print_board(board)


main()
