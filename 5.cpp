#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

int main() {
    fast;
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "1";
    } else if (n == 2 || n == 3 ) {
        cout << "NO SOLUTION";
    } else {
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
    }
    return 0;
}