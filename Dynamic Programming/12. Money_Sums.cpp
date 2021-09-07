#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<vector<bool> > dp(n + 1, vector<bool>(100001, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    unordered_set<int> st;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100000; j++) {
            dp[i][j] = dp[i - 1][j];
            if (x[i - 1] <= j) {
                dp[i][j] = dp[i][j] | dp[i - 1][j - x[i - 1]];
            }
            if (dp[i][j]) {
                if (st.find(j) == st.end()) {
                    st.insert(j);
                    ans.push_back(j);
                }
            }
        }
    }
    cout << ans.size() << endl;
    sort(begin(ans), end(ans));
    for (int k : ans) {
        cout << k << " ";
    }
    return 0;
}
