#include <bits/stdc++.h>
using namespace std;

const int nodes = 2e5 + 1;
const int LOG = 20;
vector<int> tr[nodes];
int dp[nodes][LOG + 1];
int in[nodes];
int out[nodes];
int dist[nodes];
int timer = 0;

void dfs(int u, int p, int d) {
    dist[u] = d;
    dp[u][0] = p;
    in[u] = ++timer;
    for (int i = 1; i <= LOG; i++) {
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    for (int v : tr[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
    out[u] = ++timer;
}

bool isAncestor(int u, int v) {
    return (in[u] <= in[v] && out[u] >= out[v]);
}

int LCA(int u, int v) {
    if (isAncestor(u, v)) {
        return u;
    }
    if (isAncestor(v, u)) {
        return v;
    }
    for (int i = LOG; i >= 0; i--) {
        if (!isAncestor(dp[u][i], v)) {
            u = dp[u][i];
        }
    }
    return dp[u][0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q, u, v;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    dfs(1, 1, 0);
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        int lca = LCA(u, v);
        int answer = dist[u] + dist[v] - 2 * dist[lca];
        cout << answer << "\n";
    }

    return 0;
}
