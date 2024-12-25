#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        if (a % 2 == 0 && (b % 2 == 0 || a != 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}