#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    int price[n];
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    int page[n];
    for (int i = 0; i < n; i++) {
        cin >> page[i];
    }
    vector<vector<int> > dp(n + 1, vector<int>(x + 1, 0));
    /* dp[i][j]: maximum pages you can buy with budget j from first i books */
    for (int numBooks = 1; numBooks <= n; numBooks++) {
        for (int budget = 1; budget <= x; budget++) {
            dp[numBooks][budget] = dp[numBooks - 1][budget];
            if (price[numBooks - 1] <= budget) {
                dp[numBooks][budget] = max(dp[numBooks][budget], page[numBooks - 1] + dp[numBooks - 1][budget - price[numBooks - 1]]);
            }
        }
    }
    cout << dp[n][x];
    return 0;
}
