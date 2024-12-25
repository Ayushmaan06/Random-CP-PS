#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << v[0] << endl;
        return 0;
    }

    vector<int> dp(n + 1, 0);
    dp[1] = v[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-1], v[i-1] + dp[i-2]);
    }

    cout << dp[n] << endl;
    return 0;
}