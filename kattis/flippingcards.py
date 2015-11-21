def find(x):
    # we keep finding which component tree x belongs to
    # until x says 'I am the root of my own component tree'
    while (x != component[x]):
        x = component[x]
        component[x] = component[component[x]]
    return x


def union(x, y):
    # determine which component x and y belong to
    x = find(x)
    y = find(y)
    if x == y:
        # x and y are of the same component
        # so we're adding a cycle to the component
        cycles[x] = cycles[x] + 1
    else:
        # we union the two components
        component[y] = x
        cycles[x] = cycles[x] + cycles[y]

        
component = []
cycles = []
tc = int(raw_input())
for t in range(tc):
    n = int(raw_input())
    component = [i for i in range(2*n + 1)]
    cycles = [0 for i in range(2*n + 1)]
    for i in range(n):
        x1, x2 = map(int, raw_input().split())
        union(x1, x2)

    ok = True
    for i in cycles:
        if i > 1:
            ok = False
            break

    if not ok:
        print 'impossible'
    else:
        print 'possible'
    
