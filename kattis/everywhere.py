from sys import stdin

n = int(stdin.readline())

for i in range(n):
    visited = set()
    m = int(stdin.readline())
    # simply track unique city names
    for j in range(m):
        visited.add(stdin.readline().strip())

    # count number of unique names
    print len(visited)
