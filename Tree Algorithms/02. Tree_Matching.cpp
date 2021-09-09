#include <bits/stdc++.h>
using namespace std;

const int nodes = 2e5 + 1;
vector<int> tr[nodes];
int dp1[nodes];
int dp2[nodes];

void dfs(int u, int p) {
    dp1[u] = 0;
    bool isLeaf = 1;
    for (int v : tr[u]) {
        if (v != p) {
            dfs(v, u);
            isLeaf = 0;
            dp1[u] += max(dp1[v], dp2[v]);
        }
    }
    if (isLeaf) return;
    for (int v : tr[u]) {
        if (v != p) {
            int value = dp1[u] - max(dp1[v], dp2[v]) + 1 + dp1[v];
            dp2[u] = max(dp2[u], value);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp1[1], dp2[1]);
    return 0;
}
