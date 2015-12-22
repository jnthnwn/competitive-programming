# consume input
T = int(input())
for t in range(T):
    input()
    N = int(input())
    nums = list(map(int, input().split()))

    # this dict will hold a mapping of a sum to its frequency
    d = {}
    ans = 0
    sum = 0
    # we'll iterate through the list, calculating the sum of all the
    # numbers we've encountered thus far and updating that sum's
    # frequency in d, including if we take no numbers (sum == 0)
    for n in range(N):
        d[sum] = d.get(sum, 0) + 1
        sum += nums[n]
        # then we check if any of the sums we've run into before
        # is exactly 47 less than the current sum
        # and increase our answer tally
        if sum - 47 in d:
            ans += d[sum - 47]
    print(ans)

