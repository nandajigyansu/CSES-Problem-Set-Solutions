#include <bits/stdc++.h>
using namespace std;
#define int long long
 
struct P
{
	int x, y;
 
	P() {}
 
	P(int x, int y): x(x), y(y) {}
 
	void read() {
		cin >> x >> y;
	}
 
	P& operator+=(const P &t) {
		x += t.x;
		y += t.y;
		return *this;
	}
 
	P& operator-=(const P &t) {
		x -= t.x;
		y -= t.y;
		return *this;
	}
 
	P operator+(const P &t) const {
		return P(*this) += t;
	}
 
	P operator-(const P &t) const {
		return P(*this) -= t;
	}
 
	int operator*(const P &t) {
		return (x * t.y - y * t.x);
	}
};
 
 
 
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
		int d = b * c;
		if (d == 0) {
			cout << "TOUCH" << "\n";
		}
		else if (d > 0) {
			cout << "LEFT" << "\n";
		}
		else {
			cout << "RIGHT" << "\n";
		}
	}
 
	return 0;
}
