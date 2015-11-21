def dist(p1, p2, t):
    x = (p1.x + p1.dx*t) - (p2.x + p2.dx*t)
    y = (p1.y + p1.dy*t) - (p2.y + p2.dy*t)
    z = (p1.z + p1.dz*t) - (p2.z + p2.dz*t)
    return (x**2 + y**2 + z**2)**0.5

class Point():
    def __init__(self):
        self.x = 0
        self.y = 0
        self.z = 0
        self.dx = 0
        self.dy = 0
        self.dz = 0
        self.r = 0

tc = int(raw_input())
for t in range(tc):
    p1 = Point()
    p2 = Point()

    p1.x, p1.y, p1.z, p1.r, p1.dx, p1.dy, p1.dz = map(float,raw_input().split())
    p2.x, p2.y, p2.z, p2.r, p2.dx, p2.dy, p2.dz = map(float,raw_input().split())
    d = p1.r + p2.r

    lo = 0
    hi = 1e30
    # binary search to determine the smallest distance between p1 and p2
    for i in range(500):
        mi = (lo+hi)/2
        a = (lo+mi)/2
        b = (mi+hi)/2
        # if time `a` gets us a smaller distance,
        # use the lower half and bump hi limit to mi
        if dist(p1, p2, a) < dist(p1, p2, b):
            hi = mi
        # otherwise time `b` gets us a smaller/equal distance,
        # use the upper half and bump lo limit to mi
        else:
            lo = mi
   
    # if the distance is still too big or we're still looking for big times,
    # spheres will never collide
    if dist(p1, p2, lo) > d or hi == 1e30:
        print 'No collision'
    # it's possible we have the larger collision time - the second time the
    # surfaces touch after the spheres pass through each other
    # let's do another binary search using this upper limit
    else:
        lo = 0
        for i in range(500):
            mi = (lo+hi)/2
            if dist(p1, p2, mi) < d:
                hi = mi
            else:
                lo = mi
        print '{:.3f}'.format(lo)
    
