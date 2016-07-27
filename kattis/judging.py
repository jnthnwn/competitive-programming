from collections import defaultdict

n = int(input())

# defaultdicts simplify increasing the counts for
# previously unseen keys
domjudge_results = defaultdict(int)
kattis_results = defaultdict(int)

# keep track of the number of results for domjudge
for i in range(n):
    result = input().strip()
    domjudge_results[result] += 1

# keep track of the number of results for kattis
# but only if we ran into them for domjudge
# (since they couldn't share the results otherwise)
for i in range(n):
    result = input().strip()
    if result in domjudge_results.keys():
        kattis_results[result] += 1

same_for_both = 0

# now take the minimum count of any of the common results from
# either judge
for key in kattis_results.keys():
    same_for_both += min(kattis_results[key], domjudge_results[key])

print(same_for_both)
