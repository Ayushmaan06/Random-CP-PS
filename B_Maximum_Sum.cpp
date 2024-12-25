#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

const ll MOD = 1e9 + 7;

ll power(ll a, ll b, ll m) {
    a %= m;
    if (a == 1 || b == 0) return 1;
    ll res = power(a, b / 2, m);
    res %= m;
    if (b % 2 == 1) {
        return ((res * res) % m * a) % m;
    }
    return (res * res) % m;
}

ll mod_mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll mod_add(ll a, ll b) {
    return (a + b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll test;
    cin >> test;
    for (ll _ = 0; _ < test; _++) {
        ll n, k;
        cin >> n >> k;
        vi vec(n);
        for (ll i = 0; i < n; i++) cin >> vec[i];
        ll mx = 0;
        for (ll i = 0; i < n; i++) {
            mx += vec[i];
            if (mx < 0) mx += MOD;
        }
        ll cr_sm = 0;
        ll max_pa = 0;
        for (ll i = 0; i < n; i++) {
            cr_sm += vec[i];
            if (cr_sm < 0) cr_sm = 0;
            max_pa = max(max_pa, cr_sm);
        }
        ll ans = 0;
        if (max_pa > 0) {
            max_pa %= MOD;
            ll ptwo = mod_add(power(2, k, MOD), -1);
            ans = mod_mul(max_pa, ptwo);
            ans = mod_add(ans, mx);
            if (ans < 0) ans += MOD;
        } else {
            ans = mx;
            if (ans < 0) ans += MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
