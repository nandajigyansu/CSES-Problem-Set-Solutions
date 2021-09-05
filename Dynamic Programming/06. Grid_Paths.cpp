#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s;
    char a[n][n];
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }
    int dp[n][n];
    dp[0][0] = (a[0][0] == '.') ? 1 : 0;
    for (int j = 1; j < n; j++) {
        dp[0][j] = (a[0][j] == '.' && dp[0][j - 1] == 1) ? 1 : 0;
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = (a[i][0] == '.' && dp[i - 1][0] == 1) ? 1 : 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = (a[i][j] == '.') ? (dp[i - 1][j] + dp[i][j - 1]) % mod : 0;
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}
