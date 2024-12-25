#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

int main() {
    ll t;
    std::cin >> t;
    while (t--) {
        ll n;
        std::cin >> n;
        std::vector<ll> a(n);
        for (ll p = 0; p < n; p++) {
            std::cin >> a[p];
        }

        ll mod(0);
        for (ll t = 2; !mod && t < 3e18; t *= 2) {
            std::set<ll> s;
            for (ll p = 0; s.size() < 3 && p < n; p++) {
                s.insert(a[p] % t);
            }
            if (s.size() == 2) {
                mod = t;
                break;
            }
        }

        std::cout << mod << std::endl;
    }

    return 0;
}