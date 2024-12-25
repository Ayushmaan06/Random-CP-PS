#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int prices[n];
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    sort(prices, prices + n);

    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        int shops = upper_bound(prices, prices + n, m) - prices;
        cout << shops << endl;
    }

    return 0;
}