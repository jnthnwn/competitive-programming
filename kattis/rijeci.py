num_A = 1
num_B = 0
answer = [None] * 46

# the number of A's and B's after i button pushes
# is just calculated from the problem description
# i.e. every A -> B, every B -> BA
for i in range(46):
    answer[i] = [num_A, num_B]
    num_A, num_B = num_B, num_A+num_B

K = int(input())

print(answer[K][0], answer[K][1])
