#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    int n;
    cin >> n;
    int m = n * (n - 1) / 2;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < m; i += --n) {
        cout << b[i] << ' ';
    }
    cout << "1000000000\n";
}

int main() {
    fastio;
    int NoOfTestCase;
    cin >> NoOfTestCase;
    for (int testcaseno = 1; testcaseno <= NoOfTestCase; testcaseno++) {
        solve();
    }
    return 0;
}