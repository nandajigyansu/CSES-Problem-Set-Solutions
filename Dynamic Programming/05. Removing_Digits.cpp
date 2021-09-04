#include <bits/stdc++.h>
using namespace std;
#define nl  "\n"
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define int long long
#define skip continue
#define pf  push_front
#define ld  long double
#define pii pair<int, int>
#define all(v)  (v).begin(), (v).end()
#define PI  3.141592653589793238462
#define fr(i, N)    for (int i = 0; i < (int) N; i++)
#define frr(i, A, B)    for (int i = (int) A; i <= (int) B; i++)
#define fro(i, A, B)    for (int i = (int) A; i >= (int) B; i--)

void fileIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int _gcd(int A, int B) { return (B) ? _gcd(B, A % B) : A; }
int _lcm(int A, int B) { return A * B / _gcd(A, B); }
int max(int A, int B) { return (A >= B) ? A : B; }
int min(int A, int B) { return (A <= B) ? A : B; }

int bpow(int A, int B) { int res = 1; while (B > 0) { if (B & 1) { res = res * A; } A = A * A; B = B >> 1; } return res; }
int bpow(int A, int B, int MOD) { int res = 1; A %= MOD; while (B > 0) { if (B & 1) { res = (res * A) % MOD; } A = (A * A) % MOD; B = B >> 1; } return res; }
int exGCD(int A, int B, int& X, int& Y) { if (B == 0) { X = 1; Y = 0; return A; } int X1, Y1; int gcd = exGCD(B, A % B, X1, Y1); X = Y1; Y = X1 - (Y1 * (A / B)); return gcd; }
int modInv(int A, int M) { int X, Y; int gcd = exGCD(A, M, X, Y); if (gcd != 1) { cout << "A and M are NOT coprime" << "\n"; return -1; } else { return (X % M + M) % M; } }
int modInvFormat(int A, int M) { return bpow(A, M - 2, M); } // Assert M is prime

const int inf = (int)1e17;
const int ninf = -(int)1e17;
const int mod = (int)1e9 + 7;
const int mod2 = 998244353;

/* ----------------------------( solution )---------------------------- */


vector<int> getDigit(int n) {
    vector<int> v;
    while (n) {
        v.pb(n % 10);
        n /= 10;
    }
    return v;
}

void solve(int T = 0) {
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    frr(i, 1, min(n, 9)) {
        dp[i] = 1;
    }
    frr(i, 10, n) {
        dp[i] = inf;
        auto v = getDigit(i);
        for (auto j : v) {
            if (j) {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }
    cout << dp[n];
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    fileIO();
    // cin >> T;
    while (T--) {
        solve(T);
    }
    return 0;
}
