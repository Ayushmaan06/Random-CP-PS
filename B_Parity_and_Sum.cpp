#include <bits/stdc++.h>
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll lo = 0; 
    ll le = 0; 

    // Find largest odd and even numbers
    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 1 && a[i] > lo) lo = a[i];
        if (a[i] % 2 == 0 && a[i] > le) le = a[i];
    }

    int c = 0;
    bool all_same_parity = true;
    for (ll i = 1; i < n; i++) {
        if (a[i] % 2 != a[0] % 2) {
            all_same_parity = false;
            break;
        }
    }

    if (all_same_parity) {
        cout << 0 << "\n";
        return;
    }

    sort(a.begin(), a.end());
    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] < lo) {
            c++;
            a[i] = a[i] + lo;
            lo = max(lo, a[i]);
        }
    }

    all_same_parity = true;
    for (ll i = 1; i < n; i++) {
        if (a[i] % 2 != a[0] % 2) {
            all_same_parity = false;
            break;
        }
    }

    if (all_same_parity) {
        cout << c << "\n";
        return;
    }

    ll indx = 0; // index of largest odd
    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 1 && a[i] == lo) {
            indx = i;
            break;
        }
    }

    a[indx] = lo + le;
    c++;

    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            c++;
        }
    }

    cout << c << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}