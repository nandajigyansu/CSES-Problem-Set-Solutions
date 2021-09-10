#include <bits/stdc++.h>
using namespace std;
 
const int nodes = 2e5 + 1;
const int LOG = 20;
vector<int> tr[nodes];
int dp[nodes][LOG + 1];
int n, q;
 
void dfs(int u, int p) {
    dp[u][0] = p;
    for (int i = 1; i <= LOG; i++) {
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    for (int v : tr[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}
 
int solve(int x, int k) {
    for (int i = LOG; i >= 0; i--) {
        if (k >= (1 << i)) {
            x = dp[x][i];
            k -= (1 << i);
        }
    }
    return (x == 0) ? -1 : x;
}
 
int main() {
    cin >> n >> q;
    int e, x, k;
    for (int i = 2; i <= n; i++) {
        cin >> e;
        tr[i].push_back(e);
        tr[e].push_back(i);
    }
    dfs(1, 0);
    while (q--) {
        cin >> x >> k;
        cout << solve(x, k) << "\n";
    }
    return 0;
}
