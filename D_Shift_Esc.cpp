#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX

void solve() {
    int t;
    cin >> t;  // number of test cases
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        // Precompute all cyclic shifts for each row
        vector<vector<vector<int>>> row_shifts(n, vector<vector<int>>(m, vector<int>(m)));
        for (int i = 0; i < n; ++i) {
            for (int shift = 0; shift < m; ++shift) {
                for (int j = 0; j < m; ++j) {
                    row_shifts[i][shift][j] = grid[i][(j + shift) % m];
                }
            }
        }

        // DP table to store the minimum cost up to (i, j) with s shifts on row i
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(m, INF)));

        // Initialize the DP table for the first cell (1, 1)
        for (int s = 0; s < m; ++s) {
            dp[0][0][s] = row_shifts[0][s][0];  // The cost at (1, 1) after s shifts
        }

        // Fill the DP table
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int s = 0; s < m; ++s) {
                    // Moving right from (i, j-1)
                    if (j > 0) {
                        dp[i][j][s] = min(dp[i][j][s], dp[i][j-1][s] + row_shifts[i][s][j]);
                    }
                    // Moving down from (i-1, j)
                    if (i > 0) {
                        dp[i][j][s] = min(dp[i][j][s], dp[i-1][j][s] + row_shifts[i][s][j]);
                    }
                }
            }
        }

        // The result is the minimum cost to reach the bottom-right corner (n, m)
        long long result = INF;
        for (int s = 0; s < m; ++s) {
            result = min(result, dp[n-1][m-1][s] + k * s);  // Add cost for x operations
        }

        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();  // Solve all test cases
    
    return 0;
}
