#include <bits/stdc++.h>
using namespace std;

int l, w, n, r, x, y;

// given the x and y coordiantes of a crane,
// return a bitset that represents which walls it can reach
// 
// that is, if the distance between the crane and then middle of the wall
// is less than the radius of the crane, that wall can be reached
bitset<4> reaches(int x, int y)
{
    bitset<4> res (0x0);

    // important to include `.0` to avoid integer division errors!

    // west wall
    if (hypot(x-(l/2.0), y) <= r)
    {
        res.set(0);
    }
    // easy wall
    if (hypot(x+(l/2.0), y) <= r)
    {
        res.set(1);
    }
    // south wall
    if (hypot(x, y-(w/2.0)) <= r)
    {
        res.set(2);
    }
    // north wall
    if (hypot(x, y+(w/2.0)) <= r)
    {
        res.set(3);
    }
    
    return res;
}

int main()
{
    // eat your input
    cin >> l >> w >> n >> r;
    bitset<4> cranes[n];

    // keep track of which walls each crane can reach
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        cranes[i] = reaches(x, y);
    }

    // respectively, this is all four walls and zero walls:
    // 1111
    // 0000
    bitset<4> all_covered (0xf);
    bitset<4> none_covered (0x0);

    // the smallest number you should ever need to reach 4 walls is 4
    // this 4+1, so if we can't cover all walls,
    // this will be our final, *incorrect* answer
    int min_cranes = 5;

    // go through all possibilities of 1-, 2-, 3-, and 4- crane combos
    // always choosing the minimum answer
    //
    // for every combo, you are doing a bitwise OR to see if this
    // combo of cranes can reach all 4 walls
    for (int i1 = 0; i1 < n; i1++)
    {
        bitset<4> covered1 = (none_covered | cranes[i1]);
        if (covered1 == all_covered)
        { min_cranes = min(min_cranes, 1); }

        for (int i2 = i1 + 1; i2 < n; i2++)
        {
            bitset<4> covered2 = (covered1 | cranes[i2]);
            if (covered2 == all_covered)
            { min_cranes = min(min_cranes, 2); } 

            for (int i3 = i2 + 1; i3 < n; i3++)
            {
                bitset<4> covered3 = (covered2 | cranes[i3]);
                if (covered3 == all_covered)
                { min_cranes = min(min_cranes, 3); }

                for (int i4 = i3 + 1; i4 < n; i4++)
                {
                    bitset<4> covered4 = (covered3 | cranes[i4]);
                    if (covered4 == all_covered)
                    { min_cranes = min(min_cranes,4); }
                }
            }
        }
    }

    // print out the answer if less than 5, otherwise "Impossible"
    cout << (min_cranes == 5 ? "Impossible" : to_string(min_cranes)) << endl;
}
