#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    int dp[a + 1][b + 1];
    for (int i = 0; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = inf;
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
                }
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                }
            }
        }
    }
    cout << dp[a][b];
    return 0;
}
