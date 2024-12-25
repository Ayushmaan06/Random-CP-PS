#include <algorithm>
#include <iostream>
#include <vector>

int solve(int n, std::vector<int>& a) {
    int res = 0;
    std::sort(a.begin(), a.end());
    for(int i = 1; i <= n; i++) {
        res += std::abs((i - 1) - a[i - 1]);
    }
    return res;
}

// Example usage:
int main() {
    int T;
    std::cin >> T;
    for(int t = 0; t < T; t++) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::cout << solve(n, a) << "\n";
    }
    return 0;
}