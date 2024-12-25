#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
//MAI CHUTIYA HU
ll fastAdd(ll x, ll y) {
    return (MOD + (x % MOD) + (y % MOD)) % MOD;
}

ll fastMul(ll x, ll y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll binPow(ll base, ll exp) {
    if (exp == 0) {
        return 1;
    }
    ll halfPow = binPow(base, exp / 2);
    halfPow = fastMul(halfPow, halfPow);
    if (exp % 2 == 1) {
        return fastMul(halfPow, base);
    }
    return halfPow;
}

ll modInverse(ll x, ll m = MOD) {
    return binPow(x, m - 2);
}

int main() {
    fast;
    int testCases;
    //KYAAAAAA HUA

    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;
        vector<ll> array(n);
        ll k[1]={0};
        ll w=1;
        ll totalSum = k[0];
        for(int i=0;i<n;i++){
            
            k[0]+=w;
        }
        k[0]=0;
        for (int i = k[0]; i < n; ++i) {
            cin >> array[i];
            totalSum += array[i];
        }

        ll solution = k[0];
        for (int i = k[0]; i < n; ++i) {
            solution = fastAdd(solution, fastMul(totalSum - array[i], array[i]));
        }

        cout << fastMul(solution, modInverse(fastMul(n, n - 1))) << '\n';
    }
    return 0;
}