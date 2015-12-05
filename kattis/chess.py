def char_to_index(ch):
    # maps A to 1, B to 2, ..., H to 8
    return ord(ch) - ord('A') + 1


def index_to_char(i):
    # maps 1 to A, 2 to B, ..., 8 to H
    return chr(ord('A') + i - 1)


def get_diagonals(row, col):
    # from a target square, get all diagonals as a pair/2-list of ints

    result = []
    # get diagonals to the lower left
    i, j = row - 1, col - 1
    while i > 0 and j > 0:
        result.append([i, j])
        i -= 1
        j -= 1
        
    # get diagonals to the upper left
    i, j = row + 1, col - 1
    while i <= 8 and j > 0:
        result.append([i, j])
        i += 1
        j -= 1

    # get diagonals to the lower right
    i, j = row - 1, col + 1
    while i > 0 and j <= 8:
        result.append([i, j])
        i -= 1
        j += 1

    # get diagonals to the upper right
    i, j = row + 1, col + 1
    while i > 0 and j <= 8:
        result.append([i, j])
        i += 1
        j += 1

    return result


tc = int(input())

for i in range(tc):
    # eat input, turn into consistent int indexes
    x_col, x_row, y_col, y_row = input().split()
    x_col = char_to_index(x_col)
    x_row = int(x_row)
    y_col = char_to_index(y_col)
    y_row = int(y_row)

    # get diagonals obviously
    x_diags = get_diagonals(x_row, x_col)
    y_diags = get_diagonals(y_row, y_col)
    
    # case 1: we start on the target square, no moves
    if (x_row, x_col) == (y_row, y_col):
        print('0 {} {}'.
              format(index_to_char(x_col), x_row))
    # case 2: the target square is on one of the first diagonals
    elif [y_row, y_col] in x_diags:
        print('1 {} {} {} {}'.
              format(index_to_char(x_col), x_row,
                     index_to_char(y_col), y_row))
    # just need to check if the start square's diagonals ever
    # intersect with the target square's diagonals
    # we should need at most 2 moves for any test case
    else:
        found = False
        for coord in x_diags:
            if coord in y_diags:
                midpoint = coord
                found = True
                print('2 {} {} {} {} {} {}'.
                      format(index_to_char(x_col), x_row,
                             index_to_char(coord[1]), coord[0],
                             index_to_char(y_col), y_row))
                break
        # otherwise the diagonals never intersect
        if not found:
            print('Impossible')

