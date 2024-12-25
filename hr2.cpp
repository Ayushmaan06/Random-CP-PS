#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    int N = A.size();
    vector<vector<int>> dp(2, vector<int>(N, 0));
    dp[0][0] = A[0];
    dp[1][0] = max(A[0], B[0]);
    
    for (int j = 1; j < N; ++j) {
        dp[0][j] = max(dp[0][j - 1], A[j]);
        dp[1][j] = min(max(dp[0][j], B[j]), max(dp[1][j - 1], B[j]));
    }
    
    return dp[1][N - 1];
} 

int main(){
    fast;
    int t; 
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        cout << solution(A, B) << endl;
    }

    return 0;
}
