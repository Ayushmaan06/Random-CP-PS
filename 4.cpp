#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

int main() {
    fast;
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll moves = 0;
    for (int i = 1; i < n; i++) {
        if (x[i] < x[i - 1]) {
            moves += x[i - 1] - x[i];
            x[i] = x[i - 1];
        }
    }

    cout << moves << "\n";
    return 0;
}