t = int(input())

for tt in range(t):
    line = input().strip()
    n = int(len(line) ** 0.5)
    answer = []
    for i in range(n):
        for j in range(n):
            answer.append(line[j*n + n-i-1])

    print(''.join(answer))



