#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int solve(int n, vector<int>& a) {
    vector<vector<int>> dp(n, vector<int>(2, 0));

    dp[0][0] = a[0];
    dp[0][1] = a[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i] * (i + 1);
        dp[i][1] = a[i] * i + a[i - 1] * (i + 1) + (i - 2 >= 0 ? max(dp[i - 2][0], dp[i - 2][1]) : 0);
    }

    return max(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
    fast;
    int t; cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << solve(n, a) << endl;
    }
    return 0;
}
