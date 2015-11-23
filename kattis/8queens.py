board = []

for i in range(8):
    board += [input().strip()]

# keep track of which rows/columns have queens in them
row_taken = [False for i in range(8)]
col_taken = [False for i in range(8)]

# keep track of individual squares for diagonal check
has_queen = [[False for j in range(8)] for i in range(8)]

ok = True
# track how many queens there are in case less than 8 queens
# are present
# e.g. a blank board will *technically* have no queens attacking each other!
queen_count = 0

for i in range(8):
    if not ok:
        break
    for j in range(8):
        # only perform checks if you're on a queen square
        if board[i][j] == '*':
            queen_count += 1
            if row_taken[i] or col_taken[j]:
                ok = False
                break

            # check diagonal squares moving out from current square i,j
            # be careful to stay within board boundaries
            for x in range(1,8):
                if i - x >= 0 and j - x >= 0 and has_queen[i-x][j-x]:
                    ok = False
                    break
                if i - x >= 0 and j + x < 8 and has_queen[i-x][j+x]:
                    ok = False
                    break
                if i + x < 8 and j - x >= 0 and has_queen[i+x][j-x]:
                    ok = False
                    break
                if i + x < 8 and j + x < 8 and has_queen[i+x][j+x]:
                    ok = False
                    break

            if not ok:
                break

            # mark this row, column, and square
            row_taken[i] = col_taken[j] = True
            has_queen[i][j] = True

# no conflicts and 8 queens present
if ok and queen_count is 8:
    print('valid')
else:
    print('invalid')
