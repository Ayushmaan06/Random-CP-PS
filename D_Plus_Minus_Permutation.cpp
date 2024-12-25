#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define multicase int NoOfTestCase = 1; cin >> NoOfTestCase; for (int testcaseno = 1; testcaseno <= NoOfTestCase; testcaseno++)

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return abs(a * b) / gcd(a, b);
}

ll rangesum(ll L, ll R) {
    return ((L + R) * (abs(R - L) + 1)) / 2;
}

void solve() {
    ll n, x, y, c;
    cin >> n >> x >> y;
    if (gcd(x, y) == 1) {
        c = n / (x * y);
    } else {
        c = n / lcm(x, y);
    }
    ll a, b;
    a = (n / x) - c; // positive
    b = (n / y) - c; // negative
    b = b * (b + 1) / 2;
    if (a > 0) {
        a = rangesum(n - a + 1, n);
        cout << a - b << '\n';
    } else {
        a = abs(a);
        a = a * (a + 1) / 2;
        cout << -a - b << '\n';
    }
}

int32_t main() {
    fastio
    multicase {
        solve();
    }
    return 0;
}