#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        
        // Calculate the required coins to open the "Profitable" deposit
        int req = max(b - a, (ll)0);
        
        // Calculate the maximum coins Alice can deposit into the "Profitable" deposit
        cout << max(a - req, (ll)0) << endl;
    }
    return 0;
}