from sys import stdin

# problem is relatively straightforward - follow steps provided
# in problem description

tt = int(stdin.readline())
for t in range(tt):
    r,p,d = map(int, stdin.readline().split())
    ingredients = {}
    order = []
    main = None

    for i in range(r):
        name, weight, percent = stdin.readline().split()
        order += [name]
        weight, percent = map(float, [weight,percent])
        ingredients[name] = [weight, percent]
        if percent == 100.0:
            main = name

    ratio = d/(p * 1.0)
    # weight is at index 0
    scaled_weight = ratio * ingredients[main][0]

    print 'Recipe # {}'.format(t+1)
    for name in order:
        print '{} {:0.1f}'.format(name, scaled_weight * ingredients[name][1] / 100)
    print '-' * 40

