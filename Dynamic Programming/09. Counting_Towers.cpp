#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1000001][2];
const int mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < 1000001; i++) {
        dp[i][0] = ((dp[i - 1][0] * 4) % mod + dp[i - 1][1] % mod) % mod;
        dp[i][1] = (dp[i - 1][0] % mod + (2 * dp[i - 1][1]) % mod) % mod;
    }
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        int res = (dp[N][0] + dp[N][1]) % mod;
        cout << res << "\n";
    }
    return 0;
}
