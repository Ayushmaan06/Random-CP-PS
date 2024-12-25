#include <bits/stdc++.h>
using namespace std;

int maxSumNonAdjacent(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = max(0, grid[0][0]);
    for (int j = 1; j < m; ++j) {
        dp[0][j] = max(dp[0][j - 1], grid[0][j]);
    }
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], grid[i][0]);
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], grid[i][j]});
        }
    }

    int result = 0;
    for (int j = 0; j < m; ++j) {
        result = max(result, dp[n - 1][j]);
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << maxSumNonAdjacent(grid) << endl;
    return 0;
}