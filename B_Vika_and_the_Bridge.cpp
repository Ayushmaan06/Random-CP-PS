#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; 
    while (t--) {
        int n, k;
        cin >> n >> k; 
        vi a(n);
        for (auto &i : a) cin >> i;

        map<int, vector<int>> mv; 
        map<int, int> met;
        for (int i = 0; i < n; ++i) {
            int diff = i + 1 - met[a[i]];
            mv[a[i]].push_back(diff - 1);
            met[a[i]] = i + 1;
        }
        for (int i = 0; i < k; ++i) {
            int diff = n + 1 - met[i + 1];
            mv[i + 1].push_back(diff - 1);
        }
        int ans = INT_MAX;
        for (auto &pair : mv) {
            auto &v = pair.second;
            sort(v.begin(), v.end());
            int mx = v.back() / 2;
            int mn = (v.size() >= 2) ? v[v.size() - 2] : 0;
            ans = min(ans, max(mx, mn));
        }
        cout << ans << "\n";
    }
    return 0;
}