from sys import stdin

tc = int(stdin.readline())
for t in range(tc):
    n = int(stdin.readline())
    # track the total number of votes
    vote_sum = 0
    votes = [0 for i in range(n)]
    for i in range(n):
        votes[i] = int(stdin.readline())
        vote_sum += votes[i]

    # keep track of which candidate has the most votes
    max_vote_candidate = 0
    for i in range(n):
        if votes[i] > votes[max_vote_candidate]:
            max_vote_candidate = i

    # see if there's more than one candidate with the most votes
    tie = False
    for i in range(n):
        if i != max_vote_candidate:
            if votes[i] == votes[max_vote_candidate]:
                tie = True
                break

    if tie:
        print 'no winner'
    # an alternative check to votes[max_vote_candidate]/vote_sum > 0.5
    # to avoid errors with integer/floating point division
    elif votes[max_vote_candidate] * 2 > vote_sum:
        print 'majority winner {}'.format(max_vote_candidate+1)
    else:
        print 'minority winner {}'.format(max_vote_candidate+1)
