#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

int main() {
    fast;
    string s;
    cin >> s;
    ll n = s.length();
    ll m = 1, c = 1; 

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            m = max(m, c);
            c = 1; // Reset count to 1 for the new character sequence
        } else {
            c++;
        }
    }
    m = max(m, c); // Check the last sequence
    cout << m;

    return 0;
}