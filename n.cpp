#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

int max_min_point(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> prefix_sum(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = prefix_sum[i];
    }

    for (int j = 1; j <= k; ++j) {
        dp[j][j] = *min_element(arr.begin(), arr.begin() + j);
    }

    for (int j = 2; j <= k; ++j) {
        for (int i = j; i <= n; ++i) {
            for (int m = j - 1; m < i; ++m) {
                int current_sum = prefix_sum[i] - prefix_sum[m];
                dp[i][j] = max(dp[i][j], min(dp[m][j - 1], current_sum));
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = max_min_point(arr, k);
    cout << result << endl;
    return 0;
}