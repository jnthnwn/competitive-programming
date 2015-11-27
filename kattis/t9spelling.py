# map the characters to their digit sequences
d = {
        ' ': 0,
        'a': 2, 'b': 22, 'c': 222,
        'd': 3, 'e': 33, 'f': 333,
        'g': 4, 'h': 44, 'i': 444,
        'j': 5, 'k': 55, 'l': 555,
        'm': 6, 'n': 66, 'o': 666,
        'p': 7, 'q': 77, 'r': 777, 's': 7777,
        't': 8, 'u': 88, 'v': 888,
        'w': 9, 'x': 99, 'y': 999, 'z': 9999,
    }

n = int(input())

for i in range(n):
    # i made the mistake of putting input().strip()
    # but we want to keep leading and trailing spaces
    # since they should print out '0'
    line = input()
    ans = []
    # keep track of what digit was printed out last
    last_digit = None
    for ch in line:
        # so we've got a repeat digit in our sequence for two different
        # characters - add a space
        if last_digit is not None and last_digit == d[ch]%10:
            ans.append(' ')
        ans.append(d[ch])
        # update the last digit seen
        last_digit = d[ch]%10

    # kind of treated ans like a java stringbuilder
    print('Case #{:d}: {}'.format(int(i+1), ''.join(map(str, ans))))
