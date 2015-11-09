#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, x;
    deque<int> seq;

    while (cin >> n >> s)
    {
        // start off 
        int ans = 100001, sum = 0;
        seq.clear();
        while (n--)
        {
            // move right end of window to include more elements
            cin >> x;
            seq.push_back(x);
            sum += x;

            // remove elements from left end of window if `sum` > `s`
            // and decrement `sum`
            while (sum - seq.front() > s)
            {
                sum -= seq.front();
                seq.pop_front();
            }

            // calculate length of window
            if (sum >= s)
                ans = min(ans, (int)seq.size());
        }
        if (ans == 100001) cout << 0 << endl;
        else cout << ans << endl;
    }
}
