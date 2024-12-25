#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return root * root == n;
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
        
        if (!isPerfectSquare(n)) {
            cout << "No" << endl;
            continue;
        }
        
        int r = sqrt(n);
        bool isSquareMatrix = true;
        
        for (int i = 0; i < r; i++) {
            if (s[i] != '1' || s[n - r + i] != '1') {
                isSquareMatrix = false;
                break;
            }
        }
        
        // Check middle rows
        for (int i = r; i < n - r; i += r) {
            if (s[i] != '1' || s[i + r - 1] != '1') {
                isSquareMatrix = false;
                break;
            }
            for (int j = 1; j < r - 1; j++) {
                if (s[i + j] != '0') {
                    isSquareMatrix = false;
                    break;
                }
            }
        }
        
        cout << (isSquareMatrix ? "Yes" : "No") << endl;
    }
    return 0;
}