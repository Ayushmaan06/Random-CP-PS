#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

int processString(const string& s) {
    int maxConsecutiveDots = 0;
    int currentConsecutiveDots = 0;
    int totalDots = 0;

    for (char c : s) {
        if (c == '.') {
            currentConsecutiveDots++;
            totalDots++;
            if(currentConsecutiveDots == 3) {
                return 2;
            }
        } else if (c == '#') {
            if (currentConsecutiveDots > maxConsecutiveDots) {
                maxConsecutiveDots = currentConsecutiveDots;
            }
            currentConsecutiveDots = 0;
        }
    }

    if (currentConsecutiveDots > maxConsecutiveDots) {
        maxConsecutiveDots = currentConsecutiveDots;
    }

    if (maxConsecutiveDots >= 3) {
        return 2;
    } else {
        return totalDots;
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << processString(s) << endl;
    }
    return 0;
}