#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int solve(int sum, int i, int n) {
    if (sum == 0) return 1;
    if (i > n) return 0;
    return solve(sum, i + 1, n) + solve(sum - i, i + 1, n);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int k = (n * (n + 1)) / 2;
    if (k % 2) {
        cout << 0;
    }
    else {
        k /= 2;
        int dp[k + 1][n + 1];
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= k; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j - 1];
                if (i >= j) {
                    dp[i][j] = (dp[i][j] + dp[i - j][j - 1]) % mod;
                }
            }
        }
        int res = (dp[k][n] * 500000004) % mod;
        cout << res;
    }
    return 0;
}
