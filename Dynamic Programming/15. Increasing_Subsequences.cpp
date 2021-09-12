#include <bits/stdc++.h>
using namespace std;
 
int search(vector<int>& v, int k) {
    int lo = -1;
    int hi = v.size();
    while (hi > lo + 1) {
        int mid = (lo + hi) >> 1;
        if (v[mid] < k) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    return hi;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp;
    /*
    dp[x]: minimum ending value of an increasing
    subsequence of length x+1
    */
    for (int i = 0; i < n; i++) {
        int x = search(dp, a[i]);
        if (x == dp.size()) {
            dp.push_back(a[i]);
        }
        else {
            dp[x] = a[i];
        }
    }
    cout << dp.size();
    return 0;
}
