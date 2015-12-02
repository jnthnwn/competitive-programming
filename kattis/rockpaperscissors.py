# this kept timing out no matter what i did.
# this does the same thing as the c++ solution
n = list(map(int, input().split()))

while len(n) > 1:
    n, k = n[0], n[1]
    wins = [0 for i in range(n+1)]
    losses = [0 for i in range(n+1)]

    for i in range(k*n*(n-1)//2):
        p1, m1, p2, m2 = input().split()
        p1 = int(p1)
        p2 = int(p2)

        if m1 == 'rock' and m2 == 'scissors' or \
            m1 == 'scissors' and m2 == 'paper' or \
            m1 == 'paper' and m2 == 'rock':
                wins[p1] += 1
                losses[p2] += 1
        elif m2 == 'rock' and m1 == 'scissors' or \
            m2 == 'scissors' and m1 == 'paper' or\
            m2 == 'paper' and m1 == 'rock':
                wins[p2] += 1
                losses[p1] += 1

    for i in range(1, n+1):
        if wins[i] + losses[i] == 0:
            print('-')
        else:
            print('{0:.3f}'.format(float(wins[i]) / (wins[i]+losses[i])))

    print()

    n = list(map(int, input().split()))
