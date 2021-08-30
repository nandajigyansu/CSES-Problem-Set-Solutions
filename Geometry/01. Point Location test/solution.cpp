#include <bits/stdc++.h>
using namespace std;
#define int long long

struct P {

    int x, y;

    P() {}

    P(int x, int y) : x(x), y(y) {}

    void read() {
        cin >> x >> y;
    }

    P& operator+=(const P& p) {
        x += p.x;
        y += p.y;
        return *this;
    }

    P& operator-=(const P& p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    P operator+(const P& p) const {
        return P(*this) += p;
    }

    P operator-(const P& p) const {
        return P(*this) -= p;
    }
};

int crossProduct(P a, P b) {
    return (a.x * b.y - a.y * b.x);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    P a, b, c;
    while (T--) {
        a.read();
        b.read();
        c.read();
        b -= a;
        c -= a;
        int value = crossProduct(b, c);
        if (value == 0) {
            cout << "TOUCH" << "\n";
        }
        else if (value < 0) {
            cout << "RIGHT" << "\n";
        }
        else {
            cout << "LEFT" << "\n";
        }
    }
    return 0;
}
