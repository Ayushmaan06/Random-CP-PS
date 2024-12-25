#include <bits/stdc++.h>
using namespace std;

#define fast_io            ios::sync_with_stdio(false), cin.tie(NULL)
#define vi                 vector<int>
#define ln                 "\n"

int main(void) {
    fast_io;

    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        vi a(n);
        for (auto &i : a) cin >> i; 

        if (count(a.begin(), a.end(), a[0]) == n) {
            cout << 1 << ln;
            continue;
        }

        int cnt = 2;
        for (int i = 1; i < n;) {
            if (a[i] > a[i - 1]) {
                while (i < n && a[i] >= a[i - 1]) ++i;
                if (i < n) ++cnt;
            } else if (a[i] < a[i - 1]) {
                while (i < n && a[i] <= a[i - 1]) ++i;
                if (i < n) ++cnt;
            } else ++i;
        }
        cout << cnt << ln;
    }
    return 0;
}
