#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int nodes = 2e5 + 2;
vector<int> tr[nodes];
int n, a, b;
 
int parent[nodes];  // parent[u]: parent node of node u
int sub[nodes];     // sub[u]: size of subtree rooted at u
int dp1[nodes];     // dp1[u]: sum of distances between u and all nodes in subtree rooted at u
int dp2[nodes];     // dp2[u]: sum of distances between u and all nodes NOT PRESENT in subtree rooted at u
 
void dfs1(int u, int p) {
    parent[u] = p;
    for (int v : tr[u]) {
        if (v != p) {
            dfs1(v, u);
            sub[u] += sub[v];
            dp1[u] += (dp1[v] + sub[v]);
        }
    }
    sub[u]++;
}
 
void dfs2(int u, int p) {
    if (u != 1) {
        dp2[u] += (dp2[p] + n - sub[p] + 1);
    }
    for (int v : tr[p]) {
        if (v != u && v != parent[p]) {
            dp2[u] += (dp1[v] + (2 * sub[v]));
        }
    }
    for (int v : tr[u]) {
        if (v != p) {
            dfs2(v, u);
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << (dp1[i] + dp2[i]) << " ";
    }
 
    return 0;
}
