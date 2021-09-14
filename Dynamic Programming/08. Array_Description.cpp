#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<vector<int> > dp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    dp.assign(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        if (x[i] == 0) {
            if (i == 0) {
                for (int j = 1; j <= m; j++) {
                    dp[i][j] = 1;
                }
            }
            else {
                for (int j = 1; j <= m; j++) {
                    dp[i][j] = dp[i - 1][j];
                    if (j - 1 >= 1) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                    }
                    if (j + 1 <= m) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                    }
                }
            }
        }
        else {
            if (i == 0) {
                dp[i][x[i]] = 1;
            }
            else {
                dp[i][x[i]] = dp[i - 1][x[i]];
                if (x[i] - 1 >= 1) {
                    dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] - 1]) % mod;
                }
                if (x[i] + 1 <= m) {
                    dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] + 1]) % mod;
                }
            }
        }
    }
    int res = 0;
    for (int j = 1; j <= m; j++) {
        res = (res + dp[n - 1][j]) % mod;
    }
    cout << res;
    return 0;
}
