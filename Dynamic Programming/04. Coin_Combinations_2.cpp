#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int dp[n + 1][x + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j == 0) {
                dp[i][j] = 1;
            }
            else {
                // don't use the coin
                int subres1 = (i == 0) ? 0 : dp[i - 1][j];
                // use the coin
                int subres2 = (i == 0) ? 0 : ((c[i - 1] > j) ? 0 : dp[i][j - c[i - 1]]);
                dp[i][j] = (subres1 + subres2) % mod;
            }
        }
    }
    cout << dp[n][x];
    return 0;
}
