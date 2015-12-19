# keep track of what component (AKA group) each person belongs to
component = {}
# keep track of the size of each component
count = {}


def find(x):
    if x not in component:
        # we haven't put this person into a component yet
        # so make them their own component with size 1
        component[x] = x
        count[x] = 1

    # every component has a representative person,
    # like a leader of the friend group
    # we always want to return this representative
    if x == component[x]:
        return x
    else:
        component[x] = find(component[x])
        return component[x]


def union(x, y):
    # grab the representatives for person x and person y
    xx = find(x)
    yy = find(y)

    if xx != yy:
        # person x and person y had different representatives
        # so they're from different friend groups
        # make one person the new representative for the merged group
        # there can only be one
        component[xx] = yy

        # and sum up the size of each group for the size of the merged group
        count[xx] = count[xx] + count[yy]
        count[yy] = count[xx]

    # return the size of the merged group
    return count[xx]


T = int(input())
for t in range(T):
    F = int(input())
    # never forget to clear global vars
    component.clear()
    count.clear()

    for f in range(F):
        # grab the names and merged their friend groups together
        x, y = input().split()
        ans = union(x,y)
        print(ans)
