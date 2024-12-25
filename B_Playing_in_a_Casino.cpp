#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

int sumOfAbsoluteDifferences(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Transpose the matrix
    vector<vector<int>> transposed(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    int totalSum = 0;
    for (auto& row : transposed) {
        sort(row.begin(), row.end());
        vector<int> prefixSum(row.size() + 1, 0);
        for (size_t i = 0; i < row.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + row[i];
        }

        int rowSum = 0;
        for (size_t i = 0; i < row.size(); ++i) {
            rowSum += row[i] * i - prefixSum[i];
            rowSum += (prefixSum[row.size()] - prefixSum[i + 1]) - row[i] * (row.size() - i - 1);
        }
        totalSum += rowSum;
    }

    return totalSum;
}

int main(void) {
    fast;
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (auto& row : matrix) {
            for (auto& cell : row) {
                cin >> cell;
            }
        }
        cout << sumOfAbsoluteDifferences(matrix)/2 << endl;
    }
    return 0;
}