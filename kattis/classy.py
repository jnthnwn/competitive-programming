from sys import stdin

# maps a class to an appropriate value so the classes can be put in 
# lexicographical order
def reassign(s):
    if s == 'upper':
        return 'A'
    elif s == 'middle':
        return 'B'
    else:
        return 'C'

tc = int(stdin.readline())
for t in range(tc):
    n = int(stdin.readline())
    names = {}
    max_len = 0

    for i in range(n):
        # track person name and classiness, discard the word 'class'
        name, classes, _ = stdin.readline().split()
        # trim the ending colon
        name = name[:-1]
        # separate out the classes
        classes = classes.split('-')
        # the right-most class is the most significant, so let's compare
        # in reverse
        classes.reverse()
        # map the class names so they compare properly,
        # i.e. 'upper' > 'middle' > 'lower', but we want 'A' < 'B' < 'C'
        classes = map(reassign, classes)
        max_len = max(max_len, len(classes))
        names[name] = classes

    # let's pad the length of everyone's classes to aid lex. sort, 
    # keeping in mind that trailing 'middle' class distinctions are equivalent
    for k in names:
        while len(names[k]) < max_len:
            names[k]  = names[k] + ['B']

    # here, we sort by their classes (x[1]), and then by their name (x[0])
    # in cases where classes are equivalent
    for k,v in sorted(names.items(), key=lambda x: str(x[1]) + x[0]):
        print k

    print '=' * 30

