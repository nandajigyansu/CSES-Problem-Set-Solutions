#include <bits/stdc++.h>
using namespace std;

const int nodes = 2e5 + 1;
vector<int> tr[nodes];
int dp[nodes];

void dfs(int u, int p) {
    for (int v : tr[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u] += (1 + dp[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int u;
    for (int i = 2; i <= n; i++) {
        cin >> u;
        tr[u].push_back(i);
        tr[i].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    return 0;
}
