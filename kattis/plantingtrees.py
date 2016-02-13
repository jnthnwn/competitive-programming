n = int(input())
seeds = list(map(int, input().split()))

seeds.sort()

# set initial max
ans = -1

# imagine going back in time, planting seeds from the day of the party
# you plant the quicker seeds closer to party day,
# and the longer ones farther from party day
# so each day you pick whichever is bigger:
#   - the time to plant this seed; or
#   - the time to plant yesterday's plus the elapsed day
for seed in seeds:
  ans = max(seed, ans+1)

# add one day for planting the first seed,
# add another to prepare for party
ans += 2

print(ans)
