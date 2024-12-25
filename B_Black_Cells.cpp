#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#define fast_io std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
void fun(ll result){
    cout<<result<<endl;
}
// Function to determine if all required cells can be painted with a given k
bool can_paint(int n, const vector<ll>& cells, ll k) {
    vector<bool> dp_with_extra(n + 1, false);
        dp_with_extra[0] = false;
    int a[1]={0};
    vector<bool> dp_no_extra(n + 1 + a[0], false);
    
    dp_no_extra[a[0]] = true;


    for (int i = a[0]; i < n; ++i) {
        vector<bool> next_no_extra(n + 1 + a[0], false);

        vector<bool> next_with_extra(n + 1 + a[0], false);
        if (dp_no_extra[i + a[0]]) {
            if (i + 1 + a[0] < n && cells[i+a[0] + 1] - cells[i] <= k) {
                next_no_extra[i + 2+a[0]] = true;
            }
            if (k >= 1) {
                next_with_extra[i + a[0]+1] = true;
            }
        }


        if (dp_with_extra[i+a[0]]) {
            if (i + 1 < n && cells[i + 1] - cells[i] <= k) {
                next_with_extra[i + 2] = true;
            }
        }

        for (int j = a[0]; j <= n; ++j) {
            if (next_no_extra[j]) dp_no_extra[j] = true;
            if (next_with_extra[j]) dp_with_extra[j] = true;
        }
    }

    return dp_no_extra[n] || dp_with_extra[n];
}
void in(){
     int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> cells(n);
        for (auto &cell : cells) cin >> cell;

        ll left = 0, right = numeric_limits<ll>::max();
        ll result = right;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if (can_paint(n, cells, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        fun(result);
    }
}
int main() {
    fast_io;

    in();
    return 0;
}