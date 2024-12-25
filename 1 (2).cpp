#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

int main() {
    fast;
    ll n;
    cin >> n;
    cout << n << " ";
    
    unordered_map<int, int> mp;
    while (n != 1) {
        if (mp.find(n) != mp.end()) {
            n = mp[n];
        } else {
            ll next_n;
            if (n % 2 == 0) {
                next_n = n / 2;
            } else {
                next_n = 3 * n + 1;
            }
            mp[n] = next_n;
            n = next_n;
        }
        cout << n << " ";
    }

    return 0;
}
