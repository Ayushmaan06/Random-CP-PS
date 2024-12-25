#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int main() {
    fast;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // Construct the sequence b
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += a[j];
            b.push_back(sum);
        }
    }


    // Compute prefix sums for b
    vector<long long> prefix_sum(b.size() + 1, 0);
    for (size_t i = 0; i < b.size(); ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + b[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Convert 1-based index to 0-based
        l--; r--;
        cout << prefix_sum[r + 1] - prefix_sum[l] << "\n";
    }

    return 0;
}