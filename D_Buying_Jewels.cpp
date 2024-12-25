#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18 + 5;

// Node structure for the segment tree
struct Node {
    long long min_price;
};

// Build segment tree
void build(vector<Node>& tree, const vector<long long>& arr, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].min_price = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(tree, arr, v*2, tl, tm);
        build(tree, arr, v*2+1, tm+1, tr);
        tree[v].min_price = min(tree[v*2].min_price, tree[v*2+1].min_price);
    }
}

// Query the segment tree
long long query(vector<Node>& tree, int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INF;
    if (l == tl && r == tr)
        return tree[v].min_price;
    int tm = (tl + tr) / 2;
    return min(query(tree, v*2, tl, tm, l, min(r, tm)),
               query(tree, v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        // Build the array representing the prices of jewels
        vector<long long> arr(60);
        for (int i = 0; i < 60; ++i) {
            arr[i] = i + 1;
        }

        // Build the segment tree
        vector<Node> tree(4 * 60);
        build(tree, arr, 1, 0, 59);

        // Find the minimum price for Alice to buy exactly k jewels
        long long min_price = query(tree, 1, 0, 59, 0, k - 1);

        // Output the result
        if (min_price <= n) {
            cout << "YES" << endl;
            cout << k << endl;
            for (int i = 0; i < k; ++i) {
                cout << min_price << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
