#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;

        if (l == r) {
            cout << 1 << endl;
            continue;
        }
        
//PLZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ HOJAAAAAAAAAAAAAAAAA
        ll maxLen = 1;
        ll diff = r - l;
        
        // We solve k * (k - 1) / 2 <= diff which is equivalent to solving quadratic equation
        maxLen = floor((-1 + sqrt(1 + 8 * diff)) / 2) + 1;
       //REVISE FORMULA
       //DUMB ME 
        cout << maxLen << endl;
    }
    return 0;
}