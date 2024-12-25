#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        ll prev = 0;
        ll m = 0;
        ll c;
        for (int i = 0; i < n; i++) {
            cin >> c;
            m = max(m, c - prev);
            prev = c;
        }
        m = max(m, 2 * (x - prev));
        cout << m << endl;
    }
}