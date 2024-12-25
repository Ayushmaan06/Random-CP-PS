#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculatePathSum(ll u, ll N) {
    ll sum = 0, steps = 0;
    while (u > 0 && steps < N) {
        sum += u;
        u /= 2; // Move to the parent node
        steps++;
    }
    return sum;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        ll N, X;
        cin >> N >> X;

        ll left = 1, right = X, result = -1;

        while (left <= right) {
            ll mid = (left + right) / 2;

            ll pathSum = calculatePathSum(mid, N);

            if (pathSum == X) {
                result = mid;
                break; // Found a valid starting node
            } else if (pathSum < X) {
                left = mid + 1; // Search higher
            } else {
                right = mid - 1; // Search lower
            }
        }

        cout << result << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
