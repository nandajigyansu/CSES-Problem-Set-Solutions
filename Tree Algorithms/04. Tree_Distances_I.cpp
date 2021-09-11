#include <bits/stdc++.h>
using namespace std;

const int nodes = 2e5 + 1;
vector<int> tr[nodes];
int dist[nodes];

int bfs(int u) {
    queue<int> q;
    q.push(u);
    vector<int> d(nodes, -1);
    d[u] = 0;
    int endPoint = u;
    dist[u] = max(dist[u], d[u]);
    while (q.empty() == false) {
        u = q.front();
        q.pop();
        for (int v : tr[u]) {
            if (d[v] != -1) continue;
            d[v] = d[u] + 1;
            if (d[v] > d[endPoint]) {
                endPoint = v;
            }
            dist[v] = max(dist[v], d[v]);
            q.push(v);
        }
    }
    return endPoint;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    int endPoint1 = bfs(1);
    int endPoint2 = bfs(endPoint1);
    bfs(endPoint2);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
