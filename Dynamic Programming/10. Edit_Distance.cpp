#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    int m = a.length();
    int n = b.length();
    int dp[m + 1][n + 1];
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    cout << dp[m][n];
    return 0;
}
