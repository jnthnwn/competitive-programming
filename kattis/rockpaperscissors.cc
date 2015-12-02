#include <bits/stdc++.h>
using namespace std;

int n, k, p1, p2;
string m1, m2;
// you can expect to track a player i's wins/losses, 1 <= i <= 100
int wins[101];
int losses[101];

int main()
{
    // while n != 0
    while (cin >> n && n)
    {
        // don't forget to wipe out these arrays
        // at the start of each test case
        fill(wins, wins+101, 0);
        fill(losses, losses+101, 0);

        cin >> k;
        int games = k*n*(n-1)/2;
        while (games--)
        {
            cin >> p1 >> m1 >> p2 >> m2;
            if ((!m1.compare("rock") && !m2.compare("scissors")) ||
                (!m1.compare("scissors") && !m2.compare("paper")) ||
                (!m1.compare("paper") && !m2.compare("rock")))
            {
                wins[p1]++; losses[p2]++;
            }
            else if ((!m2.compare("rock") && !m1.compare("scissors")) ||
                (!m2.compare("scissors") && !m1.compare("paper")) ||
                (!m2.compare("paper") && !m1.compare("rock")))
            {
                wins[p2]++; losses[p1]++;
            }
        }

        for (int i = 1; i < n+1; i++)
        {
            if (wins[i] + losses[i] == 0)
            {
                cout << "-" << endl;
            }
            else
            {
                printf("%.3f\n", double(wins[i])/(wins[i]+losses[i]));
            }
        }
    }
}
