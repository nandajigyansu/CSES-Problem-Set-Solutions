#include <bits/stdc++.h>
using namespace std;

const int nodes = 2e5 + 1;
vector<int> tr[nodes];
int dp1[nodes];
int dp2[nodes];
int height[nodes];

void dfs(int u, int p) {
    bool isLeaf = 1;
    vector<int> depth;
    for (int v : tr[u]) {
        if (v != p) {
            dfs(v, u);
            isLeaf = 0;
            height[u] = max(height[u], 1 + height[v]);
            depth.push_back(height[v]);
            dp1[u] = max(dp1[u], max(dp1[v], dp2[v]));
        }
    }
    if (isLeaf) return;
    sort(begin(depth), end(depth), greater<int>());
    if (depth.size() == 1) {
        dp2[u] = 1 + depth[0];
    }
    else if (depth.size() >= 2) {
        dp2[u] = 2 + depth[0] + depth[1];
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
