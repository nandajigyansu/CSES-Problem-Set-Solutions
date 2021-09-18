#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int> > dp;

int solve(int* a, int l, int r) {
    if (l > r) return 0;
    if (l == r) return a[l];
    if (dp[l][r] != -1) return dp[l][r];
    int subres1 = a[l] + min(solve(a, l + 2, r), solve(a, l + 1, r - 1));
    int subres2 = a[r] + min(solve(a, l + 1, r - 1), solve(a, l, r - 2));
    return dp[l][r] = max(subres1, subres2);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp.resize(n, vector<int>(n, -1));
    int res = solve(a, 0, n - 1);
    cout << res << "\n";
    return 0;
}
