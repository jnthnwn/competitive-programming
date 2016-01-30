#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x, y;
    cin >> N;
    vector<bool> row(N);
    vector<bool> column(N);
    vector<pair<int, int> > queens(N);
    bool okay = true;

    for (int n = 0; n < N; n++) {
        cin >> x >> y;

        // check first if any queen occupies row y or column x
        if (row[y] || column[x] ) {
            okay = false;
            break;
        }
        // for every queen we've looked at before, we can see if
        // they lie on the same diagonal by determining if
        // the x distance and the y distance are the same
        for (pair<int, int> queen : queens) {
            if (abs(x - queen.first) == abs(y - queen.second)) {
                okay = false;
                break;
            }
        }

        row[y] = true;
        column[x] = true;
        queens.push_back(make_pair(x, y));
    }

    cout << (okay ? "CORRECT" : "INCORRECT") << endl;
}
