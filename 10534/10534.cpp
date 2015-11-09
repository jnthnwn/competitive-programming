#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int seq[n];
        vector<int> lis;
        vector<int> increasing;
        vector<int> decreasing;
        
        for (int i = 0; i < n; i++)
        {
            cin >> seq[i];
        }

        // build up longest increasing subsequence from left to right
        for (int x : seq)
        {
            auto it_index = lower_bound(lis.begin(), lis.end(), x);
            if (it_index == lis.end()) lis.push_back(x);
            else (*it_index) = x;

            increasing.push_back(lis.size());
        }

        // build up longest increasing subsequence from right to left,
        // aka longest decreasing subsequence
        lis.clear();
        reverse(seq, seq+n);
        for (int x : seq)
        {
            auto it_index = lower_bound(lis.begin(), lis.end(), x);
            if (it_index == lis.end()) lis.push_back(x);
            else *it_index = x;

            decreasing.push_back(lis.size());
        }
        reverse(decreasing.begin(), decreasing.end());

        // find an element with maximum matching length of LIS and LDS,
        // like the 'peak' of the wavio sequence
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (increasing[i] == decreasing[i])
                ans = max(ans, increasing[i]);
        }

        cout << ans * 2 - 1<< endl;
    }
}
