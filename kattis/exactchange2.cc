#include <bits/stdc++.h>
using namespace std;

// this DP table is structured like this:
// each index is the price you can achieve
// the value at the index is the number of coins used
int dp[1000001];

int main() {
  int T, N, price;
  cin >> T;
  for (int t = 0; t < T; t++) {
    // eat your input
    cin >> price;
    cin >> N;
    int coins[N];
    for (int n = 0; n < N; n++) {
      cin >> coins[n];
    }

    // we start off saying all of the prices are not reached
    fill(begin(dp), end(dp), -1);
    // except for a price of 0 - we get that literally for free
    // without using any coins
    dp[0] = 0;

    // so now we want to do this:
    // take coin i
    // look at every price j that we've been able to make so far
    // add the value of coin i to each of those prices
    for (int i = 0; i < N; i++) {
      for (int j = price-1; j >= 0; j--) {
        // skip this - we haven't been able to make j cents yet
        // so there's no point in working from there
        if (dp[j] == -1) {
          continue;
        }
        // if we get to this point, we've managed to make j cents
        // with all the previous coins
        //
        // let's add coin i to it. if we've never made this amount before,
        // then we used however many coins we used to make j, plus one more
        // or
        // if we made this amount with more coins than j+1,
        // e.g. 100 = 50+50 vs 100 = 10+10+80,
        // let's update our dp table with the better answer
        if (dp[j+coins[i]] == -1 || dp[j+coins[i]] > dp[j]+1) {
          dp[j+coins[i]] = dp[j]+1;
        }
      }
    }

    // start at our ideal solution, where we can make the price exactly
    // check if there was a solution using some number of coins to hit price
    // if not, keep increasing the lowest price we can reach
    int lowest_price = price;
    while (dp[lowest_price] == -1) {
      lowest_price++;
    }
    // our lowest price, and the coins to get to that price
    cout << lowest_price << " " << dp[lowest_price] << endl;

    // wow that's a lot of writing, i hope dp makes sense to you now
  }
}
