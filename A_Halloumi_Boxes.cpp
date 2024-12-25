#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    
    if (is_sorted(v.begin(), v.end())) {
        cout << "YES" << endl;
    } else if (n > 1 && k < 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int TC;
    cin >> TC;
    while (TC--) solve();
    
    return 0;
}