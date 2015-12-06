#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, cd;
    while (scanf("%d %d", &n, &m) && n + m != 0)
    {
        vector<int> jack;
        // don't forget to clear this between test cases
        jack.clear();
        // adjust the size of your container
        jack.resize(n);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            // consume input, put into vector
            scanf("%d", &cd);
            jack[i] = cd;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &cd);
            // use binary search to find the cd in jack's collection
            // to avoid getting TLE since CD order is already sorted
            if (binary_search(jack.begin(), jack.end(), cd))
            {
                // if it's already there, we can sell this CD
                count++;
            }
        }
        printf("%d\n", count);
    }
}
