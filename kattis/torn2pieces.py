import collections
# number of pieces of paper to process
N = int(input())

# set up the adjacency list
adjacent = collections.defaultdict(list)
# keep track of all the stops that appear in the input
stops = set()

for n in range(N):
    # eat your input, it's good for you!
    line = input().split()
    # first station connects to all of the stations in seconds
    first = line[0]
    seconds = line[1:]
    for second in seconds:
        stops.add(first)
        stops.add(second)
        adjacent[first].append(second)
        adjacent[second].append(first)

# initially say that none of the stops have been visited
visited = {}
for stop in stops:
    visited[stop] = False

# eat your input, it's good for you!
start, destination = input().split()
# start off needing to visit the start station
to_visit = [start]
previous = {}
# say that there are no stops that you visit before the start
previous[start] = None

# maintain a flag for early exiting the DFS
solved = False

# perform DFS
while to_visit:
    current = to_visit.pop()
    visited[current] = True
    if current == destination:
        solved = True
        break
    for stop in adjacent[current]:
        if not visited[stop]:
            to_visit.append(stop)
            previous[stop] = current

# build up the path from the previous stations if it exists
if solved:
    path = []
    current = destination
    while current is not None:
        path.append(current)
        current = previous[current]
    # be sure to print it from start to destination!
    path.reverse()
    print(' '.join(path))
# :( unsuccessful
else:
    print('no route found')
