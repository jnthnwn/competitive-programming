import math

def get_input():
    a, b, s, m, n = [int(x) for x in input().split()]
    return a, b, s, m, n

while True:
    a, b, s, m, n = get_input()

    if 0 == a + b + s + m + n:
        break

    # the ball is launched from the middle of the table
    # and finishes in the middle of the table
    # so every bounce will cover the full horizontal/vertical
    # distance of the table
    total_x = m * a
    total_y = n * b
    total_distance = math.hypot(total_x, total_y)
    velocity = total_distance / s

    # now we need to calculate the launching angle
    # we can basically tile infinite adjacent tables
    # next to the original table and pretend the ball
    # gets shot out straight and lands in the middle of
    # one of these adjacent tables
    # you can think of the ball bouncing off the edge
    # as crossing a table border into a reflection of the original
    if total_x == 0:
        # avoid the divide by zero error below
        angle = 90
    else:
        angle = math.degrees(math.atan(total_y/total_x))

    print('{:0.2f} {:0.2f}'.format(angle, velocity))
    
